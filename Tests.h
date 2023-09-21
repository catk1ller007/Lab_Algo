#ifndef TESTS_H
#define TESTS_H

#include "Algorithms.h"
#include "timer.h"
#include "Generator.h"

template<typename T>
void printVector(const std::vector<T>& elems)
{
	for (const auto& elem : elems) 
	{
		std::cout << elem << ' ';
	}
	std::cout << std::endl;
}

//----------------------------AVL SORT------------------------//
void testAVLSort() 
{
	std::cout << std::endl;

	std::vector<int64_t> elems{ 1,5,-2,11,5,6,57,38,9,0,1,22,3,4,INT_MIN};
	printVector(elems);

	TIMER_START(timer, tmr::nanosecond_t);
	AVLsort(elems);
	int64_t result = TIMER_GET(timer);
	
	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandomAVLSort() {
	std::cout << std::endl;

	IntegerGenerator generator(-1000, 1000);
	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generator.generate();
	printVector(elems);

	TIMER_START(timer, tmr::nanosecond_t);
	AVLsort(elems);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandAVLInc_Sort() {
	std::cout << std::endl;

	IntegerGenerator generator(-1000, 1000);
	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generator.generate();
	printVector(elems);

	std::sort(elems.begin(), elems.end());
	TIMER_START(timer, tmr::nanosecond_t);
	AVLsort(elems);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandAVLDic_Sort() {
	std::cout << std::endl;

	IntegerGenerator generator(-1000, 1000);
	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generator.generate();
	printVector(elems);

	std::sort(elems.rbegin(), elems.rend());
	TIMER_START(timer, tmr::nanosecond_t);
	AVLsort(elems);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

int64_t testChangeSizeAVLSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();
	std::vector<int64_t> arr(elems);
	std::sort(elems.begin(), elems.end());
	
	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(arr);
	int64_t result = TIMER_GET(timer);
	std::cout << (arr == elems) << ' ';

	return result;
}

void autoTestChangeSizeAVLSort() {
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}

}

//---------------------------QUICK SORT----------------------//
void testQuickSort()
{
	std::cout << std::endl;

	std::vector<int64_t> elems{ 1,5,-2,11,5,6,57,38,9,0,1,22,3,4,INT_MIN };
	printVector(elems);

	TIMER_START(timer, tmr::nanosecond_t);
	quickSort(elems, 0, elems.size() - 1);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandomQuickSort() {
	std::cout << std::endl;

	IntegerGenerator generator(-1000, 1000);
	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generator.generate();
	printVector(elems);

	TIMER_START(timer, tmr::nanosecond_t);
	quickSort(elems, 0, elems.size() - 1);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandQuickSortInc_Sort() {
	std::cout << std::endl;

	IntegerGenerator generator(-1000, 1000);
	std::vector<int64_t> elems(15);	
	for (auto& elem : elems) elem = generator.generate();
	printVector(elems);

	std::sort(elems.begin(), elems.end());
	TIMER_START(timer, tmr::nanosecond_t);
	quickSort(elems, 0, elems.size() - 1);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

void testRandQuickSortDic_Sort() {
	std::cout << std::endl;

	IntegerGenerator generator(-1000, 1000);
	std::vector<int64_t> elems(15);
	for (auto& elem : elems) elem = generator.generate();
	printVector(elems);

	std::sort(elems.rbegin(), elems.rend());
	TIMER_START(timer, tmr::nanosecond_t);
	quickSort(elems, 0, elems.size() - 1);
	int64_t result = TIMER_GET(timer);

	printVector(elems);
	std::cout << "Result: " << result << "ns" << std::endl;

	std::cout << std::endl;
}

int64_t testChangeSizeQuickSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();
	
	TIMER_START(timer, tmr::millisecond_t);
	quickSort(elems, 0, elems.size() - 1);
	return TIMER_GET(timer);
}

void autoTestChangeSizeQuickSort(){
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeQuickSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}
	
}

#endif // TESTS_H