// Name: Anish Tilloo
// Roll No: 34
// Sec: A
// Practical 3 Extended Euclidean Algorithm

#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; 
	int gcd = gcdExtended(b%a, a, &x1, &y1);

	*x = y1 - (b/a) * x1;
	*y = x1;

	return gcd;
}

int main()
{
    cout << "Name: Anish Tilloo" << endl;
    cout << "Section: A  Roll No. 34" << endl;
    cout << "Batch: A2" << endl; 
    cout << "Practical-3" <<endl;
    cout << endl;

	int x, y, a, b;
    cout << "Enter the two numbers" << endl;
    cin >> a >> b;
    
	int g = gcdExtended(a, b, &x, &y);
	cout << "GCD(" << a << ", " << b << ") = " << g << endl;
	return 0;
}
