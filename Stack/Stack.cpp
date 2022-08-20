//Stack basic implementation

//output
// a.push(1)  a.push(2)  a.push(3)
// a.Top()  =>  3
// a.pop()  a.pop()  a.pop() a.pop() 

//  No element available to pop..
// a.Top()  =>  
//  No element available in stack..
// -1
// Stack is empty

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define n 100

class Stack {
    int* arr;
    int top;
    
    public:
    
    Stack(){
        arr = new int[n];
        top= -1;
    }
    
    void push(int x){ 
        if(top==n-1){ cout<<"\n Stack Overflow..\n";
            return;
        }
        top++;
        arr[top]=x;
    }
    
    void pop(){
        if(top==-1){
            cout<<"\n No element available to pop..\n";
            return;
        }
        top--;
    }
    
    int Top(){
      if(top==-1){
          cout<<"\n No element available in stack..\n";
          return -1;
      }
      return arr[top];  
    }
    
    bool empty() {
        return top==-1;
    }
};



int main()
{
   Stack a;
   cout<<"a.push(1)  a.push(2)  a.push(3)\n";
   a.push(1);
   a.push(2);
   a.push(3);
   
   cout<<"a.Top()  =>  "<<a.Top();
   
   cout<<"\na.pop()  a.pop()  a.pop() a.pop() \n";
   a.pop();
   a.pop();
   a.pop();
   a.pop();

   cout<<"a.Top()  =>  "<<a.Top();
   
   (a.empty())?cout<<"\nStack is empty\n":cout<<"\nStack is not empty\n";

    return 0;
}






//reverse a string using stack               level 1
//for input Hey! How are you buddy? Wanna have fun ?
//output
// ? fun have Wanna buddy? you are How Hey! 

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void ReverseStringWithStack(string s){
    stack <string> x;
    
    for(int i=0; i<s.length(); i++) {
        
    string word="";
    
        while(s[i]!=' ' && i<s.length()){
            word=word+s[i];
            i++;
        }
        x.push(word);
    }
    
     while(x.empty()!=true) {
        cout<<x.top()<<" ";
        x.pop();
    }
    
    
}

int main()
{
    string s="Hey! How are you buddy? Wanna have fun ?";


    ReverseStringWithStack(s);
   
    return 0;
}





//prefix evaluation and postfix evaluation ( almost same minor changes)
//ouput
// postfix expression => 46+2/5*7+ = 32
// prefix expression => -+7*45+20 = 25
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int postfixEval(string s){
    
    stack<int> a;
    int ans;
    
    for(int i=0; i<s.length(); i++){      
        if(isdigit(s[i])==true) {
            a.push(s[i]-'0');
         }else {
            if(s[i]=='+'){
                ans=a.top();
                a.pop();
                ans= ans+ a.top();
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='-'){
                ans=a.top();
                a.pop();
                ans= a.top()-ans;         // lower in stack - upper in stack
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='*'){
                ans=a.top();
                a.pop();
                ans= ans* a.top();
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='/'){
                ans=a.top();
                a.pop();
                ans=  a.top()/ ans;
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='^'){
                ans=a.top();
                a.pop();
                ans=  pow(a.top(),ans);
                a.pop();
                a.push(ans);
            } 
    }
   
}

    return a.top();
}


int prefixEval(string s){
    
    stack<int> a;
    int ans;
  
    
    for(int i=s.length()-1; i>=0; i--){
        if(isdigit(s[i])==true) {
            a.push(s[i]-'0');
         }else {
            if(s[i]=='+'){
                ans=a.top();
                a.pop();
                ans= ans+ a.top();
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='-'){
                ans=a.top();
                a.pop();
                ans= ans-a.top();             // small changes that is ans-top() upar wala stack main neeche is minus hoega ie
                a.pop();                    //upper in stack - lower in stack
                a.push(ans);
            }else 
            if(s[i]=='*'){
                ans=a.top();
                a.pop();
                ans= ans* a.top();
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='/'){
                ans=a.top();
                a.pop();
                ans=  ans/a.top();
                a.pop();
                a.push(ans);
            }else 
            if(s[i]=='^'){
                ans=a.top();
                a.pop();
                ans=  pow(ans,a.top());
                a.pop();
                a.push(ans);
            } 
    }
   
}

    return a.top();
}


int main()
{
    string postfix ="46+2/5*7+";   // 4+6  25+7 32
    // cout<<postfixEval(postfix);
    cout<<"\npostfix expression => "<<postfix<<" = "<<postfixEval(postfix);
    
    string prefix= "-+7*45+20";
    cout<<prefixEval(prefix);
    cout<<"\nprefix expression => "<<prefix<<" = "<<prefixEval(prefix);
    
    return 0;
}





//infix to postfix  and  infix to prefix
//output
//abc/-ak/-*
// *-a/bc-/ak
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int                                          // precision aloting function for operators +-/*^
prec (char a)
{
  if (a == '^')
    return 3;
  else if (a == '*' || a == '/')
    return 2;
  else if (a == '+' || a == '-')
    return 1;
  else
    return -1;
}
                                                // infix to postfix
string
infixToPostfix (string s) 
{
  stack < char >a;
  string res = "";

  for (int i = 0; i < s.length (); i++)
    {

      if (s[i] >= 'a' and s[i] <= 'z' || s[i] >= 'A' and s[i] <= 'Z')
	{
	  res = res + s[i];

	}
      else if (s[i] == '(')
	a.push (s[i]);
      else if (s[i] == ')')
	{
	  while (!a.empty ()and a.top () != '(')
	    {
	      res = res + a.top ();
	      a.pop ();
	    }
	  a.pop ();
	}
      else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] ==
	       '/' or s[i] == '^')
	{

	  while (!a.empty ()and prec (a.top ()) >= prec (s[i]))
	    {
	      res = res + a.top ();
	      a.pop ();
	    }
	  a.push (s[i]);
	}
    }

  while (!a.empty ())
    {
      res = res + a.top ();
      a.pop ();
    }

  return res;
}


string
infixToPrefix (string s) {                   //Infix to prefix
    
    string res= s;
    reverse(res.begin(), res.end());           // reversing the input string
    
    for(int i=0; i<res.length(); i++) {           //  Re-reversing the brackets
        if(res[i]=='(') res[i]=')';
        else if(res[i]==')') res[i]='(';
    }
     
    
    
    res = infixToPostfix(res);                // applying postifix
    reverse(res.begin(), res.end());            // reversing the ans

    return res;
}

int
main ()
{
  // cout<<"Hello World";s
  string str = "(a-b/c)*(a/k-1)";
  cout << infixToPostfix (str)<<endl;
  cout << infixToPrefix (str);

  return 0;
}

