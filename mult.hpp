#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
	Base* left;
	Base* right;
    public:
        Mult(Base* l, Base* r) : Base() { left = l; right = r; }
        virtual double evaluate() { return left->evaluate() * right->evaluate(); }
        virtual std::string stringify() { return '(' + left->stringify() + '*' + right->stringify() + ')'; }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) { if (i == 0) return left; return right; }
};

#endif //__MULT_HPP__
