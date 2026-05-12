#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

void gnomeSort(vector<int>& v) {
    int index = 0;

    while (index < v.size()) {
        if (index == 0 || v[index] >= v[index - 1]) {
            index++;
        }
        else {
            swap(v[index], v[index - 1]);
            index--;
        }
    }
}

void custom_sort(vector<int>& v) {
    gnomeSort(v);
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
