#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count = 0;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    //Look up the name in the list of candidates
    //If found in the list of candidates, ranks[j] should contain i where candidates[i] == name

    for(i = 0; i < candidate_count; i++){
        if(strcmp(name, candidates[i]) == 0){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    //for every j in i (nested loop) preferences[i][j] is incremented by 1
    //For all candidates found at a greater index(j) in ranks array than the current one(i)
    //preferences[i][j] must be incremented by one
    //because i by definition has better rank (lower index in ranks array) than j
    for (int i = 0; i < candidate_count-1; i++) {
        for( int j = i + 1; j < candidate_count; j++){
            preferences[i][j] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    //loop over the 2D array that is preferences and
    //if the entry in the array is different from zero,
    //candidate i and j should be inserted into the pairs array
    //where i is the index of the winner and j is the index of the loser

    // int pairsIndex = 0;
    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; i < candidate_count; j++){
            if(preferences[i][j] != 0 && preferences[i][j] > preferences[j][i]){
                pairs[pair_count].winner = i;
                parirs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int preferenceValue[pair_count];
    pairs temp;
    for(int i = 0; i < pair_count; i++){
        preferenceValue[i] = preferences[pairs[i].winner][pairs[i].loser];
    }
    for(int i = 0; i < pair_count ; i++){
        for( int j = 0; j < pair_count - 1; j++){
            if(preferenceValue[j] < preferenceValue[j+1]){
                temp.winner = pairs[j + 1].winner;
                temp.loser = pairs[j + 1].loser;
                
                pairs[j + 1].winner = pairs[j].winner;
                pairs[j + 1].loser = pairs[j].loser;

            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}