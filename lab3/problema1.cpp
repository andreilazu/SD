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
#include <algorithm>

using namespace std;

class HashTable {
private:

    vector<list<int>> table;
    int total_elements;
    int capacity;
    const double MAX_LOAD_FACTOR = 1.0; 

    int hash(int x) const {

        int h = x % capacity;
        if (h < 0) h += capacity;
        return h;
    }

    void resize() {
        int old_capacity = capacity;
        capacity *= 2; 

        vector<list<int>> new_table(capacity);

        for (int i = 0; i < old_capacity; i++) {
            for (int val : table[i]) {
                int new_idx = hash(val);
                new_table[new_idx].push_back(val);
            }
        }
        table = move(new_table);
    }

public:
    HashTable(int initial_capacity = 10) {
        capacity = initial_capacity;
        table.resize(capacity);
        total_elements = 0;
    }

    bool exists(int x) {
        int idx = hash(x);
        for (int val : table[idx]) {
            if (val == x) return true;
        }
        return false;
    }

    void insert(int x) {
        if (exists(x)) return; 

        if (total_elements >= capacity * MAX_LOAD_FACTOR) {
            resize();
        }

        int idx = hash(x);
        table[idx].push_back(x);
        total_elements++;
    }

    void erase(int x) {
        int idx = hash(x);
        auto& bucket = table[idx];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == x) {
                bucket.erase(it);
                total_elements--;
                return;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(35);

    cout << "Exists 10: " << ht.exists(10) << endl; 

    cout << "Exists 50: " << ht.exists(50) << endl; 

    ht.erase(10);
    cout << "Exists 10 after erase: " << ht.exists(10) << endl; 

    return 0;
}