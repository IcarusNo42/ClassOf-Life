#pragma once
#include "Function.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <conio.h>
using namespace std;
class Genome{
	protected:
		string inputDNA[2],DNA[2],RNA;
	public:
	Genome(string first, string second,string RNA);
	Genome(string first, string second);
	Genome(string RNA);
	Genome();
	string* getDNA();

	void build();
	
	void shortMutation(char a,char b, int n);
	
	void translocationMutation(string s1,string s2);

	void inversionMutation(string s);

	 friend class Cell;
     friend void display2(Genome genome);
};
