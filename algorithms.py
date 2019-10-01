'''
This file serves to store common algorithims that any Computing student
should know.

None of these algorithms are my own thought.

Written by: Austin Staton 
Date: October 1st, 2019
'''
############
# Sorting
############
'''
InsertionSort() sorts the first (n-1) elements, then finds the correct home
for the final element and insert it there. 

This algorithm has a polynomial (n^2) order of growth. It is an example of
using a "Decrease and Conquer" approach to sorting.

**Notice that this algorithm accesses elements CLOSE together in memory.
  Thus, it exhibits the principal of cache locality. Many languages use
  this approach of sorting for sufficiently small arrays; while they use
  a QuickSort for larger arrays. 

Param:
    array -- an array of Integers
'''
def InsertionSort(array):
    for i in range (1, len(array)):
        v = array[i]
        k = i
        while (k > 0 and v < array[k-1]):
            array[k] = array[k-1]
            k -= 1
        array[k] = v

def SelectionSort(array):
    X = 10

############
# Searching
############
'''
BinarySearch() searches a SORTED array for a search key, K. It does this
by comparing the search key to the middle element of the array, mid. If
the search key is greater than the middle element, we know that the
passible range of values is at a higher array index than the middle point.

This algorithm has a log(n) order of growth and is an example of solving the
needed problem by "Decrease and Conquer" by a constant factor.

Params:
    array -- a sorted array of integers
    l -- a lower bound index to search in the array (initially should be 0)
    u -- an upper bound index to search in the array (initially should be
         the last element of the array).
    K -- a value to search for in the array ("the search key")
'''
def BinarySearch(array, l, u, K):
    if (l < u):
        return -1
    mid = (u - l + 1)/2
    if (K == array[m]):
        return m
    elif (K > A[m]):
        return BinarySearch(array, mid+1, u, K)
    else:
        return BinarySearch(array, l, mid-l, K)




