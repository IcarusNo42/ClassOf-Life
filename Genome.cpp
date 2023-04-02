#include "Genome.h"
	void Genome::recieve(){
		cin>>RNA;
		cin>>inputDNA[0]>>inputDNA[1];
	}
	// tabe bara sakht mokamel
	char Genome::help(char& a){
		if (a=='A')
			return 'T';
		else if (a=='T')
			return 'A';
		else if (a=='C')
			return 'G';
		else if (a=='G')
			return 'C';
	}
	// tabe sakht DNA
	void Genome::build(){
		DNA[0]=RNA;
		for (int i=0 ; i<RNA.length(); i++){
			
			if (RNA[i]=='A')
				DNA[1][i]='T';
			else if (RNA[i]=='T')
				DNA[1][i]='A';
			else if (RNA[i]=='C')
				DNA[1][i]='G';
			else if (RNA[i]=='G')
				DNA[1][i]='C';
		}
		for (int i=0 ; i<RNA.length(); i++){
			cout<<DNA[1][i];
		}
		cout<<endl;
	}
	// tabe baraye jahesh koochak
	void Genome::smallJump(char a,char b, int n){
		int check=0;
		for (int i=0 ; i<RNA.length();i++){
			if (check==n)
				break;
			if (RNA[i]==a){
				RNA[i]=b;
				check++;
			}
		}
		check=0;
		char mokamel=help(b);
		for (int i=0 ; i<inputDNA[0].length(); i++){
			if (check==n)
				break;
			if (inputDNA[0][i]==a){
				inputDNA[0][i]=b;
				inputDNA[1][i]=mokamel;
				check++;
			}
			if (check==n)
				break;
			if (inputDNA[1][i]==a){
				inputDNA[1][i]=b;
				inputDNA[0][i]=mokamel;
				check++;
			}
		}
		
	}
	
	// tabe jahesh bozorg
	void Genome::bigJump(string s1,string s2){
		auto loc = RNA.find(s1);
		for (int i=0 ; i<s1.length(); i++){
			RNA[i+loc]=s2[i];
		}
		auto loc2 = inputDNA[0].find(s1);
		auto loc3=inputDNA[1].find(s1);
		if ( loc2>=loc3 )
		{
		    for (int i=0 ; i<s1.length(); i++){
				inputDNA[0][i+loc2]=s2[i];
			}
			for (int i=0 ; i<s1.length(); i++){
				inputDNA[1][i+loc2]=help(s2[i]);
			}
		}
		else
		{
		   for (int i=0 ; i<s1.length(); i++){
				inputDNA[1][i+loc3]=s2[i];
			}
			for (int i=0 ; i<s1.length(); i++){
				inputDNA[0][i+loc3]=help(s2[i]);
			}
		}
	}
	// tabe baraye jahesh makoos
	void Genome::reversing(string s){
		auto loc = RNA.find(s);
		if ( loc != string::npos )
		{
		   reverse(RNA.begin() + loc, RNA.begin() + loc +s.length());
		}
		auto loc2 = inputDNA[0].find(s);
		auto loc3=inputDNA[1].find(s);
		if ( loc2>=loc3 )
		{
		   reverse(inputDNA[0].begin() + loc2, inputDNA[0].begin() + loc2 +s.length());
		   reverse(inputDNA[1].begin() + loc2, inputDNA[1].begin() + loc2 +s.length());
		}
		else
		{
		   reverse(inputDNA[0].begin() + loc3, inputDNA[0].begin() + loc3 +s.length());
		   reverse(inputDNA[1].begin() + loc3, inputDNA[1].begin() + loc3 +s.length());
		}
	}

