//Daniel Nelson (102578897)
#pragma once
#include "Cell.h"
#include "SearchAlgorithm.h"
#include <vector>



class AStarSearch : public SearchAlgorithm
{
private:

public:
    void AS(Cell* cell, vector<int> bestgoal, bool weighted);
};