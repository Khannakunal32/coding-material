//output
// sizeof stack x.size()  =>  3

// 3 2 1 
//  swapping x={NULL} and y={10 20 30} x.swap(y) and printing x =>   40 30 20 10 

#include <iostream>
#include <stack>     //header file used

using namespace std;

int main()
{
    stack<int> x;            // defination of a stack
    x.push(1);                  // x.push(val);
    x.push(2);
    x.push(3);
    
    cout<<"\nsizeof stack x.size()  =>  "<<x.size();
    
    
    cout<<"\n\n";
    while(!x.empty()){
        cout<<x.top()<<" ";
        x.pop();
    }
    
    
    cout<<"\n swapping x={NULL} and y={10 20 30} x.swap(y) and printing x =>   ";
    stack<int> y;
    y.push(10);
    y.push(20);
    y.emplace(30);        // emplace  same as push but concept related to cosntrocutor read about it
    
    
    x.swap(y);
    // swap(x,y);        // can also be written like this
    
    while(!x.empty()){               //x.empty()
        cout<<x.top()<<" ";          //x.top()
        x.pop();                    //x.pop()
    }

    return 0;
}
