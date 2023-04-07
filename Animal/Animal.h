#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>
#include "Genome.h"
#include "Cell.h"
class Animal : public Cell
{
public:
    double calculateSimilarity(string seq1, string seq2);

    double calculateSimilarity(string *chr1, string *chr2);

    Cell merging(Cell a);

    double totalSimilarity(Cell chr_list1, Cell chr_list2);

    bool operator==(const Animal &sec);

    vector<int> generateRandom(int m);

    Animal asexualReproduction(Animal animal);

    Animal operator+(const Animal &sec);

    void removeIncorrectPairs();

    friend class Virus;
};
class Virus{
	public:
	int n;
	string RNA;
	Virus();

	//Finding the lcm
	string lcs(vector<pair<int, Genome>> str);

	bool virusCheck(string r);
};
     




