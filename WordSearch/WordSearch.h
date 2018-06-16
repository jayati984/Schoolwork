#ifndef WORDSEARCH_H
#define WORDSEARCH_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <unordered_set>

using namespace std;

class Word
{
    public:
        Word(int rows, int columns);
        ~Word();
        void findWord(string str);
        void adjacentPositions(int, int, bool);
        void givePositions(bool);
        class Letter
        {
            public:
                Letter(char value):value(value) {};
                int xValue; //x-coordinate
                int yValue; //y-coordinate
                char value; //actual letter
                Letter* adjacent[8];
        };
    private:
        unordered_set<string> table;
        Letter*** grid;
        const int ROW = 1782;//1782
        const int COL = 37;//37
};

#endif