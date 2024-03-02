# include <stdio.h>

int tree(int num) {
    if (num > 1) {
        num--;
        return num * tree(num);
    }
    return 1;
}

int main() {
    int num = 6;
    printf("%d", tree(num));
    return 0;
}
