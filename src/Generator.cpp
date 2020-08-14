#include "Generator.h"
#include <iostream>
void generateTest(const testType &test_type, const std::string &output_file)
{
    srand(time(0));
    std::ofstream fout(output_file.c_str());

    std::vector<WorkCategory> _works;
    std::vector<Applicant> _applicants;

    if (test_type == ttA)
    {
        generateTestA(_works, _applicants);
    }
    else if (test_type == ttB)
    {
        generateTestB(_works, _applicants);
    }
    else if (test_type == ttC)
    {
        generateTestC(_works, _applicants);
    }
    else if (test_type == ttD)
    {
        generateTestD(_works, _applicants);
    }
    else if (test_type == ttE)
    {
        generateTestE(_works, _applicants);
    }
    else if (test_type == ttBrute)
    {
        generateTestBrute(_works, _applicants);
    }

    // Out
    fout << _works.size() << ' ' << _applicants.size() << '\n';

    std::cout << "|Works N|\n";

    for (size_t i = 0; i < _works.size(); i++)
    {
        fout << _works[i].N << ' ';
        std::cout << _works[i].N << ' ';
    }
    fout << '\n';
    std::cout << "\n|Works P|\n";
    for (size_t i = 0; i < _works.size(); i++)
    {
        fout << _works[i].P << ' ';
        std::cout << _works[i].P << ' ';
    }
    fout << '\n';
    std::cout << "\n\n|Applicants skills|\n";
    for (size_t i = 0; i < _applicants.size(); i++)
    {
        fout << _applicants[i].skills.size() << ' ';
        std::cout << i + 1 << ") ";
        for (size_t j = 0; j < _applicants[i].skills.size(); j++)
        {
            fout << _applicants[i].skills[j] << ' ';
            std::cout << _applicants[i].skills[j] << ' ';
        }
        fout << '\n';
        std::cout << '\n';
    }

    fout.close();
}

void generateTestA(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants)
{
    _works.resize(randomRange(1, 10));

    int works_N_count = 0;
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].N = randomRange(1, 4);
        works_N_count += _works[i].N;
    }
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].P = randomRange(1, 10);
    }

    _applicants.resize(works_N_count + randomRange(1, 15));

    for (size_t i = 0; i < _works.size(); i++)
    {
        for (size_t j = 0; j < _works[i].N; j++)
        {
            size_t q = randomRange(0, _applicants.size());
            while (_applicants[q].skills.size() > 0)
            {
                q = randomRange(0, _applicants.size());
            }

            _applicants[q].skills.push_back(i + 1);
        }
    }

    int random_count = randomRange(0, works_N_count - applicants.size());
    for (size_t i = 0; i < random_count; i++)
    {
        size_t q = randomRange(0, _applicants.size());
        size_t push_random = randomRange(0, _works.size());

        while (_applicants[q].skills.size() > 0)
        {
            q = randomRange(0, _applicants.size());
            size_t push_random = randomRange(0, _works.size());
        }

        _applicants[q].skills.push_back(push_random + 1);
    }
    _applicants.erase(std::remove_if(_applicants.begin(), _applicants.end(), [&](const Applicant &applicant) { return applicant.skills.size() == 0; }), _applicants.end());
}

void generateTestB(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants)
{
    _works.resize(randomRange(1, 10));
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].N = randomRange(1, 4);
    }
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].P = randomRange(1, 10);
    }

    _applicants.resize(_works.size() + randomRange(1, 15));

    for (size_t i = 0; i < _applicants.size(); i++)
    {
        for (size_t j = 0; j < _works.size(); j++)
        {
            _applicants[i].skills.push_back(j + 1);
        }
    }
}

void generateTestC(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants)
{
    _works.resize(randomRange(5, 8));

    int works_N_random = randomRange(1, 4);
    int works_N_count = 0;
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].N = works_N_random;
        works_N_count += _works[i].N;
    }
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].P = randomRange(1, 10);
    }

    _applicants.resize(works_N_count + randomRange(1, 15));

    for (size_t i = 0; i < _works.size(); i++)
    {
        for (size_t j = 0; j < _works[i].N; j++)
        {
            size_t q = randomRange(0, _applicants.size());
            while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), i + 1) != _applicants[q].skills.end())
            {
                q = randomRange(0, _applicants.size());
            }

            _applicants[q].skills.push_back(i + 1);
        }
    }

    int random_count = randomRange(0, _applicants.size() - works_N_count);
    for (size_t i = 0; i < random_count; i++)
    {
        size_t q = randomRange(0, _applicants.size());
        size_t push_random = randomRange(0, _works.size());
        while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), push_random + 1) != _applicants[q].skills.end())
        {
            q = randomRange(0, _applicants.size());
            push_random = randomRange(0, _works.size());
        }

        _applicants[q].skills.push_back(push_random + 1);
    }
    _applicants.erase(std::remove_if(_applicants.begin(), _applicants.end(), [&](const Applicant &applicant) { return applicant.skills.size() == 0; }), _applicants.end());
}

void generateTestD(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants)
{
_works.resize(randomRange(1, 10));

    int works_N_count = 0;
    int works_P_random = randomRange(1, 5);
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].N = randomRange(1, 4);
        works_N_count += _works[i].N;
    }
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].P = works_P_random;
    }

    _applicants.resize(works_N_count + randomRange(1, 15));

    for (size_t i = 0; i < _works.size(); i++)
    {
        for (size_t j = 0; j < _works[i].N; j++)
        {
            size_t q = randomRange(0, _applicants.size());
            while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), i + 1) != _applicants[q].skills.end())
            {
                q = randomRange(0, _applicants.size());
            }

            _applicants[q].skills.push_back(i + 1);
        }
    }

    int random_count = randomRange(0, works_N_count);
    for (size_t i = 0; i < random_count; i++)
    {
        size_t q = randomRange(0, _applicants.size());
        size_t push_random = randomRange(0, _works.size());
        while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), push_random + 1) != _applicants[q].skills.end())
        {
            q = randomRange(0, _applicants.size());
            size_t push_random = randomRange(0, _works.size());
        }

        _applicants[q].skills.push_back(push_random + 1);
    }
    _applicants.erase(std::remove_if(_applicants.begin(), _applicants.end(), [&](const Applicant &applicant) { return applicant.skills.size() == 0; }), _applicants.end());
}

void generateTestE(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants)
{
    _works.resize(randomRange(1, 10));

    int works_N_count = 0;
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].N = randomRange(1, 4);
        works_N_count += _works[i].N;
    }
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].P = randomRange(1, 10);
    }

    _applicants.resize(works_N_count);

    for (size_t i = 0; i < _works.size(); i++)
    {
        for (size_t j = 0; j < _works[i].N; j++)
        {
            size_t q = randomRange(0, _applicants.size());
            while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), i + 1) != _applicants[q].skills.end())
            {
                q = randomRange(0, _applicants.size());
            }

            _applicants[q].skills.push_back(i + 1);
        }
    }

    int random_count = randomRange(0, works_N_count);
    for (size_t i = 0; i < random_count; i++)
    {
        size_t q = randomRange(0, _applicants.size());
        size_t push_random = randomRange(0, _works.size());
        while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), push_random + 1) != _applicants[q].skills.end())
        {
            q = randomRange(0, _applicants.size());
            size_t push_random = randomRange(0, _works.size());
        }

        _applicants[q].skills.push_back(push_random + 1);
    }
    _applicants.erase(std::remove_if(_applicants.begin(), _applicants.end(), [&](const Applicant &applicant) { return applicant.skills.size() == 0; }), _applicants.end());
}

void generateTestBrute(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants)
{
    _works.resize(randomRange(1, 10));

    int works_N_count = 0;
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].N = randomRange(1, 4);
        works_N_count += _works[i].N;
    }
    for (int i = 0; i < _works.size(); i++)
    {
        _works[i].P = randomRange(1, 10);
    }

    _applicants.resize(works_N_count + randomRange(1, 15));

    for (size_t i = 0; i < _works.size(); i++)
    {
        for (size_t j = 0; j < _works[i].N; j++)
        {
            size_t q = randomRange(0, _applicants.size());
            while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), i + 1) != _applicants[q].skills.end())
            {
                q = randomRange(0, _applicants.size());
            }

            _applicants[q].skills.push_back(i + 1);
        }
    }

    int random_count = randomRange(0, works_N_count);
    for (size_t i = 0; i < random_count; i++)
    {
        size_t q = randomRange(0, _applicants.size());
        size_t push_random = randomRange(0, _works.size());
        while (_applicants[q].skills.size() > 0 && std::find(_applicants[q].skills.begin(), _applicants[q].skills.end(), push_random + 1) != _applicants[q].skills.end())
        {
            q = randomRange(0, _applicants.size());
            size_t push_random = randomRange(0, _works.size());
        }

        _applicants[q].skills.push_back(push_random + 1);
    }
    _applicants.erase(std::remove_if(_applicants.begin(), _applicants.end(), [&](const Applicant &applicant) { return applicant.skills.size() == 0; }), _applicants.end());
}
