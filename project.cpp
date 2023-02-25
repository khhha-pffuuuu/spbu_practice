#include <iostream>
#include <vector>
using namespace std;

vector<int> MergeSort(vector<int> a, vector<int> b)
{
	int n = a.size(), m = b.size();
	vector <int> c;
	int a_border = 0, b_border = 0;

	for (int i = 0; i < n + m; i++) {
		if (a_border < n && b_border < m) {
			if (a[a_border] < b[b_border]) {
				c.push_back(a[a_border]);
				a_border += 1;
			}
			else {
				c.push_back(b[b_border]);
				b_border += 1;
			}
		}
		else if (a_border == n) {
			c.push_back(b[b_border]);
			b_border += 1;
		}
		else if (b_border == m) {
			c.push_back(a[a_border]);
			a_border += 1;
		}
	}

	return c;
}

int main()
{
	return 0;
}
