#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n)
{
    int i;
    printf("\nStock:\n");
    for (i = 0; i < n; i++)
        printf("Item %d: %d\n", i + 1, *(arr + i));
}

void summary(int *arr, int n)
{
    int i, total = 0, lowestIndex = 0;
    for (i = 0; i < n; i++) {
        total += *(arr + i);
        if (*(arr + i) < *(arr + lowestIndex))
            lowestIndex = i;
    }
    printf("Total stock: %d\n", total);
    printf("Lowest stock: Item %d with %d units\n", lowestIndex + 1, *(arr + lowestIndex));
}

int *insertItem(int *arr, int *n)
{
    int pos, value, i;
    int *newArr;

    do {
        printf("Enter position to insert (1-%d): ", *n + 1);
        scanf("%d", &pos);
        if (pos < 1 || pos > *n + 1)
            printf("Invalid position.\n");
    } while (pos < 1 || pos > *n + 1);

    printf("Enter stock value of new item: ");
    scanf("%d", &value);

    newArr = (int *)malloc((*n + 1) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed.\n");
        return arr;
    }

    for (i = 0; i < pos - 1; i++)
        *(newArr + i) = *(arr + i);
    *(newArr + pos - 1) = value;
    for (i = pos - 1; i < *n; i++)
        *(newArr + i + 1) = *(arr + i);

    free(arr);
    (*n)++;
    return newArr;
}

int *deleteItem(int *arr, int *n)
{
    int pos, i, j;
    int *newArr;

    if (*n <= 1) {
        printf("Cannot delete the last remaining item.\n");
        return arr;
    }

    do {
        printf("Enter position to delete (1-%d): ", *n);
        scanf("%d", &pos);
        if (pos < 1 || pos > *n)
            printf("Invalid position.\n");
    } while (pos < 1 || pos > *n);

    newArr = (int *)malloc((*n - 1) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory allocation failed.\n");
        return arr;
    }

    for (i = 0, j = 0; i < *n; i++) {
        if (i != pos - 1) {
            *(newArr + j) = *(arr + i);
            j++;
        }
    }

    free(arr);
    (*n)--;
    return newArr;
}

void sortStock(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main(void)
{
    int n, i, choice, pos, value;
    int *stock;

    do {
        printf("Enter starting size (3-8): ");
        scanf("%d", &n);
        if (n < 3 || n > 8)
            printf("Invalid size.\n");
    } while (n < 3 || n > 8);

    stock = (int *)malloc(n * sizeof(int));
    if (stock == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter stock of item %d: ", i + 1);
        scanf("%d", &stock[i]);
    }

    do {
        printf("\n====== GROCERY STOCK MENU ======\n");
        printf("1. Display stock\n");
        printf("2. Update stock of one item\n");
        printf("3. Insert a new item\n");
        printf("4. Delete an item\n");
        printf("5. Sort stock\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(stock, n);
                summary(stock, n);
                break;
            case 2:
                printf("Enter position (1-%d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position.\n");
                } else {
                    printf("Enter new stock value: ");
                    scanf("%d", &value);
                    *(stock + pos - 1) = value;
                    display(stock, n);
                    summary(stock, n);
                }
                break;
            case 3:
                stock = insertItem(stock, &n);
                display(stock, n);
                summary(stock, n);
                break;
            case 4:
                stock = deleteItem(stock, &n);
                display(stock, n);
                summary(stock, n);
                break;
            case 5:
                sortStock(stock, n);
                display(stock, n);
                summary(stock, n);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    free(stock);
    stock = NULL;
    printf("Memory released.\n");

    return 0;
}
