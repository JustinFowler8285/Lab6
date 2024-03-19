#ifndef RPG_H
#define RPG_H

using namespace std;
#include <string>

const int SKILL_SIZE = 2;

class RPG {
    public:
        //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);

        //COMPLETE THE REST
        void setSkills();
        void printAction(string, RPG);
        void updateHealth(int new_Health);// updates health to new_health
        void attack(RPG *);
        void useSkill(RPG *);

        bool isAlive() const;
        string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getDefense() const;

    private:
        //COMPLETE THE REST
        string type; // warrior, mage, thief, archer
        string skills[SKILL_SIZE];
        string name;
        int health;
        int strength;
        int defense;
};
#endif