#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.out");

void QuickSort(int v[], int st, int dr)
{
    if (st < dr)
    {
        int m = (st + dr) / 2;
        swap(v[st], v[m]);
        int i = st, j = dr, d = 0;
        while (i < j)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
                d = 1 - d;
            }
            i = i + d;
            j -= 1 - d;
        }
        QuickSort(v, st, i - 1);
        QuickSort(v, i + 1, dr);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    fin >> n;
    vector<int> a(n);
    for (int &x : a)
        fin >> x;
    QuickSort(a.data(), 0, n - 1);
    for (int x : a)
        fout << x << " ";
    return 0;
}
