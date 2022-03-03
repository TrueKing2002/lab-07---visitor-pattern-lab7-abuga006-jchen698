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
	void accept(Visitor* visitor, int index) { if (index == 0) visitor->visit_div_begin(this); else if (index == 1) visitor->visit_div_middle(this); else visitor->visit_div_end(this); }
};

#endif //__DIV_HPP__
