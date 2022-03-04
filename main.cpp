#include <iostream>

#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

using namespace std;

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    cout << minus->stringify() << " = " << minus->evaluate() << endl;
  
    VisitorLaTeX visitor;
    VisitMathML visitor2;
    cout << visitor.PrintLaTeX(minus) << endl;
    cout << visitor2.PrintMathML(minus) << endl << endl;

    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* zero = new Op(0);
    Base* sub = new Sub(five, zero);
    Base* add2 = new Add(one, sub);

    cout << add2->stringify() << " = " << add2->evaluate() << endl;
    cout << visitor.PrintLaTeX(add2) << endl;
    cout << visitor2.PrintMathML(add2) << endl;

    return 0;
}
