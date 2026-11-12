#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, hotDays = 0;
    double *temp, *ptr, *hottest, *coldest;

    do {
        printf("How many days of temperature to store (1-10): ");
        scanf("%d", &n);
        if (n < 1 || n > 10)
            printf("Invalid number of days.\n");
    } while (n < 1 || n > 10);

    temp = (double *)malloc(n * sizeof(double));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        do {
            printf("Enter temperature for day %d (-10 to 55): ", i + 1);
            scanf("%lf", &temp[i]);
            if (temp[i] < -10 || temp[i] > 55)
                printf("Invalid temperature.\n");
        } while (temp[i] < -10 || temp[i] > 55);
    }

    printf("\n");
    for (i = 0; i < n; i++)
        printf("Day %d: %.1f at address %p\n", i + 1, temp[i], (void *)&temp[i]);

    ptr = temp;
    hottest = temp;
    coldest = temp;
    for (i = 0; i < n; i++) {
        if (*ptr > *hottest)
            hottest = ptr;
        if (*ptr < *coldest)
            coldest = ptr;
        if (*ptr > 40)
            hotDays++;
        ptr++;
    }

    printf("\nHottest temperature: %.1f\n", *hottest);
    printf("Coldest temperature: %.1f\n", *coldest);
    printf("Days hotter than 40: %d\n", hotDays);

    free(temp);
    temp = NULL;
    printf("\nMemory has been released successfully.\n");

    return 0;
}
