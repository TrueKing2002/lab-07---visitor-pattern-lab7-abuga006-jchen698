#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    private:
	Base* left;
	Base* right;
    public:
        Div(Base* l, Base* r) : Base() { left = l; right = r; }
        virtual double evaluate() { return left->evaluate() / right->evaluate(); }
        virtual std::string stringify() { return '(' + left->stringify() + '/' + right->stringify() + ')'; }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) { if (i == 0) return left; return right; }
};

#endif //__DIV_HPP__
