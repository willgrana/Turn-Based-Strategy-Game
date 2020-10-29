This project is a turn based strategy game that involves the user picking from one of two
characters, and then choosing one of two unique weapons for that character. The parent class is called
Warrior.h. This class includes general fields like health, block, and attack values that all characters
in the game have. From here, I derived three classes: Archer.h, Juggernaut.h, and Enemy.h, all of which
are children of the parent class Warrior. The Juggernaut and Archer classes are characters that the user
can choose from, and the classes have their own constructors that assign their unique health, attack, and
block values. The enemy class, which also is a child of Warrior.h, uses a constructor with arguments
to assign values for health, attack, and block in main.cpp. Enemy.h also includes a method for deciding
whether they will attack or defend, which is simply a 50/50 chance. Our component class is the Weapon class.
Both the Archer and the Juggernaut have private fields that holds a weapon. This is what makes Weapon.h
a component class. The specific weapon modifies attack and block values. Finally, our unrelated class
is Battle.h. Each battle that the user encounters includes the creation of a new battle object. The Battle
class tracks the number of turns in each battle as well as providing the enemy decision for each turn.
