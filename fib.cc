#include <iostream>

// Recursive version
int calc_fib(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}

// Iterative version
long long fibo_iter(int n) {
    if( n == 0 )
      return 0;

    if( n == 1 || n == 2)
      return 1;

    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 3; i <= n; ++i) 
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibo_iter(n) << '\n';
    return 0;
}
