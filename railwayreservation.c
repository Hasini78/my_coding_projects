#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Train {
    int trainNo;
    char trainName[50];
    char source[30];
    char destination[30];
    int totalSeats;
    int bookedSeats;
    char departureTime[20];
    char arrivalTime[20];
} Train;

typedef struct TrainNode {
    int trainNo;
    Train* trainData;
    struct TrainNode* left;
    struct TrainNode* right;
} TrainNode;

typedef struct Passenger {
    int ticketNo;
    char name[50];
    int age;
    char gender;
    int trainNo;
    char bookingDateTime[30];
    struct Passenger* next;
} Passenger;

TrainNode* trainTreeRoot = NULL;
Passenger* passengerHead = NULL;
int ticketCounter = 1001;

// === TREE OPERATIONS === //
TrainNode* insertTrainNode(TrainNode* root, Train* train) {
    if (root == NULL) {
        TrainNode* node = (TrainNode*)malloc(sizeof(TrainNode));
        node->trainNo = train->trainNo;
        node->trainData = train;
        node->left = node->right = NULL;
        return node;
    }
    if (train->trainNo < root->trainNo)
        root->left = insertTrainNode(root->left, train);
    else if (train->trainNo > root->trainNo)
        root->right = insertTrainNode(root->right, train);
    return root;
}

Train* searchTrain(TrainNode* root, int trainNo) {
    if (root == NULL)
        return NULL;
    if (trainNo == root->trainNo)
        return root->trainData;
    else if (trainNo < root->trainNo)
        return searchTrain(root->left, trainNo);
    else
        return searchTrain(root->right, trainNo);
}

Train* searchTrainByName(TrainNode* root, const char* name) {
    if (root == NULL)
        return NULL;
    Train* leftSearch = searchTrainByName(root->left, name);
    if (leftSearch != NULL)
        return leftSearch;
    if (strcmp(root->trainData->trainName, name) == 0)
        return root->trainData;
    return searchTrainByName(root->right, name);
}

void displayTrainsInOrder(TrainNode* root) {
    if (root == NULL) return;
    displayTrainsInOrder(root->left);
    Train* t = root->trainData;
    printf("%-8d | %-16s | %-8s -> %-8s | %d | %-9s | %-9s\n",
           t->trainNo, t->trainName, t->source, t->destination,
           t->totalSeats - t->bookedSeats, t->departureTime, t->arrivalTime);
    displayTrainsInOrder(root->right);
}

// === CORE FUNCTIONS ===
void initializeTrains() {
    Train trains[] = {
        {1002, "Express Alpha", "Hyd", "Delhi", 100, 0, "06:00", "18:00"},
        {1092, "Shatabdi", "Chennai", "Tirupati", 180, 0, "09:00", "13:00"},
        {1103, "Rajdhani", "Mumbai", "Delhi", 120, 0, "07:00", "21:00"},
        {1084, "Duronto", "Kolkata", "Delhi", 110, 0, "05:30", "22:00"},
        {1085, "Golconda", "Delhi", "Guntur", 150, 0, "05:36", "21:00"},
        {1295, "Sangamitra", "Banglore", "Danapur", 120, 0, "04:30", "20:00"},
        {1261, "Grand Trunk", "Delhi", "Chennai", 134, 0, "02:30", "23:00"},
        {1276, "Padmavathi", "Tirupati", "Ongole", 121, 0, "01:21", "17:00"}
    };
    int n = sizeof(trains) / sizeof(trains[0]);
    for (int i = 0; i < n; ++i) {
        Train* t = (Train*)malloc(sizeof(Train));
        *t = trains[i];
        trainTreeRoot = insertTrainNode(trainTreeRoot, t);
    }
}

void viewTrains() {
    if (trainTreeRoot == NULL) {
        printf("No trains available.\n");
        return;
    }
    printf("\nTrain List:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("Train No | Train Name       | From -> To     | Seats Left | Dep. Time | Arr. Time\n");
    printf("-----------------------------------------------------------------------------\n");
    displayTrainsInOrder(trainTreeRoot);
}

void bookTicket() {
    char trainName[50];
    printf("Enter Train Name to book: ");
    scanf(" %[^\n]", trainName);
    Train* t = searchTrainByName(trainTreeRoot, trainName);
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
    p->trainNo = t->trainNo;
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
    printf("\n----- Your Ticket -----\n");
    printf("Ticket No: %d\n", p->ticketNo);
    printf("Passenger Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Gender: %c\n", p->gender);
    printf("Train No: %d\n", t->trainNo);
    printf("Train Name: %s\n", t->trainName);
    printf("Source: %s\n", t->source);
    printf("Destination: %s\n", t->destination);
    printf("Departure Time: %s\n", t->departureTime);
    printf("Arrival Time: %s\n", t->arrivalTime);
    printf("Booking Date & Time: %s\n", p->bookingDateTime);
    printf("--------------------------\n");
}

void viewBookings() {
    if (passengerHead == NULL) {
        printf("No bookings available.\n");
        return;
    }
    char trainName[50];
    printf("Enter Train Name to view bookings: ");
    scanf(" %[^\n]", trainName);
    Train* t = searchTrainByName(trainTreeRoot, trainName);
    if (t == NULL) {
        printf("Train not found!\n");
        return;
    }
    int trainNo = t->trainNo;
    printf("\nBookings for %s (Train No %d):\n", t->trainName, trainNo);
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Ticket No | Name           | Age | Gender | Booking DateTime       | Train Name     | Dep. Time | Arr. Time\n");
    printf("---------------------------------------------------------------------------------------------\n");
    Passenger* temp = passengerHead;
    while (temp != NULL) {
        if (temp->trainNo == trainNo) {
            printf("%-9d | %-14s | %-3d | %-6c | %-23s | %-14s | %-9s | %-9s\n",
                   temp->ticketNo, temp->name, temp->age, temp->gender,
                   temp->bookingDateTime, t->trainName, t->departureTime, t->arrivalTime);
        }
        temp = temp->next;
    }
}

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
    Train* t = searchTrain(trainTreeRoot, temp->trainNo);
    if (t != NULL)
        t->bookedSeats--;
    if (prev == NULL)
        passengerHead = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Ticket cancelled successfully.\n");
}

// === Main Menu ===
int main() {
    initializeTrains();
    int choice;
    do {
        printf("\n--- Railway Reservation Menu ---\n");
        printf("1. View Trains\n2. Book Ticket\n3. View Bookings\n4. Cancel Ticket\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: viewTrains(); break;
            case 2: bookTicket(); break;
            case 3: viewBookings(); break;
            case 4: cancelTicket(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}
