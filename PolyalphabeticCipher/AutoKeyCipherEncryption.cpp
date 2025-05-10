#include<iostream>
#include<string.h>
#define MOD 26
using namespace std;

string AutoKeyEncrypition(string &plaintext,int &key)
{
    string cipherText;
    char lastChar='\0';
    for(int i=0;i<plaintext.length();i++)
    {
        if(isalpha(plaintext[i]))
        {
            int P=tolower(plaintext[i])-'a';
            int K;
            if(lastChar=='\0')
            {
                K=key;
            }
            else
            {
                K=tolower(lastChar)-'a';
            }
            int C=(P+K)%MOD;
            cipherText.push_back(towupper(char('a'+C)));
            lastChar=plaintext[i];
        }
        else
        {
            cipherText.push_back(plaintext[i]);
        }
    }
    return cipherText;
}
int main()
{
    string plainText;
    cout<<"Enter the message in lower case which you want to encrypt: ";
    getline(cin,plainText);
    int key;
    cout<<"Enter the key value: ";
    cin>>key;
    cout<<AutoKeyEncrypition(plainText,key);
}