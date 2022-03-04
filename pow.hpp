#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>

class Pow : public Base {
    private:
	Base* left;
	Base* right;
    public:
        Pow(Base* l, Base* r) : Base() { left = l; right = r; }
        virtual double evaluate() { return pow(left->evaluate(), right->evaluate()); }
        virtual std::string stringify() { return '(' + left->stringify() + "**" + right->stringify() + ')'; }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) { if (i == 0) return left; return right; }
	void accept(Visitor* visitor, int index) { 
		if (index == 0) visitor->visit_pow_begin(this); 
		else if (index == 1) visitor->visit_pow_middle(this); 
		else visitor->visit_pow_end(this); 
	}
};

#endif //__POW_HPP__
