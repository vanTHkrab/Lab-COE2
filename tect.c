# include <stdio.h>

int main () {
    int ans;
    char ch;
    int i = 5;
    do
    {
        printf(": ");
        scanf("%d", &ans);
        switch (ans)
        {
        case 1:
            printf("HEE");
            break;
        case 2:
            printf("KUYGAY");
            break;
        default:
            printf("YES");
            break;
        }
    printf(":: ");
    scanf("%c", ch);
    }while(ch =='y');
} 
    