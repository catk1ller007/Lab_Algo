#ifndef TESTS_H
#define TESTS_H

#include "Algorithms.h"
#include "timer.h"
#include "Generator.h"
#include <iostream>
#include <fstream>

template<typename T>
void printVector(const std::vector<T>& elems);

//----------------------------AVL SORT------------------------//
void testAVLSort();

void testRandomAVLSort();

void testRandAVLIncSort();

void testRandAVLDicSort();

//--------------------------AVL CHANGE SIZE-------------------//

int64_t testChangeSizeAVLSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeSizeAVLSort();


int64_t testChangeSizeAVLSortIncSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeSizeAVLSortIncSort();


int64_t testChangeSizeAVLSortDicSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeSizeAVLSortDicSort();

//--------------------------AVL CHANGE VALUE-------------------------//
int64_t testChangeValueAVLSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeValueAVLSort();


int64_t testChangeValueAVLSortIncSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeValueAVLSortIncSort();


int64_t testChangeValueAVLSortDicSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeValueAVLSortDicSort();

//---------------------------QUICK SORT----------------------//
void testQuickSort();

void testRandomQuickSort();

void testRandQuickSortIncSort();

void testRandQuickSortDicSort();

//---------------------------QUICK CHANGE SIZE--------------------//

int64_t testChangeSizeQuickSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeSizeQuickSort();


int64_t testChangeSizeQuickSortIncSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeSizeQuickSortIncSort();


int64_t testChangeSizeQuickSortDicSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeSizeQuickSortDicSort();

//--------------------------QUICK CHANGE VALUE-------------------------//
int64_t testChangeValueQuickSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeValueQuickSort();


int64_t testChangeValueQuickSortIncSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeValueQuickSortIncSort();


int64_t testChangeValueQuickSortDicSort(size_t size, int64_t minValue, int64_t maxValue);

void autoTestChangeValueQuickSortDicSort();



#endif // TESTS_H