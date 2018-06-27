#include <iostream>
#include "shapes.h"
#include "Canvas.h"

using namespace std;


// TASKS 1 AND 2 - ADD/MODIFY CODE IN MAIN AS DIRECTED
int main(){

  //Shape 1
  Ellipse e1(3,5);
  e1.setPosition(15,15);

  //Array of pointers to the shapes
  const int NUM_SHAPES = 1;
  Ellipse* shapes[NUM_SHAPES] = {&e1};

  //Draw the shapes to the canvas
  Canvas c;
  int i = 0;
  for(Ellipse **s = shapes; s < shapes + NUM_SHAPES; ++s){
    cout << "Area of shape " << ++i << ": " << (*s)->area() << endl; 
    (*s)->draw(&c);
  }

  //Print out the canvas
  c.print();

}
