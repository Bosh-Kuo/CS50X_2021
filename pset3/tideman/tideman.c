#include <cs50.h>
#include <stdio.h>
#include <string.h>

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

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int winner, int loser);

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
    for (int i = 0; i < candidate_count; i++)
    {
        // update ranks[rank] to candiate's index
        if (strcmp(candidates[i], name) == 0)
        {
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
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] ++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair_count ++;
                pairs[pair_count - 1].winner = i;
                pairs[pair_count - 1].loser = j;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pair_count ++;
                pairs[pair_count - 1].winner = j;
                pairs[pair_count - 1].loser = i;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // Bubble sort
    for (int i = 0; i < pair_count; i++)  // i-th comparison
    {
       for (int j = pair_count - 1; j > i; j--)
       {
           int winner_1 = pairs[j].winner;
           int loser_1 = pairs[j].loser;
           int winner_2 = pairs[j - 1].winner;
           int loser_2 = pairs[j - 1].loser;
           int score1 = preferences[winner_1][loser_1];
           int score2 = preferences[winner_2][loser_2];

           if (score1 > score2)
           {
               // swap: move strength one to left
               int temp_winner = pairs[j].winner;
               int temp_loser = pairs[j].loser;
               pairs[j].winner = pairs[j - 1].winner;
               pairs[j].loser = pairs[j - 1].loser;
               pairs[j - 1].winner = temp_winner;
               pairs[j - 1].loser = temp_loser;
           }
       }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!check_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winner;
    for (int column = 0; column < pair_count; column++)
    {
        int win_times = 0;
        for (int row = 0; row < pair_count; row++)
        {
            if (locked[row][column] == false)
            {
                win_times ++;
            }
        }
        if (win_times == pair_count)
        {
            winner = column;
            printf("%s\n",candidates[winner]);
            break;
        }
    }

}

// Check if edge would create a cycle
bool check_cycle(int winner, int loser)
{
    if (locked[loser][winner] == true)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner] == true)  // check if winner lose to loser in the front edges
            {
                return check_cycle(i, loser);
            }
        }
        return false;
    }
}

