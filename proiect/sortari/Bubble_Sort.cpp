#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void BubbleSort(int v[], int n) {
    bool schimb = true;
    while (schimb) {
        schimb = false;
        for (int i = 0; i < n - 1; i++)
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                schimb = true;
            }
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
    BubbleSort(a.data(), n);
    for (int x : a)
        fout << x << " ";
    return 0;
}
