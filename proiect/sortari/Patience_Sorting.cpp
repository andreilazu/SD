#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

void patience_sorting(vector<int>& v) {
    vector<vector<int>> piles;

    for (int x : v) {
        int l = 0, r = piles.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (piles[m].back() >= x)
                r = m;
            else
                l = m + 1;
        }

        if (l == piles.size()) {
            piles.push_back({ x });
        }
        else {
            piles[l].push_back(x);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    for (int i = 0; i < piles.size(); ++i) {
        min_heap.push({ piles[i].back(), i });
    }

    int index = 0;

    while (!min_heap.empty()) {

        pair<int, int> top = min_heap.top();
        min_heap.pop();

        int val = top.first;
        int pile_idx = top.second;

        v[index++] = val;

        piles[pile_idx].pop_back();

        if (!piles[pile_idx].empty()) {
            min_heap.push({ piles[pile_idx].back(), pile_idx });
        }
    }
}

void custom_sort(vector<int>& v) {
    patience_sorting(v);
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

    assert(is_sorted(a.begin(), a.end()));
    return 0;
}
