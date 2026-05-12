#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tmp[20001];
void MergeSort(int v[], int st, int dr){
    if (st < dr){
        int m = (st + dr) / 2;
        MergeSort(v, st, m);
        MergeSort(v, m+1, dr);
        int i = st, j = m + 1, k = 0;
        while (i <= m && j <= dr)
            if (v[i] < v[j])
                tmp[++k] = v[i++];
            else
                tmp[++k] = v[j++];
        while (i <= m)
            tmp[++k] = v[i++];
        while (j <= dr)
            tmp[++k] = v[j++];
        for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
			v[i] = tmp[j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    fin >> n;
    vector<int> a(n);
    for (int& x : a)
        fin >> x;
    MergeSort(a.data(), 0, n - 1);
    for (int x : a)
        fout << x << " ";
    return 0;
}
