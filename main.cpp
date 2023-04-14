#include <iostream>
#include <conio.h>
#include "classes/Genome.h"
#include "classes/Animal.h"
#include "classes/Cell.h"
using namespace std;
class dataBase
{
public:
	vector<Genome> genomes;
	vector<Cell> cells;
	vector<Animal> animals;
	vector<Virus> viruses;
	void addGenome(string first, string second, string RNA)
	{
		Genome g(first, second, RNA);
		genomes.push_back(g);
	}
	void addCell(int c, string fileName)
	{
		Cell cell(c, fileName);
		cells.push_back(cell);
	}
	void addAnimal(int c, string fileName)
	{
		Animal animal(c, fileName);
		animals.push_back(animal);
	}
	void addVirus(string RNA)
	{
		Virus virus(RNA);
		viruses.push_back(virus);
	}
};
void genomeMenu(dataBase dataBase);
void cellMenu(dataBase dataBase, int n);
void animalMenu(dataBase dataBase);
void saveGenome(Animal animal);
void display(Animal animal);
int main()
{
	system("CLS");
	int choice = -1;
	int c;
	string fileName, first, second, RNA;
	dataBase dataBase;
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
			cout << "Enter a RNA :" << endl;
			cin >> RNA;
			cout << "Enter a first string of DNA:" << endl;
			cin >> first;
			cout << "Enter a second string of DNA :" << endl;
			cin >> second;
			dataBase.addGenome(first, second, RNA);
			genomeMenu(dataBase);
			break;
		case 2:
			cout << "Enter the Chromosomes number of the desired cell:" << endl;
			cin >> c;
			cout << "Enter the name of the file in which the genetic content of the cell is located:" << endl;
			cin >> fileName;
			dataBase.addCell(c, fileName);
			cellMenu(dataBase, 1);

			break;
		case 3:

			cout << "Enter the Chromosomes number of the desired animaal:" << endl;
			cin >> c;
			cout << "Enter the name of the file in which the genetic content of the animal is located:" << endl;
			cin >> fileName;
			dataBase.addAnimal(c, fileName);
			animalMenu(dataBase);
			break;
		case 0:
			break;
		default:
			cout << endl
				 << "Invalid choice. Please try again." << endl
				 << endl;
			break;
		}
	}
}
void genomeMenu(dataBase dataBase)
{
	int n, c, cn, cn2;
	char a, b;
	string str1, str2, fileName;
	int subChoice = -1;
	Genome g = dataBase.genomes[dataBase.genomes.size() - 1];
	while (subChoice != 0)
	{
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
			g.shortMutation(a, b, n);
			break;
		case 3:
			cout << "First enter the sequence you want to delete and then enter the sequence you want to replace with a space:" << endl;
			cin >> str1 >> str2;
			g.translocationMutation(str1, str2);
			break;
		case 4:
			cout << "Enter a sequence you want to reverse: " << endl;
			cin >> str1;
			g.inversionMutation(str1);
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
void cellMenu(dataBase dataBase, int s)
{
	int n, c, cn, cn2;
	char a, b;
	string str1, str2, fileName;
	int subChoice = -1;
	Cell *cell;
	if (s)
		cell = &dataBase.cells[dataBase.cells.size() - 1];
	else
		cell = &dataBase.animals[dataBase.animals.size() - 1];
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
			cell->cellDeath();
			break;
		case 2:
			cout << "First, enter the number of the two chromosomes between which you want the mutation to occur with a space" << endl;
			cin >> cn >> cn2;
			cout << "Now enter the desired sequences in chromosomes " << cn << " and " << cn2 << " in order and with a space" << endl;
			cin >> str1 >> str2;
			cell->translocationMutation(str1, cn, str2, cn2);
			break;
		case 3:
			cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
			cin >> cn;
			cout << "First enter the nucleotide you want to delete and then enter the nucleotide you want to replace with a space: " << endl;
			cin >> a >> b;
			cout << "Now enter desired number of mutation: ";
			cin >> n;
			cell->shortMutation(a, b, n, cn);
			break;
		case 4:
			cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
			cin >> cn;
			cout << "Enter a sequence you want to reverse: " << endl;
			cin >> str1;
			cell->inversionMutation(str1, cn);
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
void animalMenu(dataBase dataBase)
{
	int n, c, cn, cn2;
	int subChoice = -1;
	string fileName, RNA;
	Animal *nAnimal;
	// Animal* animal = &dataBase.animals[dataBase.animals.size() - 1];
	while (subChoice != 0)
	{
		cout << "Please choose your action:" << endl;
		cout << "1.Percentage of Similarity" << endl
			 << "2.Similarity check" << endl
			 << "3.Asexual reproduction" << endl
			 << "4.Sexual reproduction" << endl
			 << "5.Cell's death" << endl
			 << "6.Cell's functions" << endl
			 << "7.Detecting the harmfulness of the virus" << endl
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
			dataBase.addAnimal(c, fileName);
			// Animal* animal2 = &dataBase.animals[dataBase.animals.size() - 1];
			cout << "The percentage of genetic similarity between the two breeds is " << dataBase.animals[dataBase.animals.size() - 2].totalSimilarity(dataBase.animals[dataBase.animals.size() - 1]) << "%" << endl;
			break;
		case 2:
			cout << "You also need another animal to use this method" << endl;
			cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
			cin >> c;
			cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
			cin >> fileName;
			dataBase.addAnimal(c, fileName);
			// Animal* animal2 = &dataBase.animals[dataBase.animals.size() - 1];
			if (dataBase.animals[dataBase.animals.size() - 1] == dataBase.animals[dataBase.animals.size() - 2])
				cout << "Both animals are of the same species " << endl;
			else
				cout << "Both animals are not of the same species " << endl;
			break;
		case 3:
			nAnimal = dataBase.animals[dataBase.animals.size() - 2].asexualReproduction();

			if (nAnimal != NULL)
			{
				saveGenome(*nAnimal);
				display(*nAnimal);
			}

			break;
		case 4:
			cout << "You also need another animal to use this method" << endl;
			cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
			cin >> c;
			cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
			cin >> fileName;
			dataBase.addAnimal(c, fileName);
			nAnimal = dataBase.animals[dataBase.animals.size() - 2] + dataBase.animals[dataBase.animals.size() - 1];
			// Animal dataBase.animals[dataBase.animals.size() - 2] = dataBase.animals[dataBase.animals.size() - 1];
			if (nAnimal != NULL)
			{
				saveGenome(*nAnimal);
				display(*nAnimal);
			}

			break;
		case 5:
			dataBase.animals[dataBase.animals.size() - 2].removeIncorrectPairs();
			break;
		case 6:
			cellMenu(dataBase, 0);
			break;
		case 7:
			cout << "Enter the RNA of the desired virus:" << endl;
			cin >> RNA;
			dataBase.addVirus(RNA);
			if (dataBase.viruses[dataBase.viruses.size() - 1].virusCheck(dataBase.animals[dataBase.animals.size() - 1]))
				cout << "The virus is harmfull for animal!!!!" << endl;
			else
				cout << "The viris is harmless for animal!!!!" << endl;
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
void display(Animal animal)
{

	cout << "Do you want the genome to be displayed here?y/N (Not recommended)" << endl;

	char answer;

	answer = getch();

	if (answer == 'y' || answer == 'Y')
	{

		for (auto &chrom : animal.chromosomes)
		{
			// receive the three parts of the line from user
			string part1, part2, part3;

			// create a string with the three parts separated by spaces
			string line = to_string(chrom.first) + " " + chrom.second.getDNA()[0] + " " + chrom.second.getDNA()[1];

			// write the line to the file
			cout << line << endl;
		}
	}
}
void saveGenome(Animal animal)
{
	ofstream myfile("child.txt");

	// write n lines
	for (auto &chrom : animal.chromosomes)
	{
		// receive the three parts of the line from user
		string part1, part2, part3;

		// create a string with the three parts separated by spaces
		string line = to_string(chrom.first) + " " + chrom.second.getDNA()[0] + " " + chrom.second.getDNA()[1];

		// write the line to the file
		myfile << line << endl;
	}

	// close the file
	myfile.close();

	cout << "The genome of your new animal has been saved in the <child.txt> file." << endl;
}
