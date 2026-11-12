#include <stdio.h>
#include <string.h>

void printRoutes(void)
{
    printf("====== BUS TICKET BOOKING ======\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}

int getRouteNumber(void)
{
    int route;
    do {
        printf("Enter route number (1-3): ");
        scanf("%d", &route);
        if (route < 1 || route > 3)
            printf("Invalid route number.\n");
    } while (route < 1 || route > 3);
    return route;
}

int getSeats(void)
{
    int seats;
    do {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &seats);
        if (seats < 1 || seats > 6)
            printf("Invalid number of seats.\n");
    } while (seats < 1 || seats > 6);
    return seats;
}

char getSeatType(void)
{
    char type;
    do {
        printf("Enter seat type (E = Economy, B = Business): ");
        scanf(" %c", &type);
        if (type == 'e')
            type = 'E';
        if (type == 'b')
            type = 'B';
        if (type != 'E' && type != 'B')
            printf("Invalid seat type.\n");
    } while (type != 'E' && type != 'B');
    return type;
}

double getSeatFare(int route)
{
    if (route == 1)
        return 800;
    if (route == 2)
        return 2200;
    return 3500;
}

double getTotalFare(double seatFare, int seats)
{
    return seatFare * seats;
}

double addSeatTypeCharge(double total, char type)
{
    if (type == 'B')
        return total + total * 0.30;
    return total;
}

void getRouteName(int route, char name[])
{
    if (route == 1)
        strcpy(name, "Karachi to Hyderabad");
    else if (route == 2)
        strcpy(name, "Karachi to Sukkur");
    else
        strcpy(name, "Karachi to Multan");
}

void printTicket(char routeName[], int seats, char type, double finalFare)
{
    printf("\n------ BUS TICKET ------\n");
    printf("Route      : %s\n", routeName);
    printf("Seats      : %d\n", seats);
    printf("Seat Type  : %s\n", type == 'B' ? "Business" : "Economy");
    printf("Final Fare : Rs. %.2f\n", finalFare);
    printf("------------------------\n\n");
}

int main(void)
{
    int i, route, seats;
    char type, routeName[30];
    double seatFare, total, finalFare;
    double totalEarnings = 0;

    for (i = 1; i <= 2; i++) {
        printf("\n*** Passenger %d of 2 ***\n", i);
        printRoutes();
        route = getRouteNumber();
        seats = getSeats();
        type = getSeatType();

        seatFare = getSeatFare(route);
        total = getTotalFare(seatFare, seats);
        finalFare = addSeatTypeCharge(total, type);
        getRouteName(route, routeName);

        printTicket(routeName, seats, type, finalFare);
        totalEarnings += finalFare;
    }

    printf("Total earnings of the bus company: Rs. %.2f\n", totalEarnings);
    return 0;
}
