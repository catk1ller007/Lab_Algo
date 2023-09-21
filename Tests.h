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

void testRandAVLIncSort() {
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

void testRandAVLDicSort() {
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

//--------------------------AVL CHANGE SIZE-------------------//

int64_t testChangeSizeAVLSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();
	
	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(elems);

	return TIMER_GET(timer);;
}

void autoTestChangeSizeAVLSort() {
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}

}


int64_t testChangeSizeAVLSortIncSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.begin(), elems.end());
	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(elems);

	return TIMER_GET(timer);;
}

void autoTestChangeSizeAVLSortIncSort() {
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSortIncSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}

}


int64_t testChangeSizeAVLSortDicSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.rbegin(), elems.rend());
	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(elems);

	return TIMER_GET(timer);;
}

void autoTestChangeSizeAVLSortDicSort() {
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeAVLSortDicSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}

}

//--------------------------AVL CHANGE VALUE-------------------------//
int64_t testChangeValueAVLSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(elems);

	return TIMER_GET(timer);;
}

void autoTestChangeValueAVLSort() {
	int64_t result = 0;

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueAVLSort(1'000'000, 1, value);
		std::cout << value << ' ' << result << '\n';
	}

}


int64_t testChangeValueAVLSortIncSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.begin(), elems.end());
	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(elems);

	return TIMER_GET(timer);;
}

void autoTestChangeValueAVLSortIncSort() {
	int64_t result = 0;

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueAVLSortIncSort(1'000'000, 1, value);
		std::cout << value << ' ' << result << '\n';
	}

}


int64_t testChangeValueAVLSortDicSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.rbegin(), elems.rend());
	TIMER_START(timer, tmr::millisecond_t);
	AVLsort(elems);

	return TIMER_GET(timer);;
}

void autoTestChangeValueAVLSortDicSort() {
	int64_t result = 0;

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueAVLSortDicSort(1'000'000, 1, value);
		std::cout << value << ' ' << result << '\n';
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

void testRandQuickSortIncSort() {
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

void testRandQuickSortDicSort() {
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

//---------------------------QUICK CHANGE SIZE--------------------//

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


int64_t testChangeSizeQuickSortIncSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.begin(), elems.end());
	TIMER_START(timer, tmr::millisecond_t);
	quickSort(elems, 0, elems.size() - 1);

	return TIMER_GET(timer);;
}

void autoTestChangeSizeQuickSortIncSort() {
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeQuickSortIncSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}

}


int64_t testChangeSizeQuickSortDicSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.rbegin(), elems.rend());
	TIMER_START(timer, tmr::millisecond_t);
	quickSort(elems, 0, elems.size() - 1);

	return TIMER_GET(timer);;
}

void autoTestChangeSizeQuickSortDicSort() {
	int64_t result = 0;

	for (size_t size = 1; size <= 1'000'001; size += 10'000) {
		result = testChangeSizeQuickSortDicSort(size, 0, 1'000'000'000);
		std::cout << size << ' ' << result << '\n';
	}

}

//--------------------------QUICK CHANGE VALUE-------------------------//
int64_t testChangeValueQuickSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	TIMER_START(timer, tmr::millisecond_t);
	quickSort(elems, 0, elems.size() - 1);
	return TIMER_GET(timer);
}

void autoTestChangeValueQuickSort() {
	int64_t result = 0;

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueQuickSort(1'000'000, 1, value);
		std::cout << value << ' ' << result << '\n';
	}
}


int64_t testChangeValueQuickSortIncSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.begin(), elems.end());
	TIMER_START(timer, tmr::millisecond_t);
	quickSort(elems, 0, elems.size() - 1);

	return TIMER_GET(timer);;
}

void autoTestChangeValueQuickSortIncSort() {
	int64_t result = 0;

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueQuickSortIncSort(1'000'000, 1, value);
		std::cout << value << ' ' << result << '\n';
	}
}


int64_t testChangeValueQuickSortDicSort(size_t size, int64_t minValue, int64_t maxValue) {
	IntegerGenerator generator(minValue, maxValue);
	std::vector<int64_t> elems(size);

	for (auto& elem : elems) elem = generator.generate();

	std::sort(elems.rbegin(), elems.rend());
	TIMER_START(timer, tmr::millisecond_t);
	quickSort(elems, 0, elems.size() - 1);

	return TIMER_GET(timer);;
}

void autoTestChangeValueQuickSortDicSort() {
	int64_t result = 0;

	for (size_t value = 1; value <= 100; value++) {
		result = testChangeValueQuickSortDicSort(1'000'000, 1, value);
		std::cout << value << ' ' << result << '\n';
	}
}

#endif // TESTS_H