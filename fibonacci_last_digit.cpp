#include <iostream>

int get_fibonacci_last_digit(int n) {
  //write your code here
  long long fib[] = { 0, 1, 1 };
  for( int i = 2; i <= n; ++i )
  {
	fib[ i % 3 ] = ( ( fib[ ( i - 1 ) % 3 ] % 10 ) + ( fib[ ( i - 2 ) % 3 ] % 10 ) ) % 10;
  }
  return fib[ n % 3 ];
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
