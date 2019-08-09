# DataStructuresH
Projects submitted for Data Structures with C++ Honors course at BMCC

--------------------------

Large Integer Project

CSC 331H   LargeInt PROGRAMMING PROJECT 

PART 1:

Design and implement a class representing a doubly linked list. The class must have the following requirements:

1.	The linked list and the nodes must be implemented  as  C++ templates
1.	The list must be generic – it should not implement arithmetic/logic functions.  
2.	It must include a destructor, a copy constructor and operator=
3.	It must include methods to insert at the front and at the back of the list
4.	It must include a method to return the length of the list
5.	It must provide an iterator-based interface for the user from front to back
6.	It must include an iterator-based interface for the user from back to front


PART 2:

The implementation of the class LargeInt will use a dynamic physical structure to store the individual digits of an integer, and will provide some basic I/O and arithmetic operations that can be performed on integers.  
In particular, the class should include:

1)	Operator functions to overload the operators +, -, *, /, %
2)	Operator functions to overload the operators ==, <, <=, >, >=
3)	An operator function to overload the operator << 
4)	An operator function to overload the operator >> 

Note 1: Since the LargeInt class does not contain pointers, there is no need for a copy constructor or a destructor.

Note 2: Huge integers may be positive or negative (or zero).

Note 3: Your implementation of the huge integer type must be encapsulated as a C++ class, aggregating a list object for the internal representation of the huge integer value. The huge integer type is not a list, nor does it make sense for it to be derived from a list using inheritance.

Note 4: Aside from list nodes used only within an encapsulating list template, all data members of classes and templates must be private or protected. Friend operators are permissible, but the huge integer type should absolutely not be declared a friend of the list.


-------------------------

Sorting Analysis

SORTING  PROJECT       

The classic question “Which sorting algorithm is faster?” does not have an easy answer. The speed of a sorting algorithm can depend on many factors, such as the type of elements that are sorted, the environment where the sorting is done and how the elements are distributed.
For example, sorting an array of 100 integers can be very different from sorting a large database; sorting a linked list can be different from sorting an array. Often, a particular algorithm is fast in some cases and slow in other cases.
This project will provide an opportunity to implement and analyze various sorting algorithms. 
Specifications
Write a program to compare the relative performance of different sorting algorithms on datasets containing  integers. Ultimately, the data should be sorted in ascending order. Your sorting algorithms should use arrays.
Test your program on two different array sizes : 100 and 1000.
Use the following random number distributions :
a) Completely random
b) Almost sorted in ascending order ( about 90% of items are in increasing order, 10% are random)
c) Almost reversed -  same as b) but in reverse order
d) Array is sorted except for the last 10% 
You should include the following sorting algorithms Feel free to place all of these in the same file. This is an analysis problem, not a structured software solution.
•Selection Sort 
•Insertion Sort 
•Heap Sort 
•Merge Sort
•QuickSort
 


To measure the performance of the various sorting routines, count the number of comparisons and swaps required to achieve the desired ascending sorted order. You will be required to perform this analysis for all sorting routines for the datasets. Be sure to measure compares as occurrences in each algorithm where array elements themselves are compared. 
You should utilize global variables as counters. This is required for the recursive algorithms. Place all functions in one file, if necessary. For counting the comparisons, consider each place in each algorithm where an array element is compared to another. Swaps in the algorithms should utilize an included function swap(). Be sure to utilize two separate counters; one for total swaps and one for total comparisons.
Deliverables
•Source code.
•A summary table that describes the results of the experiment, along with a summary statement highlighting your conclusions from the results.

-------------------------

Stacks Program


Write a program that uses stacks to evaluate an arithmetic expression.

The program takes as input a numeric expression, such as 3+4*2, and outputs the result.

1)   Operators are +, -, *, /
2)   Assume that the expression is formed correctly so that each operation has two arguments.
3)  The expression can have parenthesis, for example: 3*(4-2)+6. 
4)  The expression can have negative numbers.
5)  The expression can have spaces in it, for example: 3  *  (4-2)  +6 .


Here are some useful method that you may need:

               char cin.peek(); -- returns the next character of the cin input stream ( without reading it)
               bool isdigit(char c); -- returns true if c is one of the digits ‘0’ through ‘9’, false otherwise
               cin.ignore(); -- reads and discards the next character from the cin input stream
               cin.get(char &c); -- reads a character in c ( could be a space or the new line )

Test your program with a variety of arithmetic expressions.







