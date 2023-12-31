#include <stdio.h>
#include<cs50.h>
void numberOfYears(int initialNumber, int targetNumber){
    int currentPopulation = initialNumber;
    int numberOfYearsNeeded = 0;
    int diePerYear;
    int bornPerYear;
    int netPerYear;

    if(initialNumber == targetNumber){
        printf("Years: %d\n", 0);
    }
    do{
        diePerYear = currentPopulation/4;
        bornPerYear = currentPopulation/3;
        netPerYear = bornPerYear - diePerYear;
        currentPopulation += netPerYear;
        numberOfYearsNeeded++;

    }while(currentPopulation < targetNumber);
    // numberOfYearsNeeded = (targetNumber - initialNumber)/netPerYear;
    printf("Years: %d\n", numberOfYearsNeeded);
}


int main(void){
    int startingPopulation;
    int targetPopulation;
    do{
        startingPopulation = get_int("Starting size: ");
    }while(startingPopulation < 9);

    do{
        targetPopulation = get_int("Target size: ");
    }while(targetPopulation < startingPopulation);

    numberOfYears(startingPopulation, targetPopulation);


}