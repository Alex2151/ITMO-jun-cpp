#include <iostream>
#include <assert.h>

using namespace std;

//class Triangle {
//private:
//  double a;
//  double b;
//  double c;

//public:

//  Triangle(double a_in, double b_in, double c_in)
//    : a(a_in), b(b_in), c(c_in) {

//    // Тело функции пустое
//  }

//  Triangle()
//    : a(1), b(1), c(1) { }
//};



//class Triangle {
//public:
//  Triangle(double a_in, double b_in, double c_in)
//    : a(a_in), b(b_in), c(c_in) {
//    // Be assertive!
//    assert(0 < a && 0 < b && 0 < c);
//    assert(a + b > c  &&  a + c > b  &&  b + c > a);
//  }

//  Triangle(double side_in)
//    : a(side_in), b(side_in), c(side_in) {
//    // Be assertive!
//    assert(0 < a && 0 < b && 0 < c);
//    assert(a + b > c  &&  a + c > b  &&  b + c > a);
//  }

////  Triangle(double side_in)
////    : Triangle(side_in, side_in, side_in) { }

//private:
//  double a;
//  double b;
//  double c;

//};


//class Triangle {

//public:

//  Triangle(double a_in, double b_in, double c_in)
//    : a(a_in), b(b_in), c(c_in) {
//    // Be assertive!
//    assert(0 < a && 0 < b && 0 < c);
//    assert(a + b > c  &&  a + c > b  &&  b + c > a);
//  }

////do
////  Triangle(double side_in)
////    : Triangle(side_in , side_in, side_in) {
////  }

////don't
//  Triangle(double side_in) {
//    Triangle(side_in , side_in, side_in);
//  }

////private:

//  double a;
//  double b;
//  double c;

//};



//int main()
//{
//    Triangle tr1(3);

//    cout << tr1.a << endl;
//}





class Rectangle {

private:
  double w, h;

public:

  Rectangle()
   : Rectangle(1, 1) { }

  Rectangle(double s)
   : Rectangle(s, s) { }


  Rectangle(double w_in, double h_in)
      : w(w_in), h(h_in) { }

  double area() const {
      return w * h;
  }

  double perimeter() const {
      return 2 * (w + h);
  }

};

int main()
{
    Rectangle rt(3);

//    cout << tr1.a << endl;
}
