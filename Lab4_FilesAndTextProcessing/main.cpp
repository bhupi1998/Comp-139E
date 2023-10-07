#include <cstdlib>
#include <iostream>
#include <libgen.h>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try //just wanted to practice try catch exception handling
    {
        if (argc < 2) {
            throw 0;
        } else if (argc > 2) {
            throw 1;
        }
    } catch (int error) {
        if (!error) {
            cout << "Not enough arguments provided" << endl;
        } else {
            cout << "Too many arguments provided" << endl;
        }
        cout << "Usage:" << basename(argv[0]) << " fileName\n";
        exit(EXIT_FAILURE);
    }
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open(argv[1]);
    outputFile.open("OutputFile.txt", ios::app);

    char nextCharacter;
    string line;
    char characterRead;
    while (!inputFile.eof()) {
        nextCharacter = inputFile.peek();
        if (isblank(nextCharacter) || nextCharacter == '/\n' ) {
            inputFile.get(characterRead);
        }
        else if (isalpha(nextCharacter) || ispunct(nextCharacter)) {
            getline(inputFile, line, ' ');
            cout << "Found a " << line.size() << " character word: " << line << endl;
        } else if (isdigit(nextCharacter)) {
            int stringInteger = 0;
            string integerString;
            while (isdigit(nextCharacter)) {
                inputFile.get(characterRead);
                nextCharacter = inputFile.peek();
                integerString = integerString + characterRead;
            }
            cout << "Found an " << integerString.size() << " integer: " << integerString << endl;
        } 
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

