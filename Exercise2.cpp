/**
 * @file Exercise2_kcherry8.cpp
 * @author Kenneth Cherry
 * @date 2026-11-05
 * @brief This program translates English text into Morse Code.
 */

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;


/**
 * @class MorseCode
 * @brief Translates English letters into Morse Code.
 */
class MorseCode
{
private:

    vector<const char*> morse = {
        ".-",      // A
        "-...",    // B
        "-.-.",    // C
        "-..",     // D
        ".",       // E
        "..-.",    // F
        "--.",     // G
        "....",    // H
        "..",      // I
        ".---",    // J
        "-.-",     // K
        ".-..",    // L
        "--",      // M
        "-.",      // N
        "---",     // O
        ".--.",    // P
        "--.-",    // Q
        ".-.",     // R
        "...",     // S
        "-",       // T
        "..-",     // U
        "...-",    // V
        ".--",     // W
        "-..-",    // X
        "-.--",    // Y
        "--.."     // Z
    };

public:

    /**
     * @brief Translates English text into Morse Code.
     * @param text The text entered by the user.
     */
    void translate(char text[])
    {
        cout << "Morse Code: ";

        for (int i = 0; text[i] != '\0'; i++)
        {
            char letter = toupper(text[i]);

            // Only translate letters A through Z.
            if (letter >= 'A' && letter <= 'Z')
            {
                cout << morse[letter - 'A'] << " ";
            }
        }

        cout << endl;
    }
};


/**
 * @class Program
 * @brief Handles user input and controls the program.
 */
class Program
{
public:

    /**
     * @brief Runs the Morse Code translator.
     */
    void run()
    {
        char input[51];
        char again = 'Y';

        cout << "Morse Code Translator" << endl;
        cout << "---------------------" << endl;

        while (again == 'Y' || again == 'y')
        {
            cout << "Enter a sentence (maximum 50 characters): ";
            cin.getline(input, 51);

            // Check if the user entered more than 50 characters.
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Sentence is too long." << endl;
                cout << "Please enter 50 characters or less." << endl;
            }
            else
            {
                MorseCode translator;
                translator.translate(input);
            }

            cout << "Translate another sentence? (Y/N): ";
            cin >> again;

            // Remove the leftover newline.
            cin.ignore(1000, '\n');

            cout << endl;
        }

        cout << "Goodbye!" << endl;
    }
};


/**
 * @brief Starts the Morse Code translator.
 * @return 0 when the program ends.
 */
int main()
{
    Program program;

    program.run();

    return 0;
}