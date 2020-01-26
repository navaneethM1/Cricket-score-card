/*
Assumptions
1. All bowlers bowl atleast one over
2. No extras like wides, no-balls etc
3. No crossing over between wickets
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define n 3
#define overs 5


//names of players
char* batsname[n];
char* bowsname[n];

//contains runs scored and balls faced by n batsmen
int batsmen[n][2];

//containes run conceded, number of wickets and number of balls bowled by n bowlers
int bowlers[n][3];

struct strike
{
    int id;
    struct strike* left;
    struct strike* right;
};
typedef struct strike Strike;

void create_players()
{
    printf("Enter batsmen\n");
    for(int i = 0; i < n; i++)
    {
        char s[20];
        scanf("%s", s);
        batsname[i] = (char *)malloc((strlen(s) + 1)*sizeof(char));
        strcpy(batsname[i], s);
    }
    printf("\nEnter bowlers\n");
    for(int i = 0; i < n; i++)
    {
        char s[20];
        scanf("%s", s);
        bowsname[i] = (char *)malloc((strlen(s) + 1)*sizeof(char));
        strcpy(bowsname[i], s);
    }
}

Strike* init()
{
    Strike *t1 = (Strike *)malloc(sizeof(Strike));
    t1->left = NULL;
    t1->id = 0;
    Strike *t2 = (Strike *)malloc(sizeof(Strike));
    t1->right = t2;
    t2->left = t1;
    t2->id = 1;
    t2->right = NULL;
    return t1;
}

int get_bowler_id(int over)
{
    printf("Choose bowler for over %d\n", over);
    char s[20];
    scanf("%s", s);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(bowsname[i], s) == 0)
        {
            return i;
        }
    }
}

void main()
{
    FILE *fp = fopen("score.txt","w");
    //creating batsmen and bowlers
    create_players();
    
    //opening batsmen are on strike
    Strike *strk = init();

    //id of the next batsman to come
    int next_batsman_id = 2;

    //number of wickets fallen
    int w = 0;

    //over number
    int over = 1;

    //total runs
    int tot_score = 0;
    
    //not all out
    int flag = 0;

    while(over <= overs)
    {
        //get the current bowler
        int curr_bowler_id = get_bowler_id(over);
        
        printf("Enter runs scored or -1 for wicket\n");
        
        int ball_number = 1;
        
        while(ball_number <= 6)
        {
            int score;
            scanf("%d", &score);

            if(ball_number != 6)
            {
                if(score != -1)
                {
                    if(score % 2 == 0)
                    {
                        batsmen[strk->id][0] += score;
                        batsmen[strk->id][1] += 1;
                    }
                    else
                    {
                        batsmen[strk->id][0] += score;
                        batsmen[strk->id][1] += 1;
                        if(strk->left == NULL)
                            strk = strk->right;
                        else
                            strk = strk->left;
                    }
                    tot_score += score;
                    bowlers[curr_bowler_id][0] += score;
                    bowlers[curr_bowler_id][2] += 1;
                }
                else
                {
                    w++;
                    batsmen[strk->id][1] += 1;
                    strk->id = next_batsman_id;
                    bowlers[curr_bowler_id][1] += 1;
                    bowlers[curr_bowler_id][2] += 1;
                    next_batsman_id++;
                    if(w == n - 1)
                        break;
                }
            }
            else
            {
                if(score != -1)
                {
                    if(score % 2 == 0)
                    {
                        batsmen[strk->id][0] += score;
                        batsmen[strk->id][1] += 1;
                        if(strk->left == NULL)
                            strk = strk->right;
                        else
                            strk = strk->left;
                    }
                    else
                    {
                        batsmen[strk->id][0] += score;
                        batsmen[strk->id][1] += 1;
                    }
                    tot_score += score;
                    bowlers[curr_bowler_id][0] += score;
                    bowlers[curr_bowler_id][2] += 1;
                }
                else
                {
                    w++;
                    batsmen[strk->id][1] += 1;
                    bowlers[curr_bowler_id][1] += 1;
                    bowlers[curr_bowler_id][2] += 1;
                    next_batsman_id++;
                    if(w == n - 1)
                        break;
                    strk->id = next_batsman_id;
                    if(strk->left == NULL)
                        strk = strk->right;
                    else
                        strk = strk->left;
                }
            }
            ball_number++;
        }
        if(w == n - 1)
        {
            flag = 1;
            break;
        }
        over++;
    }
    if(flag == 1)
    {
        fprintf(fp, "%d all out\n", tot_score);
    }
    else
    {
        fprintf(fp, "%d/%d\n", tot_score, w);
    }
    for(int i = 0; i < n; i++)
    {
        fprintf(fp, "%s %d %d\n", batsname[i], batsmen[i][0], batsmen[i][1]);
    }
}