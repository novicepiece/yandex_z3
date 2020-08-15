#include "Solve.h"
#include <iostream>

std::vector<int> solveA()
{
    std::vector<int> result;

    for (int i = 0; i < applicants.size(); i++)
    {
        if (works[applicants[i].skills[0]].N > 0)
        {
            works[applicants[i].skills[0]].N--;
            result.push_back(i);
        }
    }

    return result;
}

std::vector<int> solveB()
{
    std::vector<int> result;

    int max_N = 0;

    for (size_t i = 0; i < works.size(); i++)
    {
        max_N = std::max(max_N, works[i].N);
    }

    result.resize(max_N);
    std::iota(result.begin(), result.end(), 0);

    return result;
}

std::vector<int> solveC()
{
    return brute();
}

std::vector<int> solveD()
{
    return brute();
}

std::vector<int> solveE()
{
    return brute();
}

bool next_combination(std::vector<int> &current)
{
    int n = applicants.size() - 1;
    int k = current.size();
    for (int i = k - 1; i >= 0; i--)
    {
        if (current[i] < n - k + i + 1)
        {
            current[i]++;
            for (int j = i + 1; j < k; j++)
            {
                current[j] = current[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

std::vector<int> brute()
{
    std::vector<bool> activated(applicants.size());

    int min_score = INT_MAX;
    std::vector<int> best_result;
    int min_possible_score = 0;

    int max_P = 0;
    int max_N = 0;
    for (size_t i = 0; i < works.size(); i++)
    {
        max_N = std::max(max_N, works[i].N);
        max_P = std::max(max_P, works[i].P);
    }

    min_possible_score = max_P * max_N;

    std::vector<int> current;

    for (int i = 1; i <= applicants.size(); i++)
    {
        current.resize(i);
        std::iota(current.begin(), current.end(), 0);

        do
        {
            int current_score = countScore(current);
            if (min_score > current_score && isWorks(current))
            {
                min_score = current_score;
                best_result = current;
                if (min_score == min_possible_score)
                {
                    return best_result;
                }
            }
        } while (next_combination(current));
    }

    return best_result;
}

std::vector<int> solve(testType test_type)
{
    if (test_type == ttA)
    {
        return solveA();
    }
    else if (test_type == ttB)
    {
        return solveB();
    }
    else if (test_type == ttC)
    {
        return solveC();
    }
    else if (test_type == ttD)
    {
        return solveD();
    }
    else if (test_type == ttE)
    {
        return solveE();
    }
    else
    {
        return brute();
    }
}
