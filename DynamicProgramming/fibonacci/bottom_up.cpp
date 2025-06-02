#include <iostream>
using namespace std;

void fibonacci_optimized(int n) {
    if (n <= 0) return;

    int a = 0, b = 1;

    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }

    cout << endl;
}

int main() {
    int n = 5;
    cout << "Fibonacci series (Bottom-Up without Extra Space) up to " << n << " terms:\n";
    fibonacci_optimized(n);
    return 0;
}
