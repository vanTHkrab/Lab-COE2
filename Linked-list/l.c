#include <stdio.h>
#include <stdlib.h>

int main() {
    int Element[10] = {14,21,40,77,84},i=9;
    if(i>=3){
        Element[i]=Element[i-1];
        i-=1;
    }
    Element[3]=50;

    for(int n=0;n<=9;n++)
        printf("%d\t",Element[n]);
}