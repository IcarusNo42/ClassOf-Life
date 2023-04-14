#include "Genome.h"
using namespace std;
Genome::Genome(string first, string second, string RNA) : RNA(RNA)
{
	DNA[0] = first;
	DNA[1] = second;
}
Genome::Genome(string first, string second)
{
	DNA[0] = first;
	DNA[1] = second;
}
Genome::Genome(string RNA) : RNA(RNA) {}
Genome::Genome() {}
string *Genome::getDNA()
{
	return DNA;
}
// Create a new DNA from RNA
void Genome::build()
{
	inputDNA[0] = RNA;
	inputDNA[1] = "";

	for (int i = 0; i < RNA.length(); i++)
	{
		inputDNA[1]+= complement[RNA[i]];
	}

cout << "Do you want the genome to be displayed here?y/N (Not recommended)" << endl;

	char answer;

	answer = getch();

	if (answer == 'y' || answer == 'Y')
	{
		cout<<"DNA"<<endl
			<<inputDNA[0]<<" "<<inputDNA[1]<<endl;
	}
}
// This method replaces a specific number of nucleotides with another nucleotide
void Genome::shortMutation(char a, char b, int n)
{
	int check = 0;
	for (int i = 0; i < RNA.length(); i++)
	{
		if (check == n)
			break;
		if (RNA[i] == a)
		{
			RNA[i] = b;
			check++;
		}
	}
	check = 0;
	char mokamel = complement[b];
	for (int i = 0; i < DNA[0].length(); i++)
	{
		if (check == n)
			break;
		if (DNA[0][i] == a)
		{
			DNA[0][i] = b;
			DNA[1][i] = mokamel;
			check++;
		}

		else if (DNA[1][i] == a)
		{
			DNA[1][i] = b;
			DNA[0][i] = mokamel;
			check++;
		}
	}
}
// This method replace a nucleotide sequence with another one
void Genome::translocationMutation(string S1, string S2)
{
	// Find the first occurrence of S1 in DNA using the KMP algorithm
	int n1 = DNA[0].size(), m1 = S1.size();
	vector<int> lps1 = computeLPS(S1);
	string _S1 = complementary(S1), _S2 = complementary(S2);
	bool found1 = false, found2 = false;
	int i = 0, j = 0, r = 0, p = 0, s = 0;
	while (i < n1 || p < n1)
	{
		if (S1[j] == DNA[0][i])
		{
			i++;
			j++;
		}
		if (S1[r] == DNA[1][p])
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
		else if (i < n1 && S1[j] != DNA[0][i])
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
		else if (p < n1 && S1[r] != DNA[1][p])
		{
			if (r != 0)
				r = lps1[r - 1];
			else
				p++;
		}
	}
	i = 0;
	j = 0;
	int n2 = RNA.size(), m2 = S2.size();
	vector<int> lps2 = computeLPS(S1);
	while (i < n2)
	{
		if (S1[j] == RNA[i])
		{
			i++;
			j++;
		}
		if (j == m2)
		{
			j = i - j;
			found2 = true;
			break;
		}
		else if (i < n2 && S1[j] != RNA[i])
		{
			if (j != 0)
				j = lps2[j - 1];
			else
				i++;
		}
	}
	if (found1)
	{
		if (DNA[0].substr(s, m1) == S1)
		{
			DNA[0].replace(s, m1, S2);
			DNA[1].replace(s, m1, _S2);
		}
		else
		{
			DNA[0].replace(s, m1, _S2);
			DNA[1].replace(s, m1, S2);
		}
		cout << "The desired operation was completed on DNAsuccessfully" << endl;
	}
	else
		cout << "The desired nucleotide sequence was not found in the chromosome, translocation mutation is not possible !!!" << '\n';
	if (found2)
	{
		RNA.replace(s, m1, S2);

		cout << "The desired operation was completed on RNA successfully " << endl;
	}
	else
		cout << "The desired nucleotide sequence was not found in the RNA, translocation mutation is not possible !!!" << '\n';
}
// This method inversion a nucleotide sequence in DNA
void Genome::inversionMutation(string s1)
{
	int i = 0, j = 0, r = 0, p = 0, s = 0;
	string S2 = s1;
	reverse(S2.begin(), S2.end());
	int n1 = DNA[0].size(), m1 = s1.size();
	string _S2 = complementary(S2);
	vector<int> lps1 = computeLPS(s1);
	bool found = false, found2 = false;
	;
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
	i = 0;
	j = 0;
	int n2 = RNA.size();
	while (i < n2)
	{
		if (s1[j] == RNA[i])
		{
			i++;
			j++;
		}
		if (j == m1)
		{
			s = i - j;
			DNA[0].replace(s, m1, S2);
			found2 = true;
			break;
		}
		else if (i < n2 && s1[j] != RNA[i])
		{
			if (j != 0)
				j = lps1[j - 1];
			else
				i++;
		}
	}
	if (!found)
		cout << "It is not possible to carry out inversion mutation in the desired DNA" << endl;
	else
		cout << "The desired operation was completed on DNA successfully" << endl;
	if (!found2)
		cout << "It is not possible to carry out inversion mutation in the desired RNA" << endl;
	else
		cout << "The desired operation was completed on RNA successfully" << endl;
}
