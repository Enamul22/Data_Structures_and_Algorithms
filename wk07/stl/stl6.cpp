#include <iterator>
#include <map>
#include <algorithm>
#include "test.hh"

using namespace std;

/**
 * @brief From a map find the first element, whose value is at least given limit
 *        regardless of the key of the element. Return only the value or
 *        NOT_FOUND if none of the values match the the search criteria.
 * @param m map that is scanned through
 * @param given limit for the values to search
 * @return int the real found value
 */
int findAtLeastGiven(std::map<std::string, int>& m, int given)
{
    auto it = std::find_if(m.begin(), m.end(), [given](const std::pair<std::string, int>& elem) {
        return elem.second >= given;
    });

    if (it != m.end()) {
        return it->second;
    }

    return NOT_FOUND;
}


