# include <stdio.h>

int main(){
    int a[10] = {40, 84, 21, 14, 77};
    int n = 5;

    printf("The original array elements are :\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d \n", i, a[i]);
    }

    int p = 3;
    int i = n - 1;
    for (i, p; i >= p; i--) {
        a[i + 1] = a[i];
    }
    a[p] = 50;
    n = n + 1;
    printf("Inserted element is %d\n", a[p]);
    printf("The array elements after insertion :\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d \n", i, a[i]);
    }

    int q = 2;

    i = q;
    int key = a[q];
    for (i = q; i < n - 1; i++) {
        a[i] = a[i+1];
    }
    n = n - 1;
    printf("deleted element is %d\n", key);
    printf("The array elements after deletion :\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d \n", i, a[i]);
    }
}