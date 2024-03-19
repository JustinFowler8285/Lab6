#include <cstdlib>
#include "RPG.h"
#include <iostream>

using namespace std;

//constructors
RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}
RPG:: RPG(string newName, int newHealth, int newStrength, int newDefense, string newType) {
    name = newName;
    health = newHealth;
    strength = newStrength;
    defense = newDefense;
    type = newType;
    setSkills(); //Call setSkills to initialize skills on the RPGs role
}

//Accessor functions
string RPG::getName() const {
    return name;
}
int RPG::getHealth() const {
    return health;
}
int RPG:: getStrength() const {
    return strength;
}
int RPG:: getDefense() const {
    return defense;
}
/** myPrint
 * @brief sets the skills based on the RPG's role
 * 
*/
void RPG::setSkills() {
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "theif"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}
/**
 * @brief Prints along the lines of Name used Skill on OPPONENT
 * 
 * @param skill
 * @param opponent
*/
void RPG::printAction(string skill, RPG opponent){
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

//updateHealth()
/**
 * @brief updates health into new_health
 * 
 * @param new_health
*/
void RPG::updateHealth(int new_Health){
    health = new_Health;
}
//isAlive()
/**
 * @brief returns whether health is greater than 0
 * 
 * @return true
 * @return false
*/
bool RPG::isAlive() const{
    return health > 0;
}
/**
 * @brief attack decreases the opponent's health by (strength - opponent's defense)
 * In other words, the opponents's defense should soften the blow from the attack
 * 
 * For example, if opponent's health is 100, opponent' defense is 5, and player's
 * strength is 20, then after the attack, opponent's health should be
 * 85 (i.e. 100 - (20-5)).
 * 
 * First calculate the opponent's health, then use (*opponent).getUpdate(new_health)
 *  to update their health.
 * 
 * @param opponent
*/
void RPG::attack(RPG * opponent){
    //Implement brief
   int new_health = (*opponent).getHealth() - (strength - (*opponent).getDefense());
   (*opponent).updateHealth(new_health);
}
/**
 * @brief Prompts that user to choose a skill and calls printAction() and acttack()
 * 
 * @param opponent
 */
void RPG:: useSkill(RPG * opponent){
    // use a for loop to print out all the player's skill
    // the code within your loop should be:
    // printf("Skill %i: %s\n", i, skills[i].c_str());
    // where i is the index given your for loop
    // Recall that SKILL_SIZE is set to 2 within RPG.h
    // The values of i should be 0 <= i < SKILL_SIZE.

    for(int i = 0; i < SKILL_SIZE;i++){
        printf("skill %i: %s\n", i, skills[i].c_str());
    }
    // create an in called chosen_skill_index
    int chosen_skill_index;

    //use a print to output "choose a skill to use: Enter 0 or 1\n" on the terminal
    printf("choose a skill to use: Enter 0 or 1\n");

    // get user inpput and assign it to chosen_skill_index
    //(e.g. cin >>)
    cin >> chosen_skill_index;

    //assigns the chosen_skill into a string called chosen_skill
    //no modification needed here
    string chosen_skill = skills[chosen_skill_index];

    //call printAction(string, RPG) and use chosen_skill and (*oppenent)
    //as the parameters
    printAction(chosen_skill, (*opponent));

    //call attack on opponent
    attack(opponent);

}