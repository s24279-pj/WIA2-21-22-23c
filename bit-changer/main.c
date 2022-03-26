#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int converter(unsigned int X){

    int binary = 0;
    int i = 1;
    int rest;
    while (X!=0){
        rest = X%2;
        X/=2;
        binary+=rest*i;
        i*=10;
    }
    return binary;
}

int binary_test (unsigned int X){

    while (X > 0){
        int number = X%10;
        if (number > 1)
            return false;
        X /=10;
    }
    return true;
}

int bit_changer(unsigned int X, int P, bool n) {

    int bin;
    int changed_bin = 0;
    bool test;
    bin = converter(X);
    int temp = 1;
    int result = 0;
    for (int i = 0; i < P; i++) {
        temp=temp*10;
    }

    if (n == 1) {
        changed_bin = bin + temp;
        test = binary_test(changed_bin);
        if (test == true) {
            return changed_bin;
        }else if (test == false) {
            return bin;
        }
    }

    if (n == 0) {
        changed_bin = bin - temp;
        test = binary_test(changed_bin);
        if (test == true) {
            return changed_bin;
        }else if (test == false) {
            return bin;
        }
    }
}

int convert_reversed (int binary){

    int rest;
    int decimal = 0;
    int base = 1;

    while (binary > 0){
        rest = binary % 10;
        decimal = decimal + rest*base;
        binary = binary/10;
        base = base * 2;
    }
    return decimal;
}

int main()
{

    int X, P, n;
    printf("Podaj liczbe: ");
    scanf("%d", &X);
    printf("Forma binarna: ");
    printf("%d", converter(X));
    printf("\n\nPodaj miejsce (od 0) i bit (0 lub 1) do zamiany. \n");
    printf("Miejsce (liczac od zerowej pozycji): ");
    scanf("%d", &P);
    printf("Bit (0 lub 1): ");
    scanf("%d", &n);

    printf("\nPo binarne: ");
    printf("%d", bit_changer(X,P,n));
    printf("\nDziesietne: ");
    printf("%d", convert_reversed(bit_changer(X,P,n)));


    return 0;
}
