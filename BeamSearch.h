//Daniel Nelson (102578897)
#pragma once
#include "SearchAlgorithm.h"
using namespace std;

class BeamSearch : public SearchAlgorithm
{
    public:
        void BS(Cell*, vector<int> bestgoal, bool weighted);
        bool Search(Cell*, vector<int> bestgoal, size_t beamwidth, bool weighted);
};