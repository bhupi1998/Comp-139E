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
    while (!inputFile.eof()) {
        nextCharacter = inputFile.peek();
        if (isalpha(nextCharacter)) {
            getline(inputFile, line, ' ');
            cout << line << '\n';
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

