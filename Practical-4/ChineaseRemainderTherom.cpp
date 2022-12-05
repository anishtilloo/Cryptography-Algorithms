// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 4 Chinese Remainder Therom

#include <bits/stdc++.h>
using namespace std;

int CRT(int r1, int r2)
{
    int t1 = 0, t2 = 1, x = r1;
    while (r2 > 0)
    {
        int q = r1 / r2;
        int r = r1 - (q * r2);
        r1 = r2;
        r2 = r;
        int t = t1 - (q * t2);
        t1 = t2;
        t2 = t;
        if (t1 < 0)
        {
            t1 += x;
        }
    }
    return t1;
}

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

int findGCD(int m[], int n, int idx)
{
 int result = m[0];
  for (int i = 1; i < n; i++)
  {
    result = gcd(m[i], result);
 
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}

int main()
{
    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-8" <<endl;
    cout << endl;

    int n, M = 1, x = 0;
    cout << "Enter the number of equations: ";
    cin >> n;

    int a[n], m[n], Mx[n], mul_inverse[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the values for a" << i << " and m" << i <<": ";
        cin >> a[i] >> m[i];
    }

    
    int result = findGCD(m, n, 0);
   
    
    cout << "GCD of m's: " << result << endl;

    if (result == 1)
    {
        // calculating M  M = m1*m2*m3
        for (int i = 0; i < n; i++)
        {
            M *= m[i];
        }
        cout << "M " << M << endl;

        // calculating small m   Mn = M / mn 
        for (int i = 0; i < n; i++)
        {
            Mx[i] = M / m[i];
        }

        for (int i = 0; i < n; i++)
        {
            cout << "Value of M" << i << " " << Mx[i] << endl;
        }
    
        // calculating inverse using extended euclidian algo
        for (int i = 0; i < n; i++)
        {
            mul_inverse[i] = CRT(m[i], Mx[i]);
            cout << "Multiplicative Inverse " << mul_inverse[i] << endl;
        }

        // calculating the value of x
        // x = (a1 * M1 * Minverse1) + ..... + (an * Mn * Minversen) 
        for (int i = 0; i < n; i++)
        {
            x = x + (a[i] * Mx[i] * mul_inverse[i]);
        }
        cout << "Result: " << x % M << "" << endl;

    }
    else {
        cout << "m's are not co-prime!! Please enter co-prime numbers" << endl;
    }
    
    return 0;
}