#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
	Base* left;
	Base* right;
    public:
        Sub(Base* l, Base* r) : Base() { left = l; right = r; }
        virtual double evaluate() { return left->evaluate() - right->evaluate(); }
        virtual std::string stringify() { return '(' + left->stringify() + '-' + right->stringify() + ')'; }
	virtual int number_of_children() { return 2; }
        virtual Base* get_child(int i) { if (i == 0) return left; return right; }
};

#endif //__SUB_HPP__
