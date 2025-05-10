#include<iostream>
#include<string>
#define MOD 26
using namespace std;

string AutoKeyDecryption(string &cipherText, int &key)
{
    string plaintext;
    char lastAlpha = '\0';

    for (char ch : cipherText)
    {
        if (isalpha(ch))
        {
            int C = toupper(ch) - 'A';
            // cout<<"value of C is: "<<C<<endl;
            int K = (lastAlpha == '\0') ? key : toupper(lastAlpha) - 'A';
            // cout<<"value of K is: "<<K<<endl;
            int P = (C - K + MOD) % MOD;
            // cout<<"value of P is: "<<P<<endl;
            char decryptedChar = tolower('A' + P);
            plaintext.push_back(decryptedChar);
            lastAlpha = decryptedChar; 
           
        }
        else
        {
            plaintext.push_back(ch); 
        }
    }
    return plaintext;
}

int main()
{
    string cipherText;
    cout << "Enter the message in UPPERCASE which you want to decrypt: ";
    getline(cin, cipherText);
    
    for (char &c : cipherText){
        c = toupper(c); 
    }
    int key;
    cout << "Enter the key value: ";
    cin >> key;

    cout << "Decrypted Message (lowercase): " << AutoKeyDecryption(cipherText, key) << endl;
    return 0;
}
