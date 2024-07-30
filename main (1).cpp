
/******************************************************************************
Author: Homero Ruiz
Date: April 20, 2024
Purpose: Make a character creator using the Character class
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Character.h"
using namespace std;

// size of complete_spell_list.txt
const int SPELL_DOC_SIZE = 46;

// -------------------------------------------------
// Name: readInSpells
// Parameters: pass-by-value string filename
//             string array arr
//             pass-by-value int arr_size
// Returns: bool - true when successful, false otherwise
// Purpose: Opens the file with filename and reads in spells line-by-line into the array arr of size arr_size
// -------------------------------------------------
bool readInSpells(string filename, string arr[], int arr_size){
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << std::endl;
        return false;
    }

    string line;
    int i = 0;
    while (getline(file, line) && i < arr_size) {
        arr[i] = line;
        i++;
    }

    file.close();
    
    // Check if we have read all spells or if there are more spells than the array size
    if (i == arr_size) {
        return true; // Successfully read all spells
    } else {
        cout << "Error: Not all spells were read or array size exceeded." << endl;
        return false;
    }
}

int main()
{
    /* YOU SHOULD NOT CHANGE CODE BELOW THIS LINE UNLESS TO UNCOMMENT IT */

    // declare and initialize needed variables
    string all_spells[SPELL_DOC_SIZE];
    for (int i = 0; i < SPELL_DOC_SIZE; i++)
        all_spells[i] = "Empty";
    
    string character_name = "";
    string character_class = "";
    int character_level, choice = 0;
    bool makeAnother = false;

    // Testing methods...
    cout << "Testing readInSpells()..." << endl;
    if (readInSpells("complete_spell_list.txt", all_spells, SPELL_DOC_SIZE))
    {
        cout << "Read in spells successfully" << endl << endl;
    }

    cout << "Testing constructor..." << endl;
    Character magnus;
    magnus.print();
    cout << endl;

    cout << "Testing parameterized constructor..." << endl;
    Character merle("Merle", "Cleric", 1, true);
    merle.generateSpellList(all_spells, SPELL_DOC_SIZE);
    merle.print();
    cout << endl;

    cout << "Testing copy constructor..." << endl;
    Character merle2(merle);
    merle2.print();
    cout << endl;

    cout << "Testing setters..." << endl;
    magnus.setName("Magnus");
    magnus.setClassName("Fighter");
    magnus.setIsCaster(false);
    magnus.setLevel(3);
    magnus.setStats(18, 14, 15, 10, 11, 12);
    magnus.setSingleStat(Character::STR, 20);
    magnus.generateHitPoints();
    magnus.print();
    cout << endl;

    cout << "Testing saveCharacterSheet()..." << endl;
    if (magnus.saveCharacterSheet())
    {
        cout << "Successfully saved character sheet." << endl << endl;
    }

    /* YOU SHOULD NOT CHANGE CODE ABOVE THIS LINE UNLESS TO UNCOMMENT IT*/

    /* WHERE CHARACTER CREATOR BEGINS! */
    /** YOUR CODE GOES BELOW! */

    // Welcome user
    cout << "Welcome to the Basic DnD Character Creator!" << endl;

    do {
        // Prompt user for character name
        cout << "What do you want to name your character?" << endl;
        getline(cin, character_name);

        // Prompt user for character class
        cout << "What class do you want your character to be?" << endl;
        cout << "\t1. Fighter" << endl;
        cout << "\t2. Rogue" << endl;
        cout << "\t3. Wizard" << endl;
        cout << "\t4. Cleric" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                character_class = "Fighter";
                break;
            case 2:
                character_class = "Rogue";
                break;
            case 3:
                character_class = "Wizard";
                break;
            case 4:
                character_class = "Cleric";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        // Prompt user for character level
        cout << "What level is your character?" << endl;
        cin >> character_level;
        cin.ignore();

        // Create character based on input
        bool isCaster = (character_class == "Wizard" || character_class == "Cleric");
        Character character(character_name, character_class, character_level, isCaster);

        // If the character is a caster, generate spell list
        if (isCaster) {
            character.generateSpellList(all_spells, SPELL_DOC_SIZE);
        }

        // Print out the character
        character.print();

        // do...
        do {
            // Print menu
            cout << "Would you like to do anything else?" << endl;
            cout << "\t1. Change stats and regenerate hit points" << endl;
            cout << "\t2. Generate a different spell list" << endl;
            cout << "\t3. No. I'm finished with this character" << endl;
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1: {
                    // Ask if user wants to generate random stats or enter stats
                    cout << "Would you like to..." << endl;
                    cout << "\t1. Generate new random stats" << endl;
                    cout << "\t2. Set all stats by hand" << endl;
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) {
                        // if they want to generate random stats...
                        character.generateRandomStats();
                        character.generateHitPoints();
                    } else if (choice == 2) {
                        // otherwise, if they want to enter stats by hand...
                        int stats[6];
                        cout << "Enter stats (STR, DEX, CON, INT, WIS, CHA) separated by spaces: ";
                        for (int i = 0; i < 6; i++) {
                            cin >> stats[i];
                        }
                        cin.ignore();
                        character.setStats(stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);
                        character.generateHitPoints();
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                        continue;
                    }
                    break;
                }
                case 2: {
                    // if the character is a spellcaster...
                    if (character.getIsCaster()) {
                        // generate a new spell list
                        character.generateSpellList(all_spells, SPELL_DOC_SIZE);
                    } else {
                        // otherwise (if the character ISN'T a spellcaster)
                        // Print out message to user that their character isn't a caster
                        cout << "This character isn't a caster! They don't have a spell list." << endl;
                    }
                    break;
                }
                case 3:
                    // while the user isn't finished with their character
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }

            // Print out the character again after modifications
            character.print();
        } while (choice != 3);

        // Prompt the user if they would like to save or scrap their character
        cout << "What would you like to do now that " << character_name << " is finished?" << endl;
        cout << "\t1. Save character" << endl;
        cout << "\t2. Scrap character and start over" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            // if they choose to save their character...
            if (character.saveCharacterSheet()) {
                cout << character_name << " successfully saved!" << endl;
            } else {
                cout << "Error saving character sheet." << endl;
            }

            // Prompt user to see if they want to make another character
            cout << "Would you like to make another character?" << endl;
            cout << "\t1. Yes" << endl;
            cout << "\t2. No" << endl;
            cin >> choice;
            cin.ignore();
            if (choice == 1) {
                makeAnother = true;
            } else {
                makeAnother = false;
            }
        } else if (choice == 2) {
            makeAnother = true;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (makeAnother);

    // Print goodbye message
    cout << "Thanks for using the Character Creator! Happy rolling!" << endl;

    return 0;
}
