#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    string data;
    struct node *left, *right;
} * EpTr;

class ExpressionTree {
public:
    ExpressionTree();
    EpTr build_tree(vector<string>& expr);
    void RPN(EpTr root);
    bool checkFeasibility(string& expr);
    vector<string> vectorize(string& expr);

private:
    EpTr newNode(string _string);
    bool checkOperator(string _string, stack<string>& stCr);
    bool checkOperand(string _string);
};

#endif // EXPRESSIONTREE_H
