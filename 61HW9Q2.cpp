#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
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
    graph g;
    string str;
    
    while(instream >> str)
    {
        g.add_vertex(str);
        v.push_pack(str);
        string str2;
        for(size_t i = 0; i < v.size(); i++)
        {
            str2[i] = v[i];
            size_t count = 0;
            for(size_t j = 0; j < str.size(); j++)
            {
                if(str[j] != str2[j])
                {
                    count++;
                }
                    
                if(count == 1)
                {
                    g.add_edge(str, str2);
                }
            }
        }
    }
    
    vector<string> one {"black", "tears", "small", "stone", "angel", "amino", "angel"};
    vector<string> two {"white", "smile", "giant", "money", "devil", "right", "signs"};
    vector<strign>::iterator iter;
    for(size_t k = 0; k < one.size(); k++)
    {
        vector<string> three = g.path(one[k], two[k]);
        cout << one[i] << " - " << two[i] << " : ";
        for(iter = three.end(); iter != three.begin(); iter++)
        {
            cout << *iter << " "
        }
        cout << endl;
    }
    
    return 0;
}