#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Fixtures
{
    char team1[50];
    char team2[50];
    char location[50];
}Fixtures;

void conv_json(Fixtures *fixture, int f_count)
{
    printf("\n\n******JSON FORMAT*******\n\n");
    int i;
    for(i=0; i<f_count; i++)
    {
        printf("{\n\"team1\":\"%s\",\n\"team2\":\"%s\",\n\"location\":\"%s\"\n},\n", fixture[i].team1, fixture[i].team2, fixture[i].location);
    }
}


void enter_teams(char setA[][50], char setB[][50], int n)
{
    printf("Enter team names for set A: \n");
    for(int i=0; i<n/2; i++)
        scanf("%s", setA[i]);
    

    printf("Enter team names for set B: \n");
    for(int i=0; i <n/2; i++)
        scanf("%s", setB[i]);
    printf("\n\n");
}


void print_fixtures(char setA[][50], char setB[][50], int n)
{
    int total_matches = 0;
    int i, j;
    int f_count = 0;
    int flag[n/2];
    Fixtures fixtures[100];
    
    printf("Team 1\tV/S\tTeam 2\tHome/Away/Either\n");

    //within set A

    //init flag variable
    for(i=0; i<n/2; i++)
    {
        flag[i] = 0;
    }


    for(i=0; i<n/2; i++)
    {
        for(j=0; j<n/2; j++)
        {
            if(i == j)
                continue;
            else if(flag[i] == 0)
            {
                if(flag[j] == 1)
                    continue;
                else
                {
                    printf("%s\tV/S\t%s\t(Home)\n%s\tV/S\t%s\t(Away)\n", setA[i], setA[j], setA[i], setA[j]);
                    strcpy(fixtures[f_count].team1, setA[i]);
                    strcpy(fixtures[f_count].team2, setA[j]);
                    strcpy(fixtures[f_count++].location, "Home");

                    strcpy(fixtures[f_count].team1, setA[i]);
                    strcpy(fixtures[f_count].team2, setA[j]);
                    strcpy(fixtures[f_count++].location, "Away");

                    total_matches = total_matches + 2;
                }
                
            }
        }
        flag[i] = 1;
    }

    //within set B

    //init flag variable
    for(i=0; i<n/2; i++)
    {
        flag[i] = 0;
    }


    for(i=0; i<n/2; i++)
    {
        for(j=0; j<n/2; j++)
        {
            if(i == j)
                continue;
            else if(flag[i] == 0)
            {
                if(flag[j] == 1)
                    continue;
                else
                {
                    printf("%s\tV/S\t%s\t(Home)\n%s\tV/S\t%s\t(Away)\n", setB[i], setB[j], setB[i], setB[j]);
                    strcpy(fixtures[f_count].team1, setB[i]);
                    strcpy(fixtures[f_count].team2, setB[j]);
                    strcpy(fixtures[f_count++].location, "Home");

                    strcpy(fixtures[f_count].team1, setB[i]);
                    strcpy(fixtures[f_count].team2, setB[j]);
                    strcpy(fixtures[f_count++].location, "Away");

                    total_matches = total_matches + 2;
                }
                
            }
        }
        flag[i] = 1;
    }

    //with other set
    for(i=0; i<n/2; i++)
    {
        for(j=0; j<n/2; j++)
        {
            if(i == j)
            {
                printf("%s\tV/S\t%s\t(Home)\n%s\tV/S\t%s\t(Away)\n", setA[i], setB[j], setA[i], setB[j]);
                strcpy(fixtures[f_count].team1, setA[i]);
                strcpy(fixtures[f_count].team2, setB[j]);
                strcpy(fixtures[f_count++].location, "Home");

                strcpy(fixtures[f_count].team1, setA[i]);
                strcpy(fixtures[f_count].team2, setB[j]);
                strcpy(fixtures[f_count++].location, "Away");

                total_matches = total_matches + 2;
            }
            else
            {
                printf("%s\tV/S\t%s\t(Either)\n", setA[i], setB[j]);
                strcpy(fixtures[f_count].team1, setA[i]);
                strcpy(fixtures[f_count].team2, setB[j]);
                strcpy(fixtures[f_count++].location, "Either");

                total_matches++;
            }
                
        }
    }

    printf("\n");
    for(i=0; i<4; i++)
    {
        printf("TBD\tV/S\tTBD\t(Playoffs)\n");
        total_matches++;
    }
    printf("\n\nTotal number of matches: %d\n\n", total_matches);

    /*
    printf("Iterating thru fixtures struct: \n");
    for(i=0; i<f_count; i++)
    {
        printf("%s\tVERSUS\t%s\tAT\t%s\n", fixtures[i].team1, fixtures[i].team2, fixtures[i].location);
    }
    */

   conv_json(fixtures, f_count);

}

int main()
{
    int n;
    Fixtures fixtures[100];

    printf("Enter number of teams (even number): ");
    scanf("%d", &n);

    if(n % 2 != 0) {
        printf("Enter an even number of teams.\n");
        return 1;
    }

    char setA[n/2][50];
    char setB[n/2][50];

    enter_teams(setA, setB, n);
    print_fixtures(setA, setB, n);

    return 0;
}
