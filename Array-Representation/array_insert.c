# include <stdio.h>

int main(){
    int a[10] = {40, 84, 21, 14, 77};
    int n = 5;
    int p = 3;
    int i = n - 1;
    for (i, p; i >= p; i--) {
        a[i + 1] = a[i];
    }
    a[p] = 50;
    n = n + 1;
    printf("The array elements after insertion :\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d \n", i, a[i]);
    }
}