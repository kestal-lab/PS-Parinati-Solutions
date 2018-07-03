#include "rsa.cpp"
int main() {
    srand(time(0));
    cout<<"Enter String not more then 2 characters:"<<endl;
    string s;
    //s.append(1);
    cin>>s;


    ll encryptedString=encrypt(s);
    cout<<"Encrypted String is: "<<encryptedString<<endl;

    string decryptedString=decrypt(encryptedString);
    cout<<endl<<"Decrypted String is: "<<decryptedString<<endl;

    return 0;
}
