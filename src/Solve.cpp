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

}

std::vector<int> solveD()
{
    return brute();
}

std::vector<int> solveE()
{
    return brute();
}

std::vector<int> brute(size_t i)
{
    static std::vector<bool> activated(applicants.size());

    static int min_score = INT_MAX;
    static std::vector<int> best_result;
    static int min_possible_score = 0;

    for (size_t i = 0; i < works.size(); i++)
    {
        min_possible_score += works[i].P;
    }

    activated[i] = false;
    if (i < applicants.size() - 1)
    {
        brute(i + 1);
    }
    else
    {
        if (isWorks(activated))
        {
            int countScore_result = countScore(activated);
            if (countScore_result < min_score)
            {
                min_score = countScore_result;
                best_result.clear();
                for (size_t i = 0; i < activated.size(); i++)
                {
                    if (activated[i])
                    {
                        best_result.push_back(i);
                    }
                }

                if (min_score == min_possible_score)
                {
                    return best_result;
                }
            }
        }
    }

    activated[i] = true;
    if (i < applicants.size() - 1)
    {
        brute(i + 1);
    }
    else
    {
        if (isWorks(activated))
        {
            int countScore_result = countScore(activated);
            if (countScore_result < min_score)
            {
                min_score = countScore_result;
                best_result.clear();
                for (size_t i = 0; i < activated.size(); i++)
                {
                    if (activated[i])
                    {
                        best_result.push_back(i);
                    }
                }

                if (min_score == min_possible_score)
                {
                    return best_result;
                }
            }
        }
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
