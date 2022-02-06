#include <valarray>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	valarray<int>* arr = new valarray<int>(n);
	for (int i = 0; i < n; ++i)
	{
		int elem;
		cin >> elem;
		(*arr)[i] = elem;
	}
	cout << arr->max() * arr->min();
}