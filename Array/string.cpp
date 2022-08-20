#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main() {
    
    
    //ways of declaring string
    string str="kunal is the best ";
    cout<<str;                            //kunal is the best
    
    
    string s(10, 'k');
    cout<<endl<<s;                 //kkkkkkkkkk
    
    
    string s1(s);
    cout<<endl<<s1;                 //kkkkkkkk
    

    // //input string using cin (input any sentence)
    // cout<<"\n input a sentence using cin\n";
    // string stri;
    // cin>>stri;
    // cout<<stri;
    
    // cin.ignore();
    
    
    // //input string using getline (input any sentence)
    // cout<<"\n input a sentence usin getline(cin,s3)\n";
    // string s3;
    // getline(cin,s3);
    // cout<<s3;
    
    
    //Concatinating
    string s4="kunal";  string s5="khanna";
    cout<<"\ns4+s5 "<<s4+s5;
    
    s5.append(s4);
    cout<<"\ns5.append(s4) => "<<s5;
    
    //re assigning 
    s4="chhavi";
    s5.assign("arora");
    cout<<"\ns4+s5 after s4=\"chhavi\"  s5.assign(\"arora\") =>"<<s4+s5;
    

    //reversing a string
    s4="kunal";
    reverse(s4.begin(), s4.end());
    cout<<"\n reverse string after reverse(s4.begin(), s4.end()); => "<<s4;
    
    //at()
    str="nincompoo";
    cout<<endl<<str<<"   str[3] "<<str[3];
    cout<<"\nstr.at(3) "<<str.at(3)<<endl;
    
    //push_back()     similarly  pop_back()
    str.push_back('p');
    cout<<"\nstr after str.push_back('p')  => "<<str;

    //begin() end()  return itr
    cout<<"\nfor(auto i=str.begin(); i<=str.end(); i++) cout<<*i;  => ";
    for(auto i=str.begin(); i<=str.end(); i++) cout<<*i;
    
    str.clear(); //clears string
    if(str.empty()) cout<<"\nstr is empty after str.clear() using str.empty()\n";
    
    
    //compare function important
    s1="abc"; string s2="xyz";
    cout<<"\n s1=abc s2=xyz s2.compare(s1) => "<<s2.compare(s1);
    
    
    s2="abc";
    cout<<"\n s1=abc s2=abc s2.compare(s1) => "<<s2.compare(s1);
    

    //uppercase similarly lower case
    string strcase ="hellow world";
    cout<<endl<<strcase<<endl;
    
    transform(strcase.begin(), strcase.end() ,strcase.begin(), ::toupper);
    
    cout<<endl<<strcase<<endl;
    
    //erase() deletes substring part
    str="kunal khanna";
    str.erase(5,1);
    cout<<"\n str=\"kunal khanna\"; str.erase(5,1);   =>  "<<str;
    
    //find()
    
    cout<<"\n str.find(\"khan\")  =>  "<<str.find("khan");
    
    
    //insert()
    cout<<"\n str.insert(5, \"   space added  \") =>  "<<str.insert(5, "   space added  ");

    //resize()
    str.resize(5);
    cout<<"\n str.resize(5)   =>  "<<str;
    
    //length() size()
    cout<<"\n str.length() str.size()   =>"<<str.length()<<" "<<str.size();
    
    
    //substr()
    cout<<"\n str.substr(2,5)   =>  "<<str.substr(2,5);
    
    
    //string to integer stoi()
    string sn="100";
    int x=stoi(sn);
    cout<<"\n sn=\"100\"; int x=stoi(sn);  x+100 =>  "<<x+100;
    
    
    //integer to string
    x=100;
    string ns=to_string(x);
    cout<<"\n x=100   to_string(x)+\"100\" =>  "<<to_string(x)+"100";
    
    
    //sort string
    str="kunal khanna";
    sort(str.begin(),str.end());
    cout<<"\n str=kunal khanna  sort(str.begin(), str.end())   =>  "<<str;
    
    //transform uppercase to lower or viceversa
    str="kunal khanna";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<"\n str=kunal khanna  transform(str.begin(), str.end(), str.begin(), ::toupper);   =>  "<<str;
    

    return 0;
    
}





                                                //'a'-'A'=32   str[i]-=32;  level 1 (only 1 trick)
//upper case to lower case viceversa
//BacDeF
//bACdEf
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main() {
    
    string str="BacDeF";
    cout<<"str=BacDeF  ";
    for(int i=0; i<str.length(); i++) {
        
        if(str[i]>='a' && str[i]<='z') str[i]-=32;
        else if(str[i]>='A' && str[i]<='Z') str[i]+=32;
        
    }
    
    cout<<str;
    
    str="kunal khanna";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<"\n str=kunal khanna  transform(str.begin(), str.end(), str.begin(), ::toupper);   =>  "<<str;
    
    
    return 0;
    
}




                                     //level 3
//print alphabet with max frequency in string
//abcdefghijkalmnop
//a
#include<iostream>
#include<string.h>
#include<algorithm>
#include<limits.h>

using namespace std;

int main() {

    string str="abcdefghijkalmnop";
    // cout<<"str=BacDeF  ";

    //method 1
    sort(str.begin(), str.end());
    
    int count=0, mx=INT_MIN, mx2=INT_MIN, ptr=0;
    
    for(int i=0; i<str.length()-1; i++) {
        if(str[i]==str[i+1]) count++;
        else count=0;
        
        // mx=max(mx,count);
        // if(mx!=mx2) ptr=i;
        // mx2=mx;

        if(mx<count) {
            mx=count;
            ptr=i;
    }
    
    cout<<str[ptr];
    


    //method 2
     int ans[26];
    
    for(int i=0; i<26; i++) ans[i]=0;
    
     for(int i=0; i<str.length(); i++) {
         ans[str[i]-'a']++;
     }
     
     int mx=INT_MIN;
        int mx2=mx;
        char k;
    
    for(int i=0; i<26; i++) {
    //   if(mx<ans[i]){
    //       mx=ans[i];
    //       k='a'+i;
    // }
        mx= max(ans[i], mx);
        if(mx!=mx2) k=i+'a';
        mx2=mx;
       }

    
    cout<<k;
    //method 2 end

    
    return 0;
    
}








//remove consecutive same alphabets             level 1
// input aabdkjfdhkkljfk
// output abdkjfdhkljfk
int main() { 
   string str="aabdkjfdhkkljfk";
    
    //method 1
    for(int i=0; i<str.length()-1; i++) {
        if(str[i]==str[i+1]) str.erase(i,1);
    }
    
    cout<<str;
    
    //method 2    
    char ans[100];
    int cnt=0;
    for(int i=0; i<str.length()-1; i++) {
         if(str[i]!=str[i+1]) {
             ans[cnt]=str[i]; 
             cnt++;
         }
    }
    
    cout<<ans;
    
    return 0;
    
}