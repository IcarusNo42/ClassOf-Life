
#include "Functions.h"
unordered_map<char, char> complement = {{'A', 'T'}, {'C', 'G'}, {'G', 'C'}, {'T', 'A'}, {'#', '#'}};
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

int KMP(string S1, string *DNA1)
{
  // Find the first occurrence of S1 in DNA1 using the KMP algorithm
  int n1 = DNA1[0].size(), m1 = S1.size();
  vector<int> lps1 = computeLPS(S1);
  string _S1 = complementary(S1);
  bool found1 = false, found2 = false;
  int i = 0, j = 0, r = 0, p = 0, s = 0;
  while (i < n1 || p < n1)
  {
    if (S1[j] == DNA1[0][i])
    {
      i++;
      j++;
    }
    if (S1[r] == DNA1[1][p])
    {
      p++;
      r++;
    }
    if (j == m1)
    {
      s = i - j;
      found1 = true;
      break;
    }
    else if (i < n1 && S1[j] != DNA1[0][i])
    {
      if (j != 0)
        j = lps1[j - 1];
      else
        i++;
    }
    if (r == m1)
    {
      s = p - r;
      found1 = true;
      break;
    }
    else if (p < n1 && S1[r] != DNA1[1][p])
    {
      if (r != 0)
        r = lps1[r - 1];
      else
        p++;
    }
  }
  if (found1)
    return s;
  else
    return -1;
}

bool findWithKMP(string S1, string RNA)
{
  int i = 0, j = 0, s2 = 0;
  bool found1 = false;
  int m1 = S1.size(), n1 = RNA.size();
  vector<int> lps1 = computeLPS(S1);
  while (i < n1)
  {
    if (S1[j] == RNA[i])
    {
      i++;
      j++;
    }
    if (j == m1)
    {
      s2 = i - j;
      found1 = true;
      break;
    }
    else if (i < n1 && S1[j] != RNA[i])
    {
      if (j != 0)
        j = lps1[j - 1];
      else
        i++;
    }
  }
  if (found1)
    return true;
  else
    return false;
}