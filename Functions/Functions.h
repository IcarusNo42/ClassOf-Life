#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
extern unordered_map<char, char> complement;
// Method to find the complementary sequence of a given DNA sequence
string complementary(string s);

vector<int> computeLPS(string pattern);
//KMP algorithm for find first occurrence
int KMP(string S1,string* DNA1);
//KMP algorithm for find first occurrence
bool findWithKMP(string S1,string RNA);