/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gradeCalc.h
 * Author: bhupi
 *
 * Created on September 16, 2023, 7:46 a.m.
 */

#ifndef GRADECALC_H
#define GRADECALC_H
// hpp type for cpp
#include <cstdlib>
#include <iostream>

using namespace std;

const double markMin=0.0;
const double markMax=100.0;

const double weightMin=1.0;
const double weightMax=50.0;

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
bool getValidNumber(string prompt, double *value, const double min, const double max);

/*
 *Converts the mark into a letter grade using the Camosun College's conversions
 * @param mark The mark that is being converted
 * 
 * @return A string with the letter grade
 */
string gradeFromMark(const double mark);

#endif /* GRADECALC_H */

