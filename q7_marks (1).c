#include <stdio.h>

int findMax(int *p, int n)
{
    int i, max = *p;
    for (i = 1; i < n; i++)
        if (*(p + i) > max)
            max = *(p + i);
    return max;
}

int findMin(int *p, int n)
{
    int i, min = *p;
    for (i = 1; i < n; i++)
        if (*(p + i) < min)
            min = *(p + i);
    return min;
}

double findAverage(int *p, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += *(p + i);
    return (double)sum / n;
}

int countAbove(int *p, int n, double avg)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (*(p + i) > avg)
            count++;
    return count;
}

void reverseArray(int *p, int n)
{
    int *start = p;
    int *end = p + n - 1;
    int temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (*(p + i) == key)
            return i;
    return -1;
}

int countPass(int *p, int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (*(p + i) >= 40)
            count++;
    return count;
}

void printArray(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");
}

int main(void)
{
    int marks[10];
    int i, key, pos;
    double avg;

    for (i = 0; i < 10; i++) {
        do {
            printf("Enter marks of student %d (0-100): ", i + 1);
            scanf("%d", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100)
                printf("Invalid marks.\n");
        } while (marks[i] < 0 || marks[i] > 100);
    }

    avg = findAverage(marks, 10);

    printf("\nHighest mark   : %d\n", findMax(marks, 10));
    printf("Lowest mark    : %d\n", findMin(marks, 10));
    printf("Average        : %.2f\n", avg);
    printf("Above average  : %d students\n", countAbove(marks, 10, avg));
    printf("Pass count     : %d students\n", countPass(marks, 10));

    printf("\nEnter a mark to search: ");
    scanf("%d", &key);
    pos = searchMark(marks, 10, key);
    if (pos == -1)
        printf("Mark %d not found.\n", key);
    else
        printf("Mark %d found at position %d (roll number %d).\n", key, pos, pos + 1);

    printf("\nMarks before reversing: ");
    printArray(marks, 10);
    reverseArray(marks, 10);
    printf("Marks after reversing : ");
    printArray(marks, 10);

    return 0;
}
