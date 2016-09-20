#include <stdio.h>
#include <string.h>

//match people together and infect them accordingly
void matchMake(int* infectedGonorrhea, int* infectedHerpes, int* infectedSyphillis);

//print out the results
void printPeople(int infectedGonorrhea[], int infectedHerpes[], int infectedSyphillis[], int numElements);

//displays who infected who
void printInfection(int num1, int num2, int diseaseType);

//returns the name of the person
char* getName(int num, char name[]);


int main(int argc, const char * argv[]) {
    //declare the variables
    const int NUM_ELEMENTS = 6;
    int hasGonorrhea[NUM_ELEMENTS];
    int hasHerpes[NUM_ELEMENTS];
    int hasSyphillis[NUM_ELEMENTS];
    int i = 0;
    
    //Setting which person is starting out with which std
    hasGonorrhea[i]=0; hasHerpes[i]=0;hasSyphillis[i]=0; i++;
    hasGonorrhea[i]=1; hasHerpes[i]=0;hasSyphillis[i]=0; i++;
    hasGonorrhea[i]=0; hasHerpes[i]=1;hasSyphillis[i]=0; i++;
    hasGonorrhea[i]=0; hasHerpes[i]=0;hasSyphillis[i]=1; i++;
    hasGonorrhea[i]=0; hasHerpes[i]=0;hasSyphillis[i]=0; i++;
    hasGonorrhea[i]=0; hasHerpes[i]=0;hasSyphillis[i]=0; i++;
    
    //Calling the functions to print before stats, infect, and print after stats
    printPeople(hasGonorrhea, hasHerpes, hasSyphillis, NUM_ELEMENTS);
    matchMake(hasGonorrhea, hasHerpes, hasSyphillis);
    printPeople(hasGonorrhea, hasHerpes, hasSyphillis, NUM_ELEMENTS);
    
    return 0;
}

//match people together and infect them accordingly
void matchMake(int* infectedGonorrhea, int* infectedHerpes, int* infectedSyphillis) {
    int randomNum1 = 0;
    int randomNum2 = 3;
    char name[15];
    char name2[15];
    
    printf("Please input a random integer between 0 and 5 inclusive.\n");
    scanf("%d", &randomNum1);
    while (randomNum1 < 0 || randomNum1 > 5) { //Validation, does not include letter validation
        printf("Sorry, please enter a random integer between 0 and 5 inclusive.\n");
        scanf("%d", &randomNum1);
    }
    
    printf("Please input another random integer between 0 and 5 inclusive that is different from your previous number.\n");
    scanf("%d", &randomNum2);
    while ((randomNum2 < 0 || randomNum2 > 5) || randomNum1 == randomNum2) { //Validation, does not include letter validation
        printf("Sorry, please enter a random integer between 0 and 5 inclusive.\n");
        scanf("%d", &randomNum2);
    }
    
    //check to see who did the infecting and who got infected for each STD
    if (infectedGonorrhea[randomNum1] == 0 && infectedGonorrhea[randomNum2] == 1)  //check before infection of RandomNum1
        printInfection(randomNum1, randomNum2, 0);
    if (infectedGonorrhea[randomNum1] == 1 && infectedGonorrhea[randomNum2] == 0)  //check before infection of RandomNum1
        printInfection(randomNum2, randomNum1, 0);
    if (infectedGonorrhea[randomNum1] == 0 && infectedGonorrhea[randomNum2] == 0)
        printf("Whew! Neither %s nor %s have Gonorrhea.\n", getName(randomNum1,name), getName(randomNum2,name2));
    int newInfectNum = infectedGonorrhea[randomNum1] + infectedGonorrhea[randomNum2];
    infectedGonorrhea[randomNum1] = newInfectNum;
    infectedGonorrhea[randomNum2] = newInfectNum;
    
    if (infectedHerpes[randomNum1] == 0 && infectedHerpes[randomNum2] == 1) //check before infection of RandomNum1
        printInfection(randomNum1, randomNum2, 1);
    if (infectedHerpes[randomNum1] == 1 && infectedHerpes[randomNum2] == 0) //check before infection of RandomNum1
        printInfection(randomNum2, randomNum1, 1);
    if (infectedHerpes[randomNum1] == 0 && infectedHerpes[randomNum2] == 0)
        printf("Nothing to see here folks. %s and %s are clean of the Herp.\n", getName(randomNum1,name), getName(randomNum2,name2));
    newInfectNum = infectedHerpes[randomNum1] + infectedHerpes[randomNum2];
    infectedHerpes[randomNum1] = newInfectNum;
    infectedHerpes[randomNum2] = newInfectNum;
    
    if (infectedSyphillis[randomNum1] == 0 && infectedSyphillis[randomNum2] == 1) //check before infection of RandomNum1
        printInfection(randomNum1, randomNum2, 2);
    if (infectedSyphillis[randomNum1] == 1 && infectedSyphillis[randomNum2] == 0)  //check before infection of RandomNum1
        printInfection(randomNum2, randomNum1, 2);
    if (infectedSyphillis[randomNum1] == 0 && infectedSyphillis[randomNum2] == 0)
        printf("Aye dios mio! %s nor %s sure know how to use protection against that nasty Siphillis.\n", getName(randomNum1,name), getName(randomNum2,name2));
    newInfectNum = infectedSyphillis[randomNum1] + infectedSyphillis[randomNum2];
    infectedSyphillis[randomNum1] = newInfectNum;
    infectedSyphillis[randomNum2] = newInfectNum;
}

//print out the results
void printPeople(int infectedGonorrhea[], int infectedHerpes[], int infectedSyphillis[], int numElements) {
    int i = 0;
    for(i = 0; i < numElements; i++) {
        if(i ==0) {
            printf("Name: Taylor Gonorrhea: %d, Herpes: %d, Syphillis: %d\n", infectedGonorrhea[i], infectedHerpes[i],infectedSyphillis[i]);
        }
        else if(i ==1) {
            printf("Name: Aiden Gonorrhea: %d, Herpes: %d, Syphillis: %d\n", infectedGonorrhea[i], infectedHerpes[i],infectedSyphillis[i]);
        }
        else if(i ==2) {
            printf("Name: Ricky Gonorrhea: %d, Herpes: %d, Syphillis: %d\n", infectedGonorrhea[i], infectedHerpes[i],infectedSyphillis[i]);
        }
        else if(i ==3) {
            printf("Name: Ashley Gonorrhea: %d, Herpes: %d, Syphillis: %d\n", infectedGonorrhea[i], infectedHerpes[i],infectedSyphillis[i]);
        }
        else if(i ==4) {
            printf("Name: Jordan Gonorrhea: %d, Herpes: %d, Syphillis: %d\n", infectedGonorrhea[i], infectedHerpes[i],infectedSyphillis[i]);
        }
        else if(i ==5) {
            printf("Name: Jean Gonorrhea: %d, Herpes: %d, Syphillis: %d\n", infectedGonorrhea[i], infectedHerpes[i],infectedSyphillis[i]);
        }
        else
            printf("Error\n");
    }
}

//returns the name of the person
char* getName(int num, char name[]) {
    
    switch (num) {
        case 0:
            strcpy(name,"Taylor"); break;
        case 1:
            strcpy(name,"Aiden"); break;
        case 2:
            strcpy(name,"Ricky"); break;
        case 3:
            strcpy(name,"Ashley"); break;
        case 4:
            strcpy(name,"Jordan"); break;
        case 5:
            strcpy(name,"Jean"); break;
    }
    return name;
}

//returns the type of STD
char* getInfection(int num, char name[]) {
    
    switch (num) {
        case 0:
            strcpy(name,"Gonorrhea"); break;
        case 1:
            strcpy(name,"Herpes"); break;
        case 2:
            strcpy(name,"Syphillis"); break;
    }
    return name;
}

//displays who infected who
void printInfection(int num1, int num2, int diseaseType) {
    char type[15];
    char name[15];
    char name2[15];
    printf("%s got %s from %s!!!!\n", getName(num1,name), getInfection(diseaseType, type),getName(num2,name2));
}



