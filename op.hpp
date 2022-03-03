#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <sstream>

class Op : public Base {
    private:
	double value;
	std::ostringstream strs;
    public:
        Op(double val) : Base() { value = val; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { strs << value; return strs.str(); }
	virtual int number_of_children() { return 0; }
	virtual Base* get_child(int i) { return nullptr; }
	void accept(Visitor* visitor, int index) { visitor->visit_op(this); }
};

#endif //__OP_HPP__
