#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::cin;

struct WorkCategory
{
    uint64_t N;
    uint64_t P;
};

std::vector<WorkCategory> works;
std::vector< std::vector<int> > applicants;

void fileInput(const std::string& input_file = "input.txt")
{
    std::ifstream fin(input_file.c_str());

    int n, m;
    fin >> n >> m;

    works.resize(n);
    applicants.resize(m);

    for (int i = 0; i < n; i++)
    {
        fin >> works[i].N;
    }
    for (int i = 0; i < n; i++)
    {
        fin >> works[i].P;
    }

    for (int i = 0; i < m; i++)
    {
        int k;
        fin >> k;
        applicants[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            fin >> applicants[i][j];
        }
    }
}



int main()
{
    fileInput();



    return 0;
}
