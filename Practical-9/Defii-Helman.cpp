// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 9 Diffie-Hellman Algorithm

#include <bits/stdc++.h>
using namespace std;

int powmod (int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1)
			res = int (res * 1ll * a % p),  --b;
		else
			a = int (a * 1ll * a % p),  b >>= 1;
	return res;
}
 
int generatorOfPrimitiveRoot (int p) {
	vector<int> fact;
	int phi = p-1,  n = phi;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);
 
	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
        // &= :- to perform a bitwise operation with the values on the left and right-hand side, and then assign the result to the variable on the left
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}


// this function calculates a ^ b mod(%) c
int calculate(int a, int b, int c) {
    if (b == 1)
    {
        return a;
    }
    else 
    {
        // here int is to define the type of the variable
        return ((int)pow(a, b) % c);
    }
    
}

int main(){

    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-9" <<endl;
    cout << endl;

    // a prime number p and its primitive root q
    int primeNum, primitiveRootOfP;
    cout << "Enter a prime number: " << endl;
    cin >> primeNum;

    primitiveRootOfP = generatorOfPrimitiveRoot(primeNum);
    cout << "Primitive root of prime number " << primeNum << " is " << primitiveRootOfP << endl;

    // Private keys for both the users
    int privateKey1, privateKey2;
    cout << "Enter Private Key for User 1: " << endl;
    cin >> privateKey1;

    // generating public key for user 1
    int publicKey1 = calculate(primitiveRootOfP, privateKey1, primeNum);
    
    cout << "Enter Private Key for User 2: " << endl;
    cin >> privateKey2;

    // generated public key for user 2
    int publicKey2 = calculate(primitiveRootOfP, privateKey2, primeNum);

    // generating secret key after exchange of public keys
    int secretKey1 = calculate(publicKey2, privateKey1, primeNum);
    int secretKey2 = calculate(publicKey1, privateKey2, primeNum);

    cout << "Public Key " << publicKey1 <<endl;
    cout << "Secret Key for user 1 : " << secretKey1 << endl;
    cout << "Public Key " << publicKey2 << endl;
    cout << "Secret Key for user 2 : " << secretKey2 << endl;

    if(secretKey1 == secretKey2){
        cout << "Diffie-Hellman algorithm is sucessfull" << endl;
    } 
    else {
        cout << "Diffie-Hellman algorithm is unsucessfull" << endl;
    }


    return 0;
}