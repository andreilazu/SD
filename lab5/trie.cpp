/*Implement a trie data structure that supports the following operations:
2
• insert s — O(|s|) time.
• erase s — O(|s|) time (note: this should actually modify the trie by
deleting unused nodes).
• longest prefix s — O(|s|) time; return the length of the longest common
prefix between s and any word in the trie.
• count s — O(|s|) time.*/

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include <map>

using namespace std;

const int N = 1e5+1;

struct Node {
    map<char, int> next;
    int pass = 0; 
    int end = 0;
};

struct Trie {
    vector<Node> v;

    Trie() {
        v.push_back({}); // root
    }

    void insert(const string& s) {
        int node = 0;

        for (char c : s) {
            if (!v[node].next.count(c)) {
                v[node].next[c] = v.size();
                v.push_back({});
            }

            node = v[node].next[c];
            v[node].pass++;
        }

        v[node].end++;
    }

    bool search(const string& s) {
        int node = 0;

        for (char c : s) {
            if (!v[node].next.count(c))
                return false;

            node = v[node].next[c];
        }

        return v[node].end > 0;
    }

    bool erase(const string& s) {
        if (!search(s)) return false;

        int node = 0;
        vector<int> path;
        path.push_back(0);

        for (char c : s) {
            node = v[node].next[c];
            path.push_back(node);
        }

        v[node].end--;

        for (int i = 1; i < path.size(); i++) {
            v[path[i]].pass--;
        }

        return true;
    }

    int longest_prefix(const string& s) {
        int node = 0;
        int len = 0;

        for (char c : s) {
            if (!v[node].next.count(c))
                return len;

            node = v[node].next[c];
            len++;

            if (v[node].pass <= 1)  
                return len - 1;
        }

        return len;
    }
    int count(const string& s) {
        int node = 0;

        for (char c : s) {
            if (!v[node].next.count(c))
                return 0;
            node = v[node].next[c];
        }

        return v[node].end;
    }
};

signed main()
{
    Trie t;
    t.insert("cet");
    t.insert("cer");
    cout << t.search("cer") << '\n';
    cout << t.longest_prefix("cer") << '\n';
}
