#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        unsigned int seed;
        int players;
        int playersIn;
        int pot = 0;
        typedef enum faciem{LEFT, RIGHT, CENTER, PASS} faces;
        faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS};
        const char *names[] =
                        {"Whoopie",
                        "Dale",
                        "Rosie",
                        "Jimmie",
                        "Barbara",
                        "Kyle",
                        "Raven",
                        "Tony",
                        "Jenny",
                        "Clint"};

        printf("Random Seed: ");
        scanf("%u", &seed);
        printf("How many players? ");
        scanf("%d", &players);
        srand(seed);


        int playerMoney[players];
        for(int i = 0; i < players; i++)
        {
                playerMoney[i] = 3;
                playersIn++;
        }
        while(playersIn > 1)
        {

                for(int i = 0; i < players; i++)
                {
                        if(playerMoney[i] > 0 && playersIn > 1)
                        {
                                int rolls;
                                if(playerMoney[i] >= 3)
                                {
                                         rolls = 3;
                                }
                                else if(playerMoney[i] == 2)
                                {
                                        rolls = 2;
                                }
                                else
                                {
 					rolls = 1;
                                }
                                printf("%s rolls . . .", names[i]);
                                for(int j = 0; j < rolls; j++)
                                {
                                        int randomNumber;
                                        randomNumber = rand() % 6;

                                        if(die[randomNumber] == LEFT)
                                        {
                                                playerMoney[i] -= 1;
                                                if(playerMoney[i] <= 0)
                                                {
                                                        playersIn--;
                                                }
                                                if((i-1) < 0)
                                                {
                                                        if(playerMoney[players-1] <= 0)
                                                        {
                                                                playerMoney[players-1] += 1;
                                                                printf(" gives $1 to %s ", names[players-1]);
                                                                playersIn++;
                                                        }
                                                        else
                                                        {
                                                                playerMoney[players-1] += 1;
                                                                printf(" gives $1 to %s ", names[players-1]);
                                                        }
                                                }
                                                else
                                                {
                                                        if(playerMoney[i-1] <= 0)
                                                        {
                                                                playerMoney[i-1] += 1;
                                                                printf(" gives $1 to %s ", names[i-1]);
                                                                playersIn++;
                                                        }
                                                        else
                                                        {
                                                                playerMoney[i-1] += 1;
                                                                printf(" gives $1 to %s ", names[i-1]);
                                                        }
                                                }

                                        }
                                        else if(die[randomNumber] == RIGHT)
                                        {
                                                playerMoney[i] -=1;
                                                if(playerMoney[i] <= 0)
                                                {
                                                        playersIn--;
                                                }
 						if((i+1) > players-1)
                                                {
                                                       	 if(playerMoney[0] <= 0)
                                                      	 {
                                                               	playerMoney[0] += 1;
                                                                printf(" gives $1 to %s ", names[0]);
                                                                playersIn++;
                                                        }
                                                        else
                                                        {
                                                                playerMoney[0] += 1;
                                                                printf(" gives $1 to %s ", names[0]);
                                                        }
                                                }
                                                else
                                                {
                                                        if(playerMoney[i+1] <= 0)
                                                        {
                                                                playerMoney[i+1] += 1;
                                                                printf(" gives $1 to %s ", names[i+1]);
                                                                playersIn++;
                                                        }
                                                        else
                                                        {
                                                                 playerMoney[i+1] += 1;
                                                                 printf(" gives $1 to %s ", names[i+1]);
                                                        }
                                                }
                                        }
                                        else if(die[randomNumber] == CENTER)
                                        {
                                                playerMoney[i] -= 1;
                                                if(playerMoney[i] == 0)
                                                {
                                                        playersIn--;
                                                }
                                                printf(" puts $1 in the pot ");
                                                pot += 1;

                                        }
                                        else if(die[randomNumber] == PASS)
                                        {
                                                        printf(" gets a pass");
                                        }
                                        else
                                        {
                                                printf(" gets a pass");
                                        }

                                }
                                printf("\n");
                        }
                }
	 }
	int maximum = playerMoney[0];
        for(int i = 1; i < players; i++){
                
                int index;
                if(playerMoney[i] > maximum)
                {
                        maximum = playerMoney[i]; 
                        index = i;
                }
                if(i == players-1)
                {
                printf("%s Wins the $%d pot with $%d left in the bank!\n", names[index], pot, maximum);
                }
        }

        return 0;
}
