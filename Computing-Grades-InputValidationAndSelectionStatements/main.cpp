/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bhupi
 *
 * Created on September 15, 2023, 8:21 a.m.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "gradeCalc.h"

using namespace std;

/*
 * 
 */

#define getMark getValidNumber(markPrompt, &userMarkInput, markMin, markMax)
#define getWeight getValidNumber(weightPrompt, &userWeightInput, weightMin, weightMax)

int main(int argc, char** argv) {

    string markPrompt = "Enter a mark in percentage: ";
    string weightPrompt = "\t  Enter the weight: ";
    double userMarkInput; // why not *userMarkInput???
    double userWeightInput;
    double userMark = 0;
    double userWeight = 0;
    cout<<"This program computes a letter grade from a weighted sum of marks\nFor marks, minimum allowable value is 0, maximum is 100\nFor weights, minimum allowable value is 1, maximum is 50\nThe weights must total 100%\nEnter a non-number (such as 'q') to terminate your list of marks"<<endl<<endl;
    while (getMark && getWeight) {
        userMark = userMarkInput * (userWeightInput / 100) + userMark;
        userWeight = userWeight + userWeightInput;
    }
    if(userWeight<99.9 || userWeight>100.1){
        cout<<"Weights did not add up to 100%.  Try again."<< endl;
    }else{
        cout << "The mark is: " << userMark << " and grade is : " << gradeFromMark(userMark) << endl;
    }
    return 0;
}

