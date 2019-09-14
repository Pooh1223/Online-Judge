#include <cstdio>

void hanoi(int n, char a, char b, char c) {
    if(n == 1) {
        printf("Move sheet from %c to %c\n",a,c);
    }
    else {
        hanoi(n-1, a, c, b);
        hanoi(1, a, b, c);
        hanoi(n-1, b, a, c);
    }
}

int main() {
    int n;
    printf("Please input the amount of the disk.\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
} 
