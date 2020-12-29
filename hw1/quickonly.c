#include <stdint.h>

void your_sort(uint32_t array[], int left, int right)
{
	if (left < right)
	{
		uint32_t pivot, temp;
		int low, high;

		low = left;
		high = right + 1;
		pivot = array[left];
		do
		{
			do
			{
				low++;
			} while (low <= right && array[low] < pivot);
			do
			{
				high--;
			} while (high >= left && array[high] > pivot);
			if (low < high)
			{
				temp = array[low];
				array[low] = array[high];
				array[high] = temp;
			}
		} while (low < high);
		temp = array[left];
		array[left] = array[high];
		array[high] = temp;
		your_sort(array, left, high - 1);
		your_sort(array, high + 1, right);
	}
}