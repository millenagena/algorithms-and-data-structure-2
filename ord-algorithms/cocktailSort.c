#include<stdio.h>  

// can be any swap function. This swap is optimized for numbers.
void swap(int *x, int *y) {
	if(x == y)
		return;
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
void cocktailsort(int *a, size_t n) {
	while(1) {
		// packing two similar loops into one
		char flag;
		int it, i;
		size_t start[2] = {1, n - 1},
			   end[2] = {n, 0},
			   inc[2] = {1, -1};
		for(it = 0; it < 2; ++it) {
			flag = 1;
			for(i = start[it]; i != end[it]; i += inc[it])
				if(a[i - 1] > a[i]) {
					swap(a + i - 1, a + i);
					flag = 0;
				}
			if(flag)
				return;
		}
	}
}

int main(){
    int v1[]={5,3,6,2,7,8,1,4},
        v2[]={1,2,3,4,5,6,7,8,9,10},
        v3[]={5,4,3,2,1};
    int i;

    cocktailsort(v1,8);
    for (i=0;i<8;i++) printf("%d ",v1[i]);
    printf("\n");

    cocktailsort(v2,10);
    for (i=0;i<10;i++) printf("%d ",v2[i]);
    printf("\n");

    cocktailsort(v3,5);
    for (i=0;i<5;i++) printf("%d ",v3[i]);
    printf("\n");
}
