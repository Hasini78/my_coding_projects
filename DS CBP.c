#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // For handling time and date

typedef struct Train {
    int trainNo;
    char trainName[50];
    char source[30];
    char destination[30];
    int totalSeats;
    int bookedSeats;
    char departureTime[20]; // Time of departure (e.g., "HH:MM")
    char arrivalTime[20];   // Time of arrival (e.g., "HH:MM")
    struct Train* next;
} Train;

typedef struct Passenger {
    int ticketNo;
    char name[50];
    int age;
    char gender;
    int trainNo; // Associated train number
    char bookingDateTime[30]; // Booking date and time
    struct Passenger* next;
} Passenger;

Train* trainHead = NULL;
Passenger* passengerHead = NULL;
int ticketCounter = 1001;

// PART 2: Add Train Function
void addTrain() {
    Train* newTrain = (Train*)malloc(sizeof(Train));
    
    printf("Enter Train No: ");
    scanf("%d", &newTrain->trainNo);
    printf("Enter Train Name: ");
    scanf(" %[^\n]", newTrain->trainName);
    printf("Enter Source: ");
    scanf(" %[^\n]", newTrain->source);
    printf("Enter Destination: ");
    scanf(" %[^\n]", newTrain->destination);
    printf("Enter Total Seats: ");
    scanf("%d", &newTrain->totalSeats);
    printf("Enter Departure Time (HH:MM): ");
    scanf(" %[^\n]", newTrain->departureTime);
    printf("Enter Arrival Time (HH:MM): ");
    scanf(" %[^\n]", newTrain->arrivalTime);
    
    newTrain->bookedSeats = 0;
    newTrain->next = trainHead;
    trainHead = newTrain;

    printf("Train added successfully!\n");
}

// PART 3: View All Trains
void viewTrains() {
    if (trainHead == NULL) {
        printf("No trains available.\n");
        return;
    }

    Train* temp = trainHead;
    printf("\nTrain List:\n");
    printf("--------------------------------------------------------------\n");
    printf("Train No | Train Name       | From     -> To     | Seats Left | Dep. Time | Arr. Time\n");
    printf("--------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-8d | %-16s | %-8s -> %-8s | %d          | %-9s | %-9s\n",
            temp->trainNo, temp->trainName, temp->source,
            temp->destination, temp->totalSeats - temp->bookedSeats,
            temp->departureTime, temp->arrivalTime);
        temp = temp->next;
    }
}

// PART 4: Book Ticket for a Train
void bookTicket() {
    int trainNo;
    printf("Enter Train No to book: ");
    scanf("%d", &trainNo);

    Train* t = trainHead;
    while (t != NULL && t->trainNo != trainNo)
        t = t->next;

    if (t == NULL) {
        printf("Train not found!\n");
        return;
    }

    if (t->bookedSeats >= t->totalSeats) {
        printf("No seats available on this train.\n");
        return;
    }

    Passenger* p = (Passenger*)malloc(sizeof(Passenger));
    p->ticketNo = ticketCounter++;
    p->trainNo = trainNo;

    // Capture the booking date and time
    time_t now;
    time(&now);
    struct tm* local = localtime(&now);
    strftime(p->bookingDateTime, sizeof(p->bookingDateTime), "%Y-%m-%d %H:%M:%S", local);

    printf("Enter Name: ");
    scanf(" %[^\n]", p->name);
    printf("Enter Age: ");
    scanf("%d", &p->age);
    printf("Enter Gender (M/F): ");
    scanf(" %c", &p->gender);

    p->next = passengerHead;
    passengerHead = p;

    t->bookedSeats++;
    printf("Ticket booked successfully! Ticket No: %d\n", p->ticketNo);

    // Generate and display the ticket
    printf("\n========================= TICKET ============================\n");
printf("| %-12s: %-10d | %-12s: %-20s |\n", "Ticket No", p->ticketNo, "Passenger", p->name);
printf("| %-12s: %-10d | %-12s: %-20c |\n", "Age", p->age, "Gender", p->gender);
printf("-------------------------------------------------------------\n");
printf("| %-12s: %-10d | %-12s: %-20s |\n", "Train No", t->trainNo, "Train Name", t->trainName);
printf("| %-12s: %-10s | %-12s: %-20s |\n", "From", t->source, "To", t->destination);
printf("| %-12s: %-10s | %-12s: %-20s |\n", "Departure", t->departureTime, "Arrival", t->arrivalTime);
printf("-------------------------------------------------------------\n");
printf("| Booking Date & Time: %-35s |\n", p->bookingDateTime);
printf("=============================================================\n");


}

// PART 5: View Bookings by Train
void viewBookings() {
    if (passengerHead == NULL) {
        printf("No bookings available.\n");
        return;
    }

    int trainNo;
    printf("Enter Train No to view bookings: ");
    scanf("%d", &trainNo);

    Passenger* temp = passengerHead;
    printf("\nBookings for Train No %d:\n", trainNo);
    printf("------------------------------------------------------------\n");
    printf("Ticket No | Name           | Age | Gender | Booking DateTime        | Train No | Train Name       | Dep. Time | Arr. Time\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {
        if (temp->trainNo == trainNo) {
            Train* t = trainHead;
            while (t != NULL && t->trainNo != temp->trainNo)
                t = t->next;
            
            if (t != NULL) {
                printf("%-9d | %-14s | %-3d | %-6c | %-23s | %-8d | %-16s | %-9s | %-9s\n",
                    temp->ticketNo, temp->name, temp->age, temp->gender,
                    temp->bookingDateTime, t->trainNo, t->trainName, t->departureTime, t->arrivalTime);
            }
        }
        temp = temp->next;
    }
}

// PART 6: Cancel Ticket
void cancelTicket() {
    int ticket;
    printf("Enter Ticket No to cancel: ");
    scanf("%d", &ticket);

    Passenger* temp = passengerHead;
    Passenger* prev = NULL;

    while (temp != NULL && temp->ticketNo != ticket) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Ticket not found!\n");
        return;
    }

    Train* t = trainHead;
    while (t != NULL && t->trainNo != temp->trainNo)
        t = t->next;

    if (t != NULL)
        t->bookedSeats--;

    if (prev == NULL)
        passengerHead = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Ticket cancelled successfully.\n");
}

// PART 7: Main Menu
int main() {
    int choice;

    do {
        printf("\n--- Railway Reservation Menu ---\n");
        printf("1. Add Train\n2. View Trains\n3. Book Ticket\n4. View Bookings\n");
        printf("5. Cancel Ticket\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTrain(); break;
            case 2: viewTrains(); break;
            case 3: bookTicket(); break;
            case 4: viewBookings(); break;
            case 5: cancelTicket(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
