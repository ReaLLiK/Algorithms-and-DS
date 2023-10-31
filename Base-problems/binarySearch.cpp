#include <iostream>
using namespace std;
int binarySearch(int* heap, int target, int size)
{
	int left = 0;
	int right = size - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (target == heap[mid])
			return 1;
		if (target < heap[mid])
			right = mid;
		else
			left = mid + 1;
	}
	if (heap[left] == target)
		return 1;
	return 0;
}
int lowerBound(int* heap, int target, int size)
{
	int left = 0;
	int right = size - 1;
	int mid;
	if (target > heap[right])
		return size;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (target <= heap[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int upperBound(int* heap, int target, int size)
{
	int left = 0;
	int right = size - 1;
	int mid;
	if (target >= heap[right])
		return size;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (target < heap[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main()
{
	int size;
	int size2;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
		cin >> array[i];
	cin >> size2;
	int* array2 = new int[size2];
	for (int i = 0; i < size2; ++i)
		cin >> array2[i];
	for (int i = 0; i < size2; ++i)
		cout << binarySearch(array, array2[i], size) << ' ' << lowerBound(array, array2[i], size) << ' ' << upperBound(array, array2[i], size) << endl;
	delete[] array;
	return 0;
}
