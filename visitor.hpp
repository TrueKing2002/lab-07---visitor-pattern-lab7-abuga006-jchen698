#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

#include "iterator.cpp"

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) = 0;
        virtual void visit_add_middle(Add* node) = 0;
        virtual void visit_add_end(Add* node) = 0;
        virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(Pow* node) = 0;
        virtual void visit_pow_middle(Pow* node) = 0;
        virtual void visit_pow_end(Pow* node) = 0;
};

class VisitorLaTeX : public Visitor {
    private:
	Iterator* i;
	std::string result;

    public:
	std::string PrintLaTeX(Base* ptr) {
		i = new Iterator(ptr);
		result = "";
		for (i->current_index(); !i->is_done(); i->next())
			i->current_node()->accept(this, i->current_index());
		return '$' + result + '$';
	}	
	
	virtual void visit_op(Op* node) { result += '{' +  i->current_node()->stringify() + '}'; }
        virtual void visit_rand(Rand* node) { result += ('{' + i->current_node()->stringify() + '}'); }

	virtual void visit_add_begin(Add* node) { result += "{("; }
        virtual void visit_add_middle(Add* node) { result += '+'; }
        virtual void visit_add_end(Add* node) { result += ")}"; }

        virtual void visit_sub_begin(Sub* node) { result += "{("; }
        virtual void visit_sub_middle(Sub* node) { result += '-'; }
        virtual void visit_sub_end(Sub* node) { result +=  ")}"; }

        virtual void visit_mult_begin(Mult* node) { result += "{("; }
        virtual void visit_mult_middle(Mult* node) { result += "\\cdot"; }
        virtual void visit_mult_end(Mult* node) { result += ")}"; }

        virtual void visit_div_begin(Div* node) { result += "{\\frac"; }
        virtual void visit_div_middle(Div* node) { }
        virtual void visit_div_end(Div* node) { result += "}"; }

        virtual void visit_pow_begin(Pow* node) { result += "{("; }
        virtual void visit_pow_middle(Pow* node) { result += '^'; }
        virtual void visit_pow_end(Pow* node) { result += ")}"; }
};

class VisitMathML : public Visitor {
    private:
        Iterator* i;
        std::string result;
	std::string tab;
	void begin() { result += tab + "<apply>\n"; tab += "  "; result += tab; }
	void end() { tab.resize(tab.size() - 2); result += tab + "</apply>\n"; }

    public:
        std::string PrintMathML(Base* ptr) {
                i = new Iterator(ptr);
                result = "";
		tab = "  ";
                for (i->current_index(); !i->is_done(); i->next())
                        i->current_node()->accept(this, i->current_index());
                return "<math>\n"  + result + "</math>";
        }

        virtual void visit_op(Op* node) { result += tab + "<cn>" +  i->current_node()->stringify() + "</cn>\n"; }
        virtual void visit_rand(Rand* node) { result += tab + "<cn>" + i->current_node()->stringify() + "</cn>\n"; }

        virtual void visit_add_begin(Add* node) { begin(); result += "<plus/>\n"; }
        virtual void visit_add_middle(Add* node) { }
        virtual void visit_add_end(Add* node) { end(); }

        virtual void visit_sub_begin(Sub* node) { begin(); result += "<minus/>\n"; }
        virtual void visit_sub_middle(Sub* node) { }
        virtual void visit_sub_end(Sub* node) { end(); }

        virtual void visit_mult_begin(Mult* node) { begin(); result += "<times/>\n"; }
        virtual void visit_mult_middle(Mult* node) { }
        virtual void visit_mult_end(Mult* node) { end(); }

        virtual void visit_div_begin(Div* node) { begin(); result += "<divide/>\n"; }
        virtual void visit_div_middle(Div* node) { }
        virtual void visit_div_end(Div* node) { end(); }

        virtual void visit_pow_begin(Pow* node) { begin(); result += "<power/>\n"; }
        virtual void visit_pow_middle(Pow* node) { }
	virtual void visit_pow_end(Pow* node) { end(); }
};

#endif //__VISITOR_HPP__
