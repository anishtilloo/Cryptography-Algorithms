// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 2 Hybrid

#include <bits/stdc++.h>
using namespace std;

int main(){

    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-2" <<endl;
    cout << endl;

    string plainText;
    cout << "Enter plain Text : " << endl;
    getline(cin, plainText);
    
    // m is no of columns
    int m;
    int sizeOfPlainText = plainText.length();

    cout << "Size of Plain Text : " << sizeOfPlainText << endl;

    // m is no of columns
    cout << "Enter the size of key : " << endl;
    cin >> m;

    int noOfRows = (sizeOfPlainText / m) + 1;

    // add padding
    if (noOfRows*m > sizeOfPlainText)
    {
        int difference = (noOfRows*m) - sizeOfPlainText;
        for (int i = 0; i < difference; i++)
        {
            plainText.append("x");
        }
    }

    cout << "Plain Text with padding : " << plainText << endl; 
    

    cout << "Number of Rows : " << noOfRows << endl;
    int key[m];
    cout << "Enter the key : " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> key[i];
    }

    // iterator to insert the plain text in the matrix
    int k = 0;    
    string plainTextMatrix[noOfRows][m];

    // conversion of plain text into matrix
    cout << "Plain Text to matrix : " << endl;
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            plainTextMatrix[i][j] = plainText[k];
            k++;
        }
    }
    

    // printing of plain text matrix
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << plainTextMatrix[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Encrypted Matrix : " << endl;

    string encryptedMatrix[noOfRows][m];

    for (int i = 0; i < m; i++)
    {
        int key1 = key[i] - 1;
        for (int j = 0; j < noOfRows; j++)
        {
            swap(encryptedMatrix[j][i], plainTextMatrix[j][key1]);
        }
        
    }

    // printing encrypted matrix
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << encryptedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    string encryptedText;
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            encryptedText.append(encryptedMatrix[i][j]);
        }
    }

    cout << "Encrypted Text : " << encryptedText << endl;
    



    // Decryption

    // key generation
    int decKey[m];
     
    // swapping the contents of the array with its index's
    for (int i = 0; i < m; i++)
    {
        int temp = i;
        decKey[key[i] - 1] = temp + 1;
    }

    // printing the decryption key
    cout << "Decryption Key " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << decKey[i] << " ";
    }
    cout << endl;

    cout << "Decrypted Matrix : " << endl;

    string decryptedMatrix[noOfRows][m];

    // loop for decryption the matrix by swapping with the help of decryption key
    for (int i = 0; i < m; i++)
    {
        int decKey1 = decKey[i] - 1;
        for (int j = 0; j < noOfRows; j++)
        {
            swap(decryptedMatrix[j][i], encryptedMatrix[j][decKey1]);
        }
        
    }

    // printing of decryption matrix
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << decryptedMatrix[i][j] << " ";
        }
        cout << endl;
    }


    // conversion of decrypted text matrix into decrypted text
    string decryptedText;
    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < m; j++)
        {
            decryptedText.append(decryptedMatrix[i][j]);
        }
    }

    cout << "Decrypted Text : " << decryptedText << endl;

    // remove padding
    if (noOfRows*m > sizeOfPlainText)
    {
        int difference = (noOfRows*m) - sizeOfPlainText;
        for (int i = 0; i < difference; i++)
        {
            decryptedText.pop_back();
        }
    }

    cout << "Original Messages : " << decryptedText << endl;

    return 0;
}