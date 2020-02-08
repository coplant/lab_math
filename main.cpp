#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return (cos(x) / x);
}
void processInt(double& h, double& A, double& B, int& count, double& result)
{
	h = (B - A) / (count);
	double intOdd = 0, intEven = 0, iOdd, iEven;
	iOdd = (h + A); iEven = (2 * h + A);
	for (double i = iOdd; i < B; i += 2 * h)
		intOdd += (f(i));
	for (double i = iEven; i < B; i += 2 * h)
		intEven += (f(i));
	result = (h / 3) * (f(A) + f(B) + 4 * intOdd + 2 * intEven);
}

int main()
{
	const double E = 0.00001;
	double intervalA, intervalB, resultInt = 1, tempInt = 0, h = 0, x = 1;
	int countN = 2;
	intervalA = 0.5;
	intervalB = 1.5;
	while (abs(resultInt - tempInt) >= E)
	{
		processInt(h, intervalA, intervalB, countN, tempInt);
		countN *= 2;
		processInt(h, intervalA, intervalB, countN, resultInt);
	}
	cout << "I = " << resultInt << endl;
}
