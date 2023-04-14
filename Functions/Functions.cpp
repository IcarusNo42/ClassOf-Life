
#include "Functions.h"
unordered_map<char, char> complement = {{'A', 'T'}, {'C', 'G'}, {'G', 'C'}, {'T', 'A'}};
// Method to find the complementary sequence of a given DNA sequence
string complementary(string s)
{
  for (auto &i : s)
  {
    i = complement[i];
  }
  return s;
}
// Method to compute the Longest Proper Prefix which is also a Suffix (LPS) of a given pattern string
vector<int> computeLPS(string pattern)
{
  int m = pattern.length();
  vector<int> lps(m);
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < m)
  {
    if (pattern[i] == pattern[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
        len = lps[len - 1];
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}