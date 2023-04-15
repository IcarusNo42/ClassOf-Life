#include "Animal.h"

Animal::Animal() : Cell(){};
Animal::Animal(int chromosomeNumber, string filename) : Cell(chromosomeNumber, filename) {}
// The percentage of similarity between two animals
double Animal::calculateGeneticSimilarityPercent(string seq1, string seq2)
{
    int n = seq1.length();
    int m = seq2.length();

    // Create a matrix to store the Levenshtein distances
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        dist[i][0] = i;
    }

    for (int j = 1; j <= m; j++)
    {
        dist[0][j] = j;
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;

            dist[i][j] = min(dist[i - 1][j] + 1, min(dist[i][j - 1] + 1, dist[i - 1][j - 1] + cost));
        }
    }

    // The Levenshtein distance is in the bottom-right corner of the matrix
    int levenshteinDist = dist[n][m];

    // Calculate the genetic similarity percentage
    double similarityPercent = 100.0 - ((double)levenshteinDist / (double)max(n, m)) * 100.0;

    return similarityPercent;
}
double Animal::calculateSimilarity(string *chr1, string *chr2)
{

    // Calculate similarity between strand 1 of chromosome 1 and strand 1 of chromosome 2
    double sim1 = calculateGeneticSimilarityPercent(chr1[0], chr2[0]);
    // Calculate similarity between strand 2 of chromosome 1 and strand 1 of chromosome 2
    double sim2 = calculateGeneticSimilarityPercent(chr1[1], chr2[1]);

    // Take the average of the two similarity scores as the final similarity score for the chromosome pair
    double avg_sim1 = (sim1 + sim2) / 2.0;

    // Calculate similarity between strand 1 of chromosome 1 and strand 2 of chromosome 2
    double sima1 = calculateGeneticSimilarityPercent(chr1[0], chr2[1]);
    // Calculate similarity between strand 2 of chromosome 1 and strand 1 of chromosome 2
    double sima2 = calculateGeneticSimilarityPercent(chr2[0], chr1[1]);

    // Take the average of the two similarity scores as the final similarity score for the chromosome pair
    double avg_sim2 = (sima1 + sima2) / 2.0;
    return max(avg_sim1, avg_sim2);
}
double Animal::totalSimilarity(Animal chr_list2)
{
    double total_sim = 0.0, total_sim2 = 0.0;
    int num_comparisons = 0, num_comparisons2 = 0;
    auto &case1 = chromosomes;
    auto &case2 = chr_list2.chromosomes;
    // Compare each chromosome in list 1 to each chromosome in list 2
    for (auto chr1 : case1)
    {
        double chr_sim = 0;
        for (auto chr2 : case2)
        {
            // Calculate similarity between the two chromosomes
            double temp = calculateSimilarity(chr1.second.getDNA(), chr2.second.getDNA());
            chr_sim < temp ? chr_sim = temp : chr_sim = chr_sim;
        }
        // Add similarity score to running total
        total_sim += chr_sim;
        num_comparisons++;
    }
    // Compare each chromosome in list 2 to each chromosome in list 1
    for (auto chr2 : case1)
    {
        double chr_sim = 0;
        for (auto chr1 : case1)
        {
            // Calculate similarity between the two chromosomes
            double temp = calculateSimilarity(chr2.second.getDNA(), chr1.second.getDNA());
            chr_sim < temp ? chr_sim = temp : chr_sim = chr_sim;
        }
        // Add similarity score to running total
        total_sim2 += chr_sim;
        num_comparisons2++;
    }

    // Calculate average similarity score for the entire set of chromosomes
    double avg_sim = total_sim / num_comparisons;
    double avg_sim2 = total_sim2 / num_comparisons2;

    return (avg_sim + avg_sim2) / 2;
}

bool Animal::operator==(const Animal &sec)
{
    return (totalSimilarity(sec) >= 70 && chromosomeNumber == sec.chromosomeNumber);
}
vector<int> Animal::generateRandom(int m)
{
    int n = floor(0.7 * m);
    // Create a vector to store the unique random numbers
    vector<int> result;

    // Create a random device and generator to generate random numbers
    random_device rd;
    mt19937 gen(rd());

    // Create a vector containing the numbers 1 to m
    vector<int> numbers(m);
    iota(numbers.begin(), numbers.end(), 1);
    numbers.insert(numbers.end(), numbers.begin(), numbers.end());
    // Shuffle the vector of numbers
    shuffle(numbers.begin(), numbers.end(), gen);

    // Add the first n shuffled numbers to the vector of unique numbers
    int pos = 0;
    for (int i = 0; result.size() < n; i++)
    {
        if (count(result.begin(), result.end(), numbers[i]) == 0)
        {
            result.push_back(numbers[i]);
            numbers.erase(numbers.begin() + pos);
        }
        else
            pos++;
    }
    shuffle(numbers.begin(), numbers.end(), gen);
    for (int i = 0; i < m - n; i++)
        result.push_back(numbers[i]);

    return result;
}
// method to asexualReproduction
Animal *Animal::asexualReproduction()
{
    Animal *nn = new Animal;
    vector<int> basic = generateRandom(chromosomeNumber);
    Genome chrm;
    for (int i = 0; i < basic.size(); i++)
    {
        chrm = chromosomes[basic[i] - 1].second;
        nn->chromosomes.push_back(make_pair(i + 1, chrm));
    }
    nn->chromosomeNumber = chromosomeNumber;
    return nn;
}
// method to sexualReproduction
Animal *Animal::operator+(Animal sec)
{
    Animal *p1 = asexualReproduction();
    Animal *p2 = sec.asexualReproduction();
    Animal *child;
    if (p1 == p2 && chromosomeNumber % 2 == 0)
    {
        while (!(child == p1 && child == p2))
        {
            vector<int> basic1 = generateRandom(chromosomeNumber), basic2 = generateRandom(sec.chromosomeNumber);
            for (int i = 0; i < basic1.size(); i++)
            {
                child->chromosomes.push_back(make_pair(i + 1, chromosomes[basic1[i] - 1].second));
                child->chromosomes.push_back(make_pair(i + 1, sec.chromosomes[basic2[i] - 1].second));
            }
            child->chromosomeNumber = chromosomeNumber;
        }
        return child;
    }
    else if (sec.chromosomeNumber % 2 != 0 || chromosomeNumber % 2 != 0)
        cout << "The chromosomal number of two organisms is not sufficient for sexual reproduction!!!!" << endl;
    else
        cout << "Two organisms are not of the same species, so they cannot have sexual reproduction!!!" << endl;
    return NULL;
}
// Remove incorrect chromosomes
void Animal::removeIncorrectPairs()
{
    int pos = 0;
    for (auto &chrom : chromosomes)
    {
        int incorrect_pairs = 0;
        string *DNA = chrom.second.getDNA();
        // Loop over each DNA strand in the chromosome
        int len = DNA[0].size();
        int mismatches = 0;
        int Tpair = 0, Cpair = 0;
        bool found = false;
        // Check for incorrect base pairs
        for (int i = 0; i < len; ++i)
        {
            char base1 = DNA[1][i];
            char base2 = DNA[0][i];
            if (base1 != complement[base2])
            {
                ++mismatches;
                // Remove chromosome if more than 5 incorrect pairs were found
                if (mismatches > 5)
                {
                    cout << "Chromosome number " << chrom.first << " was destroyed due to having more than 5 incorrect base pairs !!!" << '\n';
                    chromosomes.erase(chromosomes.begin() + pos); // remove the chromosome
                    found = true;
                    break;
                }
            }
            if (base1 == 'T' || base1 == 'A')
                Tpair++;
            else
                Cpair++;
        }
        if (Tpair > Cpair * 3 && !found)
        {
            cout << "Chromosome number " << chrom.first << " was destroyed due to having more than 5 incorrect base pairs !!!" << '\n';
            chromosomes.erase(chromosomes.begin() + pos); // remove the chromosome
            found = true;
        }
        if (!found)
            pos++;
    }
}

Virus::Virus(string RNA) : Genome(RNA) {}
// Finding the lcm
string Virus::lcs(vector<pair<int, Genome>> str)
{
    string res1 = "";
    string res2 = "";

    for (int i = 0; i < str[0].second.getDNA()[0].length(); i++)
    {
        for (int j = str[0].second.getDNA()[0].length() - i; j > -1; j--)
        {

            if (j > res1.length())
            {
                for (int x = 1; x < str.size(); x++)
                {
                    if (!(findWithKMP(str[0].second.getDNA()[0].substr(i, j), str[x].second.getDNA()[0])) && (!findWithKMP(str[0].second.getDNA()[0].substr(i, j), str[x].second.getDNA()[1])))
                    {
                        break;
                    }

                    if (x == str.size() - 1)
                        res1 = str[0].second.getDNA()[0].substr(i, j);
                }
            }
        }
    }
    for (int i = 0; i < str[0].second.getDNA()[1].length(); i++)
    {
        for (int j = str[0].second.getDNA()[1].length() - i; j > -1; j--)
        {

            if (j > res2.length())
            {
                for (int x = 1; x < str.size(); x++)
                {
                    if (!(findWithKMP(str[0].second.getDNA()[1].substr(i, j), str[x].second.getDNA()[0])) && !(findWithKMP(str[0].second.getDNA()[1].substr(i, j), str[x].second.getDNA()[1])))
                    {
                        break;
                    }

                    if (x == str.size() - 1)
                        res2 = str[0].second.getDNA()[1].substr(i, j);
                }
            }
        }
    }
    if (res1.length() >= res2.length())
        return res1;
    else
        return res2;
}
// method to check if the virus is safe or not
bool Virus::virusCheck(Animal a)
{
    string r = lcs(a.chromosomes);
    string s = "";
    for (int i = 0; i < r.length(); i++)
        s += complement[r[i]];
    if (findWithKMP(r, RNA))
        return true;
    else if (findWithKMP(s, RNA))
        return true;
    else
        return false;
}
