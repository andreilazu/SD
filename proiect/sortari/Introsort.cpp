#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

void insertionSortRange(vector<int>& v, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= left && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}

void heapifyRange(vector<int>& v, int n, int i, int offset) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[offset + left] > v[offset + largest])
        largest = left;
    if (right < n && v[offset + right] > v[offset + largest])
        largest = right;

    if (largest != i) {
        swap(v[offset + i], v[offset + largest]);
        heapifyRange(v, n, largest, offset);
    }
}

void heapSortRange(vector<int>& v, int left, int right) {
    int n = right - left + 1;
    int offset = left;

    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyRange(v, n, i, offset);

    for (int i = n - 1; i > 0; --i) {
        swap(v[offset], v[offset + i]);
        heapifyRange(v, i, 0, offset);
    }
}

int partitionQuick(vector<int>& v, int left, int right) {
    int m = (left + right) / 2;
    swap(v[left], v[m]);

    int i = left, j = right, d = 0;
    while (i < j) {
        if (v[i] > v[j]) {
            swap(v[i], v[j]);
            d = 1 - d;
        }
        i += d;
        j -= 1 - d;
    }
    return i;
}

void introsort(vector<int>& v, int left, int right, int depthLimit) {
    int size = right - left + 1;

    if (size <= 16) {
        insertionSortRange(v, left, right);
        return;
    }

    if (depthLimit == 0) {
        heapSortRange(v, left, right);
        return;
    }

    int pivot = partitionQuick(v, left, right);
    introsort(v, left, pivot - 1, depthLimit - 1);
    introsort(v, pivot + 1, right, depthLimit - 1);
}

void custom_sort(vector<int>& v) {
    int n = v.size();
    if (n <= 1) return;

    int depthLimit = 2 * int(log2(n));
    introsort(v, 0, n - 1, depthLimit);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a)
        cin >> x;

    custom_sort(a);

    for (auto x : a)
        cout << x << ' ';

    assert(is_sorted(a.begin(), a.end()));
    return 0;
}
