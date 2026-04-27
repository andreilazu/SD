/*
    5.1.4 Problem 4
Consider a set of n people, numbered from 0 to n − 1. You have access to a
function knows(i, j) that returns true iff person i knows person j. We call i
a celebrity if everyone else knows i and i does not know anyone else. Find an
O(n) algorithm to identify the celebrity (assuming knows runs in O(1) time)
*/

#include <iostream>

using namespace std;

int knows(int i ,int j)
{
    // This is a mock implementation of the knows function for testing purposes.
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int i = 0 , j=1;
    while(j < n)
    {
        if(knows(i,j) == 1){
            i=j;
            j++;
        }
        else
            j++;
    }
    cout << j;
    // j e celebritatea
}