#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

void radixSort(std::vector<int>& v) {
    if (v.empty()) return;

    int maxVal = 0;

    for (auto x : v)
    {
        maxVal = max(x, maxVal);
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> output(v.size());
        int count[10] = { 0 };

        for (int num : v)
            count[(num / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = v.size() - 1; i >= 0; i--) {
            int digit = (v[i] / exp) % 10;
            output[count[digit] - 1] = v[i];
            count[digit]--;
        }

        v = output;
    }
}

void custom_sort(vector<int>& v) {
    radixSort(v);
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
