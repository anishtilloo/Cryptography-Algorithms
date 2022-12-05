// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 2 Rail Fence Transposition Cipher

#include<bits/stdc++.h>
using namespace std;

string encryptRailFence(string text, int key)
{
    char rail[key][(text.length())];
 
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
 
    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i=0; i < text.length(); i++)
    {
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
        rail[row][col++] = text[i];
 
        dir_down?row++ : row--;
    }
 
    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
 
    return result;
}
 
string decryptRailFence(string cipher, int key)
{
    char rail[key][cipher.length()];

    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';
 
    bool dir_down;
 
    int row = 0, col = 0;

    for (int i=0; i < cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        rail[row][col++] = '*';

        dir_down?row++ : row--;
    }

    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];
 

    string result;
 
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        dir_down?row++: row--;
    }
    return result;
}   

int main(){
    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-2" <<endl;
    cout << endl;

    string str;
    cout << "Enter the string you want to encrypt :-" << endl;
    getline(cin, str);
    int key;
    cout << "Enter the key (depth) :-" << endl;
    cin >> key;

    string encryptedResultString = encryptRailFence(str, key);
    string cipherToPlain = decryptRailFence(encryptedResultString,key);


    cout << "Encryption :-" << endl;
    cout << encryptedResultString << endl;
    cout << "Decryption :-" << endl;
    cout << cipherToPlain << endl;
    

    return 0;
}

 

 
