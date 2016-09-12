#include <iostream>

long long get_fibonacci_small(int n) {
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

int get_period(long long m) {
  int period = 0;
  if (m % 2 == 0) 
  {
    if(m / 2 > 1)
      period = 8 * (m / 2) + 4;
    else
      period = 3; 
  }
  else
  {
    if(((m + 1) / 2) > 1)
      period = 4 * ((m + 1) / 2);
    else
      period = 1;
  }

  return period; 
}

long long get_fibonaccihuge(long long n, long long m) {
  //write your code here
  int period = get_period( n );
  // std::cout << "Period = " << period << std::endl;
  auto smaller_num = n % period;
  auto small_fib_num = get_fibonacci_small( smaller_num );
  return small_fib_num % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
    for(int i = 0; i < 20; ++i )
    {
      std::cout << i << " " << get_period(i) << " " << get_fibonacci_small( i % get_period(i) ) << std::endl;
    }
}
