#include <iostream>
#include <conio.h>
#include "classes/Genome.h"
#include "classes/Animal.h"
#include "classes/Cell.h"

using namespace std;
int main()
{
kkkk
	int choice = -1;
	int subChoice = -1;
	int n, c, cn, cn1;
	char a, b;
	string str1, str2;
	string fileName;
	while (choice != 0)
	{
		cout << "Welcome to Class of Life" << endl;
		cout << "Please choose your class:" << endl;
		cout << "1.Genome" << endl;
		cout << "2.Cell" << endl;
		cout << "3.Animal" << endl;
		cout << "0.Exit" << endl;
		cin >> choice;
		system("CLS");
		getchar();
		switch (choice)
		{
		case 1:
			while (subChoice != 0)
			{
				Genome g;
				cout << "Enter a RNA and a DNA:" << endl;
				g.recieve();
				// vorodi greftan az genome
				cout << "Choose your action:" << endl;
				cout << "1.Creating DNA from RNA" << endl;
				cout << "2.Short mutation" << endl;
				cout << "3.Translocation mutation" << endl;
				cout << "4.Reverse mutation" << endl;
				cout << "0.Back" << endl;
				cin >> subChoice;
				system("CLS");
				getchar();
				switch (subChoice)
				{
				case 1:
					g.build();
					break;
				case 2:
					cout << "First enter the nucleotide you want to delete and then enter the nucleotide you want to replace with a space: " << endl;
					cin >> a >> b;
					cout << "Now enter desired number of mutation: ";
					cin >> n;
					g.smallJump(a, b, n);
					break;
				case 3:
					cout << "First enter the sequence you want to delete and then enter the sequence you want to replace with a space:" << endl;
					cin >> str1 >> str2;
					g.bigJump(str1, str2);
					break;
				case 4:
					cout << "Enter a sequence you want to reverse: " << endl;
					cin >> str1;
					g.reversing(str1);
					break;
				case 0:
					break;
				default:
					cout << endl
						 << "Invalid choice. Please try again." << endl;
					break;
				}
			}
			subChoice = -1; // Reset subChoice for next sub-menu
			break;
		case 2:
			while (subChoice != 0)
			{
				cout << "Enter the Chromosomes number of the desired cell:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the cell is located:" << endl;
				cin >> fileName;
				Cell cell(c, fileName);
				cout << "Please choose your action:" << endl;
				cout << "1.Cell's death" << endl
					 << "2.Translocation mutation" << endl
					 << "3.Small mutation" << endl
					 << "4.inversion mutation" << endl
					 << "0.Back" << endl;
				cin >> subChoice;
				system("CLS");
				getchar();
				switch (subChoice)
				{
				case 1:
					cell.cellDeath();
					break;
				case 2:
					cout << "First, enter the number of the two chromosomes between which you want the mutation to occur with a space" << endl;
					cin >> cn >> cn2;
					cout << "Now enter the desired sequences in chromosomes " << n1 << " and " << n2 << " in order and with a space" << endl;
					cin >> str1 >> str2;
					cell.translocationMutation(str1 cn, str2, cn2);
					break;
				case 3:
					cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
					cin >> cn;
					cout << "First enter the nucleotide you want to delete and then enter the nucleotide you want to replace with a space: " << endl;
					cin >> a >> b;
					cout << "Now enter desired number of mutation: ";
					cin >> n;
					cell.shortMutation(a, b, n, cn);
					break;
				case 4:
					cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
					cin >> cn;
					cout << "Enter a sequence you want to reverse: " << endl;
					cin >> str1;
					cell.inversionMutation(str1, cn);
					break;
				case 0:
					break;
				default:
					cout << endl
						 << "Invalid choice. Please try again." << endl;
					break;
				}
			}
			subChoice = -1; // Reset subChoice for next sub-menu
			break;
		case 3:
			while (subChoice != 0)
			{
				cout << "Enter the Chromosomes number of the desired animaal:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the animal is located:" << endl;
				cin >> fileName;
				Animal animal.Cell(c, fileName);
				cout << "Please choose your action:" << endl;
				cout << "1.Percentage of Similarity" << endl
					 << "2.Similarity check" << endl
					 << "3.Asexual reproduction" << endl
					 << "4.Sexual reproduction" << endl
					 << "5.Cell's death" << endl
					 << "6.Cell's functions" << endl
					 << "7.Virus" << endl
					 << "0.Back" << endl;
				cin >> subChoice;
				system("CLS");
				getchar();
				switch (subChoice)
				{
				case 1:
					cout << "You also need another animal to use this method" << endl;
					cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
					cin >> c;
					cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
					cin >> fileName;
					Animal animal2.Cell(c, fileName);
					cout << "The percentage of genetic similarity between the two breeds is " << animal.totalSimilarity(animal2) << "%" << endl;
					break;
				case 2:
					cout << "You also need another animal to use this method" << endl;
					cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
					cin >> c;
					cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
					cin >> fileName;
					Animal animal2.Cell(c, fileName);
					if (animal == animal2)
						cout << "Both animals are of the same species " << endl;
					else
						cout << "Both animals are not of the same species " << endl;
					break;
				case 3:
					animal.asexualReproduction();
					break;
				case 4:
					cout << "You also need another animal to use this method" << endl;
					cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
					cin >> c;
					cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
					cin >> fileName;
					Animal animal2.Cell(c, fileName);
					animal.sexualReproduction(animal2);
					break;
				case 5:
					animal.removeIncorrectPairs();
					break;
				case 6:
					while (subChoice != 0)
					{
						cout << "Please choose your action:" << endl;
						cout << "1.Cell's death" << endl
							 << "2.Translocation mutation" << endl
							 << "3.Small mutation" << endl
							 << "4.inversion mutation" << endl
							 << "0.Back" << endl;
						cin >> subChoice;
						system("CLS");
						getchar();
						switch (subChoice)
						{
						case 1:
							animal.cellDeath();
							break;
						case 2:
							cout << "First, enter the number of the two chromosomes between which you want the mutation to occur with a space" << endl;
							cin >> cn >> cn2;
							cout << "Now enter the desired sequences in chromosomes " << n1 << " and " << n2 << " in order and with a space" << endl;
							cin >> str1 >> str2;
							animal.translocationMutation(str1 cn, str2, cn2);
							break;
						case 3:
							cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
							cin >> cn;
							cout << "First enter the nucleotide you want to delete and then enter the nucleotide you want to replace with a space: " << endl;
							cin >> a >> b;
							cout << "Now enter desired number of mutation: ";
							cin >> n;
							animal.shortMutation(a, b, n, cn);
							break;
						case 4:
							cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
							cin >> cn;
							cout << "Enter a sequence you want to reverse: " << endl;
							cin >> str1;
							animal.inversionMutation(str1, cn);
							break;
						case 0:
							break;
						default:
							cout << endl
								 << "Invalid choice. Please try again." << endl;
							break;
						}
					}
					subChoice = -1; // Reset subChoice for next sub-menu
					break;

				case 7:
					cout << "Enter Virus' RNA:" << endl;
					// vorodi
					break;
				case 0:
					break;
				default:
					cout << endl
						 << "Invalid choice. Please try again." << endl;
					break;
				}
			}
			subChoice = -1; // Reset subChoice for next sub-menu
			break;
		case 0:
			break;
		default:
			cout << endl
				 << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}
