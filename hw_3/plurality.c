#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner();

int main(int argc, string argv[])
{
    // sanity check
    if (argc < 2)
    {
        printf("Candidates must more than two.");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Too many candidates.");
        return 2;
    }
    for (int i = 1; i < candidate_count; i++)
    {
        for (int j = i+1; j < argc; j++)
        {
            if (!(strcmp(argv[i], argv[j])))
            {
                printf("Candidate repeated!");
                return 0;
            }
        }
    }

    //create array for candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int total_voters;
    do
    {
        total_voters = get_int("Number of voters: ");
    } while (isdigit(total_voters));

    // loop over all the voters
    for (int i = 0; i < total_voters; i++)
    {
        string name = get_string("Vote: ");
        if (!(vote(name)))
        {
            printf("Invalid vote.\n");
        }
    }
    print_winner();
    return 0;
}


bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++){
        if (strcmp(name, candidates[i].name) == 0){
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}


void print_winner(){
    // find the max vote.
    int max = 0;
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes > max){
            max = candidates[i].votes;
        }
    }

    // print the results
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes == max){
            printf("%s\n", candidates[i].name);
        }
    }
}