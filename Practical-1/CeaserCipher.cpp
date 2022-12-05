// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 1 Ceaser Cipher                                    z

#include <bits/stdc++.h>
using namespace std;

void ceaserCipher(char plainText[], int n, char cipherText[], int shift){
  char letter;
  int letterNo;
  // loop to create Ceaser Cipher
  for (int i = 0; i < n; i++)
  {  
    letterNo = int(plainText[i]) + shift;
    // if shift no is greater than the z the it will circle back to a
    // for small letter 
    if (letterNo > int('z') ) {
      letterNo = letterNo - int('z') ;
      letterNo = (int('a') - 1) + letterNo;
      letter = char(letterNo); 
      cipherText[i] = letter;
    } else
    {
      // char character = plainText[i];
      // && character.isupper()
      if (letterNo > int('Z') && isupper(plainText[i])) {
        // if shift no is greater than the Z the it will circle back to A
        // for Capital letter 
        letterNo = letterNo - int('Z');
        letterNo = (int('A') - 1) + letterNo;
        letter = char(letterNo); 
        cipherText[i] = letter;
      } else {
        letter = char(int(plainText[i]) + shift);
        cipherText[i] = letter;
      }
    }
  }
}

void inputArray(char plainText[], int n) {
  cout << "Plain Text : ";
   for (int i = 0; i < n; i++)
   {
     cin >> plainText[i];
   }
}

int main() {

  cout << "Name: Anish Tilloo" << endl;
  cout << "Section: A  Roll No. 34" << endl;
  cout << "Batch: A2" << endl; 
  cout << "Practical-1" <<endl;
  cout << endl;

  int n;
  cout << "Size of Plain Text" << endl;
  cin >> n;
  char plainText[n];

  inputArray(plainText, n);

  int shift;
  cout << "Shift: ";
  cin >> shift;
  cout << endl;

  char cipherText[n];

  ceaserCipher(plainText, n, cipherText, shift) ;


  cout << "Cipher Text: ";
  for (int i = 0; i < n; i++)
  {
    cout << cipherText[i];
  }
  cout << endl;

  return 0;
}