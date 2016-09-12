#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

//int get_majority_element(vector<int> &a, int left, int right) {
//  if (left == right) return -1;
//  if (left + 1 == right) return a[left];
//  //write your code here
//  return -1;
//}
//
//int main() {
//  int n;
//  std::cin >> n;
//  vector<int> a(n);
//  for (size_t i = 0; i < a.size(); ++i) {
//    std::cin >> a[i];
//  }
//  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
//}

// Function to find the candidate for Majority
int findCandidate(std::vector<int> a, int size)
{
  int maj_index = 0, count = 1;
  int i;
  for( i = 1; i < size; i++ )
  {
    if( a[maj_index] == a[i] )
      count++;
    else
      count--;
    if( count == 0 )
    {
      maj_index = i;
      count = 1;
    }
  }
  return a[maj_index];
}

// Function to check if the candidate occurs more than n/2 times
int isMajority(std::vector<int> a, int size, int cand)
{
  int i, count = 0;
  for( i = 0; i < size; i++ )
    if( a[i] == cand )
      count++;
  if( count > size / 2 )
    return 1;
  else
    return 0;
}

int get_majority_element(std::vector<int> &a, int left, int right)
{
  //if( left == right ) return -1;
  //if( left + 1 == right ) return a[left];
  //write your code here
  //return -1;

  int cand = findCandidate(a, a.size());
  if( isMajority(a, a.size(), cand) )
    return 1;
  else
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for( size_t i = 0; i < a.size(); ++i ) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';

  //system("pause");
}
