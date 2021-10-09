#include "assignSHJ986.h"

// A function to check if 'c' is an operator 
bool isOperator(string c) 
{ 
    if (c == "+" || c == "-" ||c == "*" || c == "/" || c == "^") 
        return true; 
    return false; 
} 

//A function to do preorder traversal
void preOrder(et *t)
{
    if (t != NULL)
    {
        cout << " " << t->value;
        preOrder(t->left);
        preOrder(t->right);
    }
}
  
//A function to do inorder traversal 
void inorder(et *t) 
{ 
    if (t != NULL)
    {
        inorder(t->left);
        cout << " "<< t->value;
        inorder(t->right);
    }
} 

//A function to do Postorder traversal
void postOrder(et *t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout << " " << t->value;
    }
}
  
// A function to create a new node 
et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 

 
/* get weight of operators as per precedence 
higher weight given to operators with higher precedence
for non operators, return 0 */
int getWeight(string ch) {

   if(ch == "/" || ch == "*") 
      return 2;  
   else if(ch == "+" || ch == "-")
      return 1;
   else
      return 0; 
}

int applyOp(int a, int b, string op){ 
    if(op == "+")
       return a + b; 
    else if(op == "-")    
       return a - b; 
    else if(op == "*")    
       return a * b; 
    else if(op == "/")
       return a / b;
    else
       return 0; 
    
}

//To check whether the string is a digit or not.
bool Ifdigit(string tokens)
{
        
     for(int i = 0; i < tokens.size(); i++){
         if(isdigit(tokens[i])){
            continue;
         } 
         else
            return false;
         }
         return true;
}

//To check the input and determine the type of input
//Infix or Postfix or Prefix
void validateInputExpression(string input){
     
     string str = input;
     
     int len = str.size();
     //cout << "Length :" << len;
     int i = 0;
     if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')   
         cout << "\nEntered expression is Prefix" << endl;     
     
     else if(input[len - 1] == '+' || input[len - 1] == '-' || input[len - 1] == '*' || input[len - 1] == '/')
         cout << "\nEntered expression is Postfix" << endl;
   
     else
         cout << "\nEntered expression is Infix" << endl;

}  


// convert infix expression to postfix using a stack
bool validateExpression(string input, int size)
{
   char ch;
   int cntr = 0, numctr = 0, optctr = 0;
   
   // iterate over the input expression 
   int i=0;  
   while (i < size) {
	string num="";
	ch = input[i];
 	while(isdigit(ch) && (i<size))
	{ 
	  num = num + ch;
          i++;
          ch = input[i];
	}
        if(num != "")
        {
           numctr++;
           expression.push_back(num);
        }
        if (i == size)
	  break;
        if (ch==' ')
        {
          i++;
          continue;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
          optctr++;
          expression.push_back(string(1,ch));
        }
	else if (ch == '(' || ch == ')')
        {
          expression.push_back(string(1,ch));
          cntr ++;
        }
        else
        {
          cout << "No alpha characters can be included in the expression. Invalid Expression" << endl;
          exit(0);
        }
        i++;
      }

      if (cntr % 2 != 0)
      {
          cout << "Missing brackets. Invalid Expression" << endl;
          exit(0);
      }
      else if (numctr < 2)
      {
          cout << "Too few numbers. Invalid Expression" << endl;
          exit(0);
      }
      else if (numctr >= 2 && optctr < 1)
      {
          cout << "Too few operators. Invalid Expression" << endl;
          exit(0);
      }

      /*cout << "size: " << expression.size() << endl;
      for(i = 0; i < expression.size(); i++)
          cout << expression[i] << endl;*/
 
     
     

}

// convert infix expression to postfix using a stack
void infix2postfix(vector<string> expression, vector<string>& postfix, int size) {
   stack<string> s;
   int weight;
   int i = 0;
   int k = 0;
   string ch;

   // iterate over the infix expression   
   while (i < expression.size()) {
      ch = expression[i];
      if (ch == "(") {
         // simply push the opening parenthesis
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ")") {
         /* if we see a closing parenthesis,
         pop of all the elements and append it to
         the postfix expression till we encounter
         opening parenthesis */
         while (!s.empty() && s.top() != "(") {
            postfix.push_back(s.top());
            s.pop();

         }
         // pop off the opening parenthesis also
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         // we got an operand
         // simply append it to postfix expression
         
         postfix.push_back(ch);

      }
      else {
         // we saw an operator
         if (s.empty()) {
            // simply push the operator onto stack if
            // stack is empty
            s.push(ch);
         }
         else {
            // pop of all the operators from the stack and
            // append it to the postfix expression till we
            // see an operator with a lower precedence that
            // the current operator
            while (!s.empty() && s.top() != "(" && weight <= getWeight(s.top())) {
               postfix.push_back(s.top());
               s.pop();

            }
            // push the current operator onto stack
            s.push(ch);
         }
      }
      i++;
   }
   // pop of the remaining operators present in the stack
   // and append it to postfix expression 
   while (!s.empty()) {
      postfix.push_back(s.top());
      s.pop();
   }
   //postfix[k] = 0; // null terminate the postfix expression 
}  

// Returns root of constructed tree for given 
// postfix expression 
et* constructTree(vector<string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    // Traverse through every character of 
    // input expression 
    for (int i = 0; i < postfix.size(); i++) 
    { 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else // operator 
        { 
            t = newNode(postfix[i]); 
  
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop(); 
  
            //  make them children 
            t->right = t1; 
            t->left = t2; 
  
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
  
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
    //cout << "t value:" << t;
    return t; 
} 

// Function that returns value of 
// expression after evaluation. 
int evaluate(vector<string> tokens){ 
    int i; 
      
    // stack to store integer values. 
    stack <int> values; 
      
    // stack to store operators. 
    stack <string> ops; 
      
    for(i = 0; i < tokens.size(); i++){ 
          
                  
        // Current token is an opening  
        // brace, push it to 'ops' 
        if(tokens[i] == "("){ 
            ops.push(tokens[i]); 
        } 
        
        // Current token is a number, push  
        // it to stack for numbers. 
        else if(Ifdigit(tokens[i])){ 
            //atoi(tokens.c_str());
            int val = atoi(tokens[i].c_str()); 
            values.push(val); 
        } 
         
 
        // Closing brace encountered, solve  
        // entire brace. 
        else if(tokens[i] == ")") 
        { 
            while(!ops.empty() && ops.top() != "(") 
            { 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                string op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // pop opening brace. 
            if(!ops.empty()) 
               ops.pop(); 
        } 
          
        // Current token is an operator. 
        else
        { 
            // While top of 'ops' has same or greater  
            // precedence to current token, which 
            // is an operator. Apply operator on top  
            // of 'ops' to top two elements in values stack. 
            while(!ops.empty() && getWeight(ops.top()) >= getWeight(tokens[i])){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                string op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // Push current token to 'ops'. 
            ops.push(tokens[i]); 
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        string op = ops.top(); 
        ops.pop(); 
                  
        values.push(applyOp(val1, val2, op)); 
    } 
      
    // Top of 'values' contains result, return it. 
    return values.top(); 
} 

// main
int main() {
   cout << "* * * Please read the README file before executing the code * * *" << endl;
   string input;
   int i;
   string postfix_out = "";
   cout << "Enter the expression:";
   getline(cin,input);
   int size = input.length();
   vector<string> postfix;
   validateInputExpression(input);
   bool isValid=validateExpression(input,size);
   infix2postfix(expression,postfix,size);

   for(i = 0; i < postfix.size() ; i++){
   postfix_out = postfix_out + " " + postfix[i];
   }
   cout << "\nPostFix Expression of the given input:: " << postfix_out << endl;
   
   //char Post_fix[postfix_out.length()+1];
   //strcpy(Post_fix,postfix_out.c_str());
   
   et* r = constructTree(postfix); 
   //cout << "\nInfix expression is:" << r; 
   
   cout << "\nInorder of the expression :: ";
   inorder(r);
   
   cout << "\nPreorder of the expression :: ";
   preOrder(r);
   
   cout << "\nPostorder of the expression :: ";
   postOrder(r);
  
   cout << "\nEvaluation of the Input Expression ::" << evaluate(expression) << endl;
   return 0;

}
