
#include "expressiontree.h"

int main()
{
	vector<string> strings;
	strings.push_back("a^b*c");
	strings.push_back("a*b*c+d^(e-f)*g");
	strings.push_back("a+b+(c+g)*d");
	strings.push_back("(A*(B+(C/D)))");
	strings.push_back("((A*B)+(C/D))");
	strings.push_back("22^b^(cc/d2/ef-f)^(x*y-m*n)");
    ExpressionTree expression_tree;
    int cnt = 1;
    for(auto _string: strings) {
	    if (expression_tree.checkFeasibility(_string)) {
	        vector<string> expr = expression_tree.vectorize(_string);
	        EpTr root = expression_tree.build_tree(expr);
	        cout << "Reverse Polish Notion of Expr " << cnt << " is: " << endl;
	        expression_tree.RPN(root);
	        cout << endl;
	    } else {
	        cout << "Expr is not balanced with bracket!" << endl;
	    }
	    cnt++;
	    cout << "----------------------------------" << endl;
    }
    return 0;
}
