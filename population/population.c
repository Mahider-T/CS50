#include <stdio.h>
#include <stdlib.h>

int main()
{
    int startingPopulation, endingPopulation;

    while (1)
    {
        printf("Enter the starting population size: ");
        if (scanf("%d", &startingPopulation) != 1 || startingPopulation < 0)
        {
            printf("Invalid input. Please enter a positive number.\n");
            continue;
        }

        printf("Enter the ending population size: ");
        if (scanf("%d", &endingPopulation) != 1 || endingPopulation < 0)
        {
            printf("Invalid input. Please enter a positive number.\n");
            continue;
        }

        if (endingPopulation < startingPopulation)
        {
            printf("The ending population should be greater than or equal to the starting population.\n");
        }
        else
        {
            break;
        }
    }

    if (endingPopulation == startingPopulation)
    {
        printf("Years = 0.\n");
    }
    else
    {
        int years = 0;

        while (startingPopulation < endingPopulation)
        {
            int births = startingPopulation / 3;
            int deaths = startingPopulation / 4;
            startingPopulation += births - deaths;
            years++;
        }

        printf("It takes %d years to reach the ending population size.\n", years);
    }

    return 0;
}