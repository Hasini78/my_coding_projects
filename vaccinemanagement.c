#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//vaccine management system
struct Details {
    int id;
    int age;
    char firstname[100];
    char lastname[100];
    int year, month, day;
    char phone[15];
    char address[100];
};

void registerCitizen();
void listCitizens();
void searchProfile();
void displayMenu();
void displayDateTime();

int main() {
    displayMenu();
    return 0;
}

void displayDateTime() {
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    printf("Current Date: %02d-%02d-%d\n",
           localTime->tm_mday,
           localTime->tm_mon + 1,   // Months are 0-based
           localTime->tm_year + 1900); // Years since 1900
    printf("Current Time: %02d:%02d:%02d\n",
           localTime->tm_hour,
           localTime->tm_min,
           localTime->tm_sec);
    printf("==============================================\n");
}

void displayMenu() {
    int choice;
    do {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printf("==============================================\n");
        printf("* Vaccine Registration *\n");
        printf("==============================================\n");
        displayDateTime();
        printf("1. Register Citizen\n");
        printf("2. Citizen List\n");
        printf("3. Search Your Profile\n");
        printf("4. Exit\n");
        printf("==============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline left in buffer

        switch (choice) {
            case 1:
                registerCitizen();
                break;
            case 2:
                listCitizens();
                break;
            case 3:
                searchProfile();
                break;
            case 4:
                printf("Exiting the program. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
#ifdef _WIN32
                system("pause");
#else
                printf("Press Enter to continue...");
                getchar();
#endif
        }
    } while (choice != 4);
}

void registerCitizen() {
    FILE *file = fopen("citizens.txt", "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    struct Details citizen;
    printf("Enter ID: ");
    scanf("%d", &citizen.id);
    getchar(); // Clear newline

    printf("Enter First Name: ");
    scanf("%s", citizen.firstname);

    printf("Enter Last Name: ");
    scanf("%s", citizen.lastname);

    printf("Enter Date of Birth (YYYY MM DD): ");
    scanf("%d %d %d", &citizen.year, &citizen.month, &citizen.day);

    citizen.age = 2024 - citizen.year;
    if (citizen.age < 18) {
        printf("You must be at least 18 years old to register.\n");
#ifdef _WIN32
        system("pause");
#else
        printf("Press Enter to continue...");
        getchar();
        getchar();
#endif
        fclose(file);
        return;
    }

    printf("Enter Phone Number: ");
    scanf("%s", citizen.phone);

    printf("Enter Address: ");
    getchar(); // clear buffer
    fgets(citizen.address, sizeof(citizen.address), stdin);
    citizen.address[strcspn(citizen.address, "\n")] = '\0'; // remove newline

    fprintf(file, "%d,%s,%s,%d-%d-%d,%d,%s,%s\n",
            citizen.id, citizen.firstname, citizen.lastname,
            citizen.year, citizen.month, citizen.day,
            citizen.age, citizen.phone, citizen.address);

    printf("Registration successful!\n");
    fclose(file);

#ifdef _WIN32
    system("pause");
#else
    printf("Press Enter to continue...");
    getchar();
#endif
}

void listCitizens() {
    FILE *file = fopen("citizens.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    struct Details citizen;
    char line[256];
    int isEmpty = 1;

    printf("=== Citizen List ===\n");
    printf("ID   First Name  Last Name   DOB         Age  Phone         Address\n");
    printf("---------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d,%99[^,],%99[^,],%d-%d-%d,%d,%14[^,],%99[^\n]",
                   &citizen.id, citizen.firstname, citizen.lastname,
                   &citizen.year, &citizen.month, &citizen.day,
                   &citizen.age, citizen.phone, citizen.address) == 9) {
            printf("%-4d %-11s %-11s %02d-%02d-%d %-4d %-12s %-15s\n",
                   citizen.id, citizen.firstname, citizen.lastname,
                   citizen.day, citizen.month, citizen.year,
                   citizen.age, citizen.phone, citizen.address);
            isEmpty = 0;
        }
    }

    if (isEmpty) {
        printf("No citizens registered yet.\n");
    }

    fclose(file);
    printf("Press Enter to return to the menu...");
    getchar();
}

void searchProfile() {
    FILE *file = fopen("citizens.txt", "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int searchId, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &searchId);
    getchar(); // clear buffer

    struct Details citizen;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d,%99[^,],%99[^,],%d-%d-%d,%d,%14[^,],%99[^\n]",
                   &citizen.id, citizen.firstname, citizen.lastname,
                   &citizen.year, &citizen.month, &citizen.day,
                   &citizen.age, citizen.phone, citizen.address) == 9) {
            if (citizen.id == searchId) {
                printf("Profile Found:\n");
                printf("ID: %d\n", citizen.id);
                printf("Name: %s %s\n", citizen.firstname, citizen.lastname);
                printf("DOB: %02d-%02d-%d\n", citizen.day, citizen.month, citizen.year);
                printf("Age: %d\n", citizen.age);
                printf("Phone: %s\n", citizen.phone);
                printf("Address: %s\n", citizen.address);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Profile not found.\n");
    }

    fclose(file);
    printf("Press Enter to continue...");
    getchar();
}
