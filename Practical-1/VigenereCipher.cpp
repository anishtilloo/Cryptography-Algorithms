// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 1 Vigenere Cipher

#include<bits/stdc++.h>
using namespace std;

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string str, string key)
{
	int strLen = str.size();

	for (int i = 0; ; i++)
	{
		if (strLen == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// This function returns the encrypted text
// generated with the help of the key
string encryptedCipherText(string str, string key)
{
	string cipherText1;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		char cha = (str[i] + key[i]) % 26;

		// convert into alphabets(ASCII)
		cha = cha + 'A';

		cipherText1.push_back(cha);
	}
	return cipherText1;
}

// This function decrypts the encrypted text
// and returns the original text
string decryptedOriginalText(string cipher_text, string key)
{
	string originalText;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		// converting in range 0-25
		char cha = (cipher_text[i] - key[i] + 26) % 26;

		// convert into alphabets(ASCII)
		cha = cha + 'A';
		originalText.push_back(cha);
	}
	return originalText;
}


int main()
{
    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-1" <<endl;
    cout << endl;

	string str;
    cout << "Enter the string to be encrypted.(please enter in capital letters)" << endl;
    getline(cin, str);

    string keyword;
    cout << "Enter the keyword with which the string will be encrypted.(please enter in capital letters)" << endl;
    cin >> keyword;

	
	string key = generateKey(str, keyword);
	string cipherText = encryptedCipherText(str, key);

	cout << "Ciphertext : "
		<< cipherText << "\n";

	cout << "Original/Decrypted Text : "
		<< decryptedOriginalText(cipherText, key);
	return 0;
}
