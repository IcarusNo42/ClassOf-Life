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
    Animal();
    Animal(int chromosomeNumber, string filename);

    double calculateGeneticSimilarityPercent(string seq1, string seq2);

    double calculateSimilarity(string *chr1, string *chr2);

    double totalSimilarity(Animal chr_list2);

    bool operator==(const Animal &sec);

    vector<int> generateRandom(int m);

    Animal* asexualReproduction();

    Animal* operator+( Animal sec);

    void removeIncorrectPairs();

    friend class Virus;
    friend void display(Animal animal);
    friend void saveGenome(Animal animal);
};
class Virus : public Genome{
	public:
	Virus(string RNA);

	//Finding the lcm
	string lcs(vector<pair<int, Genome>> str);

	bool virusCheck(Animal a);
};
     




