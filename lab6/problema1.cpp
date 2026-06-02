/*
RMQ
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>  

using namespace std;

ifstream in("rmq.in");
ofstream out("rmq.out");

#define cin in
#define cout out

const int N = 1e5 + 1, LOGN = 20;

int A[N], lg[N];
int M[N][LOGN];

int n, q;

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        M[i][0] = i;
    }
    A[0] = 9999999;
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << (j - 1)) <= n; i++)
        {
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
            {
                M[i][j] = M[i][j - 1];
            }
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        int k = log2(b - a + 1);
        cout << min(A[M[a][k]], A[M[b - (1 << k) + 1][k]]) << '\n';
    }
}
