#include <iostream>
#include <string>
#include "Tests.h"
using namespace std;



int main() {
	std::cout << "AVLSort:";
	testAVLSort();

	std::cout << "QuickSort:";
	testQuickSort();

	std::cout << "RandomAVLSort:";
	testRandomAVLSort();

	std::cout << "RandomQuickSort:";
	testRandomQuickSort();

	std::cout << "RandQuickSortInc_Sort:";
	testRandQuickSortInc_Sort();

	std::cout << "RandAVLInc_Sort:";
	testRandAVLInc_Sort();

	std::cout << "RandQuickSortDic_Sort:";
	testRandQuickSortDic_Sort();

	std::cout << "RandAVLDic_Sort:";
	testRandAVLDic_Sort();

	return 0;
}
