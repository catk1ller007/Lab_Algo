#include <iostream>
#include <string>
#include "Tests.h"
using namespace std;



int main() {

	//----------------AVL Change Size--------------------//
	autoTestChangeSizeAVLSort();

	autoTestChangeSizeAVLSortIncSort();

	autoTestChangeSizeAVLSortDicSort();

	//----------------AVL Change Value-------------------//
	autoTestChangeValueAVLSort();

	autoTestChangeValueAVLSortIncSort();

	autoTestChangeValueAVLSortDicSort();



	//----------------QuickSort Change Size--------------------//
	autoTestChangeSizeQuickSort();

	autoTestChangeSizeQuickSortIncSort();

	autoTestChangeSizeQuickSortDicSort();


	//----------------QuickSort Change Value-------------------//
	autoTestChangeValueQuickSort();

	autoTestChangeValueQuickSortIncSort();

	autoTestChangeValueQuickSortDicSort();

	return 0;
}
