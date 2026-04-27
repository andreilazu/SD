#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

/*5.3.1 Problem 1 – Deque
You are given an array a of n integers. For each contiguous subsequence of k
elements in a, compute the minimum value in that subsequence. Aim for an
O(n) algorithm. The solution can be seen as a generalization of Problem 1 in
the Stacks section.*/

using namespace std;

vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

const int N = 1e5;

int k = 3;

int deq[N], front = 0, back = -1;

int main()
{
    for(int i = 0 ; i < k ; i++)
    {
        while(front <= back && v[deq[back]] >= v[i])
            back--;
        deq[++back] = i;
    }
    for(int i = k ; i < v.size() ; i++)
    {
        cout << v[deq[front]] << " ";
        while(front <= back && deq[front] <= i - k)
            front++;
        while(front <= back && v[deq[back]] >= v[i])
            back--;
        deq[++back] = i;
     }
     cout << v[deq[front]];
}