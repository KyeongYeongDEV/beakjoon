#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int x = 0;
	vector<int> array;
	cin >> x;
	for (int i = 0; i < x; ++i)
	{
		int input_num;
		cin >> input_num;
		array.push_back(input_num);
	}
	sort(array.begin(), array.end());
	cout << array.back() << endl;

	return 0;
}