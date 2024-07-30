/******************************************************************************
Spring 2024 Programming Foundations I
Author: STUDENT NAME
Date: April ???, 2024
Purpose: Implement the Character class
*******************************************************************************/

#include "Character.h"

using namespace std;

// -------------------------------------------------
// Name: Character
// Parameters: none
// Returns: none
// Purpose: Constructor. Initializes instance variables other than hit points, including giving random stats.
// -------------------------------------------------
Character::Character(){
    
}

// -------------------------------------------------
// Name: Character
// Parameters: pass-by-value string newName
//             pass-by-value string newClassName
//             pass-by-value int newLevel
//             pass-by-value bool newIsCaster
// Returns: none
// Purpose: Parameterized constructor. Initializes instance variables based off parameters.
//          Because we will know the class, level, and stats, it should also initialize the character's hit points.
// -------------------------------------------------
Character::Character(string newName,string newCLassname,int newLevel, bool newIsCaster){
    
}

// -------------------------------------------------
// Name: Character
// Parameters: pass-by-reference Character other
// Returns: none
// Purpose: Copy constructor. Copies all instance variables of other into new Character object
// -------------------------------------------------
Character::Character(Character &other){
    
}

// -------------------------------------------------
// Name: ~Character
// Parameters: none
// Returns: none
// Purpose: Destructor. Frees up memory space at end of program.
// -------------------------------------------------
Character::~Character()
{

}

// -------------------------------------------------
// Name: getName
// Parameters: none
// Returns: string
// Purpose: Gets the Character object's name
// -------------------------------------------------
string Character::getName() const {
    return name;
}

// -------------------------------------------------
// Name: getClassName
// Parameters: none
// Returns: string
// Purpose: Gets the Character object's class
// -------------------------------------------------
string Character::getClassName() const {
    return className;
}

// -------------------------------------------------
// Name: getHitPoints
// Parameters: none
// Returns: int
// Purpose: Gets the Character object's hit points
// -------------------------------------------------
int Character::getHitPoints() const {
    return hitPoints;
}

// -------------------------------------------------
// Name: getLevel
// Parameters: none
// Returns: int
// Purpose: Gets the Character object's level
// -------------------------------------------------
int Character::getLevel() const {
    return level;
}

// -------------------------------------------------
// Name: getStat
// Parameters: pass-by-value int index
// Returns: int
// Purpose: Gets the Character object's stat at the given index
// -------------------------------------------------
int Character::getStat(int index) const {
    return stats[index];
}

// -------------------------------------------------
// Name: getIsCaster
// Parameters: none
// Returns: bool
// Purpose: Gets the Character object's bool that signals if the Character is a spellcaster
// -------------------------------------------------
bool Character::getIsCaster() const {
    return isCaster;
}

// -------------------------------------------------
// Name: setName
// Parameters: pass-by-value string newName
// Returns: none
// Purpose: Sets the Character object's name
// -------------------------------------------------
void Character::setName(string newName) {
    name = newName;
}

// -------------------------------------------------
// Name: setClass
// Parameters: pass-by-value string newClass
// Returns: none
// Purpose: Sets the Character object's class name
// -------------------------------------------------
void Character::setClassName(string newClass) {
    className = newClass;
}

// -------------------------------------------------
// Name: setLevel
// Parameters: pass-by-value int newLevel
// Returns: none
// Purpose: Sets the Character object's level
// -------------------------------------------------
void Character::setLevel(int newLevel) {
    level = newLevel;
}

// -------------------------------------------------
// Name: setStats
// Parameters: pass-by-value int strength
//             pass-by-value int dexterity
//             pass-by-value int constitution
//             pass-by-value int intelligence
//             pass-by-value int wisdom
//             pass-by-value int charisma
// Returns: none
// Purpose: Sets the Character object's stats
// -------------------------------------------------
void Character::setStats(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma) {
    stats[STR] = strength;
    stats[DEX] = dexterity;
    stats[CON] = constitution;
    stats[INT] = intelligence;
    stats[WIS] = wisdom;
    stats[CHA] = charisma;
}

// -------------------------------------------------
// Name: setSingleStat
// Parameters: pass-by-value int index
//             pass-by-value int score
// Returns: none
// Purpose: Sets the score of a single stat for the Character object
// -------------------------------------------------
void Character::setSingleStat(int index, int score) {
    stats[index] = score;
}


// -------------------------------------------------
// Name: setIsCaster
// Parameters: pass-by-value bool newIsCaster
// Returns: none
// Purpose: Sets the Character object's bool that signals if the Character is a spellcaster
// -------------------------------------------------
void Character::setIsCaster(bool newIsCaster) {
    isCaster = newIsCaster;
}

// -------------------------------------------------
// Name: print
// Parameters: none
// Returns: none
// Purpose: Prints out name, class, level, hit points, and stats of Character.
//          If they're a caster, it also prints their spell list.
// -------------------------------------------------
void Character::print() const
{
    cout << "Name: " << name << endl;
    cout << "Class: " << className << endl;
    cout << "Level: " << level << endl;
    cout << "Number of Hit Points: " << hitPoints << endl;
    cout << "Stats:" << endl;
    cout << "\tStrength: " << stats[STR] << endl;
    cout << "\tDexterity: " << stats[DEX] << endl;
    cout << "\tConstitution: " << stats[CON] << endl;
    cout << "\tIntelligence: " << stats[INT] << endl;
    cout << "\tWisdom: " << stats[WIS] << endl;
    cout << "\tCharisma: " << stats[CHA] << endl;

    if (isCaster)
    {
        cout << "Spell List:" << endl;
        for (int i = 0; i < SPELL_LIST_SIZE; i++)
            cout << "\t" << spellList[i] << endl;
    }
}

// -------------------------------------------------
// Name: saveCharacterSheet
// Parameters: none
// Returns: a boolean - true if successful, false otherwise
// Purpose: Saves the name, class, level, hit points, and stats of the Character to a file.
//          If the Character is a caster, it also saves the Character's spell list.
//          The name of the file should be the character's name with the .txt extension.
// -------------------------------------------------
bool Character::saveCharacterSheet()const{
    string filename = name + ".txt";
    ofstream file(filename);
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return false;
    }
    file << "Name: " << name << endl;
    file << "Class: " << className << endl;
    file << "Level: " << level << endl;
    file << "Number of Hit Points: " << hitPoints << endl;
    file << "Stats:" << endl;
    file << "\tStrength: " << stats[STR] << endl;
    file << "\tDexterity: " << stats[DEX] << endl;
    file << "\tConstitution: " << stats[CON] << endl;
    file << "\tIntelligence: " << stats[INT] << endl;
    file << "\tWisdom: " << stats[WIS] << endl;
    file << "\tCharisma: " << stats[CHA] << endl;

    if (isCaster) {
        file << "Spell List:" << endl;
        for (int i = 0; i < SPELL_LIST_SIZE; i++)
            file << "\t" << spellList[i] << endl;
    }

    file.close();
    cout << "Character sheet saved successfully." << endl;
    return true;
}

// -------------------------------------------------
// Name: generateSpellList
// Parameters: string array complete_spells
//             pass-by-value int size
// Returns: none
// Purpose: Randomly fills the spells array with spells from the complete_spells array.
//          There should be NO REPEATS in the spell list.
// -------------------------------------------------
void Character::generateSpellList(const string complete_spells[],const int size){
    
}

// -------------------------------------------------
// Name: generateRandomStats
// Parameters: none
// Returns: none
// Purpose: Generates and assigns a random number from 8 to 20 (inclusive) to each stat in the stats array
// -------------------------------------------------
void Character::generateRandomStats(){
    
}

// -------------------------------------------------
// Name: generateHitPoints
// Parameters: none
// Returns: none
// Purpose: Generates the character's hit points based off their level, class, and constitution score
// -------------------------------------------------
void Character::generateHitPoints()
{
    // if no class has been selected
    if (className == "None selected")
    {
        // output error
        cout << "Error! Class hasn't been set!" << endl;
        // return early
        return;
    }
    
    // initialize hit die
    int hitDie = 0;

    // if the character is a fighter
    if (className == "Fighter")
    {
        // they get a d10
        hitDie = 10;
    }
    // if the character is a rogue or a cleric
    else if (className == "Rogue" || className == "Cleric")
    {
        // they get a d8
        hitDie = 8;
    }
    // if the character is a wizard
    else if (className == "Wizard")
    {
        // they get a d6
        hitDie = 6;
    }

    // calculate stat bonus
    int bonus = -5 + (stats[CON] / 2);

    // initialize sum
    int sum = 0;

    // randomize rand() seed
    srand(time(NULL));

    // at first level, the character gets the highest number from their hit die plus their CON bonus
    sum = hitDie + bonus;

    // if they are higher than level one
    if (level > 1)
    {
        // for each level over 1
        for (int i = 1; i < level; i++)
        {
            // 'roll' the hit die and add the CON bonus
            sum += (rand() % hitDie + 1) + bonus;
        }
    }
    
    // set hit points
    hitPoints = sum;
}

// -------------------------------------------------
// Name: reset
// Parameters: none
// Returns: none
// Purpose: Resets instance variables to 'starter' values.
//          Because class is no longer known, hit points should be 0
// -------------------------------------------------
void Character::reset(){
    
}