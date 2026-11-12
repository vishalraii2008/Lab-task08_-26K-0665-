#include <stdio.h>
#include <string.h>

void printRoomCharges(void)
{
    printf("====== CITY HOSPITAL ======\n");
    printf("1. General Ward  - Rs. 1500/day\n");
    printf("2. Semi-Private  - Rs. 3500/day\n");
    printf("3. Private       - Rs. 6000/day\n");
}

int getRoomType(void)
{
    int room;
    do {
        printf("Enter room type (1-3): ");
        scanf("%d", &room);
        if (room < 1 || room > 3)
            printf("Invalid room type.\n");
    } while (room < 1 || room > 3);
    return room;
}

int getDays(void)
{
    int days;
    do {
        printf("Enter number of days stayed (1-30): ");
        scanf("%d", &days);
        if (days < 1 || days > 30)
            printf("Invalid number of days.\n");
    } while (days < 1 || days > 30);
    return days;
}

void getRoomName(int room, char name[])
{
    if (room == 1)
        strcpy(name, "General Ward");
    else if (room == 2)
        strcpy(name, "Semi-Private");
    else
        strcpy(name, "Private");
}

double getRoomCharges(int room, int days)
{
    double rate;
    if (room == 1)
        rate = 1500;
    else if (room == 2)
        rate = 3500;
    else
        rate = 6000;
    return rate * days;
}

double getMedicineCharge(double medicineBill)
{
    return medicineBill + medicineBill * 0.05;
}

double applyDiscount(double total, int days)
{
    if (days >= 7)
        return total - total * 0.08;
    return total;
}

void printBill(char roomName[], int days, double roomCharges, double medicineCharges, double finalAmount)
{
    printf("\n------ FINAL BILL ------\n");
    printf("Room Type        : %s\n", roomName);
    printf("Days Stayed      : %d\n", days);
    printf("Room Charges     : Rs. %.2f\n", roomCharges);
    printf("Medicine Charges : Rs. %.2f\n", medicineCharges);
    printf("Final Amount     : Rs. %.2f\n", finalAmount);
    printf("------------------------\n");
}

int main(void)
{
    int room, days;
    char roomName[20];
    char senior;
    double medicineBill, roomCharges, medicineCharges, total, finalAmount;

    printRoomCharges();
    room = getRoomType();
    days = getDays();

    printf("Enter medicine bill: ");
    scanf("%lf", &medicineBill);

    getRoomName(room, roomName);
    roomCharges = getRoomCharges(room, days);
    medicineCharges = getMedicineCharge(medicineBill);
    total = roomCharges + medicineCharges;
    finalAmount = applyDiscount(total, days);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);
    if (senior == 'y' || senior == 'Y') {
        finalAmount -= 1000;
        if (finalAmount < 0)
            finalAmount = 0;
    }

    printBill(roomName, days, roomCharges, medicineCharges, finalAmount);
    return 0;
}
