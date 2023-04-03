#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int main(){
	cout<<"Welcome to Class of Life"<<endl;
	start:
	cout<<"Please choose your class:"<<endl;
	cout<<"1.Genome"<<endl<<"2.Cell"<<endl<<"3.Animal"<<endl;
	int n;
	cin>>n;
	system("CLS");
	getchar();
	switch(n){
		case 1:
			Genome g
			cout<<"Enter a RNA and a DNA:"<<endl;
			g.recieve();
			//vorodi greftan az genome
			cout<<"Choose your action:"<<endl;
			cout<<"1.Creating DNA from RNA"<<endl;
			cout<<"2.Small jump"<<endl<<"3.Big jump"<<endl<<"4.Reverse jump"<<endl<<"5.Back"<<endl;
			int genome;
			cin>>genome;
			system("CLS");
			getchar();
			switch(genome){
				case 1:
					g.build();
					break;
				case 2:
					cout<<"Enter 2 char and an int: "<<endl;
					char a,b;
					int n;
					cin>>a>>b>>n;
					g.smallJump(a,b,n);
					break;
				case 3:
					cout<<"Enter 2 strings:"<<endl;
					string str1,str2;
					cin>>str1>>str2;
					g.bigJump(str1,str2);
					break;
				case 4:
					cout<<"Enter a string:"<<endl;
					string str;
					cin>>str;
					g.reversing(str);
					break;
				case 5:
					goto start;
					break;
				
			}
			break;
		case 2:
			cout<<"Enter the number of Chromosomes:"<<endl;
			int c;
			cin>>c;
			cout<<"Enter File Name:"<<endl;
			//vorodi
			cellgoto:
			cout<<"Please choose your action:"<<endl;
			cout<<"1.Cell's death"<<endl<<"2.Big jump"<<endl<<"3.Small jump"<<endl<<"4.Reverse jump"<<endl<<"5.Back"<<endl;
			int cell;
			cin>>cell;
			system("CLS");
			getchar();
			switch(cell){
				case 1:
					
					break;
				case 2:
					
					break;
				case 3:
					
					break;
				case 4:
					
					break;
				case 5:
					goto start;
					break;
			}
			break;
		case 3:
			cout<<"Please enter a file: "<<endl;
			//vorodi 
			cout<<"Please choose your action:"<<endl;
			cout<<"1.Percentage of Similarity"<<endl<<"2.Similarity check"<<endl<<"3.Asexual reproduction"<<endl<<"4.Sexual reproduction"<<endl<<"5.Cell's death"<<endl<<"6.Cell's functions"<<endl<<"7.Virus"<<endl<<"8.Back"<<endl;
			int animal;
			cin>>animal;
			system("CLS");
			getchar();
			switch(animal){
				case 1:
					cout<<"Please enter another file: "<<endl;
					break;
				case 2:
					cout<<"Please enter another file: "<<endl;
					break;
				case 3:
					
					break;
				case 4:
					cout<<"Please enter another file: "<<endl;
					break;
				case 5:
	
					break;
				case 6:
					goto cellgoto;
					break;
				case 7:
					cout<<"Enter Virus' RNA:"<<endl;
					//vorodi
					break;
				case 8:
					goto start;
					break;
			}
			break;
		
			
			
			
			
			
	}
}
