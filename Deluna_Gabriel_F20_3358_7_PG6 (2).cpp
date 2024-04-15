
// <This program accepts a positive integer and creates a character array of size n.
//  It populates the array with random numbers between 50-150. Then it performs the following:
//  Sequential search of 80. Selection sort. Insertion sort. 3 Quick sorts with pivot at first
//  element, middle element, and last element. After each algorithm the program displays the
//  clock times each algorithm took to complete.>

#include <iostream>
//#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

void displayHeader();//Displays opening message
void inputValidation(int &);//validates user input
void displayArray(unsigned char*, int);//displays array
void sequentialSearch(unsigned char*, int, int &);//searches for 80
void selectionSort(unsigned char*, int, int &);//sorts array with selection sort
void insertionSort(unsigned char*, int, int &);//sorts array with insertion sort
void quickSortMiddle(unsigned char*, int &, int, int);//sorts with quick sort middle pivot
void quickSortFirst(unsigned char*, int &, int, int);//sorts with quick sort first pivot
void quickSortLast(unsigned char*, int &, int, int);//sorts with quick sort last pivot
void displayResults(clock_t, clock_t, int, string, string, unsigned char*, int);//displays results
void copyArray(unsigned char*, unsigned char*, int);//copies old array to new array
void runTest();




int main()
{
    runTest();
    return 0;
}


//*****************************************************************
// Runs a test to see effectiveness of the search and sorting algorithms
// Creates two arrays, one populated with random numbers that remains
// unchanged. The other is the array that will be sorted and then returned
// to the original order of the old array.
//
// Parameters
// none
// return - void
//*******************************************************************
void runTest()
{
    int arraySize = 0;//how many elements array has
    int cycleCount = 0;//how many cycle algorithm completed
    const int MIN = 50;//minimum range
    const int MAX = 150;// maximum range
    clock_t start;//clock time when started
    clock_t stop;//clock time when ended
    unsigned char *arrOriginal;//array that remains unchanged
    unsigned char *arrNew;//array with same elements but is sorted
    const string COMP = "Comparisons";//The following strings are to stream line displayResults()
    const string SWAP = "Swaps";      //where the labels are different with the various sorting functions.
    const string RECUR = "Recursive Calls";
    const string ARRAY = "Array";
    const string SORT = "Sorted";

    displayHeader();//display opening message
    inputValidation(arraySize);//get user input and validate

    if (arraySize != 0)//if user input was valid
    {
        unsigned char arrOriginal[arraySize];
        unsigned char arrNew[arraySize];

        srand(time(NULL)); //seed with clock

        for (int i = 0; i < arraySize; i++)//assigning random numbers 50-150
        arrOriginal[i] = MIN + rand() % ((MAX + 1) - MIN);

        cout << "\nArray elements are:";
        displayArray(arrOriginal, arraySize);//displays original array

        cout << "\nSequential Search :" << endl;
        cout << "\nSearching for 80" << endl;

        start = clock();//records clock time
        sequentialSearch(arrOriginal, arraySize, cycleCount);//sequential search for 80
        stop = clock();//records clock time

        displayResults(start, stop, cycleCount, COMP, ARRAY, arrOriginal, arraySize);//display result header

        copyArray(arrOriginal, arrNew, arraySize);

        cout << "\n\nSelection Sort :" << endl << endl;

        start = clock();
        selectionSort(arrNew, arraySize, cycleCount);//selection sort
        stop = clock();

        displayResults(start, stop, cycleCount, SWAP, SORT, arrNew, arraySize);

        copyArray(arrOriginal, arrNew, arraySize);

        cout << "\n\nInsertion Sort :" << endl << endl;

        start = clock();
        insertionSort(arrNew, arraySize, cycleCount);//insertion sort
        stop = clock();

        displayResults(start, stop, cycleCount, COMP, SORT, arrNew, arraySize);

        copyArray(arrOriginal, arrNew, arraySize);
        cycleCount = 0;

        cout << "\n\nQuick Sort - Next to the middle element as a pivot :" << endl << endl;

        start = clock();
        quickSortMiddle(arrNew, cycleCount, 0, (arraySize - 1));//quicksort next to middle pivot
        stop = clock();

        displayResults(start, stop, cycleCount, RECUR, SORT, arrNew, arraySize);

        copyArray(arrOriginal, arrNew, arraySize);
        cycleCount = 0;

        cout << "\n\nQuick Sort - First element as a pivot :" << endl << endl;

        start = clock();
        quickSortFirst(arrNew, cycleCount, 0, (arraySize - 1));//quicksort next to middle pivot
        stop = clock();

        displayResults(start, stop, cycleCount, RECUR, SORT, arrNew, arraySize);

        copyArray(arrOriginal, arrNew, arraySize);
        cycleCount = 0;

        cout << "\n\nQuick Sort - Last element as a pivot :" << endl << endl;

        start = clock();
        quickSortLast(arrNew, cycleCount, 0, (arraySize - 1));//quicksort next to middle pivot
        stop = clock();

        displayResults(start, stop, cycleCount, RECUR, SORT, arrNew, arraySize);

        cout << "\n\n11-16-2020 - By Gabriel, Deluna" << endl << endl;
        cout << "Benchmark Algorithm" << endl << endl;

    }
}


//*****************************************************************
// Displays header message at beginning of program
//
// Parameters
// none
// return - void
//*******************************************************************
void displayHeader()
{
    cout << "\nSearching / Sorting Benchmark" << endl;
    cout << "\n\n";
    cout << "Using a random number generator, we are creating an array of n" << endl;
    cout << "elements of type char then performing the following  :" << endl;
    cout << "\n  1. Displaying the first 20 numbers." << endl;
    cout << "\n  2. Searching for an element in the array using sequential search and" << endl;
    cout << "     at the end displaying number of comparisons it makes." << endl;
    cout << "\n  3. Sort the original array using Selection Sort and at the end" << endl;
    cout << "     display the number of swaps it makes." << endl;
    cout << "\n  4. Sorting the array using insertion Sort and at the end" << endl;
    cout << "     displaying the number of comparisons it makes." << endl;
    cout << "\n  5. Sorting the array using Quick Sort and at the end displaying" << endl;
    cout << "     the number of recursion calls it makes. Using the next to the" << endl;
    cout << "     middle value as a pivot value." << endl;
    cout << "\n  6. Sorting the same array using Quick Sort and at the end" << endl;
    cout << "     displaying the number of recursion calls it makes. Using the" << endl;
    cout << "     first value as a pivot value." << endl;
    cout << "\n  7. Sorting the same array using Quick Sort and at the end" << endl;
    cout << "     displaying the number of recursion calls it makes. Using the" << endl;
    cout << "     last value as a pivot value." << endl;
    cout << "\n  8. For each of the preceding steps ( 2 thru 7 ), calculating and" << endl;
    cout << "     printing the CPU time before each step starts and after each" << endl;
    cout << "     completed step then calculating actual CPU time for the" << endl;
    cout << "     completion of each step." << endl;
    cout << "\n\n";

}


//*****************************************************************
// Validates user input for size of array
//
// Parameters
// reference to arraySize
// return - void
//*******************************************************************
void inputValidation(int &arraySize)
{
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    if (arraySize <= 0 || cin.fail())
    {
        cout << "\n*** Error - Invalid input - Size must be > 0 ***" << endl;
        cout << "\n\n";
        arraySize = 0;
    }
}


//*****************************************************************
// Copies original unsorted array to new array
//
// Parameters
// unsigned char *oldArr - unsorted array, unsigned char *newArr - sorted
// array, int arraySize - size of array
// return - void
//*******************************************************************
void copyArray(unsigned char *oldArr, unsigned char *newArr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)//copying old array to new array
        newArr[i] = oldArr[i];
}


//*****************************************************************
// Displays array elements 20 or below
//
// Parameters
// unsigned char *arr - array to be displayed, int arraySize - size of
// array
// return - void
//*******************************************************************
void displayArray(unsigned char *arr, int arraySize)
{

    if (arraySize < 20)
    {
        for (int i = 0; i < arraySize; i++)
            cout << " " << arr[i];

        cout << endl << endl;
    }
    else
    {
        for (int i = 0; i < 20; i++)
            cout << " " << arr[i];

        cout << endl << endl;
    }
}


//*****************************************************************
// Searches array sequentially for the value of 80
//
// Parameters
// unsigned char *arr - unsorted array, int arraySize - size of array
// int &cycleCount - counter for how many comparisons
// return - void
//*******************************************************************
void sequentialSearch(unsigned char *arr, int arraySize, int &cycleCount)
{
   int result = 0;//stores elements from array
   cycleCount = 0;//counter for the comparisons

   for (int i = 0; i < arraySize && result != 80; i++)
   {
       result = (int)arr[i];
       cycleCount++;
   }

   if (result == 80)
    cout << "\n80 Was found" << endl;
   else
    cout << "\n80 Was Not found" << endl;

}


//*****************************************************************
// Displays the result header after each operation on the array
// shows the time it took to calculate as well as total number of
// swaps, comparisons, or recursions it took to finish.
//
// Parameters
// clock_t start - clock start time, clock_t stop - clock stop time
// int cycleCount - counter for cycles, string labelA - for display,
// string labelB - for display, unsigned char *arr - array to display
// int arraySize - array size
// return - void
//*******************************************************************
void displayResults(clock_t start, clock_t stop, int cycleCount,
                    string labelA, string labelB, unsigned char *arr, int arraySize)
{
    double totalTime;//total time calculation took

    totalTime = double(stop - start) / double(CLOCKS_PER_SEC);//total time calculation took

    cout << "Start Time  : " << start << endl;
    cout << "End Time    : " << stop << endl;
    cout << "Actual CPU Clock time : " << totalTime << setprecision(3) << endl;
    cout << "Total Number of " << labelA << " : " << cycleCount << endl;
    cout << labelB << " Elements: ";
    displayArray(arr, arraySize);//display array

}


//*****************************************************************
// Uses a selection sort algorithm to sort array
//
// Parameters
// unsigned char *arr - array to sort, int arraySize - array size
// int &cycleCount - count for cycles
// return - void
//*******************************************************************
void selectionSort(unsigned char *arr, int arraySize, int &cycleCount)
{
    cycleCount = 0;//counter for swap number

    for (int i = 0; i < arraySize - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < arraySize; j++)
        {
            if (arr[j] < arr[min])//if right element is smaller than left
                min = j;
        }
        if (i != min)
        {
            int swap = arr[i];//swap elements
            arr[i] = arr[min];
            arr[min] = swap;
            cycleCount++;//counter for swaps

        }
    }

}


//*****************************************************************
// Uses an insertion sort algorithm to sort array
//
// Parameters
// unsigned char *arr - array to sort, int arraySize - array size
// int &cycleCount - counter for cycles
// return - void
//*******************************************************************
void insertionSort(unsigned char *arr, int arraySize, int &cycleCount)
{
    cycleCount = 0;//counter for comparisons

    for(int k = 1; k < arraySize; k++)
    {
        int temp = arr[k];
        int j = k - 1;//left of k

        while( j >= 0 && temp <= arr[j])//find tmps place and shift bigger elements up
        {
            arr[j+1] = arr[j];
            j = j-1;
            cycleCount++;
        }
        arr[j+1] = temp;
    }

}


//*****************************************************************
// Uses quick sort algorithm to sort array with middle pivot
//
// Parameters
// unsigned char *arr - array to sort,
// int &cycleCount - count for cycles, int left - left most element
// int right - right most element
// return - void
//*******************************************************************
void quickSortMiddle(unsigned char *arr, int &cycleCount, int left, int right)
{
    int i = left;//leftmost element
    int j = right;//rightmost element
    int tmp;//temp for values
    int pivot = arr[(left + right) / 2];//pivot in middle of array

    /* partition */

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */

    if (left < j)//sort left recursively
    {
        quickSortMiddle(arr, cycleCount, left, j);
        cycleCount++;
    }
    if (i < right)//sort right recursively
    {
        quickSortMiddle(arr, cycleCount, i, right);
        cycleCount++;
    }
}


//*****************************************************************
// Uses quick sort algorithm to sort array with first element pivot
//
// Parameters
// unsigned char *arr - array to sort,
// int &cycleCount - count for cycles, int left - left most element
// int right - right most element
// return - void
//*******************************************************************
void quickSortFirst(unsigned char *arr, int &cycleCount, int left, int right)
{
    int i = left;//leftmost element
    int j = right;//rightmost element
    int tmp;//temp for values
    int pivot = arr[left];//First element is pivot

    /* partition */

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */

    if (left < j)//sort left recursively
    {
        quickSortFirst(arr, cycleCount, left, j);
        cycleCount++;
    }
    if (i < right)//sort right recursively
    {
        quickSortFirst(arr, cycleCount, i, right);
        cycleCount++;
    }
}


//*****************************************************************
// Uses quick sort algorithm to sort array with last element pivot
//
// Parameters
// unsigned char *arr - array to sort,
// int &cycleCount - count for cycles, int left - left most element
// int right - right most element
// return - void
//*******************************************************************
void quickSortLast(unsigned char *arr, int &cycleCount, int left, int right)
{
    int i = left;//leftmost element
    int j = right;//rightmost element
    int tmp;//temp for values
    int pivot = arr[right];//First element is pivot

    /* partition */

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */

    if (left < j)//sort left side recursively
    {
        quickSortLast(arr, cycleCount, left, j);
        cycleCount++;
    }
    if (i < right)//sort right side recursively
    {
        quickSortLast(arr, cycleCount, i, right);
        cycleCount++;
    }
}
