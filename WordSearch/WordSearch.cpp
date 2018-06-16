#include "WordSearch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unordered_set>

using namespace std;

Word::Word(int rows, int columns)
{
    rows = ROW;
    columns = COL;
    
    ifstream instream;
    instream.open("puzzle.txt");//puzzle.txt
    if(instream.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    
    grid = new Letter**[ROW];
    int i, j;
    
    for(i = 0; i < ROW; i++)
    {
        grid[i] = new Letter*[COL];
    }
    
    char value;
    while(!instream.eof())
    {
        for(i = 0; i < ROW; i++)
        {
            for(j = 0; j < COL; j++)
            {
                instream >> value;
                grid[i][j] = new Letter(value);
                grid[i][j]->yValue = i;
                grid[i][j]->xValue = j;
            }
        }
    }
    
    //instream.close();
}

Word::~Word()
{
    for(int i = 0; i < ROW; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
}

void Word::findWord(string str)
{
    int xStart = 0;
    int yStart = 0;
    int xEnd = 0;
    int yEnd = 0;
    
    ofstream outstream;
    outstream.open("WordSearchResults.txt");
    if(outstream.fail())
    {
        cout << "Output file opening failed." << endl;
        exit(1);
    }
    
    bool found = false;
    
    for(int y = 0; y < ROW && !found; y++)
    {
        for(int x = 0; x < COL && !found; x++)
        {
            //if the letter is found (first letter)
            if(tolower(str[0]) == grid[y][x]->value)
            {
                yStart = y;
                xStart = x;
                
                //searching adjacent spots
                for(int i = 0; i < 8 && !found; i++)
                {
                    bool next = true;
                    int count = 1;
                    Letter* current = grid[y][x]->adjacent[i];
                    
                    while((count < str.length()) && next && !found && (current->value != '0'))
                    {
                        if((tolower(str[count])) != current->value)
                        {
                            next = false;
                        }
                        else if(count == str.length() - 1 && tolower(str[count]) == current->value)
                        {
                            found = true;
                            yEnd = current->yValue;
                            xEnd = current->xValue;
                        }
                        else
                        {
                            count++;
                            current = current->adjacent[i];
                        }
                    }
                }
            }
        }
    }
    
    if((found) && (str.length() >= 6))
    {
        cout << str << " from (" << xStart << ", " << yStart << ") to (" << xEnd << ", " << yEnd << ")" << endl;
    }
    //outstream.close();
    //return found;
}

void Word::givePositions(bool end)
{
    for(int y = 0; y < ROW; y++)
    {
        for(int x = 0; x < COL; x++)
        {
            adjacentPositions(y,x, end);
        }
    }
}

void Word::adjacentPositions(int y, int x, bool end)
{
    int maxRow = ROW - 1;
    int maxCol = COL - 1;
    
    bool up = (y == 0);
    bool down = (y == maxRow);
    bool left = (x == 0);
    bool right = (x == maxCol);
    
    //diagonally upwards to the left - end
    if(!up && !left)
    {
        grid[y][x]->adjacent[0] = grid[y-1][x-1];
    }
    else if(up && left)
    {
        grid[y][x]->adjacent[0] = grid[maxRow][maxCol];
    }
    else if(up)
    {
        grid[y][x]->adjacent[0] = grid[maxRow][x-1];
    }
    else if(left)
    {
        grid[y][x]->adjacent[0] = grid[y-1][maxCol];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[0] = new Letter('0');
    }
    
    //upwards - end
    if(!up)
    {
        grid[y][x]->adjacent[1] = grid[y-1][x];
    }
    else if(up)
    {
        grid[y][x]->adjacent[1] = grid[maxRow][x];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[1] = new Letter('0');
    }
    
    //diagonally upwards to the right - end
    if(!up && !right)
    {
        grid[y][x]->adjacent[2] = grid[y-1][x+1];
    }
    else if(up && right)
    {
        grid[y][x]->adjacent[2] = grid[maxRow][0];
    }
    else if(up)
    {
        grid[y][x]->adjacent[2] = grid[maxRow][x+1];
    }
    else if(right)
    {
        grid[y][x]->adjacent[2] = grid[y-1][0];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[2] = new Letter('0');
    }
    
    //right - endl
    if(!right)
    {
        grid[y][x]->adjacent[3] = grid[y][x+1];
    }
    else if(right)
    {
        grid[y][x]->adjacent[3] = grid[y][0];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[3] = new Letter('0');
    }
    
    //diagonally downwards to the right - end
    if(!down && !right)
    {
        grid[y][x]->adjacent[4] = grid[y+1][x+1];
    }
    else if(down && right)
    {
        grid[y][x]->adjacent[4] = grid[0][0];
    }
    else if(down)
    {
        grid[y][x]->adjacent[4] = grid[0][x+1];
    }
    else if(right)
    {
        grid[y][x]->adjacent[4] = grid[y+1][0];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[4] = new Letter('0');
    }
    
    //downwards - end
    if(!down)
    {
        grid[y][x]->adjacent[5] = grid[y+1][x];
    }
    else if(down)
    {
        grid[y][x]->adjacent[5] = grid[0][x];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[5] = new Letter('0');
    }
    
    //diagonally downwards to the left - end
    if(!down && !left)
    {
        grid[y][x]->adjacent[6] = grid[y+1][x-1];
    }
    else if(down && left)
    {
        grid[y][x]->adjacent[6] = grid[0][maxCol];
    }
    else if(left)
    {
        grid[y][x]->adjacent[6] = grid[y+1][maxCol];
    }
    else if(down)
    {
        grid[y][x]->adjacent[6] = grid[0][x-1];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[6] = new Letter('0');
    }
    
    //left - end
    if(!left)
    {
        grid[y][x]->adjacent[7] = grid[y][x-1];
    }
    else if(left)
    {
        grid[y][x]->adjacent[7] = grid[y][maxCol];
    }
    else if(!end)
    {
        grid[y][x]->adjacent[7] = new Letter('0');
    }
}