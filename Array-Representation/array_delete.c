# include <stdio.h>

int main(){
    int a[] = {40, 84, 50, 21, 14, 77};
    int n = 6;
    int p = 3;
    int i = p;
    int key =a[p];
    for (i = p; i < n - 1; i++) {
        a[i] = a[i+1];
    }
    n = n - 1;
    printf("deleted element is %d\n", key);
    printf("The array elements after deletion :\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = %d \n", i, a[i]);
    }
}
