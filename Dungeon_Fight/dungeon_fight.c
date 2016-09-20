#include <stdio.h>
#include <stdlib.h>   
#include <string.h>   
#include <unistd.h>
#define MIN_ROOMW 8
#define MIN_ROOMH 5
#define DUNGEON_WIDTH 60
#define DUNGEON_HEIGHT 15
#define MAX_STRENGTH 10
#define MAX_HEALTH 100
#define MIN_STRENGTH 4
#define MIN_HEALTH 70


//Declare function prototypes
//Function will generate dungeon
void generateDungeon(char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT], char room[MIN_ROOMW][MIN_ROOMH]);

//Function will print dungeon
void printDungeon(char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT], char room[MIN_ROOMW][MIN_ROOMH]);

//Function will generate a room
void generateRoom(char room[MIN_ROOMW][MIN_ROOMH], char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT]);

//Function that generates the fight
int generateFight(char fighter1[], char fighter2[], int strengthFighter1, int strengthFighter2, int* healthFighter1, int* healthFighter2);
//Function that generates health and attack strength
void createWarrior(int* strength, int* health);


int main(int argc, const char * argv[]) {
    //declare the variables and arrays
    char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT];
    char room[MIN_ROOMW][MIN_ROOMH];
    unsigned seed = 0;
    char warrior1[] = "John Cena";
    char warrior2[] = "Fiddy Cent";
    int attackStrengthW1 = 0;
    int attackStrengthW2 = 0;
    int healthWarrior1 = 0;
    int healthWarrior2 = 0;
    
    //title screen
    generateDungeon(dungeon, room);
    printDungeon(dungeon, room);
    printf("THIS IS DUNGEON BATTLE!!!\n GRRRRRRRR!\n (MANLY SHOUTING)!!!!!\n\n\n\n");
    
    //get random number seed
    printf("Input a random number seed: ");
    scanf("%u",&seed);
    srand(seed);
   
    //initialize strength and health
    createWarrior(&attackStrengthW1, &healthWarrior1);
    createWarrior(&attackStrengthW2, &healthWarrior2);
    
    
    //continue fighting until health reaches or goes below zero
    while (healthWarrior1 > 0 && healthWarrior2 > 0)
        generateFight(warrior1, warrior2, attackStrengthW1, attackStrengthW2, &healthWarrior1, &healthWarrior2);
    
    if (healthWarrior1 <= 0)
        printf("%s has been vanquished!\n%s is triumphant!\n", warrior1, warrior2);
    else
        printf("%s has been vanquished!\n%s is triumphant!\n", warrior2, warrior1);
    
    
    return 0;
}

//Function definitions

//create warrior
void createWarrior(int* strength, int* health) {
    *strength = (rand() % MAX_STRENGTH) + MIN_STRENGTH;
    *health= (rand() % MAX_HEALTH) + MIN_HEALTH;
}

//Function that generates the fight
int generateFight(char fighter1[], char fighter2[], int strengthFighter1, int strengthFighter2, int* healthFighter1, int* healthFighter2) {
    //Both fighters attack each other and health is decremented
    *healthFighter1 -= strengthFighter2;
    *healthFighter2 -= strengthFighter1;
    
    printf("Name: %s  Health: %d  VS.  Name: %s  Health: %d  \n", fighter1, *healthFighter1, fighter2, *healthFighter2);
    
    if (healthFighter2 <= 0 || healthFighter1 <= 0) {
        return 0;
    }
    return 1;
}

//Function will generate dungeon
void generateDungeon(char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT], char room[MIN_ROOMW][MIN_ROOMH]) {
    int i = 0; //width
    int j = 0;  //height
    for (i = 0; i < DUNGEON_HEIGHT; i++) {
        for (j = 0; j < DUNGEON_WIDTH; j++) {
            dungeon[j][i] = '#';
        }
    }
    generateRoom(room,dungeon);
   }

//Function will print dungeon
void printDungeon(char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT], char room[MIN_ROOMW][MIN_ROOMH]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < DUNGEON_HEIGHT; i++) {
        for (j = 0; j < DUNGEON_WIDTH; j++) {
            printf("%c", dungeon[j][i]);
        }
        printf("\n");
    }
}

//Function will generate a room
void generateRoom(char room[MIN_ROOMW][MIN_ROOMH], char dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT]) {
    int i = 0;
    int j = 0;
    //get max room height and width
    int roomHeight = (rand() % (12 - MIN_ROOMH)) + MIN_ROOMH;
    int roomWidth = (rand() % (15 - MIN_ROOMW)) + MIN_ROOMW;
    
    //put room in a place with a starting position
    //make sure starting position is on grid
    int startHeight = (rand() % ((DUNGEON_HEIGHT - 1) - roomHeight)) + 1; //actual start height + 1 for minimun it can be
    int startWidth = (rand() % ((DUNGEON_WIDTH - 1) - roomWidth)) + 1; //actual start width + 1 for minimun it can be
    
    for (i = startHeight; i < startHeight + roomHeight; i++) {
        for (j = startWidth; j < startWidth + roomWidth; j++) {
            dungeon[j][i] = '.';
        }
    }
}