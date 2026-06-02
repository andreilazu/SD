/*
AINT
*/
#include <iostream>
#include <fstream>
#define INF 1<<30

using namespace std;

ifstream in("arbint.in");
ofstream out("arbint.out");

const int N = 1 << 18;

int v[N];

void construire(int arbore, int st, int dr)
{
	if (st == dr)
	{
		in >> v[arbore];
		return;
	}
	int m = (st + dr) / 2, fs = arbore * 2, fd = arbore * 2 + 1;
	construire(fs, st, m);
	construire(fd, m + 1, dr);
	v[arbore] = max(v[fs], v[fd]);
}

int interogare(int p, int st, int dr, int a, int b)
{
	if (a <= st && dr <= b)
	{
		return v[p];
	}
	int m = (st + dr) / 2, fs = 2 * p, fd = 2 * p + 1;
	int rez_st = -1 * INF, rez_dr = -1 * INF;
	if (a <= m)
	{
		rez_st = interogare(fs, st, m, a, b);
	}
	if (m + 1 <= b)
	{
		rez_dr = interogare(fd, m + 1, dr, a, b);
	}
	return max(rez_st, rez_dr);

}

void actualizare(int p, int st, int dr, int a, int b)
{
	if (st == dr)
	{
		v[p] = b;
		return;
	}
	int m = (st + dr) / 2, fs = 2 * p, fd = 2 * p + 1;
	if (a <= m)
	{
		actualizare(fs, st, m, a, b);
	}
	else
	{
		actualizare(fd, m + 1, dr, a, b);
	}
	v[p] = max(v[fs], v[fd]);
}

int main()
{
	int n, m, i, a, b, task;
	in >> n >> m;
	construire(1, 1, n);
	for (i = 1; i <= m; i++)
	{
		in >> task >> a >> b;
		if (task == 0) {
			out << interogare(1, 1, n, a, b) << endl;
		}
		else
		{
			actualizare(1, 1, n, a, b);
		}
	}
}
