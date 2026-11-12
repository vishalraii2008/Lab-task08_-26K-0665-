#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3)
{
    do {
        printf("Enter marks of subject 1 (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);
    do {
        printf("Enter marks of subject 2 (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);
    do {
        printf("Enter marks of subject 3 (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest)
{
    *total = m1 + m2 + m3;
    *average = *total / 3.0;
    *highest = m1;
    *lowest = m1;
    if (m2 > *highest)
        *highest = m2;
    if (m3 > *highest)
        *highest = m3;
    if (m2 < *lowest)
        *lowest = m2;
    if (m3 < *lowest)
        *lowest = m3;
}

void swapMarks(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortMarks(int *m1, int *m2, int *m3)
{
    if (*m1 < *m2)
        swapMarks(m1, m2);
    if (*m1 < *m3)
        swapMarks(m1, m3);
    if (*m2 < *m3)
        swapMarks(m2, m3);
}

void addGraceMarks(int *mark, int grace)
{
    int add;
    if (*mark >= 35 && *mark <= 39) {
        add = grace;
        if (add > 5)
            add = 5;
        if (*mark + add > 40)
            add = 40 - *mark;
        *mark += add;
    }
}

void findGrade(double avg, char *grade, char *remarks)
{
    if (avg >= 80) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    } else if (avg >= 60) {
        *grade = 'B';
        strcpy(remarks, "Good");
    } else {
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x)
{
    x++;
}

void incrementByReference(int *x)
{
    (*x)++;
}

int main(void)
{
    int i, m1, m2, m3;
    int total[5], highest, lowest;
    double average[5];
    char grade[5];
    char remarks[5][20];
    int num = 10;

    for (i = 0; i < 5; i++) {
        printf("\n*** Student %d ***\n", i + 1);
        readMarks(&m1, &m2, &m3);
        addGraceMarks(&m1, 5);
        addGraceMarks(&m2, 5);
        addGraceMarks(&m3, 5);
        sortMarks(&m1, &m2, &m3);
        calculateStats(m1, m2, m3, &total[i], &average[i], &highest, &lowest);
        findGrade(average[i], &grade[i], remarks[i]);
        printf("Sorted marks: %d %d %d (Highest: %d, Lowest: %d)\n", m1, m2, m3, highest, lowest);
    }

    printf("\n%-10s %-8s %-10s %-7s %-20s\n", "Student", "Total", "Average", "Grade", "Remarks");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < 5; i++)
        printf("%-10d %-8d %-10.2f %-7c %-20s\n", i + 1, total[i], average[i], grade[i], remarks[i]);

    printf("\n--- Comparison Demo ---\n");
    printf("Before: num = %d\n", num);
    incrementByValue(num);
    printf("After incrementByValue(num): num = %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference(&num): num = %d\n", num);
    printf("incrementByValue changes only a copy of num, so the original stays the same.\n");
    printf("incrementByReference works on the original variable's address, so num changes.\n");

    return 0;
}
