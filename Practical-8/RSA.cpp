// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 8 RSA

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int h)
{
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main(){

    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-8" <<endl;
    cout << endl;

    // large prime numbers
    double p , q;
    cout << "Enter the values of p and q" << endl;
    cin >> p >> q;

    double modulus, e;
    cout << "Enter the value of e " << endl;
    cin >> e;

    modulus = p * q;

    double phi = ((p-1)*(q-1));

    // double gcdResult = gcd(e, phi);
    while(e < phi){
        if (gcd(e, phi) == 1)
        {
            break;
        } else {
            e++;
        }
    }
    
    // constant
    int k = 2;
    double  d = (1 + (k * phi)) / e;

     

    double msg;
    cout << "Enter the message " << endl;
    cin >> msg;

    cout << "Message " << msg << endl;
    cout << endl;

    double power1 = pow(msg, e);
    power1 = fmod(power1, modulus);

    cout << "Encrypted Message " <<  power1 << endl;
    cout << endl;

    double power2 = pow(power1, d);
    power2 = fmod(power2, modulus);

    cout << "Original Message " << power2 << endl;
    cout << endl;

    return 0;
}