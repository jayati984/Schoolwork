#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cassert>
#include "graph.h"

using namespace std;

int main()
{
    ifstream instream;
    instream.open("knuth.txt");
    if(instream.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    
    vector<string> v;
    string str;
    graph G;
    
    while(instream >> str)
    {
        G.add_vertex(str);
        v.push_back(str);
        for(auto str2: v)
        {
            size_t count = 0;
            for(size_t i = 0; i < str.size(); i++)
            {
                if(str[i] != str2[i])
                {
                    ++count;
                }
            }
            
            if(count == 1)
            {
                G.add_edge(str, str2);
            }
        }
    }
    
    vector<string> one {"black", "tears", "small", "stone", "angel", "amino", "angel"};
    vector<string> two {"white", "smile", "giant", "money", "devil", "right", "signs"};
    for(size_t i = 0; i < one.size(); ++i)
    {
        vector<string> three = G.shortest_path(one[i], two[i]);
        cout << one[i] << " - " << two[i] << " : ";
        for(auto iter = three.rbegin(); iter != three.rend(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    
    return 0;
}