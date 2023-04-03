#include <bits/stdc++.h>
using namespace std;
class Virus{
	public:
	int n;
	string RNA;
	Virus(){
		cin>>RNA;
	}

	//Finding the lcm
	string lcs(vector<pair<int, Genome>> str){
 	string res="";

		for (int i=0 ; i<str[0].second.inputDNA[0].length(); i++){
			for (int j=str[0].second.inputDNA[0].length()-i; j>-1; j--){
				cout<<str[0].second.inputDNA[0].substr(i,j)<<endl;
				if (j>res.length()){
					for (int x=1; x<str.size(); x++){
						if (str[x].second.inputDNA[0].find(str[0].second.inputDNA[0].substr(i,j)) == std::string::npos && str[x].second.inputDNA[1].find(str[0].second.inputDNA[0].substr(i,j)) == std::string::npos ){
							break;
						}
						
						if (x==1)
							res=str[0].second.inputDNA[0].substr(i,j);
					}
				}
			}
		}
		return res;

	   
	}
	bool virusCheck(string r){
		if (RNA.find(r)!=std::string::npos){
			return true;
		}
		map<char, char> complement = {{'A', 'T'}, {'C', 'G'}, {'G', 'C'}, {'T', 'A'}};
		for (int i=0 ; i<r.length();i++){
			cout<<complement[r.[i]];
		}
		else if(RNA.find(r)!=std::string::npos){
			return true;
		}
		else{
			return false;
		}
	}
 
   
};
     




