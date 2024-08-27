#include <TXLib.h>
#include <stdio.h>

const int SUB = 26;

enum result
{
    SUCCESS = 0,
    EOF_FOUND = 1
};

struct GameResult
{
    unsigned int team1, team2;
    unsigned int goals1, goals2;
};

struct Score
{
    unsigned int goals1, goals2;
};

size_t ProgresSum(size_t num);

enum result Interact(struct Score *table, size_t nTeams);

enum result InputnTeams(size_t *nTeams);

enum result BufferClear(void);

enum result Request(int *choice);
enum result AddScore(struct Score *table, size_t nTeams);
enum result InputScore(struct GameResult *game, size_t nTeams);
void        SortData(struct GameResult *game);
void        ShowTable(struct Score *table, size_t nTeams);

int main(void)
{
    size_t nTeams = 0;

    InputnTeams(&nTeams);

    struct Score *table = (struct Score *) calloc(ProgresSum(nTeams), sizeof(struct Score));

    Interact(table, nTeams);

    free(table);

    printf("End of programm.");

    return 0;
}

enum result InputnTeams(size_t *nTeams)
{
    assert(nTeams);

    printf("Enter the number of teams.\n");

    int res = scanf("%u", nTeams);

    while (res != 1 || *nTeams < 1)
    {
        if (res == EOF)
            return EOF_FOUND;

        printf("You must enter only natural nambers.\n");

        if (BufferClear() == EOF_FOUND)
            return EOF_FOUND;

        res = scanf("%u", nTeams);
    }

    return SUCCESS;
}

enum result Interact(struct Score *table, size_t nTeams)
{
    assert(table);

    int choice = 0;

    if (Request(&choice) != SUCCESS)
        return EOF_FOUND;

    while (choice != 3)
    {
        if (choice == 1)
        {
            if (AddScore(table, nTeams) == EOF_FOUND)
                return EOF_FOUND;
        }
        else
            ShowTable(table, nTeams);

        if (Request(&choice) != SUCCESS)
            return EOF_FOUND;
    }

    return SUCCESS;
}

void ShowTable(struct Score *table, size_t nTeams)
{
    assert(table);

    printf("       ");

    for (int i = 1; i < nTeams + 1; i++)
        printf(" %5d ", i);

    printf("\n\n");

    for (size_t x = 0; x < nTeams; x++)
    {
        printf(" %5u ", x + 1);

        for (size_t y = 0; y < nTeams; y++)
        {
            if (y == x)
                printf(" _____ ");
            else if (y > x)
                printf("   *   ");
            else
                printf(" %2d:%2d ", (*(table + ProgresSum(x) + y)).goals1,
                       (*(table + ProgresSum(x) + y)).goals2);
        }

        printf("\n\n");
    }
}

enum result Request(int *choice)
{
    assert(choice);

    printf("Enter 1 to add a result. "
               "Enter 2 to see the table.\n"
               "Enter 3 to finish.\n");

    int res = scanf("%d", choice);

    while (res != 1 || *choice < 1 || *choice > 3)
    {
        if (res == EOF)
            return EOF_FOUND;

        printf("You must enter 1, 2 or 3.\n");

        if (BufferClear() == EOF_FOUND)
            return EOF_FOUND;

        res = scanf("%d", choice);
    }

    return SUCCESS;
}

enum result BufferClear(void)
{
    int ch = 0;

    while (((ch = getchar()) != '\n')  &&  (ch != SUB) && (ch != EOF));

    if (ch == EOF)
        return EOF_FOUND;
    else
        return SUCCESS;
}

enum result AddScore(struct Score *table, size_t nTeams)
{
    assert(table);

    struct GameResult game = {0, 0, 0, 0};

    if (InputScore(&game, nTeams) == EOF_FOUND)
        return EOF_FOUND;

    SortData(&game);

    (*(table + ProgresSum(game.team1 - 1) + (game.team2 - 1))).goals1 += game.goals1;
    (*(table + ProgresSum(game.team1 - 1) + (game.team2 - 1))).goals2 += game.goals2;

    return SUCCESS;
}

enum result InputScore(struct GameResult *game, size_t nTeams)
{
    assert(game);

    printf("Enter separated by a space\n"
           "number of the first team, score of the first team, "
           "number of the second team, score of the second team:\n");

    int res = scanf("%u %u %u %u", &(*game).team1, &(*game).goals1,
                    &(*game).team2, &(*game).goals2);

    while (res != 4 || (*game).team1 > nTeams || (*game).team2 > nTeams
           || (*game).team1 == (*game).team2)
    {
        if (res == EOF)
            return EOF_FOUND;

        printf("You enterred data incorrectly.\n");

        if (BufferClear() == EOF_FOUND)
            return EOF_FOUND;

        res = scanf("%u %u %u %u", &(*game).team1, &(*game).goals1, &(*game).team2, &(*game).goals2);
    }

    return SUCCESS;
}

void SortData(struct GameResult *game)
{
    assert(game);

    if ((*game).team1 < (*game).team2)
    {
        unsigned int changeTeams = (*game).team1, changeGoals = (*game).goals1;
        (*game).team1 = (*game).team2;
        (*game).goals1 = (*game).goals2;

        (*game).team2 = changeTeams;
        (*game).goals2 = changeGoals;
    }
}

size_t ProgresSum(size_t num)
{
    return (num + 1) * num / 2;
}
