# include <stdio.h>

int main() {
    int array[1000] = {1, 2, 3, 4, 5};
    int p = 2;
    int n = 5;
    for (int i = p; i < n - 1; i++){
        array[i] = array[i + 1];
    } n--;
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    for(int i = n; i >= p; i--){
        array[i + 1] = array[i];
    } n++;
    array[p] = 5;
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}