/*5.1.4 Problem 4 - Statistici de Ordine
Given an array, a, of n integers and a positive number k, find the k-th smallest
value in a. Aim for an O(n) time complexity algorithm. What is the space
complexity of your algorithm?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream in("sdo.in");
ofstream out("sdo.out");

int n, k;   
vector<int> v;

int partition(int stanga, int dreapta, int k)
{
    if (stanga == dreapta)
        return v[stanga];

    int mij = stanga + (dreapta - stanga) / 2;
    std::swap(v[mij], v[dreapta]); 

    int poz = stanga;
    for (int i = stanga; i < dreapta; i++)
    {
        if (v[i] <= v[dreapta]) {
            std::swap(v[i], v[poz]);
            poz++;
        }
    }
    std::swap(v[poz], v[dreapta]); 

    if (poz == k)
        return v[poz];
    else if (k > poz)
        return partition(poz + 1, dreapta, k);
    else
        return partition(stanga, poz - 1, k);
}

int main()
{
    cin >> n >> k;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    k = k - 1;
    // alegem un subarray
    // luam un pivot (el de la mijloc)
    // partitionam array-ul bazat pe marimea pivotului
    int rez = partition(0, n - 1 , k);
    cout << rez;
    return 0;
}