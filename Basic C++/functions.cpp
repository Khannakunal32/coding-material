#include <iostream>
#include <math.h>

using namespace std;

//print prime number between a and b               level 1

// input 1 13
// output 1 2 3 5 7 11 13

bool checkPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
        else
            continue;
    }
    return true;
}

int printPrime(int a, int b)
{

    for (int i = a; i <= b; i++)
    {
        if (checkPrime(i))
            cout << i << " ";
        else
            continue;
    }
    return 0;
}

int main()
{
    int a, b;
    cin >> a >> b;

    printPrime(a, b);

    return 0;
}








//Reverse an integer                     level 1
// 10343
// 34301

int reverseNum(int a)
{
    int x;

    while (a > 0)
    {
        x = a % 10;
        cout << x;
        a = a / 10;
    }

    return 0;
}
int main() {
    int a,b;
    cin>>a;
    reverseNum(a);
    return 0;
}






//Check Armstrong number               level  1 (better then others)
//153
//Armstrong number
int checkArmstrong(int a) {
    int x, sum=0;
    int fixa=a;
    
    while(a>0){
        x=a%10;
        sum= sum+pow(x,3);
        a=a/10;
    }
    
    if(sum==fixa) cout<<"Armstrong number";
    else cout<<"Not-Armstrong number";
    return 0;
}

int main() {
    int a,b;
    cin>>a;
    checkArmstrong(a);
    return 0;
}








//print fibonacci number till n                  //level 1 
// 10
// 0 1 1 2 3 5 8 13 21 34
int printFibonacci(int a) {
    int temp=0, num=1, temp2;
    
    cout<<"0 ";
    for(int i=1; i<a; i++) {
        cout<<num+temp<<" ";
        temp2=num;
        num=temp;
        temp=temp2+temp;
    }
    return 0;
}

int main() {
    int a,b;
    cin>>a;
    printFibonacci(a);
    return 0;
}








//Print Pascal Triangle                      Level 2
// 6
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
// 1 5 10 10 5 1 

int factorial(int a) {
    int fact=1;
    
    if(a==0) return 1;
    
    while(a>0){
        fact*=a;
        --a;
    }

    return fact;
}


int printPascalTriangle(int a) {
    int num;
    
    for(int i=0; i<=a-1; i++) {
        for(int j=0; j<=i; j++) {
            cout<<(factorial(i))/(factorial(j)*factorial(i-j))<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main() {
    int a,b;
    cin>>a;
    printPascalTriangle(a);
    return 0;
}
