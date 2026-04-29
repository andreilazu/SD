/*3.1.1 Problem 1
Implement a basic hash table using the chaining method. The following methods
should be implemented:
• insert x — O(1) expected time.
• erase x — O(1) expected time.
• exists x — O(1) expected time.
• resize (private method) — O(n) time.
For implementation, you may use list, or implement your own doubly
linked list.
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;


//insert x
//


class hashtable {
	private:
		vector<list<int>> v;
		int modulo = 1;
		void resize(int val)
		{
			vector<list<int>> new_v(val);
			int len = v.size();
			for (int i = 0; i < len; i++)
			{
				for (auto j : v[i])
				{
					int poz = i + v[i].size() * len;
					new_v[poz % val].push_back(j);

				}
			}
			v = new_v;
			modulo = val;
		}
	public:
		hashtable(int val = 30)
		{
			resize(val);
		}
		void insert(int x)
		{
			v[x % modulo].push_back(x);
		}
		bool exists(int x)
		{
			for (auto i : v[x % modulo])
				if (x == i)
					return true;
			return false;
		}
		void erase(int x)
		{
			v[x % modulo].erase(find(v[x % modulo].begin(), v[x % modulo].end(), x));
		}
};


int main()
{
	hashtable v;
	v.insert(10);	
	cout << v.exists(10) << '\n';
	v.erase(10);
	cout << v.exists(10);

}
