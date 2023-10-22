#include <iterator>
#include <vector>
#include <algorithm>
#include "test.hh"

using namespace std;

/**
 * @brief Arrange vector in three subsequent sections:
 *        - those divisible by three (asc order)
 *        - those whose reminder is 1 (asc order)
 *        - those whose reminder is 2 (asc order)
 * @param v vector to be sorted
 * @return int EXIT_SUCCESS if everything went OK, EXIT_FAILURE otherwise
 */
int sortMod3(std::vector<int>& v)
{
    // First, partition elements divisible by 3 to the beginning
    auto divByThreeEnd = std::stable_partition(v.begin(), v.end(), [](int n) { return n % 3 == 0; });
    // Then partition remaining elements whose reminder is 1
    std::stable_partition(divByThreeEnd, v.end(), [](int n) { return n % 3 == 1; });
    // No need to do anything for those whose reminder is 2, as they are naturally in the third section.

    // Sort each section individually
    std::sort(v.begin(), divByThreeEnd);
    auto rem1End = std::find_if(divByThreeEnd, v.end(), [](int n) { return n % 3 == 2; });
    std::sort(divByThreeEnd, rem1End);
    std::sort(rem1End, v.end());

    return EXIT_SUCCESS;
}


