#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct composite
{
  double ratio;
  int weight;
  int value;
};

bool sort_function(composite c1, composite c2)
{
  return ( c2.ratio < c1.ratio ); 
}

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = weights.size();

  std::vector<double> amounts(n);
  std::vector<composite> all_data;

  auto current_amount = capacity;

  std::vector<double> ratios;

  for( unsigned int i = 0; i < weights.size(); ++i )
  {
    composite comp;
    comp.weight = weights[i];
    comp.value = values[i];
    comp.ratio = (double)values[i] / (double)weights[i];
    all_data.push_back(comp);
  }

  std::sort(all_data.begin(), all_data.end(), sort_function);

  for( auto i = 0; i < n; ++i )
  {
    if( current_amount != 0 )
    {
      int a = std::min(all_data[i].weight, current_amount);
      value = value + (a * all_data[i].ratio);
      all_data[i].weight -= a;
      amounts[i] += a;
      current_amount -= a;
    }
    else
    {
      break;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
