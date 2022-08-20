// #include <bit/stdc++.h>

//output
// default constructor
// kunal
// default constructor
// default constructor

//input (program takes input)
// Name = kunal
// Roll = 6
// gender 1 or 0 = 1

// Name = chhavi
// Roll = 7
// gender 1 or 0 = 0

//output (program again shows output)
// name = kunal
// roll = 6
// gender = 1
// name = chhavi
// roll = 7
// gender = 0


// using b[i].printInfo
// Name = kunal
// roll = 6
// gender = 1

// Name = chhavi
// roll = 7
// gender = 0



// parameterized constructor
// Name = kali
// roll = 100
// gender = 0

// copy constructor

// student d=a


// using bool operator and creating in class checking if d==a   =>  same
// destructor called
// destructor called
// destructor called
// destructor called
// destructor called


#include <iostream>
#include <map>

using namespace std;

class student {
    string name;
    
    public:
    int roll;
    bool gender;
    
    void setName(string s) {               //setter function to set a something in private class
        name =s;
    }
    string getName() {                      //getter
        return name;
    }
    
   void printInfo() {
        cout<<"\nName = "<<name<<endl;
        cout<<"roll = "<<roll<<endl;
        cout<<"gender = "<<gender<<endl;
    }
    
    student() {
        cout<<"\ndefault constructor";
    }
    
     student (string n, int r, bool g) {
        cout<<"\nparameterized constructor";
        name=n; roll=r; gender=g;
    }
    
    student(student &a) {       // operator overloading
        cout<<"\ncopy constructor"; // in defualt copy cunstorctor only pointer are copied , but in our manual copy addresses are also copied
        name= a.name;                   // default copy is shallow copy (changes also occurs in original values), but here it is deep copy changes wont reflect in real values from which copied
        roll= a.roll;
        gender= a.gender;
    }
    
    bool operator == (student &a) {           // to use operator we ne to define operator function
        if(name==a.name and roll==a.roll and gender==a.gender) return true;
        return false;
    }
    
};

int main() {
    
  student a;
  //initialization 1
  a.setName("kunal");
  a.roll=6;
  a.gender=1;
  cout<<endl<<a.getName();
  
  
  //intialization 2
  cout<<"\n\n";
  student b[2];
  int bn=2;
  for(int i=0; i<bn; i++) {
      string str;
     cout<<"\nName = ";     cin>>str; b[i].setName(str);
     cout<<"Roll = ";     cin>>b[i].roll;
     cout<<"gender 1 or 0 = ";     cin>>b[i].gender;
  }
  cout<<"\n";
  for(int i=0; i<bn; i++) {
      cout<<"name = "<<b[i].getName()<<"\n";
      cout<<"roll = "<<b[i].roll<<"\n";
      cout<<"gender = "<<b[i].gender<<"\n";
  }
    
    //initialization 3 
    cout<<"\n\nusing b[i].printInfo";
    for(int i=0; i<bn; i++) b[i].printInfo();
    
    
    //initialization 4
    cout<<"\n\n";
    student c("kali",100,0);
    c.printInfo();
    
    student d=a;       //copy custroctro
    cout<<"\n\nstudent d=a";
    
    //operator
    cout<<"\n\n\nusing bool operator and creating in class checking if d==a   =>  ";
    if(d==a) cout<<"same";
    else cout<<"not same";
    
    return 0;
}


//inheritance and polymorphism
#include <iostream>


using namespace std;



class studentBase {
    private:               // this private part will not go into derived class and cannot be callable in main fucntion
    string name;
    bool int_roll;
    
    protected:             // this protected part will go into derived class but cannot be callable in main fucntion
    int roll;
    double double_roll;
    
    public:                // this private part will go into derived class and is callable in main fucntion
    
    void setRoll(int x){
        cout<<"\n\nthis is setRoll(int x) roll = "<<x;
        roll=x;
        int_roll=true;
    }
    
    void setRoll(double x){
        cout<<"\n\nthis is setRoll(double x) roll = "<<x;
        double_roll=x;
        int_roll=false;
    }
    
     void showRoll() {
        cout<<"\nthis is showRoll =>";
        if(int_roll) cout<<roll;
        else cout<<double_roll;
    }
    
};

class studentDerived: public studentBase {          //derive all the functions in public and protected from studnetBase and put in public section of studentDerived

};            //if we write private infornt of studnetBase then all datamembers and functions can not be callable in main function and will be taken from student base becomes private


int main() {
    
studentDerived sd;
sd.setRoll(5);
sd.showRoll();

sd.setRoll(5.5);
sd.showRoll();

return 0;
    
}



//operator overloading
//output  15 + i15
class Complex {
    
    int real, img;
    
    public:
    Complex(int r=0, int i=0){         // here we need to give default values as 0 or something if the complex obj is created so that it doesnt reuire any parameter while making class , else everytime it will require parameter while declaring an object eg Complex c3(0,0); , but now we can declare like Complex c3;
        real = r;
        img = i;
    }
    
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real +obj.real;
        res.img = img +obj.img;
        return res;
    }
    
    void display() {
        cout<<real<<" + i"<<img<<endl;
    }
    
};

int main() {
    
    Complex c1(5,5), c2(10,10), c3;
    
    c3=c1+c2;
    c3.display();
   
return 0;
    
}





// virtual keyword and runtime compilation
//output 
//this is base class show()
// this is derived class print()
class base {
    public:
    void show() {
        cout<<"\nthis is base class show()";
    }
    virtual void print() {                     // virtual keyword is used here, this causes dynamically binding
        cout<<"\nthis is base class print()";
    }
};

class derived : public base {
    public:
    void show() {
        cout<<"\nthis is derived class show()";
    }
    void print() {
        cout<<"\nthis is derived class print()";
    }
};

int main() {
    
    base *baseptr;
    derived d;
    baseptr = &d;
    
    baseptr -> show();         // this will show accrding to base class 
    baseptr -> print();     // this will show accrding to derived class as virtual keyword is used, this cause dynamically binding means runtime pr jab hamne adress diya
                            //baseptr = &d tab ye program uske bad bind hua or fir uska adress lekr tab run hua. to virtual program ki dynamic binding krta hai .

return 0;
    
}