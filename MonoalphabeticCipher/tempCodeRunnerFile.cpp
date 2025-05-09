#include<iostream>
#include<string.h>
using namespace std;

string additiveCipherEncrypition(string &plainText, int &key)
{
    string cipherText;
    for(int i=0;i<plainText.length();i++)
    {
        if(isalpha(plainText[i])){

            char lowerChar = tolower(plainText[i]); // ensure lowercase input
            int value = lowerChar - 'a';
            int encryption=(value+key)%26;
            cipherText.push_back(towupper(char('a'+encryption)));
        }
        else{
            cipherText.push_back(plainText[i]);
        }
    }
    return cipherText;
}
int main()
{
    string plainText;
    cout<<"Enter the message which you want to encrypt: ";
    getline(cin,plainText);
    int key;
    cout<<"Enter the key value: ";
    cin>>key;
    cout<<additiveCipherEncrypition(plainText,key);
}