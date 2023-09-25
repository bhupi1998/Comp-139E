/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "gradeCalc.h"

/**
 * A reusable function for getting validated in-range numbers.
 * Repeatedly asks for the value if an out-of-range number gets entered
 *
 * @param prompt A string such as "Enter the mark"
 * @param number A pointer to the number we are trying to read
 * @param min The minimum permissible value
 * @param max The maximum permissible value  
 *
 * @return true if the input contains only numeric characters, false otherwise
 */

bool getValidNumber(string prompt, double *value, const double min, const double max) {
    double userInput;
    do { 
        cout << prompt;
        cin >> userInput;
        if (cin.good() == false) {
            cin.clear();
            cin.ignore(255, '\n');
            cout << "Input Data Terminated." << endl << endl;
            return false;
        }
        if (userInput < min || userInput > max) {
            cout << "Number is out of range. Try again." << endl;
        }
    } while (userInput < min || userInput > max);
    *value = userInput;
    return true;
}

/*
 *Converts the mark into a letter grade using the Camosun College's conversions
 * @param mark The mark that is being converted
 * 
 * @return A string with the letter grade
 */
string gradeFromMark(const double mark) {
    string grade;
    if (mark >= 90.0 && mark <= 100.0) {
        grade = "A+";
    } else if (mark >= 85.0 && mark < 90.0) {
        grade = "A";
    } else if (mark >= 80.0 && mark < 85.0) {
        grade = "A-";
    } else if (mark >= 77.0 && mark < 80.0) {
        grade = "B+";
    } else if (mark >= 73.0 && mark < 77.0) {
        grade = "B";
    } else if (mark >= 70.0 && mark < 73.0) {
        grade = "B-";
    } else if (mark >= 65.0 && mark < 70) {
        grade = "C+";
    } else if (mark >= 60.0 && mark < 65) {
        grade = "C";
    } else if (mark >= 50.0 && mark < 60) {
        grade = "D";
    } else if (mark >= 0.0 && mark < 50) {
        grade = "F";
    }
    return grade;
}