#include <iostream>
#include "RPG.h"

using namespace std;

/**
 * @brief Prints both player's name and their health.
 * Example Output for names Wiz and NPC
 * Wis helath: 75 NPC health: 100/n
 * 
 * @param player1
 * @param player2
*/
void displayStats(RPG player1, RPG player2){
    //Implement the brief
    cout << player1.getName() << " health: " << player1.getHealth() << " ";
    cout << player2.getName() << " health: " << player2.getHealth() << endl;
}
/**
 * @brief Displays who wins based on who ius alive. use an if statement to check whether
 * player 1 is alove. If so, print that they won, else player 2 won.
 * 
 * Example Output:
 * Wiz defeated NPC! Good game!\n
 * 
 * @param player1
 * @param player2
*/
void displayEnd(RPG player1, RPG player2){
    //Implement brief
    if (player1.isAlive()) {
        cout << player1.getName() << " defeated " << player2.getName() << "! Good game!" << endl;
    } else {
        cout << player2.getName() << " defeated " << player1.getName() << "! Good game!" << endl;
    }
}
/**
 * @brief uses a while loop to check whetehr both players are alive.
 * If so, it calls dispayStats((*player1), and (*player2))
 * Inside the while loop it:
 *  Then prints the name of player one to say that it is their turn
 *  Then call (*player1).useSkill(player2)
 *  Then prints "-------------------------------------\n"
 * 
 Refer to The Role Playing Game Part Two instructions for the 
 example output
 *
 * @param player1
 * @param player2
*/
void gameLoop(RPG * player1, RPG * player2){
    //Implement brief
    while((*player1).isAlive() && (*player2).isAlive()) {
        displayStats((*player1), (*player2));
        cout << (*player1).getName() << " turn\n" << endl;
        (*player1).useSkill(player2);
        cout << "---------------------------------" << endl;

        displayStats((*player1), (*player2));
        cout << (*player2).getName() << " turn\n" << endl;
        (*player2).useSkill(player1);
        cout << "---------------------------------" << endl;
    }
}
int main(){
    RPG p1 = RPG("wiz", 70, 45, 15, "mage");
    RPG p2 = RPG(); 

    gameLoop(&p1, &p2);         
    displayEnd(p1, p2);
    return 0;

}