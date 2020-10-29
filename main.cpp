/* Main function for my game. Allows user to choose from two characters and two weapons for each character.
 * Each battle is then initialized and completed with user input.
 * Battles are lost when your health reaches 0.
 * Attempt to defeat all three enemies without dying.
 * Have Fun!
 * */

#include <iostream>
#include "Juggernaut.h"
#include "Archer.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Battle.h"

using namespace std;

int main() {
    cout << "Welcome to my game. This is a strategy game in which you will choose a warrior\nand attempt to defeat the boss and his minions." << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "You have 2 warriors to choose from: the Juggernaut and the Archer." << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "The Juggernaut has high health and a good amount of block to shrug off the\nmost powerful of enemy attacks, but his weight makes him slow and thus hinders\nhis attack damage." << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "The Archer has lower health but she is extremely quick and agile, giving her\nmore attack damage than the Juggernaut, but her lightness of foot also hinders\nher block ability." << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "Choose a character: Select 'A' for the Archer or 'J' for the Juggernaut: " << endl;
    char warriorSelection;
    cin >> warriorSelection;
    while (warriorSelection != 'A' and warriorSelection != 'a' and warriorSelection != 'J' and warriorSelection != 'j') {
        cout << " Please enter either A for Archer or J for Juggernaut" << endl;
        cin >> warriorSelection;
    }
    if (warriorSelection == 'A' or warriorSelection == 'a') {
        Archer archer;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "Excellent choice. Now let's get her a weapon. The Archer has two weapons to choose from." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "The first choice is the Bow of Fire. This weapon gives the Archer +4 attack damage\nand +1 block." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "The second choice is the Quiver of Might. This weapon gives the archer\n+1 attack damage and +4 block." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "Select 'B' for the Bow of Fire, or 'Q' for the Quiver of Might: " << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        char weaponSelectArcher;
        cin >> weaponSelectArcher;
        while(weaponSelectArcher != 'B' and weaponSelectArcher != 'b' and weaponSelectArcher != 'Q' and weaponSelectArcher != 'q'){
            cout << "Please enter either B for Bow of Fire or Q for Quiver of Might" << endl;
            cin >> weaponSelectArcher;
        }
        if (weaponSelectArcher == 'B' or weaponSelectArcher == 'b') {
            Weapon bow = Weapon(4,1);
            archer.setWeapon(bow);
        }
        if (weaponSelectArcher == 'Q' or weaponSelectArcher == 'q') {
            Weapon quiver = Weapon(1, 4);
            archer.setWeapon(quiver);
        }
        //_______________________________Battle 1_______________________________________________________________________________________
        cout << "Good choice. Now fulfill your destiny and defeat the boss. You look to the west and\nin the distance you can see the boss's stronghold.\nYou grab your weapon and begin the journey..." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "You enter the stronghold.\nCurtis the TArrible appears." << endl;
        Enemy curtis = Enemy(60,5,20,4,10);
        Battle battle1;
        while (archer.getHealth() > 0 && curtis.getHealth() > 0) {
            cout << "Turn " << battle1.getTurns() << endl;
            cout << "Your health: " << archer.getHealth() << endl;
            cout << "Curtis's health: " << curtis.getHealth() << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            int enemyAttack, enemyBlock, enemyDecision, turnAttack, turnBlock, unblockedDamage;
            char actionSelect;
            enemyDecision = battle1.getEnemyIntention(curtis);
            if (enemyDecision == 0) {
                cout << "The enemy intends to attack this turn." << endl;
                enemyAttack = curtis.getTurnAttack(curtis);
                cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                cin >> actionSelect;
                while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                }
                if (actionSelect == 'A' or actionSelect == 'a') {
                    turnAttack = archer.getTurnAttack(archer) + archer.getWeapon().getDamage();
                    curtis.setHealth(curtis.getHealth()-turnAttack);
                    archer.setHealth(archer.getHealth()-enemyAttack);
                    cout << "You did " << turnAttack << " unblocked damage to Curtis." << endl;
                    cout << "Curtis did " << enemyAttack << " unblocked damage to you." << endl;
                }
                if (actionSelect == 'B' or actionSelect == 'b') {
                    turnBlock = archer.getTurnBlock(archer) + archer.getWeapon().getBlock();
                    unblockedDamage = enemyAttack - turnBlock;
                    if (unblockedDamage > 0) {
                        archer.setHealth(archer.getHealth()-unblockedDamage);
                        cout << "Curtis did " << unblockedDamage << " unblocked damage to you." << endl;
                    }
                    else {
                        cout << "You blocked all of Curtis's damage." << endl;
                        cout << "-------------------------------------------------------------------------------------" << endl;
                    }
                }
            }
            if (enemyDecision == 1) {
                cout << "The enemy intends to block this turn." << endl;
                enemyBlock = curtis.getTurnBlock(curtis);
                cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                cin >> actionSelect;
                while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                }
                if (actionSelect == 'A' or actionSelect == 'a') {
                    turnAttack = archer.getTurnAttack(archer) + archer.getWeapon().getDamage();
                    unblockedDamage = turnAttack - enemyBlock;
                    if (unblockedDamage > 0) {
                        curtis.setHealth(curtis.getHealth() - unblockedDamage);
                        cout << "You did " << unblockedDamage << " unblocked damage to Curtis." << endl;
                        cout << "-------------------------------------------------------------------------------------" << endl;
                    } else {
                        cout << "Curtis blocked all of your damage." << endl;
                    }
                }
                if (actionSelect == 'B' or actionSelect == 'b') {
                    cout << "You both blocked. No damage was done." << endl;
                }
            }

            battle1.addTurn();
        }
        if (curtis.getHealth()<1) {
            cout << "You have slain Curtis. The battle lasted " << battle1.getTurns() << " turns." << endl;
 //--------------_________________________________Battle 2______________________________________________________________________
            cout << "You continue through the stronghold." << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "Lisa the DIONbolical appears." << endl;
            Enemy lisa = Enemy(100,12,22,4,17);
            Battle battle2;
            while (archer.getHealth() > 0 && lisa.getHealth() > 0) {
                cout << "Turn " << battle2.getTurns() << endl;
                cout << "Your health: " << archer.getHealth() << endl;
                cout << "Lisa's health: " << lisa.getHealth() << endl;
                cout << "-------------------------------------------------------------------------------------" << endl;
                int enemyAttack, enemyBlock, enemyDecision, turnAttack, turnBlock, unblockedDamage;
                char actionSelect;
                enemyDecision = battle2.getEnemyIntention(lisa);
                if (enemyDecision == 0) {
                    cout << "The enemy intends to attack this turn." << endl;
                    enemyAttack = lisa.getTurnAttack(lisa);
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                    while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                    }
                    if (actionSelect == 'A' or actionSelect == 'a') {
                        turnAttack = archer.getTurnAttack(archer) + archer.getWeapon().getDamage();
                        lisa.setHealth(lisa.getHealth()-turnAttack);
                        archer.setHealth(archer.getHealth()-enemyAttack);
                        cout << "You did " << turnAttack << " unblocked damage to Lisa." << endl;
                        cout << "Lisa did " << enemyAttack << " unblocked damage to you." << endl;
                    }
                    if (actionSelect == 'B' or actionSelect == 'b') {
                        turnBlock = archer.getTurnBlock(archer) + archer.getWeapon().getBlock();
                        unblockedDamage = enemyAttack - turnBlock;
                        if (unblockedDamage > 0) {
                            archer.setHealth(archer.getHealth()-unblockedDamage);
                            cout << "Lisa did " << unblockedDamage << " unblocked damage to you." << endl;
                        }
                        else {
                            cout << "You blocked all of Lisa's damage." << endl;
                            cout << "-------------------------------------------------------------------------------------" << endl;
                        }
                    }
                }
                if (enemyDecision == 1) {
                    cout << "The enemy intends to block this turn." << endl;
                    enemyBlock = lisa.getTurnBlock(lisa);
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                    while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                    }
                    if (actionSelect == 'A' or actionSelect == 'a') {
                        turnAttack = archer.getTurnAttack(archer) + archer.getWeapon().getDamage();
                        unblockedDamage = turnAttack - enemyBlock;
                        if (unblockedDamage > 0) {
                            lisa.setHealth(lisa.getHealth() - unblockedDamage);
                            cout << "You did " << unblockedDamage << " unblocked damage to Lisa." << endl;
                            cout << "-------------------------------------------------------------------------------------" << endl;
                        } else {
                            cout << "Lisa blocked all of your damage." << endl;
                        }
                    }
                    if (actionSelect == 'B' or actionSelect == 'b') {
                        cout << "You both blocked. No damage was done." << endl;
                    }
                }

                battle2.addTurn();
            }
            if (lisa.getHealth()<1) {
                cout << "You have slain Lisa. The battle lasted " << battle2.getTurns() << " turns." << endl;
//_______________________________________________________Battle 3___________________________________________________________
                cout << "You make your way into the final chamber of the stronghold and\nfind Bob E. the Cool waiting for your arrival..." << endl;
                cout << "-------------------------------------------------------------------------------------" << endl;
                Enemy bob = Enemy(200,5,25,13,18);
                Battle battle3;
                while (archer.getHealth() > 0 && bob.getHealth() > 0) {
                    cout << "Turn " << battle3.getTurns() << endl;
                    cout << "Your health: " << archer.getHealth() << endl;
                    cout << "Bob's health: " << bob.getHealth() << endl;
                    cout << "-------------------------------------------------------------------------------------" << endl;
                    int enemyAttack, enemyBlock, enemyDecision, turnAttack, turnBlock, unblockedDamage;
                    char actionSelect;
                    enemyDecision = battle3.getEnemyIntention(bob);
                    if (enemyDecision == 0) {
                        cout << "The enemy intends to attack this turn." << endl;
                        enemyAttack = bob.getTurnAttack(bob);
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                        while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                            cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                            cin >> actionSelect;
                        }
                        if (actionSelect == 'A' or actionSelect == 'a') {
                            turnAttack = archer.getTurnAttack(archer) + archer.getWeapon().getDamage();
                            bob.setHealth(bob.getHealth()-turnAttack);
                            archer.setHealth(archer.getHealth()-enemyAttack);
                            cout << "You did " << turnAttack << " unblocked damage to Bob." << endl;
                            cout << "Bob did " << enemyAttack << " unblocked damage to you." << endl;
                        }
                        if (actionSelect == 'B' or actionSelect == 'b') {
                            turnBlock = archer.getTurnBlock(archer) + archer.getWeapon().getBlock();
                            unblockedDamage = enemyAttack - turnBlock;
                            if (unblockedDamage > 0) {
                                archer.setHealth(archer.getHealth()-unblockedDamage);
                                cout << "Bob did " << unblockedDamage << " unblocked damage to you." << endl;
                            }
                            else {
                                cout << "You blocked all of Bob's damage." << endl;
                                cout << "-------------------------------------------------------------------------------------" << endl;
                            }
                        }
                    }
                    if (enemyDecision == 1) {
                        cout << "The enemy intends to block this turn." << endl;
                        enemyBlock = bob.getTurnBlock(bob);
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                        while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                            cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                            cin >> actionSelect;
                        }
                        if (actionSelect == 'A' or actionSelect == 'a') {
                            turnAttack = archer.getTurnAttack(archer) + archer.getWeapon().getDamage();
                            unblockedDamage = turnAttack - enemyBlock;
                            if (unblockedDamage > 0) {
                                bob.setHealth(bob.getHealth() - unblockedDamage);
                                cout << "You did " << unblockedDamage << " unblocked damage to Bob." << endl;
                                cout << "-------------------------------------------------------------------------------------" << endl;
                            } else {
                                cout << "Bob blocked all of your damage." << endl;
                            }
                        }
                        if (actionSelect == 'B' or actionSelect == 'b') {
                            cout << "You both blocked. No damage was done." << endl;
                        }
                    }

                    battle3.addTurn();
                }
                if (bob.getHealth()<1 && archer.getHealth()>0) {
                    cout << "You have slain Bob E. the Cool and his minions.\nYou have saved the land from the NetBeans takeover!" << endl;
                }
                if (archer.getHealth()<1 && bob.getHealth()>0) {
                    cout << "You have been slain by Bob E. the Cool. The battle lasted " << battle3.getTurns() << " turns." << endl;
                }
            }
            if (archer.getHealth()<1 && lisa.getHealth()>0) {
                cout << "You were slain by Lisa. The battle lasted " << battle2.getTurns() << " turns." << endl;
            }
        }
        if (archer.getHealth()<1 && curtis.getHealth()>0) {
            cout << "You were slain by Curtis. The battle lasted " << battle1.getTurns() << " turns." << endl;
        }


    }
    if (warriorSelection == 'J' or warriorSelection == 'j') {
        Juggernaut jugg;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "Great choice. Now let's get him a weapon. The Juggernaut has two weapons to choose from." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "The first choice is the Shield of Strength. This weapon gives the Juggernaut\n+1 attack damage and +4 block." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "The second choice is the Axe of Annihilation. This weapon gives the Juggernaut\n+4 attack damage and +1 block" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "Select 'S' for the Shield of Strength, or 'A' for the Axe of Annihilation" << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        char weaponSelectJuggernaut;
        cin >> weaponSelectJuggernaut;
        while(weaponSelectJuggernaut != 'S' and weaponSelectJuggernaut != 's' and weaponSelectJuggernaut != 'A' and weaponSelectJuggernaut != 'a'){
            cout << "Please enter either S for Shield of Strength or A for Axe of Annihilation" << endl;
            cin >> weaponSelectJuggernaut;
        }
        if (weaponSelectJuggernaut == 'S' or weaponSelectJuggernaut == 's') {
            Weapon shield = Weapon(1,4);
            jugg.setWeapon(shield);
        }
        if (weaponSelectJuggernaut == 'A' or weaponSelectJuggernaut == 'a') {
            Weapon axe = Weapon(4, 1);
            jugg.setWeapon(axe);
        }
        cout << "Good choice. Now fulfill your destiny and defeat the boss. You look to the west and\nin the distance you can see the boss's stronghold.\nYou grab your weapon and begin the journey..." << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "You enter the stronghold.\nCurtis the TArrible appears." << endl;
        Enemy curtis = Enemy(60,5,20,4,10);
        Battle battle4;
        while (jugg.getHealth() > 0 && curtis.getHealth() > 0) {
            cout << "Turn " << battle4.getTurns() << endl;
            cout << "Your health: " << jugg.getHealth() << endl;
            cout << "Curtis's health: " << curtis.getHealth() << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            int enemyAttack, enemyBlock, enemyDecision, turnAttack, turnBlock, unblockedDamage;
            char actionSelect;
            enemyDecision = battle4.getEnemyIntention(curtis);
            if (enemyDecision == 0) {
                cout << "The enemy intends to attack this turn." << endl;
                enemyAttack = curtis.getTurnAttack(curtis);
                cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                cin >> actionSelect;
                while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                }
                if (actionSelect == 'A' or actionSelect == 'a') {
                    turnAttack = jugg.getTurnAttack(jugg) + jugg.getWeapon().getDamage();
                    curtis.setHealth(curtis.getHealth()-turnAttack);
                    jugg.setHealth(jugg.getHealth()-enemyAttack);
                    cout << "You did " << turnAttack << " unblocked damage to Curtis." << endl;
                    cout << "Curtis did " << enemyAttack << " unblocked damage to you." << endl;
                }
                if (actionSelect == 'B' or actionSelect == 'b') {
                    turnBlock = jugg.getTurnBlock(jugg) + jugg.getWeapon().getBlock();
                    unblockedDamage = enemyAttack - turnBlock;
                    if (unblockedDamage > 0) {
                        jugg.setHealth(jugg.getHealth()-unblockedDamage);
                        cout << "Curtis did " << unblockedDamage << " unblocked damage to you." << endl;
                    }
                    else {
                        cout << "You blocked all of Curtis's damage." << endl;
                        cout << "-------------------------------------------------------------------------------------" << endl;
                    }
                }
            }
            if (enemyDecision == 1) {
                cout << "The enemy intends to block this turn." << endl;
                enemyBlock = curtis.getTurnBlock(curtis);
                cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                cin >> actionSelect;
                while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                }
                if (actionSelect == 'A' or actionSelect == 'a') {
                    turnAttack = jugg.getTurnAttack(jugg) + jugg.getWeapon().getDamage();
                    unblockedDamage = turnAttack - enemyBlock;
                    if (unblockedDamage > 0) {
                        curtis.setHealth(curtis.getHealth() - unblockedDamage);
                        cout << "You did " << unblockedDamage << " unblocked damage to Curtis." << endl;
                        cout << "-------------------------------------------------------------------------------------" << endl;
                    } else {
                        cout << "Curtis blocked all of your damage." << endl;
                    }
                }
                if (actionSelect == 'B' or actionSelect == 'b') {
                    cout << "You both blocked. No damage was done." << endl;
                }
            }

            battle4.addTurn();
        }
        if (curtis.getHealth()<1) {
            cout << "You have slain Curtis. The battle lasted " << battle4.getTurns() << " turns." << endl;
            //--------------_________________________________Battle 2______________________________________________________________________
            cout << "You continue through the stronghold." << endl;
            cout << "-------------------------------------------------------------------------------------" << endl;
            cout << "Lisa the DIONbolical appears." << endl;
            Enemy lisa = Enemy(100,12,22,4,17);
            Battle battle5;
            while (jugg.getHealth() > 0 && lisa.getHealth() > 0) {
                cout << "Turn " << battle5.getTurns() << endl;
                cout << "Your health: " << jugg.getHealth() << endl;
                cout << "Lisa's health: " << lisa.getHealth() << endl;
                cout << "-------------------------------------------------------------------------------------" << endl;
                int enemyAttack, enemyBlock, enemyDecision, turnAttack, turnBlock, unblockedDamage;
                char actionSelect;
                enemyDecision = battle5.getEnemyIntention(lisa);
                if (enemyDecision == 0) {
                    cout << "The enemy intends to attack this turn." << endl;
                    enemyAttack = lisa.getTurnAttack(lisa);
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                    while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                    }
                    if (actionSelect == 'A' or actionSelect == 'a') {
                        turnAttack = jugg.getTurnAttack(jugg) + jugg.getWeapon().getDamage();
                        lisa.setHealth(lisa.getHealth()-turnAttack);
                        jugg.setHealth(jugg.getHealth()-enemyAttack);
                        cout << "You did " << turnAttack << " unblocked damage to Lisa." << endl;
                        cout << "Lisa did " << enemyAttack << " unblocked damage to you." << endl;
                    }
                    if (actionSelect == 'B' or actionSelect == 'b') {
                        turnBlock = jugg.getTurnBlock(jugg) + jugg.getWeapon().getBlock();
                        unblockedDamage = enemyAttack - turnBlock;
                        if (unblockedDamage > 0) {
                            jugg.setHealth(jugg.getHealth()-unblockedDamage);
                            cout << "Lisa did " << unblockedDamage << " unblocked damage to you." << endl;
                        }
                        else {
                            cout << "You blocked all of Lisa's damage." << endl;
                            cout << "-------------------------------------------------------------------------------------" << endl;
                        }
                    }
                }
                if (enemyDecision == 1) {
                    cout << "The enemy intends to block this turn." << endl;
                    enemyBlock = lisa.getTurnBlock(lisa);
                    cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                    cin >> actionSelect;
                    while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                    }
                    if (actionSelect == 'A' or actionSelect == 'a') {
                        turnAttack = jugg.getTurnAttack(jugg) + jugg.getWeapon().getDamage();
                        unblockedDamage = turnAttack - enemyBlock;
                        if (unblockedDamage > 0) {
                            lisa.setHealth(lisa.getHealth() - unblockedDamage);
                            cout << "You did " << unblockedDamage << " unblocked damage to Lisa." << endl;
                            cout << "-------------------------------------------------------------------------------------" << endl;
                        } else {
                            cout << "Lisa blocked all of your damage." << endl;
                        }
                    }
                    if (actionSelect == 'B' or actionSelect == 'b') {
                        cout << "You both blocked. No damage was done." << endl;
                    }
                }

                battle5.addTurn();
            }
            if (lisa.getHealth()<1) {
                cout << "You have slain Lisa. The battle lasted " << battle5.getTurns() << " turns." << endl;
//_______________________________________________________Battle 3___________________________________________________________
                cout << "You make your way into the final chamber of the stronghold and\nfind Bob E. the Cool waiting for your arrival..." << endl;
                cout << "-------------------------------------------------------------------------------------" << endl;
                Enemy bob = Enemy(200,5,25,13,18);
                Battle battle6;
                while (jugg.getHealth() > 0 && bob.getHealth() > 0) {
                    cout << "Turn " << battle6.getTurns() << endl;
                    cout << "Your health: " << jugg.getHealth() << endl;
                    cout << "Bob's health: " << bob.getHealth() << endl;
                    cout << "-------------------------------------------------------------------------------------" << endl;
                    int enemyAttack, enemyBlock, enemyDecision, turnAttack, turnBlock, unblockedDamage;
                    char actionSelect;
                    enemyDecision = battle6.getEnemyIntention(bob);
                    if (enemyDecision == 0) {
                        cout << "The enemy intends to attack this turn." << endl;
                        enemyAttack = bob.getTurnAttack(bob);
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                        while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                            cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                            cin >> actionSelect;
                        }
                        if (actionSelect == 'A' or actionSelect == 'a') {
                            turnAttack = jugg.getTurnAttack(jugg) + jugg.getWeapon().getDamage();
                            bob.setHealth(bob.getHealth()-turnAttack);
                            jugg.setHealth(jugg.getHealth()-enemyAttack);
                            cout << "You did " << turnAttack << " unblocked damage to Bob." << endl;
                            cout << "Bob did " << enemyAttack << " unblocked damage to you." << endl;
                        }
                        if (actionSelect == 'B' or actionSelect == 'b') {
                            turnBlock = jugg.getTurnBlock(jugg) + jugg.getWeapon().getBlock();
                            unblockedDamage = enemyAttack - turnBlock;
                            if (unblockedDamage > 0) {
                                jugg.setHealth(jugg.getHealth()-unblockedDamage);
                                cout << "Bob did " << unblockedDamage << " unblocked damage to you." << endl;
                            }
                            else {
                                cout << "You blocked all of Bob's damage." << endl;
                                cout << "-------------------------------------------------------------------------------------" << endl;
                            }
                        }
                    }
                    if (enemyDecision == 1) {
                        cout << "The enemy intends to block this turn." << endl;
                        enemyBlock = bob.getTurnBlock(bob);
                        cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                        cin >> actionSelect;
                        while(actionSelect != 'A' and actionSelect != 'a' and actionSelect != 'B' and actionSelect != 'b') {
                            cout << "Would you like to attack or block? Select 'A' for attack, or 'B' for block: " << endl;
                            cin >> actionSelect;
                        }
                        if (actionSelect == 'A' or actionSelect == 'a') {
                            turnAttack = jugg.getTurnAttack(jugg) + jugg.getWeapon().getDamage();
                            unblockedDamage = turnAttack - enemyBlock;
                            if (unblockedDamage > 0) {
                                bob.setHealth(bob.getHealth() - unblockedDamage);
                                cout << "You did " << unblockedDamage << " unblocked damage to Bob." << endl;
                                cout << "-------------------------------------------------------------------------------------" << endl;
                            } else {
                                cout << "Bob blocked all of your damage." << endl;
                            }
                        }
                        if (actionSelect == 'B' or actionSelect == 'b') {
                            cout << "You both blocked. No damage was done." << endl;
                        }
                    }

                    battle6.addTurn();
                }
                if (bob.getHealth()<1 && jugg.getHealth()>0) {
                    cout << "You have slain Bob E. the Cool and his minions.\nYou have saved the land from the NetBeans takeover!" << endl;
                }
                if (jugg.getHealth()<1 && bob.getHealth()>0) {
                    cout << "You have been slain by Bob E. the Cool. The battle lasted " << battle6.getTurns() << " turns." << endl;
                }
            }
            if (jugg.getHealth()<1 && lisa.getHealth()>0) {
                cout << "You were slain by Lisa. The battle lasted " << battle5.getTurns() << " turns." << endl;
            }
        }
        if (jugg.getHealth()<1 && curtis.getHealth()>0) {
            cout << "You were slain by Curtis. The battle lasted " << battle4.getTurns() << " turns." << endl;
        }

    }
    return 0;
}
