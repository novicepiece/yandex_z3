#include "Input.h"

void fileInput(const std::string& input_file)
{
    works.clear();
    applicants.clear();
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
