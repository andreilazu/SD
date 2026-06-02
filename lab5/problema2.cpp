/*
You are given an array a of n integers. Find indices i < j that maximize ai⊕. . .⊕
aj , where ⊕ denotes the bitwise XOR operator. Aim for an O(n log(val max))
time and space complexity algorithm.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int BITS = 21;

struct Node {
    int fiu[2];
    int idx;

    Node() {
        fiu[0] = -1;
        fiu[1] = -1;
        idx = -1;
    }
};

struct Trie {
    vector<Node> t;

    Trie() {
        t.push_back(Node());
    }

    void insert(int val, int idx) {
        int node = 0;

        for (int i = BITS; i >= 0; i--) {
            int bit = (val >> i) & 1;

            if (t[node].fiu[bit] == -1) {
                t[node].fiu[bit] = t.size();
                t.push_back(Node());
            }
            node = t[node].fiu[bit];
        }
        t[node].idx = idx;
    }

    int query(int val) {
        int node = 0;

        for (int i = BITS; i >= 0; i--) {
            int bit = (val >> i) & 1;
            int ideal = 1 - bit;

            if (t[node].fiu[ideal] != -1) {
                node = t[node].fiu[ideal];
            }
            else {
                node = t[node].fiu[bit];
            }
        }
        return t[node].idx;
    }
};

int main() {
    ifstream cin("xormax.in");
    ofstream cout("xormax.out");

    int n;
    if (!(cin >> n)) return 0;

    Trie trie;

    int max_global = -1;
    int start_bun = -1, stop_bun = -1;

    int P_curent = 0;

    trie.insert(0, 0);

    vector<int> P(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        P_curent = P_curent ^ x;
        P[i] = P_curent;

        int best_idx = trie.query(P_curent);

        int xor_val = P_curent ^ P[best_idx];

        if (xor_val > max_global) {
            max_global = xor_val;
            start_bun = best_idx + 1;
            stop_bun = i;
        }

        trie.insert(P_curent, i);
    }

    cout << max_global << " " << start_bun << " " << stop_bun << "\n";

    return 0;
}
