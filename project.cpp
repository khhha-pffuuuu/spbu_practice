#include <iostream>
#include <vector>
using namespace std;


//Объединение двух отсортированных массивов
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


//Сортировка кучи
vector<int> Heapify(vector<int> a, int i) {
	for (; ;) {
		int prnt_elem = i / 2;
		if (a[i] > a[prnt_elem]) {
			swap(a[i], a[prnt_elem]);
			i = prnt_elem;
		}
		else if (a[i] <= a[prnt_elem] or i == 0) {
			break;
		}
	}

	return a;
}

vector<int> HeapSort(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		int n = a.size() - i - 1;
		a = Heapify(a, n);
		a = Heapify(a, i);
	}

	return a;
}


//Линейная сортировка кучи
vector<int> LinearSort(vector<int> a, vector<int> b = {}) {
	if (a.size() > 0) {
		int max = a[0];
		int size = a.size();
		b.push_back(max);
		swap(a[0], a[size - 1]);
		a.pop_back();
		return LinearSort(HeapSort(a), b);
	}

	return b;
}

int main()
{
	setlocale(LC_ALL, "RU");
	vector <int> first_sorted_vector = { 1, 2, 3, 7, 13 };
	vector <int> second_sorted_vector = { 4, 5, 10, 12, 15, 21 };

	vector <int> merged_vector = MergeSort(first_sorted_vector, second_sorted_vector);

	for (int i = 0; i < merged_vector.size(); i++) {
		cout << merged_vector[i] << " ";
	}
	cout << endl;


	vector <int> heap = { 16, 8, 32, 54, 12, 4, 9, 77, 43, 51 };
	heap = HeapSort(heap);
	heap = LinearSort(heap);

	for (int i = 0; i < heap.size(); i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}
