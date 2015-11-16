#include <ccSort/ccSort.h>

static void ccsSwap(int *x, int *y)
{
	if(x != y) {
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}

void ccsQuicksort(int *list, int start, int end)
{
	if(end > start + 1) {
		int pivot = list[start];
		int l = start + 1;
		int r = end;

		while(l < r) {
			if(list[l] <= pivot) {
				++l;
			}
			else{
				ccsSwap(&list[l], &list[--r]);
			}
		}

		ccsSwap(&list[--l], &list[start]);
		ccsQuicksort(list, start, l);
		ccsQuicksort(list, r, end);
	}
}