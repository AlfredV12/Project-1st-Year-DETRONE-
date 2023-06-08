#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_USERS 100
#define MAX_MOVIES 100
#define MAX_THEATRE_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
    char gender[10];
} User;

typedef struct {
    char movieName[MAX_NAME_LENGTH];
    char timeSlot[50];
    int seatsTaken;
    char theatre[MAX_THEATRE_LENGTH];
} Movie;

typedef struct {
    User users[MAX_USERS];
    int numUsers;
} UserDatabase;

typedef struct {
    Movie movies[MAX_MOVIES];
    int numMovies;
} MovieDatabase;

void signUp(UserDatabase *database) {
    if (database->numUsers >= MAX_USERS) {
        printf("Database is full. Cannot add more users.\n");
        return;
    }

    User *user = &(database->users[database->numUsers]);

    printf("=== Sign Up for getting your Ticket ===\n");
    printf("***************\n");
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &(user->age));

    printf("Enter your email: ");
    scanf("%s", user->email);

    printf("Enter your gender: ");
    scanf("%s", user->gender);

    database->numUsers++;
}

void displayUsers(const UserDatabase *database) {
    printf("\n");
    printf("User detalis Print out\n");
    printf("\n");
    printf("|~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("|No. | Name                | Age | Email                  | Gender|\n");
    printf("|-----------------------------------------------------------------|\n");
    for (int i = 0; i < database->numUsers; i++) {
        const User *user = &(database->users[i]);
        printf("%-4d|%-20s|%-5d|%-24s|%-7s\n", i + 1, user->name, user->age, user->email, user->gender);
    }
    printf("-----------------------------------------------------------------\n");
}

void addMovie(MovieDatabase *database) {
    if (database->numMovies >= MAX_MOVIES) {
        printf("Database is full. Cannot add more movies.\n");
        return;
    }

    Movie *movie = &(database->movies[database->numMovies]);

    printf("=== Add Movie ===\n");

    printf("Enter movie name: ");
    scanf("%s", movie->movieName);

    printf("Enter timeslot: ");
    scanf("%s", movie->timeSlot);

    printf("Enter seats taken: ");
    scanf("%d", &movie->seatsTaken);

    printf("Enter theatre: ");
    scanf("%s", movie->theatre);

    database->numMovies++;
}

void displayMovies(const MovieDatabase *database) {
    printf("\n");
    printf("=== DETRONE e-Ticket ===\n");
    printf("###########################\n");
    printf("\n");
    printf("No. | Movie Name           | Timeslot         | Seats Taken | Theatre\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; c; i++) {
        const Movie *movie = &(database->movies[i]);
        printf("%-4d|%-21s|%-18s|%-13d|%-7s\n", i + 1, movie->movieName, movie->timeSlot, movie->seatsTaken, movie->theatre);
    }
    printf("---------------------------------------------------------------------\n");
}

int main() {
    printf( "                                       Welcome to DETRONE e-Ticket Print out section\n");
    printf("*********************************************\n");
    UserDatabase userDatabase;
    userDatabase.numUsers = 0;

    MovieDatabase movieDatabase;
    movieDatabase.numMovies = 0;

    int choice;

    do {
        printf("=== E-TICKET GENERATOR SYSYTEM ===\n");
        printf("___________\n");
        printf("\n");
        printf("1.Login\n");
        printf("2. Print the Login slip\n");
        printf("3. Add Detalis for your e-ticket \n");
        printf("4. Print e-ticket\n");
        printf("0. Logout\n");
        printf("\n");
        printf(":::::::::::::::::::::\n");
        printf("Enter your choice:-");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                signUp(&userDatabase);
                printf("{Hint: Now please Press >> 2 << for getting your login e-slip}\n");
                break;
            case 2:
                displayUsers(&userDatabase);
                break;
            case 3:
                addMovie(&movieDatabase);
                break;
            case 4:
                displayMovies(&movieDatabase);
                break;
            case 0:
                printf("Logging out\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        fflush(stdout);
        printf("\n");
    } while (choice != 0);

    return 0;
}
