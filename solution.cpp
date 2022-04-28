#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol833;
using namespace std;

/*takeaways
  - tackle the replacements starting
    from the ones with larger indexes
    will make the code much, much easier
    to write or it will become quite
    complex to code the logic
  - the reason for that is for each
    replacement done the resulting
    s can still be used for the next
    replacement as the current
    replacement will not change
    any of the portion of the s
    that the next replacement
    needs to look at
  - this is possible due to
    there is no overlapping
    among replacements
*/

string Solution::replace(string s, vector<int> &indexes,
                         vector<string> &sources, vector<string> &targets)
{
  /* sort the indexes in descending order
     so that we can manipulate the s from
     the back without affecting each replacement
     as they are guaranteed not overlapping
     with one another
  */
  auto sorted = vector<pair<int, int>>();
  /* sort by the values of indexes */
  for (auto i = 0; i < indexes.size(); i++)
    /* record the original index so that we
       refer to the corresponding source
       and target
    */
    sorted.push_back({indexes[i], i});
  /* sort it in ascending order from the back
     - this is effectively the same as sorting
       it in descending order
  */
  sort(sorted.rbegin(), sorted.rend());

  for (auto &[at, indx] : sorted)
    if (s.substr(at).find(sources[indx]) == 0)
      /* replace the source in s with the target*/
      s = s.substr(0, at) + targets[indx] + s.substr(at + sources[indx].size());

  return s;
}