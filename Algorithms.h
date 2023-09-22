#ifndef Algorithms_H
#define Algorithms_H


#include <vector>
#include <iostream>
#include <algorithm>
#include "AVL.h"

void AVLsort(std::vector<int64_t>& elems) {
	AVLtree tree(elems);
	elems = tree.getElems();
}


void quickSort(std::vector<int64_t>& arr, int64_t left, int64_t right)
{
    if (left > right) return;
    int64_t value = arr[(left + right) >> 1];
    int64_t l = left;
    int64_t r = right;
   


    while (l <= r)
    {
        while (arr[l] < value) ++l;
        while (arr[r] > value) --r;

        if (l <= r)
        {
            std::swap(arr[l], arr[r]);
            ++l; --r;
        }
    }

    quickSort(arr, left, r);
    quickSort(arr, l, right);
}




#endif // Algorithms_H


