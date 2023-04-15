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
	int animalChoice()
	{
		int x = animals.size(), n, l;
		cout << "You currently have " << x << " animals in the database" << endl
			 << "Do you want to insert a new animal?y/N" << endl;
		char answer;

		answer = getch();

		if (answer == 'y' || answer == 'Y')
			l = 0;
		else
		{
			cout << "Do you want to see genome content before inserting ?" << endl;

			answer = getch();

			if (answer == 'y' || answer == 'Y')
			{
				while (true)
				{
					cout << "So enter the number of animals in the database that you want see(enter -1 to skip)" << endl;
					cin >> n;
					system("CLS");
					if (n == -1)
						break;
					if (n < 1 || n > animals.size())
					{
						while (n < 1 || n > animals.size())
						{
							cout << "The input number is out of range. Try again" << endl;
							cin >> n;
						}
					}
					display(animals[n - 1]);
				}
			}
			cout << "So enter the number of animals in the database that you want use" << endl;
			cin >> n;
			if (n < 1 || n > animals.size())
			{
				while (n < 1 || n > animals.size())
				{
					cout << "The input number is out of range. Try again" << endl;
					cin >> n;
				}
			}
			l = n;
		}
		return l;
	}
	int genomeChoice()
	{
		int x = genomes.size(), n, l;
		cout << "You currently have " << x << " genomes in the database" << endl
			 << "Do you want to insert a new Genome?y/N" << endl;
		char answer;

		answer = getch();

		if (answer == 'y' || answer == 'Y')
			l = 0;
		else
		{
			cout << "Do you want to see genome content before inserting ?" << endl;

			answer = getch();

			if (answer == 'y' || answer == 'Y')
			{
				while (true)
				{
					cout << "So enter the number of animals in the database that you want see(enter -1 to skip)" << endl;
					cin >> n;
					system("CLS");
					if (n == -1)
						break;
					if (n < 1 || n > genomes.size())
					{
						while (n < 1 || n > genomes.size())
						{
							cout << "The input number is out of range. Try again" << endl;
							cin >> n;
						}
					}
					display2(genomes[n - 1]);
				}
			}
			cout << "So enter the number of genomes in the database that you want use" << endl;
			cin >> n;
			if (n < 1 || n > genomes.size())
			{
				while (n < 1 || n > genomes.size())
				{
					cout << "The input number is out of range. Try again" << endl;
					cin >> n;
				}
			}
			l = n;
		}
		return l;
	}
	int cellChoice()
	{
		int x = cells.size(), n, l;
		cout << "You currently have " << x << " cells in the database" << endl
			 << "Do you want to insert a new cell?y/N" << endl;
		char answer;

		answer = getch();

		if (answer == 'y' || answer == 'Y')
			l = 0;
		else
		{
			cout << "Do you want to see genome content before inserting ?" << endl;

			answer = getch();

			if (answer == 'y' || answer == 'Y')
			{
				while (true)
				{
					cout << "So enter the number of animals in the database that you want see(enter -1 to skip)" << endl;
					cin >> n;
					system("CLS");
					if (n == -1)
						break;
					if (n < 1 || n > cells.size())
					{
						while (n < 1 || n > cells.size())
						{
							cout << "The input number is out of range. Try again" << endl;
							cin >> n;
						}
					}
					display(cells[n - 1]);
				}
			}
			cout << "So enter the number of cells in the database that you want use" << endl;
			cin >> n;
			if (n < 1 || n > cells.size())
			{
				while (n < 1 || n > cells.size())
				{
					cout << "The input number is out of range. Try again" << endl;
					cin >> n;
				}
			}
			l = n;
		}
		return l;
	}
	int virusChoice()
	{
		int x = viruses.size(), n, l;
		cout << "You currently have " << x << " viruses in the database" << endl
			 << "Do you want to insert a new virus?y/N" << endl;
		char answer;

		answer = getch();

		if (answer == 'y' || answer == 'Y')
			l = 0;
		else
		{
			cout << "So enter the number of viruses in the database that you want use" << endl;
			cin >> n;
			if (n < 1 || n > viruses.size())
			{
				while (n < 1 || n > viruses.size())
				{
					cout << "The input number is out of range. Try again" << endl;
					cin >> n;
				}
			}
			l = n;
		}
		return l;
	}
};
void genomeMenu(dataBase &dataBase, int x);
void cellMenu(dataBase &dataBase, int n, int x);
void animalMenu(dataBase &dataBase, int x);
void saveGenome(Animal animal, string filename);
void display(Cell animal);
void display2(Genome genome);
int main()
{
	system("CLS");
	int choice = -1;
	int c, x, l, n;
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
			l = 0;
			x = dataBase.genomes.size();
			if (x)
			{
				l = dataBase.genomeChoice();
			}
			if (!l)
			{
				cout << "Enter a RNA :" << endl;
				cin >> RNA;
				cout << "Enter a first string of DNA:" << endl;
				cin >> first;
				cout << "Enter a second string of DNA :" << endl;
				cin >> second;
				dataBase.addGenome(first, second, RNA);
				l = dataBase.genomes.size();
			}
			genomeMenu(dataBase, l - 1);
			break;
		case 2:
			l = 0;
			x = dataBase.cells.size();
			if (x)
			{
				l = dataBase.cellChoice();
			}
			if (!l)
			{
				cout << "Enter the Chromosomes number of the desired cell:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the cell is located:" << endl;
				cin >> fileName;
				dataBase.addCell(c, fileName);
				l = dataBase.cells.size();
			}
			cellMenu(dataBase, 1, l - 1);
			break;
		case 3:
			l = 0;
			x = dataBase.animals.size();
			if (x)
			{
				l = dataBase.animalChoice();
			}
			if (!l)
			{
				cout << "Enter the Chromosomes number of the desired animaal:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the animal is located:" << endl;
				cin >> fileName;
				dataBase.addAnimal(c, fileName);
				l = dataBase.animals.size();
			}
			animalMenu(dataBase, l - 1);

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
void genomeMenu(dataBase &dataBase, int x)
{
	int n, c, cn, cn2;
	char a, b;
	string str1, str2, fileName;
	int subChoice = -1;
	Genome *g = &dataBase.genomes[x];
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
			g->build();
			break;
		case 2:
			cout << "First enter the nucleotide you want to delete and then enter the nucleotide you want to replace with a space: " << endl;
			cin >> a >> b;
			cout << "Now enter desired number of mutation: ";
			cin >> n;
			g->shortMutation(a, b, n);
			display2(*g);
			break;
		case 3:
			cout << "First enter the sequence you want to delete and then enter the sequence you want to replace with a space:" << endl;
			cin >> str1 >> str2;
			g->translocationMutation(str1, str2);
			display2(*g);
			break;
		case 4:
			cout << "Enter a sequence you want to reverse: " << endl;
			cin >> str1;
			g->inversionMutation(str1);
			display2(*g);
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
void cellMenu(dataBase &dataBase, int s, int x)
{
	int n, c, cn, cn2, cnt;
	char a, b;
	string str1, str2, fileName;
	int subChoice = -1;
	Cell *cell = new Cell;
	if (s)
		cell = &dataBase.cells[x];
	else
		cell = &dataBase.animals[x];
	while (subChoice != 0)
	{

		cout << "Please choose your action:" << endl;
		cout << "1.Cell's death" << endl
			 << "2.Translocation mutation" << endl
			 << "3.Small mutation" << endl
			 << "4.inversion mutation" << endl
			 << "5.findComplementaryPalindromes" << endl
			 << "0.Back" << endl;
		cin >> subChoice;
		system("CLS");
		getchar();
		switch (subChoice)
		{
		case 1:
			cell->cellDeath(dataBase.cells, x);
			subChoice = 0;
			break;
		case 2:
			cout << "First, enter the number of the two chromosomes between which you want the mutation to occur with a space" << endl;
			cin >> cn >> cn2;
			cout << "Now enter the desired sequences in chromosomes " << cn << " and " << cn2 << " in order and with a space" << endl;
			cin >> str1 >> str2;
			cell->translocationMutation(str1, cn, str2, cn2);
			display(*cell);
			break;
		case 3:
			cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
			cin >> cn;
			cout << "First enter the nucleotide you want to delete and then enter the nucleotide you want to replace with a space: " << endl;
			cin >> a >> b;
			cout << "Now enter desired number of mutation: ";
			cin >> n;
			cell->shortMutation(a, b, n, cn);
			display(*cell);
			break;
		case 4:
			cout << "First, enter the chromosome number in which you want make a mutation: " << endl;
			cin >> cn;
			cout << "Enter a sequence you want to reverse: " << endl;
			cin >> str1;
			cell->inversionMutation(str1, cn);
			display(*cell);
			break;
		case 5:
			cout << "Enter the number od desired chromosome: " << endl;
			cin >> cn;
			cell->findComplementaryPalindromes(cn);
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
void animalMenu(dataBase &dataBase, int x)
{
	int n, c, cn, cn2, y, Q;
	int subChoice = -1;
	string fileName, RNA;
	Animal *nAnimal;
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
			y = 0;
			Q = dataBase.animals.size();
			if (Q)
			{
				y = dataBase.animalChoice();
			}
			if (!y)
			{
				cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
				cin >> fileName;
				dataBase.addAnimal(c, fileName);
				y = dataBase.animals.size();
			}
			cout << "The percentage of genetic similarity between the two breeds is " << dataBase.animals[x].totalSimilarity(dataBase.animals[y - 1]) << "%" << endl;
			break;
		case 2:
			cout << "You also need another animal to use this method" << endl;
			y = 0;
			Q = dataBase.animals.size();
			if (Q)
			{
				y = dataBase.animalChoice();
			}
			if (!y)
			{
				cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
				cin >> fileName;
				dataBase.addAnimal(c, fileName);
				y = dataBase.animals.size();
			}
			if (dataBase.animals[x] == dataBase.animals[y - 1])
				cout << "Both animals are of the same species " << endl;
			else
				cout << "Both animals are not of the same species " << endl;
			break;
		case 3:

			nAnimal = dataBase.animals[x].asexualReproduction();
			if (nAnimal != NULL)
			{
				cout << "Do you want to save the new animal?y/N" << endl;
				char answer;

				answer = getch();

				if (answer == 'y' || answer == 'Y')
				{
					cout << "What is the name of your new file??" << endl;
					cin >> fileName;
					saveGenome(*nAnimal, fileName);
				}
				display(*nAnimal);
			}

			break;
		case 4:
			cout << "You also need another animal to use this method" << endl;
			y = 0;
			Q = dataBase.animals.size();
			if (Q)
			{
				y = dataBase.animalChoice();
			}
			if (!y)
			{
				cout << "Enter the Chromosomes number of the desired another animaal:" << endl;
				cin >> c;
				cout << "Enter the name of the file in which the genetic content of the another animal is located:" << endl;
				cin >> fileName;
				dataBase.addAnimal(c, fileName);
				y = dataBase.animals.size();
			}
			nAnimal = dataBase.animals[x] + dataBase.animals[y - 1];
			if (nAnimal != NULL)
			{
				cout << "Do you want to save the new animal?y/N" << endl;
				char answer;

				answer = getch();

				if (answer == 'y' || answer == 'Y')
				{
					cout << "What is the name of your new file??" << endl;
					cin >> fileName;
					saveGenome(*nAnimal, fileName);
				}
				display(*nAnimal);
			}

			break;
		case 5:
			dataBase.animals[x].removeIncorrectPairs();
			break;
		case 6:
			cellMenu(dataBase, 0, x);
			break;
		case 7:
			y = 0;
			Q = dataBase.viruses.size();
			if (Q)
			{
				y = dataBase.animalChoice();
			}
			if (!y)
			{
				cout << "Enter the RNA of the desired virus:" << endl;
				cin >> RNA;
				dataBase.addVirus(RNA);
				y = dataBase.viruses.size();
			}
			if (dataBase.viruses[y - 1].virusCheck(dataBase.animals[x]))
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
void display(Cell animal)
{

	cout << "Do you want the genome to be displayed here?y/N (Not recommended)" << endl;

	char answer;

	answer = getch();

	if (answer == 'y' || answer == 'Y')
	{
		string line;
		for (auto &chrom : animal.chromosomes)
		{
			// create a string with the three parts separated by spaces
			line = to_string(chrom.first) + " " + chrom.second.getDNA()[0] + " " + chrom.second.getDNA()[1];

			// write the line to the file
			cout << line << endl;
		}
	}
}
void display2(Genome genome)
{
	cout << "Do you want the genome to be displayed here?y/N (Not recommended)" << endl;

	char answer;

	answer = getch();

	if (answer == 'y' || answer == 'Y')
	{
		cout << "DNA" << endl
			 << genome.DNA[0] << " " << genome.DNA[1] << endl
			 << "RNA" << endl
			 << genome.RNA << endl;
	}
}
void saveGenome(Animal animal, string filename)
{
	system("CLS");
	ofstream myfile(filename);

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

	cout << "The genome of your new animal has been saved in the <" << filename << "> file." << endl;
}
