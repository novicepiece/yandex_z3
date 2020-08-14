#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED

#include "Data.h"
#include <vector>
#include <cstdlib>
#include <algorithm>

std::vector<int> solve(testType test_type = ttBrute);
std::vector<int> solveA();
std::vector<int> solveB();
std::vector<int> solveC();
std::vector<int> solveD();
std::vector<int> solveE();
std::vector<int> brute(size_t i = 0);

#endif // SOLVE_H_INCLUDED
