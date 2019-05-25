/*Daniel Racz
Sorting Program Analysis
CSC331H
Professor Salvati

Description - Program compares the performance of different sorting algorithms on datasets containing integers.
The data set should be sorted in ascending order and the algorithms will use arrays containing 100 or 1000 integers.

The following number distributions will be used:

a.) Completely Random
b.) Almost sorted in ascending order ( about 90% of items are in increasing order, 10% are random)
c.) Almost reversed -  same as b) but in reverse order
d.) Array is sorted except for the last 10%

The following sorting algorithms are used:

•Selection Sort
•Insertion Sort
•Heap Sort
•Merge Sort
•QuickSort

*/

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

int swaps = 0;    // Global Variable for counting swaps in sorting algorithms
int comparisons = 0;  // Global Variable for comparison counts in algorithms.

//Sorting Algorithm Functions used for Analysis
void Merge(int *a, int low, int high, int mid);
void MergeSort(int *a, int low, int high);
void selection(int a[], int length);
void insertionSort(int arr[], int length);
int partition(int a[], int low, int high);
void quickSort(int a[], int low, int high);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

//Functions used to generate arrays with various number distributions
void randomAll(int a[], int length);
void randomLast(int a[], int length);
void almostSorted(int a[], int length);
void almostReversed(int a[], int length);

//Functions for printing unsorted and sorted results seperately
void printUnsorted(int a[], int length);
void printSorted(int a[], int length);
int selections();
int sorting();


int main() {
  int* b;
  int* d;
  b = new int[100];   // Testing 100 integers
  d = new int[1000];  // Testing 1000 integers
  int choice;
  int* test;
  int length = 0;
  int arrayCase;
  int sortCase;

  cout << "How many integers to test - 100 or 1000? " << endl;

  cin >> choice;

  if (choice == 100){
    test = b;
    length = 100;
}
    else {
    test = d;
    length = 1000;
}

    cout << "Select a scenario of integers to arrange " << endl;
    arrayCase = selections();

    cout << "Select a sorting algorithm to perform " << endl;
    sortCase = sorting();


        switch(arrayCase)
        {
        case 1 :randomAll(test,length);
            break;
        case 2 :randomLast(test,length);
            break;
        case 3 :almostSorted(test,length);
            break;
        case 4 :almostReversed(test,length);
            break;
        }

        printUnsorted(test, length);

        switch(sortCase) {
        case 1: selection(test,length);
            break;
        case 2: insertionSort(test,length);
            break;
        case 3: MergeSort(test, 0, length);
            break;
        case 4: quickSort(test, 0, length);
            break;
        case 5: heapSort(test,length);
            break;
        }

        printSorted(test, length);

        std::cout << swaps << " swaps" << std::endl;
        std::cout << comparisons << " comparisons " << std::endl;

        cout << "End" << endl;
        return 0;

}

int selections() {
    int s;

    cout << "1. All Random Integers" << endl;
    cout << "2. All Sorted Except Last 10% " << endl;
    cout << "3. Almost Sorted - 10% Randomly Placed " << endl;
    cout << "4. Almost Sorted - Except in Reverse Order " << endl;
    cin >> s;

    return s;
}

int sorting() {
    int s;

    cout << "1. Selection Sort " << endl;
    cout << "2. Insertion Sort " << endl;
    cout << "3. MergeSort " << endl;
    cout << "4. QuickSort " << endl;
    cout << "5. HeapSort " << endl;
    cin >> s;

    return s;
}

void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
      ++swaps;
      ++comparisons;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
      ++swaps;
      ++comparisons;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
    ++swaps;
    ++comparisons;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
    ++swaps;
    ++comparisons;
	}
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

void selection(int a[], int length) {

  for(int i = 0; i < length - 1; i++)
  {
    int min = i;
    for(int j = i+1; j < length; j++) {
    if(a[j] < a[min]){
    min = j;
    }
    ++comparisons;
    }
    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
    ++swaps;
  }
}

void insertionSort(int arr[], int length)
{
     int key, j;
    for (int i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            ++swaps;
            ++comparisons;
        }
        arr[j + 1] = key;
        ++comparisons;
    }
}

int partition(int a[], int low, int high) {

  int pivotPos = a[high];  // Pivot is chosen at right position.
  int pivot = low - 1;

for(int i = low; i <= high - 1; i++){
    if(a[i] <= pivotPos){
        pivot++;
        std::swap(a[pivot], a[i]);
        ++comparisons;
        ++swaps;
    }
}
std::swap(a[pivot + 1], a[high]);
++swaps;
return (pivot + 1);
}

void quickSort(int a[], int low, int high) {

  if (low < high) {
      ++comparisons;
    int p = partition(a,low,high);

    quickSort(a, low, p-1);
    quickSort(a, p+1, high);
  }
}

void heapify(int arr[], int n, int i)
{
   // Find largest among root, left child and right child
   int largest = i;
   int l = 2*i + 1;
   int r = 2*i + 2;

   if (l < n && arr[l] > arr[largest]){
     largest = l;
     ++comparisons;
   }

   if (r < n && arr[r] > arr[largest]){
     largest = r;
     ++comparisons;
   }
   // Swap and continue heapifying if root is not largest
   if (largest != i)
   {
     std::swap(arr[i], arr[largest]);
     ++swaps;
     ++comparisons;
     heapify(arr, n, largest);
   }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
   // Build max heap
   for (int i = (n / 2 - 1); i >= 0; i--)
     heapify(arr, n, i);

   // Heap sort
   for (int i=n-1; i>=0; i--)
   {
     std::swap(arr[0], arr[i]);
     ++swaps;
     // Heapify root element to get highest element at root again
     heapify(arr, i, 0);
   }
}

void randomAll(int a[], int length) {
int k = 0;
assert(a);                  // Assigning random numbers
srand((unsigned)time(0));
int random;
for (int index = 0; index < length; index++)
 {
	random = (rand() % 100) + 1;
	a[k] = random; k++;
 }
}

void randomLast(int a[], int length) {


    int l = length - (length * .10);   // Calculate first 90% of integers
    int m = length * .10;         // Last 10%
    int n = 1;

assert(a);                  // Assigning random numbers
srand((unsigned)time(0));
int random;

 for (int i = 0; i < l; i++){        // After dispersing 90% of integers, will then calculate last 10% as random.  
  a[i] = n;
  n += 1;
  }
for (int index = 0; index < m; index++){
	random = (rand() % 100) + 1;
	a[l] = random;
  l += 1;
    }
}

void almostSorted(int a[], int length) {

    int index = 0;
    int n = 1;

assert(a);                  // Assigning random numbers
srand((unsigned)time(0));
int random, random2;

 for (int i = 0; i < length; i++){
  a[i] = n;
  n += 1;
  }

while (index < (length * .10)) {
    random = (rand() % length) + 1;
    random2 = (rand() % length) + 1;
	a[random] = random2;
    index++;
}

}

void almostReversed(int a[], int length) {

    int index = 0;
    int n = 0;

assert(a);                  // Assigning random numbers
srand((unsigned)time(0));
int random, random2;

 for (int i = length; i >= 0; i--){
  a[i] = n;
  n += 1;
  }

while (index < (length * .10)) {
    random = (rand() % length) + 1;
    random2 = (rand() % length) + 1;
	a[random] = random2;
    index++;
}
}

void printUnsorted(int a[], int length) {

     std::cout << "-------------Unsorted----------" << std::endl;
  for(int i = 0; i < length; i++)
  {
    std::cout << a[i] << std::endl;
  }
}
void printSorted(int a[], int length) {

  int count = 0;

   std::cout << "-------------Sorted----------" << std::endl;
  for(int i = 0; i < length; i++)
  {
    ++count;
    std::cout << a[i] << std::endl;
  }
  std::cout << "-----------------------------" << std::endl;
  std::cout << count << " integers" << std::endl;

}
