#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <vector>
#include <cstdlib>
#include <algorithm>

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

extern std::vector<WorkCategory> works;
extern std::vector<Applicant> applicants;

int applicantScore(Applicant applicant);
int countScore(const std::vector<int> &activated);
bool isWorks(std::vector<int> &activated);


#endif // DATA_H_INCLUDED
