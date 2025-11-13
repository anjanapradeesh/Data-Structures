#include <stdio.h>


void printBits(int num) {
    for (int i = 4; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {

    int A = 0b10110;
    int B = 0b01101;
    int mask = 0b11111; 

    printf("Set A  : ");
    printBits(A);

    printf("Set B  : ");
    printBits(B);


    printf("Union (A ∪ B) : ");
    printBits(A | B);

    printf("Intersection  : ");
    printBits(A & B);


    printf("A - B         : ");
    printBits(A & (~B & mask));

    return 0;
}