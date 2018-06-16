#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <queue>
#include <algorithm>
/*
namespace std
{
    template <>
	class hash<std::pair<std::string, std::string>>
        {
        public:
		std::size_t operator() (const std::pair<std::string, std::string> & p) const
		{
                    return std::hash<std::string> () (p.first) ^
                            std::hash<std::string> () (p.second);
                }
        };
}*/

class graph
{   
    public:
	typedef std::string Vertex;
	typedef std::pair<Vertex, Vertex> Edge;
	typedef std::vector<Vertex>      Path;
	
	typedef std::unordered_set<Vertex> VertexSet;
	typedef std::unordered_set<Edge>   EdgeSet;
        typedef std::unordered_map<Vertex, std::size_t> V2I;
        typedef std::unordered_map<Vertex, Vertex>      V2V;

        graph()
        {
            
        }

        std::size_t n()
        {
            return _t.size();
        }

        std::size_t m()
        {
            std::size_t ans(0);
            
            for (auto p: _t)
                ans += p.second.size();
            
            return ans/2;
        }

        bool isVertex(Vertex & v)
        {
            return (_t.count(v) == 1);
        }

        std::size_t deg(Vertex & v)
        {
            assert (isVertex(v));
            
            return  _t.at(v).size();
        }

        VertexSet V()
        {
            VertexSet ans;
            
            for (auto p: _t)
		ans.insert(p.first);
            
            return ans;
        }

        VertexSet Adj(Vertex & v)
        {
            assert(isVertex(v));
            return _t.at(v);
        }

        void add_vertex(Vertex & v)
        {
            assert(_t.find(v) == _t.end());
            _t[v] = VertexSet();
        }

        void add_edge(Vertex & s, Vertex & d)
        {
            assert(isVertex(s) && isVertex(d));
            _t[s].insert(d);
            _t[d].insert(s);
        }   

        V2V bfs(Vertex& start)
        {
            std::queue<Vertex> q;
            V2V parent;
	
            q.push(start);
            parent[start] = start;

            while(!q.empty())
            {
                Vertex front = q.front();
                q.pop();
                for(auto v: Adj(front))
                {
                    if(parent.count(v) == 0)
                    {
                        q.push(v);
                        parent[v] = front;
                    }
                }
            }
            return parent;
        }

        Path shortest_path(Vertex & s , Vertex & d)
        {
            std::queue<Vertex> q;
            V2V parent;
            Path ans;
    
            parent[s] = s;
            q.push(s);
    
            bool found(false);
            while(!q.empty())
            {
                Vertex front = q.front();
                q.pop();
                for(auto n: Adj(front))
                {
                    if(parent.find(n) == parent.end())
                    {
                        parent[n] = front;
                        q.push(n);
                    
                        if(n == d)
                        {
                            found = true;
                            break;
                        }
                    }
                }
            }
            
            if(found)
            {
                Vertex v = d;
                while(v != s)
                {
                    ans.push_back(v);
                    v = parent[v];
                }
                ans.push_back(s);
            }
            return ans;
        }

        /*std::size_t nc() const
        {
            std::size_t ans(0);
            VertexSet visited;

            for(auto v : V())
            {
                ++ans;
                if(visited.count(v))
                    V2V parent = bfs(v);

                for(auto p: parent)
                    visited.insert(p.first);
            }
            
            return ans;
        }

        bool isConnected() const
        {
            return (nc() == 1);
        }

        bool isAcyclic() const
        {
            return (n() >=  m() + nc());
        }*/

    private:
        
        std::unordered_map<Vertex, VertexSet> _t;
};

std::ostream & operator << (std::ostream & os, graph & G)
{
    os << G.n() << " " << G.m() << std:: endl;
    
    for (auto v : G.V())
        os << v << " ";
    
    os << std:: endl;

    for (auto v: G.V())
    {
        for(auto w: G.Adj(v))
            if(v < w)
                os << v << " " << w << std:: endl;
    }
        
    return os;
}

std::istream & operator >> (std::istream & is, graph & G)
{
    std::size_t n, m;
    is >> n >> m;
    std::string s, d;
	
    for(std::size_t i = 0; i < n; ++i)
    {
        is >> s;
        G.add_vertex(s);
    }
        
    for(std::size_t i = 0; i < m; ++i)
    {
        is >> s >> d;
        G.add_edge(s,d);
    }
    
    return is;
}
	
#endif //GRAPH_H
