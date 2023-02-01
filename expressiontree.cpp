#include "expressiontree.h"

ExpressionTree::ExpressionTree()
{
}

EpTr ExpressionTree::newNode(string _string)
{
    EpTr n = new node;
    n->data = _string;
    n->left = n->right = nullptr;
    return n;
}

bool ExpressionTree::checkOperator(string _string, stack<string>& stCr)
{
    if (stCr.empty())
        return false;
    else {
        if (stCr.top() == "(")
            return false;
        else {
            if (_string != "^") {
                if (stCr.top() == "/" || stCr.top() == "*" || stCr.top() == "^") {
                    return true;
                } else {
                    if (_string == "+" || _string == "-")
                        return true;
                }
            }
        }
    }
    return false;
}

bool ExpressionTree::checkOperand(string _string)
{
    if (_string != ")" && _string != "(" && _string != "-" && _string != "+" && _string != "*" && _string != "/" && _string != "^") {
        return true;
    }
    return false;
}

EpTr ExpressionTree::build_tree(vector<string>& expr)
{
    stack<EpTr> stNo;
    stack<string> stCr;

    EpTr t, t1, t2;

    for (int i = 0; i < (int)expr.size(); i++) {
        if (expr.at(i) == "(") {
            stCr.push(expr.at(i));
        } else if (checkOperand(expr.at(i))) {
            t = newNode(expr.at(i));
            stNo.push(t);
        } else if (expr.at(i) != ")") {

            while (checkOperator(expr.at(i), stCr)) {
                t = newNode(stCr.top());
                stCr.pop();

                t1 = stNo.top();
                stNo.pop();

                t2 = stNo.top();
                stNo.pop();

                t->left = t2;
                t->right = t1;

                stNo.push(t);
            }
            stCr.push(expr.at(i));

        } else if (expr.at(i) == ")") {
            while (!stCr.empty() && stCr.top() != "(") {
                t = newNode(stCr.top());
                stCr.pop();
                t1 = stNo.top();
                stNo.pop();
                t2 = stNo.top();
                stNo.pop();
                t->left = t2;
                t->right = t1;
                stNo.push(t);
            }
            stCr.pop();
        }
    }
    t = stNo.top();
    return t;
}

void ExpressionTree::RPN(EpTr root)
{
    if (root) {
        RPN(root->left);
        RPN(root->right);
        cout << root->data << " , ";
    }
}

bool ExpressionTree::checkFeasibility(string& expr)
{
    if (expr != "")
        if (expr[0] != '(')
            expr = "(" + expr + ")";
    stack<char> s;
    char x;

    for (int i = 0; i < (int)expr.length(); i++) {
        if (expr[i] == '(') {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
            return false;

        if (expr[i] == ')') {
            x = s.top();
            s.pop();
        }
    }

    return (s.empty());
}

vector<string> ExpressionTree::vectorize(string& expr)
{
    vector<string> res;
    int j = 0;
    for (int i = 0; i < (int)expr.length(); i++) {
        int cnt = 0;
        if (isalpha(expr[i]) || isalnum(expr[i])) {
            j = i;
            while (isalpha(expr[j]) || isalnum(expr[j])) {
                cnt++;
                j++;
            }
        } else {
            cnt = 1;
        }

        if (cnt == 1)
            res.push_back(string(cnt, expr[i]));
        else {
            res.push_back(expr.substr(i, cnt));
            i = i + cnt - 1;
        }
    }
    return res;
}
