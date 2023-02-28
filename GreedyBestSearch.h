//Daniel Nelson (102578897)
#pragma once
#include "Cell.h"
#include "SearchAlgorithm.h"
#include <vector>

class GreedyBestSearch : public SearchAlgorithm
{
private:

public:
    void GBFS(Cell* cell, vector<int> bestgoal, bool weighted);
};

