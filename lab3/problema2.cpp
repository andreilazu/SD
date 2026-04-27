/*
3.1.3 Problem 3
You are given a list of n strings of length m, over an alphabet of constant size
(for example, lowercase English letters). Design an efficient hashing method for
these strings. Try to optimize not only asymptotic time complexity, but also
constant factors.
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <cstring>
#define infi 999999

using namespace std;

ifstream in("hashuri.in");
ofstream out("hashuri.out");

#define cin in
#define cout out

const int N = 2e6+1;

int P = 91;

int MOD1 = 100007;
int MOD2 = 100021;

char A[N], B[N];
int marked[N];

signed main()
{
	cin >> A >> B;
	int AN, BM;
	AN = strlen(A);
	BM = strlen(B);
	int hashA1 = 0 , hashA2 = 0;
	int P1 = 1, P2 = 1;
	for (int i = 0; i < AN; i++)
	{
		hashA1 = (hashA1 * P + A[i]) % MOD1;
		hashA2 = (hashA2 * P + A[i]) % MOD2;
		if (i != 0)
		{
			P1 = P * P1 % MOD1;
			P2 = P * P2 % MOD2;
		}
	}
	if (AN > BM)
	{
		cout << "0\n";
		return 0;
	}
	int hashB1=0, hashB2=0;
	for (int i = 0; i < AN; i++)
	{
		hashB1 = (hashB1 * P + B[i]) % MOD1;
		hashB2 = (hashB2 * P + B[i]) % MOD2;
	}
	int nr = 0;
	for (int i = AN; i < BM; i++)
	{
		hashB1 = ((hashB1 - (B[i - AN] * P1) % MOD1 + MOD1) * P + B[i]) % MOD1;
		hashB2 = ((hashB2 - (B[i - AN] * P2) % MOD2 + MOD2) * P + B[i]) % MOD2;
		if (hashB1 == hashA1 && hashB2 == hashA2)
		{
			nr++;
			marked[i - AN + 1] = i; // i unde incepe , AN lungimea
		}
	}
	cout << nr << "\n";
	nr = 0;
	for (int i = 0; i < BM && nr < 1000; i++)
	{
		if (marked[i])
		{
			nr++;
			cout << i << ' ';
		}
	}

}