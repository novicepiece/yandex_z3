#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Data.h"
#include "Random.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

void generateTest(const testType &test_type, const std::string &output_file = "input.txt");
void generateTestA(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants);
void generateTestB(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants);
void generateTestC(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants);
void generateTestD(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants);
void generateTestE(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants);
void generateTestBrute(std::vector<WorkCategory> &_works, std::vector<Applicant> &_applicants);
#endif // GENERATOR_H_INCLUDED
