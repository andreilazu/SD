/*5.1.6 Problem 6 – Bonus
You are given an array a of n integers, along with an operation f that is associative (e.g., bitwise OR, bitwise AND, min, max, etc.) and has an identity
element. You are also given a positive integer k. For each contiguous subsequence of length k, compute the value of f applied to all elements in that
subsequence. Find an O(n) time and space complexity algorithm, assuming
f(a, b) runs in O(1) time.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

int f(int a, int b)
{
    return a ^ b;
}

vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

const int k = 3;

const int N = 1e5;

vector<int> prefix(N, 0);
vector<int> suffix(N, 0);

int main()
{
    int l = v.size();
    for (int i = 0; i < l; i++) {
        if (i % k == 0) {
            prefix[i] = v[i];
        } else {
            prefix[i] = f(prefix[i - 1], v[i]);
        }
    }

    for (int i = l - 1; i >= 0; i--) {
        if (i == l - 1 || (i + 1) % k == 0) {
            suffix[i] = v[i];
        } else {
            suffix[i] = f(v[i], suffix[i + 1]);
        }
    }

    int querry_left = 0 , querry_right = k-1;
    while(querry_right < l)
    {
        int ans = f(suffix[querry_left], prefix[querry_right]);
        cout << ans << " ";
        querry_left++;
        querry_right++;
    }
}