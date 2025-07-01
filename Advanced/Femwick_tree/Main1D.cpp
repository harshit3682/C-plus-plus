#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> tree;
    int size;

public:
    FenwickTree(int size) : size(size) {
        tree.resize(size + 1, 0);
    }

    void update(int idx, int delta) {
        while (idx <= size) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    int size = 5;
    FenwickTree ft(size);
    std::vector<int> data = {1, 2, 3, 4, 5};

    for (int i = 0; i < size; ++i) {
        ft.update(i + 1, data[i]);
    }

    std::cout << ft.query(3) << std::endl; // Output: 6
    ft.update(3, 3);
    std::cout << ft.query(3) << std::endl; // Output: 9

    return 0;
}
