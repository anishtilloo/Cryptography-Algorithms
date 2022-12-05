// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 1 Ceaser Cipher   

#include<bits/stdc++.h> 
using namespace std;
 
int main()
{   
  cout << "Name: Anish Tilloo" << endl;
  cout << "Section: A  Roll No. 34" << endl;
  cout << "Batch: A2" << endl; 
  cout << "Practical-1" <<endl;
  cout << endl;
  
  char message[100], ch;
  int i, key;
  cout << "Enter a message to decrypt: ";
  cin.getline(message, 100);
  cout << "Enter key: ";
  cin >> key;
  for(i = 0; message[i] != '\0'; ++i){
    ch = message[i];
    if(ch >= 'a' && ch <= 'z'){
        ch = ch - key;
        if(ch < 'a'){
            ch = ch + 'z' - 'a' + 1;
        }
        message[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z'){
        ch = ch - key;
        if(ch > 'a'){
            ch = ch + 'Z' - 'A' + 1;
        }
        message[i] = ch;
    }
  }
  cout << "Decrypted message: " << message;
  return 0;
}