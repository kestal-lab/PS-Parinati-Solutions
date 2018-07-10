#include <iostream>
#include <bits/stdc++.h>
#include "picosha2.h"

using namespace std;

void hashingTest() {
    string st="";
    cout<<"Enter string to hash or else 1 to exit:"<<endl;
    cin>>st;
    while(st!="1")
    {
        string hashedString;
        picosha2::hash256_hex_string(st,hashedString);
        cout<<endl<<endl<<"Entered string length: "<<st.length();
        cout<<"  Entered string: "<<st<<endl;
        cout<<"Hashed  string length: "<<hashedString.length();
        cout<<"  Hashed  string: "<<hashedString<<endl<<endl;


        cout<<"Enter string to hash or else 1 to exit:"<<endl;
        cin>>st;
    }
    return ;
}
