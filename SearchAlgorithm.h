//Daniel Nelson (102578897)
#pragma once
#include "Cell.h"
#include <vector>

using namespace std;

class SearchAlgorithm 
{
    private:

    public:

        int Distance(int x1, int y1, int x2, int y2);

        vector<Cell*> Sort(vector<Cell*> queue);
        
        void PrintPath(Cell* goal);
        
        vector<int> BestGoal(Cell * cell, vector<vector<int>>& goals);

        int Get_Weight(int index);

};