#include <ccSort/ccSort.h>

static void ccsSwap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void ccsQuicksort(int *list, int start, int end)
{
	if(end > start + 1) {
		int pivot = list[start];
		int l = start + 1;
		int r = end;

		while(l < r) {
			if(list[l] <= pivot) {
				l++;
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

void ccsQuicksortDouble(int *list, int *secondary, int start, int end)
{
	if(end > start + 1) {
		int pivot = list[start];
		int l = start + 1;
		int r = end;

		while(l < r) {
			if(list[l] <= pivot) {
				l++;
			}
			else{
				r--;
				ccsSwap(&list[l], &list[r]);
				ccsSwap(&secondary[l], &secondary[r]);
			}
		}

		l--;
		ccsSwap(&list[l], &list[start]);
		ccsSwap(&secondary[l], &secondary[start]);

		ccsQuicksortDouble(list, secondary, start, l);
		ccsQuicksortDouble(list, secondary, r, end);
	}
}