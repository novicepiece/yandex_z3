#include "include/Input.h"
#include "include/Data.h"
#include "include/Generator.h"
#include "include/Solve.h"

using std::cout;
using std::cin;

std::vector<WorkCategory> works;
std::vector<Applicant> applicants;

int main()
{
    const testType test_type = ttC;
    generateTest(test_type);
    fileInput();
    std::vector<int> result = solve(test_type);
    cout << "You should take applicants number\n";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] + 1 << " ";
    }
    cout << "\n";

    int solved_score = countScore(result);
    fileInput();
    std::vector<int> brute_result = solve(ttBrute);
    int brute_score = countScore(brute_result);

    cout << "Brute solution\n";
    for (size_t i = 0; i < brute_result.size(); i++)
    {
        cout << brute_result[i] + 1 << " ";
    }
    cout << "\n";

    cout << solved_score << " " << brute_score << "\n" << (brute_score == solved_score) << "\n";
    return 0;
}
