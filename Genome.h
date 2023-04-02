#pragma once
#include <bits/stdc++.h>

using namespace std;
class Genome{
	private:
		string inputDNA[2],DNA[2],RNA;
	public:
	void recieve();
	// tabe bara sakht mokamel
	char help(char& a);
	// tabe sakht DNA
	void build();
	// tabe baraye jahesh koochak
	void smallJump(char a,char b, int n);
	// tabe jahesh bozorg
	void bigJump(string s1,string s2);
	// tabe baraye jahesh makoos
	void reversing(string s);
};
