
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;
namespace sol833
{

  class Solution
  {
  private:
  public:
    string replace(string s, vector<int> &indexes,
                   vector<string> &sources, vector<string> &targets);
  };
}
#endif