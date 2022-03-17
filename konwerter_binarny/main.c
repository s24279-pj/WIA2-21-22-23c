#include <stdio.h>
#include <stdlib.h>

int main()
{
    int liczba, reszta, dzielnik, j;
    char dwunastkowy[10];
    int i = 0;
    printf("Podaj liczbe do konwersji na system dwunastkowy: ");
    scanf("%d", &liczba);

    dzielnik = liczba;

    while(dzielnik != 0)
    {
        reszta = dzielnik % 12;

        if (reszta < 10)
            {
                reszta = reszta + 48;
            }
        else
            {
                reszta = reszta + 51;
            }
        dwunastkowy[i]=reszta;
        dzielnik = dzielnik / 12;
        i++;
    }

    for (int j=i-1; j >= 0; j--)
        {
            printf("%c", dwunastkowy[j]);
        }
    return 0;
}
