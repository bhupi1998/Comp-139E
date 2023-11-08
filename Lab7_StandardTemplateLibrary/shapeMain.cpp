/*
 * A main() to demonstrate inheritance, polymorphism, virtual functions,
 * and an abstract class.
 * Uses classes: Shape, Rectangle, and Circle.
 * 
 * File:   shapeMain.cpp
 * Author: dale
 *
 * Created on November 7, 2011, 2:27 PM
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Rectangle.hpp"
#include "Circle.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const int N_SHAPES = 3;
    Circle c1(20.5, 4, 10);
    Rectangle r1(10, 20.7, 8, 8);
    Circle c2(11, 10, 5);
    Circle c3(15, 5, 7);

    vector<Shape*> shapesV;

    try{
    shapesV.push_back(&c1);
    shapesV.push_back(&r1);
    shapesV.push_back(&c2);
    }
    catch(bad_alloc& e ){
        cout<<e.what()<<endl;
        return EXIT_FAILURE;
    }
    
    try{
    shapesV.at(2)->draw();
    }
    catch(out_of_range& e){
        cout<<e.what()<<endl;
        return EXIT_FAILURE;
    }
    Shape* front = shapesV.front();
    Shape* back = shapesV.back();
    cout << "Printing front shape" << endl;
    front->draw();
    cout << "Printing back shape" << endl;
    back->draw();
    cout << "Total objects in vector: " << shapesV.size() << endl;
    shapesV.pop_back();
    cout << "Total objects in vector after pop: " << shapesV.size() << endl;
    cout << "Current capacity of vector pop: " << shapesV.capacity() << endl;
    vector<Shape*>::iterator ptr = shapesV.begin();
    advance(ptr, 2);
    shapesV.insert(ptr, &c3);
    shapesV.at(2)->draw();
    cout<<"Max possible size of vector: "<< shapesV.max_size()<<endl; //throws errors but works??
    
    cout <<"Drawing all shapes:"<<endl;
    for(ptr = shapesV.begin(); ptr<shapesV.end(); ptr++){
        (*ptr)->draw(); //why is this giving a segmentation fault???
    }
    try{
        shapesV.at(shapesV.max_size())=&c3;
    }
    catch(out_of_range& e){
        cout<<e.what()<<endl;
    }

    return EXIT_SUCCESS;
}

