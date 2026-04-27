/*5.4.2 Problem 2
Given a natural number n, calculate the integer part of √
n. Start with an
O(log n) algorithm. Can you find some better or faster approaches? How many
square roots can your algorithm compute in a given period of time? Explain
your solution.*/

// explanation: we can use binary search to find the largest integer x such that x^2 <= n.
// This will give us the integer part of the square root of n. 
// The time complexity of this algorithm is O(log n) because we are halving the search space in each step.

long long sqrt(long long n) {
    long long x = n;
    while (x * x > n) {
        x = (x + n / x) / 2; // newton type shii
    }
    return x;
}