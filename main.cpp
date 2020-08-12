#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::cin;

enum testType
{
    ttA,
    ttB,
    ttC,
    ttD,
    ttE,
    ttBrute
};

struct WorkCategory
{
    int N;
    int P;
};

struct Applicant
{
    std::vector<int> skills;
};

std::vector<WorkCategory> works;
std::vector<Applicant> applicants;

void fileInput(const std::string& input_file = "input.txt")
{
    std::ifstream fin(input_file.c_str());

    size_t n, m;
    fin >> n >> m;

    works.resize(n);
    applicants.resize(m);

    for (size_t i = 0; i < n; i++)
    {
        fin >> works[i].N;
    }
    for (size_t i = 0; i < n; i++)
    {
        fin >> works[i].P;
    }

    for (size_t i = 0; i < m; i++)
    {
        size_t k;
        fin >> k;
        applicants[i].skills.resize(k);
        for (size_t j = 0; j < k; j++)
        {
            fin >> applicants[i].skills[j];
            applicants[i].skills[j]--;
        }
    }
}

int applicantScore(Applicant applicant)
{
    int max_P = 0;

    for (int i = 0; i < applicant.skills.size(); i++)
    {
        max_P = std::max(max_P, works[applicant.skills[i]].P);
    }

    return max_P;
}

int countScore(const std::vector<bool> &activated)
{
    int result = 0;

    for (size_t i = 0; i < activated.size(); i++)
    {
        if (activated[i])
        {
            result += applicantScore(applicants[i]);
        }
    }
}

void generateTest(const std::string& output_file = "input.txt", const testType test_type = ttBrute)
{
    std::ofstream fout(output_file.c_str());
}

bool foo(const Applicant &applicant)
{
    return true;
}

std::vector<int> solveA()
{
    std::vector<int> result;

    std::vector<Applicant>::iterator it = applicants.begin();
    for (int i = 0; i < works.size(); i++)
    {
        it = std::find_if(it, applicants.end(), [&i](const Applicant &applicant) { return applicant.skills[0] == i; });
        result.push_back(it - applicants.begin());
    }

    return result;
}

std::vector<int> solveB()
{
    std::vector<int> result;

    int max_N = 0;

    for (size_t i = 0; i < works.size(); i++)
    {
        std::max(max_N, works[i].N);
    }

    result.resize(max_N);
    std::iota(result.begin(), result.end(), 1);

    return result;
}


std::vector<int> solveC()
{

}

std::vector<int> solveD()
{

}

std::vector<int> solveE()
{

}

std::vector<int> brute(size_t i = 0)
{
    static std::vector<bool> activated(applicants.size());

    static int min_score = INT_MIN;
    static std::vector<int> best_result;

    activated[i] = false;
    if (i < applicants.size() - 1)
    {
        brute(i + 1);
    }
    else
    {
        if (min_score < countScore(activated))
        {
            best_result.clear();

            for (size_t i = 0; i < activated.size(); i++)
            {
                if (activated[i])
                {
                    best_result.push_back(i);
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
        if (min_score < countScore(activated))
        {
            best_result.clear();

            for (size_t i = 0; i < activated.size(); i++)
            {
                if (activated[i])
                {
                    best_result.push_back(i);
                }
            }
        }
    }
}

std::vector<int> solve(testType test_type = ttBrute)
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

int main()
{
    fileInput();
    std::vector<int> result = solve(ttBrute);

    cout << "You should take applicants number\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}
