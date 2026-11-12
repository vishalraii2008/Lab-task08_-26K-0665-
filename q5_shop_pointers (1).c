#include <stdio.h>

int main(void)
{
    double costPrice, sellPrice, quantity;
    double totalCost, totalSales, profit, percent;

    double *pCost = &costPrice;
    double *pSell = &sellPrice;
    double *pQty = &quantity;
    double *pTotalCost = &totalCost;
    double *pTotalSales = &totalSales;
    double *pProfit = &profit;
    double *pPercent = &percent;
    double *pLarger;

    printf("Enter cost price: ");
    scanf("%lf", pCost);
    printf("Enter selling price: ");
    scanf("%lf", pSell);
    printf("Enter quantity sold: ");
    scanf("%lf", pQty);

    *pTotalCost = *pCost * *pQty;
    *pTotalSales = *pSell * *pQty;
    *pProfit = *pTotalSales - *pTotalCost;

    printf("\nTotal Cost  : %.2f\n", *pTotalCost);
    printf("Total Sales : %.2f\n", *pTotalSales);

    if (*pProfit > 0)
        printf("Result      : Profit of %.2f\n", *pProfit);
    else if (*pProfit < 0)
        printf("Result      : Loss of %.2f\n", -*pProfit);
    else
        printf("Result      : No profit no loss\n");

    if (*pTotalCost != 0)
        *pPercent = (*pProfit / *pTotalCost) * 100;
    else
        *pPercent = 0;
    printf("Profit Percentage: %.2f%%\n", *pPercent);

    if (*pCost > *pSell) {
        pLarger = pCost;
        printf("\nLarger value is costPrice = %.2f\n", *pLarger);
    } else {
        pLarger = pSell;
        printf("\nLarger value is sellPrice = %.2f\n", *pLarger);
    }

    printf("\n%-15s %-20s\n", "Name", "Address");
    printf("-------------------------------------\n");
    printf("%-15s %p\n", "costPrice", (void *)&costPrice);
    printf("%-15s %p\n", "sellPrice", (void *)&sellPrice);
    printf("%-15s %p\n", "quantity", (void *)&quantity);
    printf("%-15s %p\n", "totalCost", (void *)&totalCost);
    printf("%-15s %p\n", "totalSales", (void *)&totalSales);
    printf("%-15s %p\n", "profit", (void *)&profit);
    printf("%-15s %p\n", "percent", (void *)&percent);
    printf("%-15s %p\n", "pCost", (void *)&pCost);
    printf("%-15s %p\n", "pSell", (void *)&pSell);
    printf("%-15s %p\n", "pQty", (void *)&pQty);
    printf("%-15s %p\n", "pTotalCost", (void *)&pTotalCost);
    printf("%-15s %p\n", "pTotalSales", (void *)&pTotalSales);
    printf("%-15s %p\n", "pProfit", (void *)&pProfit);
    printf("%-15s %p\n", "pPercent", (void *)&pPercent);
    printf("%-15s %p\n", "pLarger", (void *)&pLarger);

    return 0;
}
