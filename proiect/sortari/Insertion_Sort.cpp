#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void InsertionSort(int v[] , int n){
    for(int i = 1; i < n; i++){
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
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
    InsertionSort(a.data(), n);
    for (int x : a)
        fout << x << " ";
    return 0;
}
