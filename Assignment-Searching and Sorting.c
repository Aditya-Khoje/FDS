#include <stdio.h>
#include <string.h>

// structure to save cricketers information
struct Cricketer_Details
{
    char name[50];
    int age;
    char country[15];
    char category[15];
    int odi_played;
    int twenty_twenty_played;
    float avg_batting_score;
    int total_wickets;
} c[35];

int main()
{
    // function declearation
    void display_particular_player(struct Cricketer_Details c[35], int n, char cricket_name[50]);
    void printData(struct Cricketer_Details c[35], int n);
    void getdata(struct Cricketer_Details c[35], int n);
    void putdata(struct Cricketer_Details c[35], int n);
    void linearSearch(struct Cricketer_Details c[35], int n, char intput_country[20], char Player_Category[20]);
    void bubble_Sort(struct Cricketer_Details c[35], int n, int temp);
    int binarySearch(struct Cricketer_Details c[35], int n, float high_average_score);

    int choice, n, temp;
    char intput_country[20];
    char cricket_name[50];

    do
    {
        printf("\n************************** MENU *****************************\n");

        printf("\n1: Input players details :- ");
        printf("\n2: All players details :- ");
        printf("\n3: Batsman of particular country : ");
        printf("\n4: Bowler of particular country : ");
        printf("\n5: Sorted list of batsman according average batting score :- ");
        printf("\n6: Batsman with highest average score :- ");
        printf("\n7: The bowler that has taken a maximum no of wickets :- ");
        printf("\n8: Details of particular player :- ");
        printf("\n9: exit :- ");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        printf("\n***************************************************************\n");

        switch (choice)
        {
        case 1:
            printf("\nHow many cricketers data do you want to take : ");
            scanf("%d", &n);
            getdata(c, n);
            break;
        case 2:
            putdata(c, n);
            break;
        case 3:
            printf("\nWhich country's batsman details do you want : ");
            scanf("%s", intput_country);
            printf("\nBatsmans from %s are :- \n", intput_country);
            linearSearch(c, n, intput_country, "batsman");
            break;
        case 4:
            printf("\nWhich country's bowlers details do you want : ");
            scanf("%s", intput_country);
            printf("\nBowlers from %s are :- \n", intput_country);
            linearSearch(c, n, intput_country, "bowler");
            break;
        case 5:
            bubble_Sort(c, n, 0);
            printf("\nSorted list of batsman in descending order according to their average batting score :- ");
            printData(c, n);

            break;
        case 6:
            bubble_Sort(c, n, 0);
            temp = binarySearch(c, n, c[0].avg_batting_score);
            printf("\nBatsman with highest average score : %s\n", c[0].name);
            printf("\nAverage score : %0.2f\n", c[0].avg_batting_score);
            printf("\nSorted list of batsman according to average score : \n");
            putdata(c, n);
            break;

        case 7:
            bubble_Sort(c, n, 1);
            printf("\nBowler with highest wickets : %s\n", c[0].name);
            printf("\nWickets taken : %d\n", c[0].total_wickets);
            printf("\nSorted list of bowlers in descending order according to their wickets :- ");
            putdata(c, n);
            break;

        case 8:
            printf("\nEnter particular name of player to display his information : ");
            scanf("%s", cricket_name);
            display_particular_player(c, n, cricket_name);
            break;

        case 9:
            printf("\n\nTHANK YOU :) \n\n");
            break;

        default:
            printf("\nEnter correct choice\n");
            break;
        }

    } while (choice != 9);

    return 0;
}

void printData(struct Cricketer_Details c[35], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d) %s", i + 1, c[i].name);
    }
}

void getdata(struct Cricketer_Details c[35], int n) //function to get input data
{
    printf("\n\n****************** GETDATA **************************\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of cricketer no. %d :-", i + 1);

        printf("\nName : ");
        scanf("%s", c[i].name);
        printf("Age : ");
        scanf("%d", &c[i].age);
        printf("Country : ");
        scanf("%s", c[i].country);
        printf("Category (batsman/bowler/wicket-keeper/all-rounder) : ");
        scanf("%s", c[i].category);
        printf("No. of ODI played : ");
        scanf("%d", &c[i].odi_played);
        printf("No. of 20-20 played : ");
        scanf("%d", &c[i].twenty_twenty_played);
        printf("Average Score : ");
        scanf("%f", &c[i].avg_batting_score);
        printf("Total no. of wickets taken : ");
        scanf("%d", &c[i].total_wickets);

        printf("\n");
    }

    printf("\n\n");
}

// function to show data in record format
void putdata(struct Cricketer_Details c[35], int n) //function to print all data
{
    printf("\n\n");

    printf("No.\t|Name\t|Age\t|Country\t|Category\t|ODI\t|20-20\t|Avg Score\t|Wickets taken\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d)\t|%s\t|%d\t|       %s\t|       %s\t|%d\t|%d\t|      %0.2f\t|%d\n", i + 1, c[i].name, c[i].age, c[i].country, c[i].category, c[i].odi_played, c[i].twenty_twenty_played, c[i].avg_batting_score, c[i].total_wickets);
    }
    printf("\n\n");
}

// linear search to search batsmans and bowlers of perticular country
void linearSearch(struct Cricketer_Details c[35], int n, char intput_country[20], char Player_Category[20])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(c[i].country, intput_country) == 0 && strcmp(c[i].category, Player_Category) == 0)
        {
            count++;
            printf("\n%d) Cricketer Name = %s ", count, c[i].name);
        }
    }
    printf("\n\nNo. of %s of %s are :- %d", Player_Category, intput_country, count);
    printf("\n\n");
}

// bubble sort to sort the data
// if temp argument pass as 1 then it sort by total wickets
// if temp argument pass as 0 then it sort by average score
void bubble_Sort(struct Cricketer_Details c[35], int n, int temp)
{

    struct Cricketer_Details t;
    if (temp == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (c[j].avg_batting_score < c[j + 1].avg_batting_score)
                {
                    t = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = t;
                }
            }
        }
    }
    else
    {
        struct Cricketer_Details t;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (c[j].total_wickets < c[j + 1].total_wickets)
                {
                    t = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = t;
                }
            }
        }
    }
}

// function to display details of perticular player
void display_particular_player(struct Cricketer_Details c[35], int n, char cricket_name[50])
{
    printf("\n************ Display perticular player ************\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(c[i].name, cricket_name) == 0)
        {
            printf("\nName                       : %s", c[i].name);
            printf("\nAge                        : %d", c[i].age);
            printf("\nCountry                    : %s", c[i].country);
            printf("\nCategory                   : %s", c[i].category);
            printf("\nNo. of ODI played          : %d", c[i].odi_played);
            printf("\nNo. of 20-20 played        : %d", c[i].twenty_twenty_played);
            printf("\nAverage Score              : %f", c[i].avg_batting_score);
            printf("\nTotal no. of wickets taken : %d", c[i].total_wickets);
            printf("\n");
        }
    }
}

// binary search to find batsman with highest average score
int binarySearch(struct Cricketer_Details c[35], int n, float high_average_score)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (high >= low)
    {
        mid = (low + high) / 2;
        if (high_average_score == c[mid].avg_batting_score)
        {
            return mid;
        }
        else
        {
            if (high_average_score > c[mid].avg_batting_score)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
