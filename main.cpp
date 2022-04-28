#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol833;

/*
Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".
*/

tuple<string, vector<int>, vector<string>, vector<string>, string>
testFixture1()
{
  return make_tuple("abcd", vector<int>{0, 2},
                    vector<string>{"a", "cd"},
                    vector<string>{"eee", "ffff"},
                    "eeebffff");
}

/*
Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee".
"ec" doesn't starts at index 2 in the original S, so we do nothing.
*/

tuple<string, vector<int>, vector<string>, vector<string>, string>
testFixture2()
{
  return make_tuple("abcd", vector<int>{0, 2},
                    vector<string>{"ab", "ec"},
                    vector<string>{"eee", "ffff"},
                    "eeecd");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << get<4>(f) << endl;
  Solution sol;
  cout << sol.replace(get<0>(f), get<1>(f), get<2>(f), get<3>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << get<4>(f) << endl;
  Solution sol;
  cout << sol.replace(get<0>(f), get<1>(f), get<2>(f), get<3>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}