#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;

  auto remainder = m;
  auto num_dimes = m / 10;
  remainder -= (10 * num_dimes);
  auto num_nickels = remainder / 5;
  remainder -= (5 * num_nickels);
  auto num_cents = remainder; 
  n = num_dimes + num_nickels + num_cents;
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
