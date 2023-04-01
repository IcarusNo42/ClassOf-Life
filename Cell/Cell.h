#pragma once
#include "Genome.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define SIZE 100000 + 1
extern unordered_map<char, char> complement;
extern int P[SIZE * 2];
class Cell
{
public:
    Cell(int chromosomeNumber, string filename);

    void cellDeath();

    string complementary(string s);

    vector<int> computeLPS(string pattern);

    void translocationMutation(string S1, int n, string S2, int m);

    void inversionMutation(string s1, int chrom_num);

    string convertToNewString(const string &s);

    void findComplementaryPalindromes(int m);

    void shortMutation(char o, char r, int num, int chorm_num);

protected:
    vector<pair<int, Genome>> chromosomes;
    int chromosomeNumber;
};
