#include "Cell.h"

int P[SIZE * 2];

// Map of complementary nucleotides
unordered_map<char, char> complement = {{'A', 'T'}, {'C', 'G'}, {'G', 'C'}, {'T', 'A'}};

Cell::Cell() {}

Cell::Cell(int chromosomeNumber, string filename)
{
  chromosomes.reserve(chromosomeNumber);
  this->chromosomeNumber = chromosomeNumber;
  // Read chromosome data from file
  ifstream file(filename);
  int index = 0;
  if (file.is_open())
  {
    string DNA1, DNA2;
    int chromosome_number;
    while (file >> chromosome_number >> DNA1 >> DNA2)
    {
      Genome chromosome(DNA1, DNA2);
      chromosomes.push_back(make_pair(chromosome_number, chromosome));
      index++;
    }
  }
  else
  {
    cout << "!!Error opening file: " << filename << endl;
    return;
  }
  file.close();
}
// Method to remove cells with incorrect base pairs
void Cell::cellDeath()
{
  int pos = 0;
  for (auto &chrom : chromosomes)
  {
    int incorrect_pairs = 0;
    auto &DNA = chrom.second.DNA;
    // Loop over each DNA strand in the chromosome
    int len = DNA[0].size();
    int mismatches = 0;
    int Tpair = 0, Cpair = 0;
    bool found = false;
    // Check for incorrect base pairs
    for (int i = 0; i < len; ++i)
    {
      char base1 = DNA[1][i];
      char base2 = DNA[0][i];
      if (base1 != complement[base2])
      {
        ++mismatches;
        // Remove chromosome if more than 5 incorrect pairs were found
        if (mismatches > 5)
        {
          cout << "Chromosome number " << chrom.first << " was destroyed due to having more than 5 incorrect base pairs !!!" << '\n';
          chromosomes.erase(chromosomes.begin() + pos); // remove the chromosome
          found = true;
          break;
        }
      }
      if (mismatches <= 5)
        pos++;
      if (base1 == 'T' || base1 == 'A')
        Tpair++;
      else
        Cpair++;
    }
    if (found || Tpair > Cpair * 3)
    {
      delete this;
      cout << "So you will lose your cell and it will die" << endl;
      break;
    }
  }
}
// Method to find the complementary sequence of a given DNA sequence
string Cell::complementary(string s)
{
  for (auto &i : s)
  {
    i = complement[i];
  }
  return s;
}
// Method to compute the Longest Proper Prefix which is also a Suffix (LPS) of a given pattern string
vector<int> Cell::computeLPS(string pattern)
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
// This method moves two nucleotide sequences between two chromosomes
void Cell::translocationMutation(string S1, int n, string S2, int m)
{
  auto &DNA1 = chromosomes[n - 1].second.DNA;
  auto &DNA2 = chromosomes[m - 1].second.DNA;
  // Find the first occurrence of S1 in DNA1 using the KMP algorithm
  int n1 = DNA1[0].size(), m1 = S1.size();
  vector<int> lps1 = computeLPS(S1);
  string _S1 = complementary(S1), _S2 = complementary(S2);
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
  i = 0;
  j = 0;
  r = 0;
  p = 0;
  int n2 = DNA2[0].size(), m2 = S2.size();
  vector<int> lps2 = computeLPS(S2);
  while (i < n2 || p < n2)
  {
    if (S2[j] == DNA2[0][i])
    {
      i++;
      j++;
    }
    if (S2[j] == DNA2[1][i])
    {
      p++;
      r++;
    }
    if (j == m2)
    {
      j = i - j;
      found2 = true;
      break;
    }
    else if (i < n2 && S2[j] != DNA2[0][i])
    {
      if (j != 0)
        j = lps2[j - 1];
      else
        i++;
    }
    if (r == m2)
    {
      j = p - r;
      found2 = true;
      break;
    }
    else if (p < n2 && S2[r] != DNA2[1][p])
    {
      if (r != 0)
        r = lps2[r - 1];
      else
        p++;
    }
  }
  // Perform translocation mutation if both S1 and S2 were found in their respective chromosomes
  if (found1 && found2)
  {
    if (DNA1[0].substr(s, m1) == S1)
    {
      DNA1[0].replace(s, m1, S2);
      DNA1[1].replace(s, m1, _S2);
    }
    else
    {
      DNA1[0].replace(s, m1, _S2);
      DNA1[1].replace(s, m1, S2);
    }
    if (DNA2[0].substr(j, m2) == S2)
    {
      DNA2[0].replace(j, m2, S1);
      DNA2[1].replace(j, m2, _S1);
    }
    else
    {
      DNA2[0].replace(j, m2, _S1);
      DNA2[1].replace(j, m2, S1);
    }
    cout << "The desired operation was completed successfully" << endl;
  }
  else
    cout << "The desired nucleotide sequence was not found in the chromosome, translocation mutation is not possible !!!" << '\n';
}
// This method inversion a nucleotide sequence in DNA
void Cell::inversionMutation(string s1, int chrom_num)
{
  int i = 0, j = 0, r = 0, p = 0, s = 0;
  string S2 = s1;
  auto &DNA = chromosomes[chrom_num - 1].second.DNA;
  reverse(S2.begin(), S2.end());
  int n1 = DNA[0].size(), m1 = s1.size();
  string _S2 = complementary(S2);
  vector<int> lps1 = computeLPS(s1);
  bool found = false;
  while (i < n1 || p < n1)
  {
    if (s1[j] == DNA[0][i])
    {
      i++;
      j++;
    }
    if (s1[r] == DNA[1][p])
    {
      p++;
      r++;
    }
    if (j == m1)
    {
      s = i - j;
      DNA[0].replace(s, m1, S2);
      DNA[1].replace(s, m1, _S2);
      found = true;
      break;
    }
    else if (i < n1 && s1[j] != DNA[0][i])
    {
      if (j != 0)
        j = lps1[j - 1];
      else
        i++;
    }
    if (r == m1)
    {
      s = p - r;
      DNA[0].replace(s, m1, _S2);
      DNA[1].replace(s, m1, S2);
      found = true;
      break;
    }
    else if (p < n1 && s1[r] != DNA[1][p])
    {
      if (r != 0)
        r = lps1[r - 1];
      else
        p++;
    }
  }
  if (!found)
    cout << "It is not possible to carry out inversion mutation in the desired chromosome" << endl;
  else
    cout << "The desired operation was completed successfully" << endl;
}
string Cell::convertToNewString(const string &s)
{
  string newString = "@";

  for (int i = 0; i < s.size(); i++)
  {
    newString += "#" + s.substr(i, 1);
  }

  newString += "#$";
  return newString;
}
// This method find allthe complementary palindromes nucleotide sequence in DNA
void Cell::findComplementaryPalindromes(int m)
{
  string chromosome = chromosomes[m - 1].second.DNA[0];
  string Q = convertToNewString(chromosome);
  int c = 0, r = 0; // current center, right limit

  for (int i = 1; i < Q.size() - 1; i++)
  {
    // find the corresponding letter in the palidrome subString
    int iMirror = c - (i - c);

    if (r > i)
    {
      P[i] = min(r - i, P[iMirror]);
    }

    // expanding around center i
    string s1 = "", s2 = "";
    while (Q[i + 1 + P[i]] == complement[Q[i - 1 - P[i]]])
    {
      if (Q[i + 1 + P[i]] != '#')
      {
        s1 = Q[i + 1 + P[i]] + s1 + Q[i - 1 - P[i]];
        if (s1.size() >= 4 && s1.size() % 2 == 0)
          cout << s1 << endl;
      }
      P[i]++;
    }

    // Update c,r in case if the palindrome centered at i expands past r,
    if (i + P[i] > r)
    {
      c = i; // next center = i
      r = i + P[i];
    }
  }
}
// This method replaces a specific number of nucleotides with another nucleotide
void Cell::shortMutation(char o, char r, int num, int chorm_num)
{
  auto &DNA = chromosomes[chorm_num - 1].second.DNA;
  if (count(DNA[0].begin(), DNA[0].end(), o) + count(DNA[1].begin(), DNA[1].end(), o) >= num)
  {
    bool finished = false;
    int count = 0;
    for (int j = 0; j < 2; j++)
    {
      if (!finished)
      {
        for (int i = 0; i < DNA[0].length(); i++)
        {
          if (DNA[j][i] == o)
          {
            DNA[j][i] = r;
            DNA[1 - j][i] = complement[r];
            count++;
            if (count == num)
            {
              finished = true;
              cout << "The desired operation was completed successfully" << endl;
              break;
            }
          }
        }
      }
    }
  }
  else
    cout << "The target chromosome does not have a sufficient number of nucleotide " << o << " to cause a small mutation" << endl;
}
