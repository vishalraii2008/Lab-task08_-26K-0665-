#include <stdio.h>

void printMenu(void)
{
    printf("====== MOBILE RECHARGE ======\n");
    printf("1. Rs. 100\n");
    printf("2. Rs. 200\n");
    printf("3. Rs. 500\n");
    printf("4. Rs. 1000\n");
}

int getPackNumber(void)
{
    int pack;
    do {
        printf("Enter pack number (1-4): ");
        scanf("%d", &pack);
        if (pack < 1 || pack > 4)
            printf("Invalid pack number.\n");
    } while (pack < 1 || pack > 4);
    return pack;
}

long long getMobileNumber(void)
{
    long long mobile;
    do {
        printf("Enter 11 digit mobile number: ");
        scanf("%lld", &mobile);
        if (mobile < 1000000000LL || mobile > 99999999999LL)
            printf("Invalid mobile number.\n");
    } while (mobile < 1000000000LL || mobile > 99999999999LL);
    return mobile;
}

int getPackAmount(int pack)
{
    int amount;
    switch (pack) {
        case 1: amount = 100; break;
        case 2: amount = 200; break;
        case 3: amount = 500; break;
        case 4: amount = 1000; break;
        default: amount = 0;
    }
    return amount;
}

double addTax(double amount)
{
    return amount + amount * 0.15;
}

double getBonus(double amount)
{
    if (amount >= 500)
        return amount * 0.10;
    return 0;
}

void printSlip(long long mobile, double amount, double tax, double totalBalance)
{
    printf("\n------ RECHARGE SLIP ------\n");
    printf("Mobile Number : %011lld\n", mobile);
    printf("Amount        : Rs. %.2f\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Total Balance : Rs. %.2f\n", totalBalance);
    printf("---------------------------\n\n");
}

int main(void)
{
    int i, pack;
    long long mobile;
    double amount, newAmount, tax, bonus, totalBalance;
    double totalSpent = 0;

    for (i = 1; i <= 3; i++) {
        printf("\n*** Recharge %d of 3 ***\n", i);
        printMenu();
        pack = getPackNumber();
        mobile = getMobileNumber();
        amount = getPackAmount(pack);
        newAmount = addTax(amount);
        tax = newAmount - amount;
        bonus = getBonus(amount);
        totalBalance = amount + bonus;
        printSlip(mobile, amount, tax, totalBalance);
        totalSpent += newAmount;
    }

    printf("Total money spent: Rs. %.2f\n", totalSpent);
    return 0;
}
