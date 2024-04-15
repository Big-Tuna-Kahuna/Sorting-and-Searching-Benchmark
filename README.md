# Sorting-and-Searching-Benchmark
Demonstrates the use of various sorting and searching algorithms on a dynamically generated array of unsigned characters. The program measures the efficiency of each algorithm in terms of CPU time and the number of operations (comparisons, swaps, recursive calls) performed.  It provides insights into the performance of sequential search, selection sort, insertion sort, and three variations of quicksort (using the first, middle, and last elements as pivots).

Features
Random Array Generation: Generates an array of random unsigned characters within a specified range.
Sequential Search: Searches for a specific character in the array and counts the number of comparisons.
Sorting Algorithms:
Selection Sort: Sorts the array and counts the number of swaps.
Insertion Sort: Sorts the array and counts the number of comparisons.
Quick Sort: Implements three versions of quicksort, counting the number of recursive calls.
Performance Measurement: Records and displays the CPU time for each operation.
User Interaction: Allows the user to specify the size of the array.

Requirements
C++11 compatible compiler
Standard libraries: iostream, cstdlib, ctime, iomanip, bits/stdc++.h

Compilation Command
g++ -o benchmark_program benchmark_program.cpp -std=c++11

Running the Program
Execute the compiled program from the command line:
./benchmark_program

User Input
The user will be prompted to enter the size of the array for the benchmark. Input should be a positive integer.

Output
The program outputs:

The original array elements (first 20 or total if fewer).
Results of the sequential search for the character '80', including whether it was found and the number of comparisons.
Results of each sorting algorithm, including the CPU start and end times, total CPU time taken, and the total number of relevant operations (swaps, comparisons, recursive calls).
The sorted array elements after each sort (first 20 or total if fewer).

Code Explanation
runTest(): Orchestrates the benchmark by generating the array, performing searches and sorts, and displaying results.
displayHeader(): Prints introductory information about the program.
inputValidation(): Ensures that the user inputs a valid positive integer for the array size.
copyArray(): Copies the contents of one array to another.
displayArray(): Displays up to 20 elements of an array.
sequentialSearch(): Performs a linear search for the character '80' in the array.
selectionSort(), insertionSort(), quickSortMiddle(), quickSortFirst(), quickSortLast(): Implement the respective sorting algorithms.
displayResults(): Outputs the timing and operation count for each search or sort.
