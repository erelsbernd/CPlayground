#include <stdio.h>

/* This is a simple matchmaking algorithm that prompts the user for responses to a series of questions. Based on the yes/no response to these questions, the program will match the user with a man that best suits his or her personality. */

    //Declare function prototypes.

int matchMake(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, char num9, char num10);
void displayMatch(int partnerChoice);


int main() {
    //Declare the variables
    char name[50];
    char questionNum1[5];
    char questionNum2[5];
    char questionNum3[5];
    char questionNum4[5];
    char questionNum5[5];
    char questionNum6[5];
    char questionNum7[5];
    char questionNum8[5];
    char questionNum9[5];
    char questionNum10[5];
    int manChoice = 0;
    
    //Introduce the matchmaking service.
    printf("Hello! Welcome to the Find Your Fantasy dating service!\nPlease take the time to respond to the following series of questions. Our specially crafted personality program will match you with the partner of your dreams. Let's begin!\n");
    
    printf("What is your first name? \n");
    scanf("%s", name);
    printf("Hello %s! \nPlease answer 'y' for yes or 'n' for no to the following series of questions.\n", name);
    
    //Prompt user with questions, ask for response, and validate response.
    printf("Do you value physical appearance more than intelligence in a partner? \n");
    scanf("%s", questionNum1);
    while (questionNum1[0] != 'y' && questionNum1[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum1);
    }
    
    printf("Do you prefer to stay at home on a Friday night and watch Netflix with a good friends as opposed to going out?\n");
    scanf("%s", questionNum2);
    while (questionNum2[0] != 'y' && questionNum2[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum2);
    }

    
    printf("Do you view a partner's financial stability as extremely important? \n");
    scanf("%s", questionNum3);
    while (questionNum3[0] != 'y' && questionNum3[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum3);
    }
    
    printf("Do you like to eat rich, decadent foods? \n");
    scanf("%s", questionNum4);
    while (questionNum4[0] != 'y' && questionNum4[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum4);
    }
    
    printf("Do you like to go on picnics in nature and make out in a rowboat? \n");
    scanf("%s", questionNum5);
    while (questionNum5[0] != 'y' && questionNum5[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum5);
    }
    
    printf("Are you bold and mischevious? \n");
    scanf("%s", questionNum6);
    while (questionNum6[0] != 'y' && questionNum6[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum6);
    }
    
    printf("Do you like to eat prunes and hard candy? \n");
    scanf("%s", questionNum7);
    while (questionNum7[0] != 'y' && questionNum7[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum7);
    }
    
    printf("Are you shy and introverted? \n");
    scanf("%s", questionNum8);
    while (questionNum8[0] != 'y' && questionNum8[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum8);
    }
          
    printf("Do you like to dance? \n");
    scanf("%s", questionNum9);
    while (questionNum9[0] != 'y' && questionNum9[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum9);
    }
    
    printf("Is 'Love' your favorite part of 'Eat, Pray, Love'? \n");
    scanf("%s", questionNum10);
    while (questionNum10[0] != 'y' && questionNum10[0] != 'n') { //Validation
        printf("Sorry, please enter 'yes' or 'no'.");
        scanf("%s", questionNum10);
    }
          
   printf("Thank you for your responses!\n");
   
    //Call functions to determine and display partner choice.
    manChoice = matchMake(questionNum1[0], questionNum2[0], questionNum3[0], questionNum4[0], questionNum5[0], questionNum6[0], questionNum7[0], questionNum8[0], questionNum9[0], questionNum10[0]);
    displayMatch(manChoice);
    
    
    return 0;
}

//Functions.

//Function determines user's perfect match by reviewing the user responses.
int matchMake(char num1, char num2, char num3, char num4, char num5, char num6, char num7, char num8, char num9, char num10) {
    int choice = 0;
    if (num1 == 'y' && num4 == 'y' && num6 == 'y' && num9 == 'y') {  //yes to 1,4,6,9 is Ronaldo
        printf("Your match is...\n\n\n\nRonaldo!\n");
        choice = 1;
    }
    else if (num3 == 'y' && num4 == 'y' && num7 == 'y') {   // yes to 3, 4, 7, is old, rich man Rupert
        printf("Your match is...\n\n\n\nRupert Humphrey!\n");
        choice = 2;
    }
    else if (num2 == 'y' && num5 == 'y' && num8 == 'y' && num10 == 'y') {   // yes to 2, 5, 8, 10 is sensitive Bartholomew
        printf("Your match is...\n\n\n\nBartholomew!\n");
        choice = 3;
    }
    else {
        printf("We are so sorry. You are utterly incompatible. There is no one for you.\n");  //no match
        choice = 0;
    }
    return choice;
}

//Function displays description of user match.
void displayMatch(int partnerChoice) {
    if (partnerChoice == 1) {
        printf("Ronaldo hails from Brazil but has lived in the United States for the past 8 years. He enjoys staying active by frequenting Capoeira and Salsa clubs. Ronaldo is a very attentive lover and wants to indulge your deepest, darkest fantasies while breaking all the rules.\n");
    }
    else if (partnerChoice == 2) {
        printf("Rupert Humphrey is approximately 83 years old and is the CEO of luxury canine lingerie company: Bow Wow's Secret. He enjoys exploring new investment and entrepreneur opportunities. Because his schedule is often packed with business meetings, new denture fittings, and golf he will not have a lot of time or love to give you. However, he will attempt to make it all right by giving you generous company stock options, lavish shopping sprees, and a killer 401k!\n");
    }
    else if (partnerChoice == 3) {
        printf("Bartholomew is a sweet and sensitive soul. He is bashful but utterly devoted to finding and pleasing his one true love--you! He enjoys going for walks on the beach, watching sappy cry-porn on Netflix, and giving long massages to his soul-mate while picnicing on vegan Komex fusion.\n");
    }
    else {
        printf("Here are some tips for improving your compatibility.\n*Eat more hard candy or rich decadent foods.\n*Socialize more by going out to clubs and dancing.\n*Expand your knowledge of pop culture and world cinema by watching Netflix.\n*Read 'Eat, Pray, Love', even if you thought the movie was trash and was an unneccessary tale of the plight of a modern, upper-middle class, first-world, white woman who had the luxury of traveling the world to get over ennui.\n*Get outside and go for a picnic with friends.\n*Channel your inner she-demon and do something naughty and mischevious.\n");
    }
}
