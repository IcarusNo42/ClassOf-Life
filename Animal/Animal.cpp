#include "Animal.h"

double Animal::calculateSimilarity(string seq1, string seq2);
{
    int n = seq1.length();
    int m = seq2.length();
    int match_score = 1;
    int mismatch_score = -1;
    int gap_penalty = -2;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Initialize first row and column with gap penalties
    for (int i = 0; i <= n; i++)
        dp[i][0] = i * gap_penalty;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j * gap_penalty;

    // Fill in the dynamic programming matrix using the scoring scheme
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int match = dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? match_score : mismatch_score);
            int gap1 = dp[i - 1][j] + gap_penalty;
            int gap2 = dp[i][j - 1] + gap_penalty;
            dp[i][j] = max({match, gap1, gap2});
        }
    }

    // Trace back the optimal alignment to calculate similarity percentage
    int i = n;
    int j = m;
    int matched = 0;
    int total = 0;
    while (i > 0 && j > 0)
    {
        if (seq1[i - 1] == seq2[j - 1])
            matched++;
        total++;
        if (dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? match_score : mismatch_score) == dp[i][j])
        {
            i--;
            j--;
        }
        else if (dp[i - 1][j] + gap_penalty == dp[i][j])
            i--;
        else
            j--;
    }

    // Return the percentage of genetic similarity
    return (double)matched / total * 100.0;
}
double Animal::calculateSimilarity(string *chr1, string *chr2)
{

    // Calculate similarity between strand 1 of chromosome 1 and strand 1 of chromosome 2
    double sim1 = calculateSimilarity(chr1[0], chr2[0]);
    // Calculate similarity between strand 2 of chromosome 1 and strand 1 of chromosome 2
    double sim2 = calculateSimilarity(chr1[1], chr2[1]);

    // Take the average of the two similarity scores as the final similarity score for the chromosome pair
    double avg_sim1 = (sim1 + sim2) / 2.0;

    // Calculate similarity between strand 1 of chromosome 1 and strand 2 of chromosome 2
    double sima1 = calculateSimilarity(chr1[0], chr2[1]);
    // Calculate similarity between strand 2 of chromosome 1 and strand 1 of chromosome 2
    double sima2 = calculateSimilarity(chr2[0], chr1[1]);

    // Take the average of the two similarity scores as the final similarity score for the chromosome pair
    double avg_sim2 = (sima1 + sima2) / 2.0;
    return max(avg_sim1, avg_sim2);
}
Cell Animal::merging(Cell a)
{
    vector<int> id;
    vector<pair<int, genome>> result = a.chromosomes;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = i + 1; j < result.size(); j++)
        {
            if (result[j].second == result[i].second)
                id.push_back(result[j].first);
        }
    }
    int pos = 0;
    for (auto chr : result)
    {
        if (count(id.begin(), id.end(), chr.first) != 0)
            result.erase(result.begin() + pos); // remove the chromosome
        else
            pos++;
    }
    return result;
}
double Animal::totalSimilarity(Cell chr_list1, Cell chr_list2)
{
    double total_sim = 0.0;
    int num_comparisons = 0;
    auto &case1 = merging(chr_list1);
    auto &case2 = merging(chr_list2);
    if (case2.size() > case1.size())
    {
        auto &case3 = case1;
        case2 = case1;
        case1 = case3;
    }
    // Compare each chromosome in list 1 to each chromosome in list 2
    for (auto chr1 : case1)
    {
        double chr_sim = 0;
        for (auto chr2 : case2)
        {
            // Calculate similarity between the two chromosomes
            double temp = calculateSimilarity(chr1.second, chr2.second);
            chr_sim < temp ? chr_sim = temp : chr_sim = chr_sim;
        }
        // Add similarity score to running total
        total_sim += chr_sim;
        num_comparisons++;
    }

    // Calculate average similarity score for the entire set of chromosomes
    double avg_sim = total_sim / num_comparisons;

    return avg_sim;
}
bool Animal::operator==(const Animal &sec)
{
    return (totalSimilarity(chromosomes, sec.chromosomes) >= 70 && chromosomeNumber == sec.chromosomeNumber);
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

Animal Animal::asexualReproduction(Animal animal)
{
    Animal new;
    vector<int> basic = generateRandom(animal.chromosomeNumber);
    for (int i = 0; i < basic.size(); i++)
        new.chromosomes.push_back(i + 1, animal.chromosomes[basic[i] - 1].second);
    new.chromosomeNumber = animal.chromosomeNumber;
    return new;
}

Animal Animal::operator+(const Animal &sec)
{

    Animal p1 = asexualReproduction(animal1), p2 = asexualReproduction(sec), child;
    if (p1 == p2 && chromosomeNumber % 2 == 0)
    {
        while (child != p1 || child != p2)
        {
            vector<int> basic1 = generateRandom(*this), basic2 = generateRandom(sec.chromosomeNumber);
            for (int i = 0; i < basic1.size(); i++)
            {
                child.chromosomes.push_back(i + 1, chromosomes[basic1[i] - 1].second);
                child.chromosomes.push_back(i + 1, sec.chromosomes[basic2[i] - 1].second);
            }
            child.chromosomeNumber = chromosomeNumber;
        }
        return child;
    }
    else if (p1 == p2 && chromosomeNumber % 2 != 0)
        cout << "The chromosomal number of two organisms is not sufficient for sexual reproduction!!!!" << endl;
    else
        cout << "Two organisms are not of the same species, so they cannot have sexual reproduction!!!" << endl;
}
void Animal::removeIncorrectPairs()
{
    int pos = 0;
    for (auto &chrom : chromosomes)
    {
        int incorrect_pairs = 0;
        auto &DNA = chrom.second.DNA;
        // Loop over each DNA strand in the chromosome
        int len = DNA[0].size();
        int mismatches = 0;

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
                    break;
                }
            }
            if (mismatches <= 5)
                pos++;
        }
    }
}
