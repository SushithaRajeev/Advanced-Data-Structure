#include <iostream>
#include <cstring>
#include <stack>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<string> expression;

// An expression tree node 
struct et
{ 
    string value; 
    et* left; 
    et* right; 
};
 
bool isOperator(string c);
void preOrder(et *t);
void inorder(et *t);
void postOrder(et *t);
et* newNode(string v);
int getWeight(string ch);
int applyOp(int a, int b, string op);
bool Ifdigit(string tokens);
void validateInputExpression(string input);
bool validateExpression(string input,int size);
void infix2postfix(vector<string> expression, vector<string>& postfix, int size);
et* constructTree(vector<string> postfix);
int evaluate(vector<string> tokens);