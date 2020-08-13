#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <time.h>

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

int randomRange(int bottom, int up)
{
    return (rand() % (up - bottom)) + bottom;
}

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
    return result;
}

bool isWorks(std::vector<bool> &activated)
{
    std::vector<int> N(works.size());

    for (size_t i = 0; i < activated.size(); i++)
    {
        if (activated[i])
        {
            for (size_t j = 0; j < applicants[i].skills.size(); j++)
            {
                N[applicants[i].skills[j]]++;
            }
        }
    }

    for (size_t i = 0; i < N.size(); i++)
    {
        if (N[i] < works[i].N)
        {
            return false;
        }
    }

    return true;
}

void generateTest(const std::string& output_file = "input.txt", const testType test_type = ttBrute)
{
    srand(time(0));
    std::ofstream fout(output_file.c_str());

    int n = randomRange(1, 10);

    std::vector<WorkCategory> _works(n);
    int works_count = 0;
    for (int i = 0; i < n; i++)
    {
        _works[i].N = randomRange(1, 5);
        works_count += _works[i].N;
    }
    for (int i = 0; i < n; i++)
    {
        _works[i].P = randomRange(1, 10);
    }

    int m = works_count + randomRange(1, 15);
    std::vector<Applicant> _applicants(m);

    for (size_t i = 0; i < _works.size(); i++)
    {
        for (size_t j = 0; j < _works[i].N; j++)
        {
            size_t q = randomRange(0, m);
            while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), i + 1) != _applicants[q].skills.end())
            {
                q = randomRange(0, m);
            }
            _applicants[q].skills.push_back(i + 1);
        }
    }

    int random_count = randomRange(0, n);
    for (size_t i = 0; i < random_count; i++)
    {
        size_t q = randomRange(0, m);
        size_t push_random = randomRange(0, _works.size()) + 1;
        while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), push_random) != _applicants[q].skills.end())
        {
            push_random = randomRange(0, _works.size()) + 1;
            q = randomRange(0, m);
        }

        _applicants[q].skills.push_back(push_random);
    }
    _applicants.erase(std::remove_if(_applicants.begin(), _applicants.end(), [&](const Applicant &applicant) { return applicant.skills.size() == 0; }), _applicants.end());

    m = _applicants.size();

    fout << n << ' ' << m << '\n';

    for (int i = 0; i < n; i++)
    {
        fout << _works[i].N << ' ';
    }
    fout << '\n';
    for (int i = 0; i < n; i++)
    {
        fout << _works[i].P << ' ';
    }
    fout << '\n';

    for (int i = 0; i < m; i++)
    {
        fout << _applicants[i].skills.size() << ' ';
        for (int j = 0; j < _applicants[i].skills.size(); j++)
        {
            fout << _applicants[i].skills[j] << ' ';
        }
        fout << '\n';
    }
    fout.close();
}

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

    static int min_score = INT_MAX;
    static std::vector<int> best_result;

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
            }
        }
    }

    return best_result;
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
    generateTest();
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
