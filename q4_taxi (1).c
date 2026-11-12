#include <stdio.h>

void printRules(void)
{
    printf("====== TAXI FARE CALCULATOR ======\n");
    printf("Base fare: Rs. 150\n");
    printf("First 10 km: Rs. 60 per km\n");
    printf("After 10 km: Rs. 45 per km\n");
    printf("Waiting: first 5 minutes free, then Rs. 10 per minute\n");
    printf("Night charge (10 PM to 6 AM): 25%% extra\n");
}

double getDistance(void)
{
    double distance;
    do {
        printf("Enter distance in km (more than 0, up to 200): ");
        scanf("%lf", &distance);
        if (distance <= 0 || distance > 200)
            printf("Invalid distance.\n");
    } while (distance <= 0 || distance > 200);
    return distance;
}

int getWaitingTime(void)
{
    int waiting;
    do {
        printf("Enter waiting time in minutes (0-120): ");
        scanf("%d", &waiting);
        if (waiting < 0 || waiting > 120)
            printf("Invalid waiting time.\n");
    } while (waiting < 0 || waiting > 120);
    return waiting;
}

int getHour(void)
{
    int hour;
    do {
        printf("Enter hour of the trip (0-23): ");
        scanf("%d", &hour);
        if (hour < 0 || hour > 23)
            printf("Invalid hour.\n");
    } while (hour < 0 || hour > 23);
    return hour;
}

double getDistanceCharge(double distance)
{
    double charge;
    if (distance <= 10)
        charge = distance * 60;
    else
        charge = 10 * 60 + (distance - 10) * 45;
    return charge;
}

double getWaitingCharge(int waiting)
{
    if (waiting <= 5)
        return 0;
    return (waiting - 5) * 10;
}

double addNightCharge(double fare, int hour)
{
    if (hour >= 22 || hour < 6)
        return fare + fare * 0.25;
    return fare;
}

void printReceipt(double distance, int waiting, double finalFare)
{
    printf("\n------ TRIP RECEIPT ------\n");
    printf("Distance     : %.2f km\n", distance);
    printf("Waiting Time : %d minutes\n", waiting);
    printf("Final Fare   : Rs. %.2f\n", finalFare);
    printf("--------------------------\n\n");
}

int main(void)
{
    int i, waiting, hour;
    double distance, fare, finalFare;
    double totalEarnings = 0;
    double highest = 0;

    printRules();

    for (i = 1; i <= 3; i++) {
        printf("\n*** Trip %d of 3 ***\n", i);
        distance = getDistance();
        waiting = getWaitingTime();
        hour = getHour();

        fare = 150 + getDistanceCharge(distance) + getWaitingCharge(waiting);
        finalFare = addNightCharge(fare, hour);

        printReceipt(distance, waiting, finalFare);

        totalEarnings += finalFare;
        if (finalFare > highest)
            highest = finalFare;
    }

    printf("Total earnings: Rs. %.2f\n", totalEarnings);
    printf("Highest fare of the day: Rs. %.2f\n", highest);
    return 0;
}
