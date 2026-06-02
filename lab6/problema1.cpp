/*
RMQ
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <fstream>

using namespace std;

const int LOG = 20;

struct Node {
    map<char, int> next;
    int pass = 0;
    int end = 0;
};

struct Trie {
    vector<Node> v;
    unordered_map<int, int> tin;
    vector<vector<int>> up;
    vector<int> parent;

    Trie() {
        v.push_back({});
        up.push_back(vector<int>(LOG, 0));
        parent.push_back(0);
    }

    int insert(const string& s)
    {
        int node = 0;

        for (char c : s)
        {
            if (!v[node].next.count(c))
            {
                v[node].next[c] = v.size();
                v.push_back({});
                up.push_back(vector<int>(LOG, 0));
                parent.push_back(node);
            }

            node = v[node].next[c];
        }

        v[node].end++;
        return node;
    }

    void dfs(int node, int depth = 0)
    {
        tin[node] = depth;

        for (int i = 1; i < LOG; i++)
            up[node][i] = up[up[node][i - 1]][i - 1];

        for (auto& p : v[node].next)
        {
            int child = p.second;
            up[child][0] = node;
            dfs(child, depth + 1);
        }
    }

    int lca(int a, int b)
    {
        if (tin[a] < tin[b])
            swap(a, b);

        int diff = tin[a] - tin[b];

        for (int k = LOG - 1; k >= 0; k--)
            if (diff & (1 << k))
                a = up[a][k];

        if (a == b)
            return a;

        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[a][k] != up[b][k])
            {
                a = up[a][k];
                b = up[b][k];
            }
        }

        return up[a][0];
    }

    int query(vector<int>& nodes)
    {
        int cur = nodes[0];

        for (int i = 1; i < nodes.size(); i++)
            cur = lca(cur, nodes[i]);

        return tin[cur];
    }
};

int main()
{
    ifstream fin("ratina.in");
    ofstream fout("ratina.out");

    int N, M;
    fin >> N >> M;

    Trie t;
    vector<int> wordNode(N);

    for (int i = 0; i < N; i++)
    {
        string s;
        fin >> s;
        wordNode[i] = t.insert(s);
    }

    t.dfs(0, 0);

    while (M--)
    {
        int k;
        fin >> k;

        vector<int> nodes(k);

        for (int i = 0; i < k; i++)
        {
            int x;
            fin >> x;
            nodes[i] = wordNode[x - 1];
        }

        fout << t.query(nodes) << "\n";
    }

    return 0;
}
