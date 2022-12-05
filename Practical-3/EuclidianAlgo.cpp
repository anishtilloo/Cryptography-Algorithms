// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 3 Euclidean Algorithm

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-3" <<endl;
    cout << endl;

    int a, b;
    cout << "Enter the two numbers" << endl;
    cin >> a >> b;

    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    
    return 0;
}