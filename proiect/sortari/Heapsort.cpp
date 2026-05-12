#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

void heapify(vector<int>& v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i) {
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}

void heapSort(vector<int>& v) {
    int n = v.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i); // O(1)

    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]); // REMOVE
        heapify(v, i, 0); // rebuild
    }
}

void custom_sort(vector<int>& v) {
    heapSort(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    custom_sort(a);
    
    for (auto x : a)
    {
        cout << x << ' ';
    }

    assert(is_sorted(a.begin(), a.end()));
    return 0;
}
