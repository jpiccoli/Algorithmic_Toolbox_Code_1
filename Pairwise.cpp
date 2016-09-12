// Pairwise.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>

using namespace std;

// For stress testing only
long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * numbers[j] > result) {
         result = ((long long)numbers[i]) * numbers[j];
	  }
    }
  }
  return result;
}

long long MaxPairwiseProductFast(std::vector<int>& vec)
{
  unsigned int size = vec.size();
  int max1 = 0, max2 = 0;

  for( unsigned int i = 0; i < size; ++i )
  {
    if( vec[i] > max1 )
	{
	  if(max2 < max1)
		  max2 = max1;
	  
      max1 = vec[i];
	}
    else if( vec[i] > max2 )
	{
      max2 = vec[i];
	}
  }
  //std::cout << max1 << " " << max2 << std::endl;
  return (long long)( max1 ) * max2;
}

int main(int argc, char* argv[])
{
  // Stress test section
  /*
  while (true) {
	  int n = rand() % 1000 + 2;
	  cerr << n << "\n";
	  vector<int> a;
	  for (int i = 0; i < n; ++i) {
		a.push_back(rand() % 100000);
	  }
	  for (int i = 0; i < n; ++i) {
		cerr << a[i] << ' ';
	  }
	  cerr << "\n";
	  long long res1 = MaxPairwiseProduct(a);
	  long long res2 = MaxPairwiseProductFast(a);
	  if (res1 != res2) {
		cerr << "Wrong answer: " << res1 << ' ' << res2 << "\n";
		break;
	  }
	  else {
		cerr << "OK\n";
	  }
  }  
  */
  
  int n;
  cin >> n;
  vector<int> numbers(n);
  for(int i = 0; i < n; ++i)
    cin >> numbers[i];

  auto result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";

  return 0;
}
