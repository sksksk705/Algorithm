#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool Prime[1000000];
bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n);++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void Goldbach(int n)
{
	for (int i = 3; i <= n/2; ++i)
	{
		if (isPrime(i) && isPrime(n - i))
		{
			cout << n << " = " << i << " + " << n - i << '\n';
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong"<<'\n';
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n != 0){
		Goldbach(n);
		cin >> n;
	}
	return 0;
}