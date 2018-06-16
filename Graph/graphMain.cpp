#include "graph.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    graph g;
    
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    
    //first screenshot input
    /*g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(3,4);
    
    cout << "From vertex 1 to vertex 4: " << endl;
    g.longest_path(1,4);*/
    
    //second screenshot input
    g.add_edge(1,4);
    g.add_edge(4,3);
    g.add_edge(3,2);

    cout << "From vertex 1 to vertex 2: " << endl;
    g.longest_path(1,2);
    cout << endl;
    
    return 0;
}