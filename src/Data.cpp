#include "Data.h"

int applicantScore(Applicant applicant)
{
    int max_P = 0;

    for (size_t i = 0; i < applicant.skills.size(); i++)
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

int countScore(const std::vector<int> &activated)
{
    int result = 0;

    for (size_t i = 0; i < activated.size(); i++)
    {
        result += applicantScore(applicants[activated[i]]);
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
