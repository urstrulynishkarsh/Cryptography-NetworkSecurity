#include<iostream>
#include<string.h>
using namespace std;

string additiveCipherDecrypition(string &cipherText, int &key)
{
    string plainText;
    for(int i=0;i<cipherText.length();i++)
    {
        if(isalpha(cipherText[i])){
            int value=cipherText[i]-'A';
            int encryption=(value-key+26)%26;
            plainText.push_back(towlower(char('A'+encryption)));
        }
        else{
            plainText.push_back(cipherText[i]);
        }
    }
    return plainText;
}
int main()
{
    string cipherText;
    cout<<"Enter the message which you want to encrypt: ";
    getline(cin,cipherText);
    for (char &c : cipherText)
    {
        c = toupper(c);
    }
    int key;
    cout<<"Enter the key value: ";
    cin>>key;
    cout<<additiveCipherDecrypition(cipherText,key);
}