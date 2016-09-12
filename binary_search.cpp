#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

/////////////////////////////////////////////////////////////////////////
// Quicksort #1
/////////////////////////////////////////////////////////////////////////
void quicksort(std::vector<int> & arr, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quicksort(arr, left, j);
      if (i < right)
            quicksort(arr, i, right);
}

/////////////////////////////////////////////////////////////////////////
// Quicksort #2
/////////////////////////////////////////////////////////////////////////
void PrintArray(int* array, int n);
void QuickSort(int* array, int startIndex, int endIndex);
int SplitArray(int* array, int pivotValue, int startIndex, int endIndex);
void swap(int &a, int &b);

/* This function swaps two numbers
Arguments :
a, b - the numbers to be swapped
*/
void swap(int &a, int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

/* This function prints an array.
Arguments :
array - the array to be printed
n - number of elements in the array
*/
void PrintArray(int* array, int n)
{
  int i;

  for( i = 0; i < n; i++ ) std::cout << array[i] << '\t';
}

/* This function does the quicksort
Arguments :
array - the array to be sorted
startIndex - index of the first element of the section
endIndex - index of the last element of the section
*/
void QuickSort(int* array, int startIndex, int endIndex)
{
  int pivot = array[startIndex];					//pivot element is the leftmost element
  int splitPoint;

  if( endIndex > startIndex )						 //if they are equal, it means there is
    //only one element and quicksort's job
    //here is finished
  {
    splitPoint = SplitArray(array, pivot, startIndex, endIndex);
    //SplitArray() returns the position where
    //pivot belongs to
    array[splitPoint] = pivot;
    QuickSort(array, startIndex, splitPoint - 1);   //Quick sort first half
    QuickSort(array, splitPoint + 1, endIndex);	 //Quick sort second half
  }
}

/* This function splits the array around the pivot
Arguments :
array - the array to be split
pivot - pivot element whose position will be returned
startIndex - index of the first element of the section
endIndex - index of the last element of the section
Returns :
the position of the pivot
*/
int SplitArray(int* array, int pivot, int startIndex, int endIndex)
{
  int leftBoundary = startIndex;
  int rightBoundary = endIndex;

  while( leftBoundary < rightBoundary )			   //shuttle pivot until the boundaries meet
  {
    while( pivot < array[rightBoundary]		  //keep moving until a lesser element is found
      && rightBoundary > leftBoundary )	  //or until the leftBoundary is reached
    {
      rightBoundary--;						//move left
    }
    swap(array[leftBoundary], array[rightBoundary]);
    //PrintArray(array, ARRAY_SIZE);			 //Uncomment this line for study

    while( pivot >= array[leftBoundary]		  //keep moving until a greater or equal element is found
      && leftBoundary < rightBoundary )	  //or until the rightBoundary is reached
    {
      leftBoundary++;						 //move right
    }
    swap(array[rightBoundary], array[leftBoundary]);
    //PrintArray(array, ARRAY_SIZE);			 //Uncomment this line for study
  }
  return leftBoundary;							  //leftBoundary is the split point because
  //the above while loop exits only when 
  //leftBoundary and rightBoundary are equal
}

/////////////////////////////////////////////////////////////////////////
// Binary Search #1 
/////////////////////////////////////////////////////////////////////////

int binary_search(const vector<int> &a, int key) 
{
  int low = 0;
  int high = a.size() - 1; 

  //write your code here
  while ( low <= high )
  {
    int mid = low + ( ( high - low ) / 2 );
    if ( key < a[ mid ] )
      high = mid - 1;
    else if( key > a[ mid ] )
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

/////////////////////////////////////////////////////////////////////////
// Binary Search #2 
/////////////////////////////////////////////////////////////////////////
int binary_search( const vector<int> a, int low, int high, int key )
{
    if( high < low )
      return -1;
    
    int mid = low + ( ( high - low ) / 2 );
    if( key == a[ mid ] )
      return mid;
    else if ( key < a[ mid ] )
      return binary_search( a, low, mid-1, key );
    else
      return binary_search( a, mid+1, high, key );
}

/////////////////////////////////////////////////////////////////////////
// Binary Search #3 
/////////////////////////////////////////////////////////////////////////
int binary_search( int* a, int low, int high, int key )
{
    if( high < low )
      return -1;
    
    int mid = low + ( ( high - low ) / 2 );
    if( key == a[ mid ] )
      return mid;
    else if ( key < a[ mid ] )
      return binary_search( a, low, mid-1, key );
    else
      return binary_search( a, mid+1, high, key );
}


/////////////////////////////////////////////////////////////////////////
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

/////////////////////////////////////////////////////////////////////////
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  std::sort( a.begin(), a.end() );
  //quicksort( a, 0, a.size() );
  //for( auto const& item : a )
  //  std::cout << item << " ";
  //std::cout << std::endl;

  //for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << binary_search(a, 0, a.size(), b[i]) << ' ';
    //std::cout << binary_search(a, b[i]) << ' ';
    //std::cout << "(i=" << i << ",b[i]=" << b[i] << "): " << binary_search(a, b[i]) << ' ';
  //}
  
  int *arr = new int[a.size()];
  for( unsigned int i = 0; i < a.size(); ++i )
    arr[i] = a[i];

  //QuickSort(arr, 0, a.size()-1);
  //std::sort(a.begin(), a.end());
  //for( auto const& item : a )
  //  std::cout << item << " ";
  //std::cout << std::endl;

  //for( unsigned int i = 0; i < a.size(); ++i )
  //  a[i] = arr[i];

  // Vector version
  //for( int i = 0; i < m; ++i ) {
    //replace with the call to binary_search when implemented
  //  std::cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
  //}

  //std::cout << std::endl

  // Array version
  for( int i = 0; i < m; ++i ) {
    std::cout << binary_search(arr, 0, a.size() - 1, b[i]) << ' ';
  }
}
