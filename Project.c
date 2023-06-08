#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10




typedef struct {
    char name[50];
    char genre[20];
    float rating;
    char timing[20];
    unsigned int tickavail;
    unsigned int price;
} Movie;




Movie database[MAX_MOVIES];
int numMovies = 0;

void addMovie(const char *name, const char *genre, float rating, const char *timing, unsigned int tickavail, unsigned int price) {
    if (numMovies < MAX_MOVIES) {
        strcpy(database[numMovies].name, name);
        strcpy(database[numMovies].genre, genre);
        database[numMovies].rating = rating;
        strcpy(database[numMovies].timing, timing);
        database[numMovies].tickavail = tickavail;
        database[numMovies].price = price;
        numMovies++;
    } else {
        printf("Database is full. Cannot add more movies.\n");
    }
}

void createDatabase() {
    addMovie("John Wick","Action-packed movie.",8.2," 10:00 AM to 01:00PM", 100, 3);
    addMovie("World War Z","zombie outbreak.", 7.0, "02:00 PM to 5:00  PM", 150, 2);
    addMovie("Avengers", "Superheroes team .", 8.5, "06:00 PM to 08:30 PM", 200, 5);
    addMovie("Batman V Superman","The Dark.",  6.4,  "09:30 PM to 12:30 AM", 120, 10);
    addMovie("Mission Impossible","Elite."   , 7.7,"  01:00 AM to 02:30 AM",   80, 8);
    addMovie("Lagaan", "Patriotism       ",    8.1,   "06:00 AM to 08:00 AM", 100, 4);
    addMovie("Laal Singh Chaddha", "Inspirational", 7.9, "08:30 PM to 09:40 PM", 150,7);
}

void displayMovies() {
    printf("\n");
    printf("List of Movies or Shows Available:\n");
    printf("=====================================================================================================================================\n");
    printf("No. | Name                | Synopsis                  | Rating |         Timing              | Available Tickets| Price\n");
    printf("======================================================================================================================================\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%-4d|%-20s|%-30s|%-6.1f| %-28s|%-18u|$%-3u\n", i + 1, database[i].name, database[i].genre, database[i].rating, database[i].timing, database[i].tickavail, database[i].price);
    }
    printf("=======================================================================================================================================\n");
}

void getNumberOfSeats() {
    int numSeats;
    printf("\n");
    printf("Enter the number of seats you want to book: ");
    scanf("%d", &numSeats);
    printf("Number of seats selected: %d\n", numSeats);
}

void getTimings() {
    printf("\n");
    printf("Available Timings:\n");
    printf("1. 10:00 AM to 1:00  PM\n");
    printf("2.  2:00 PM to 5:00  PM\n");
    printf("3.  6:00 PM to 8:30  PM\n");
    printf("4.  9:30 PM to 12:30 AM\n");
    printf("5.  1:00 AM to 02:30 AM\n");
    printf("6.  6:00 AM to 8:00  AM\n");
    printf("7.  8:30 AM to 9:45  AM\n");

    int choice;
    printf("Enter your preferred timing for watching Movies or shows: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Timing selected: 10:00 AM to 1:00 PM\n");
            break;
        case 2:
            printf("Timing selected: 2:00 PM to 5:00 PM\n");
            break;
        case 3:
            printf("Timing selected: 6:00 PM  to 8:30 PM\n");
            break;
        case 4:
            printf("Timing selected: 9:30 PM to 12:30 AM\n");
            break;
        case 5:
            printf("Timing selected: 01:00 AM to 2:30 AM\n");
            break;
        case 6:
            printf("Timing selected: 6:00 AM to 8:00 AM\n");
            break;
        case 7:
            printf("Timing selected: 8:30 AM to 9:30 AM\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void getTheatres() {
    printf("\n");
    printf("Available Theatres:\n");
    printf("1. PVR\n");
    printf("2. INOX\n");
    printf("3. BIG CINEMA\n");
    printf("4. CINEPOLIS\n");
    printf("5. DETRONE\n");

    int choice;
    printf("Enter your preferred cinema for watching Movies or shows: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Theatre selected: PVR\n");
            break;
        case 2:
            printf("Theatre selected: INOX\n");
            break;
        case 3:
            printf("Theatre selected: BIG CINEMA\n");
            break;
        case 4:
            printf("Theatre selected: CINEPOLIS\n");
            break;
        case 5:
            printf("Theatre selected: DETRONE\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void purchaseTickets() {
    int movieChoice;
    printf("\n");
    printf("Confirm the movie Number for which you want to purchase tickets: ");
    scanf("%d", &movieChoice);

    if (movieChoice < 1 || movieChoice > numMovies) {
        printf("Invalid movie choice!\n");
        return;
    }

    Movie selectedMovie = database[movieChoice - 1];

    int numSeats;
    printf("Enter the number of Tickets you want to purchase: ");
    scanf("%d", &numSeats);

    if (numSeats > selectedMovie.tickavail) {
        printf("Not enough tickets available!\n");
        return;
    }

    selectedMovie.tickavail-=numSeats;

    float ticketPrice = selectedMovie.price;
    float totalCost = ticketPrice * numSeats;

    printf("Successfully purchased %d ticket(s) for %s!\n", numSeats, selectedMovie.name);
    printf("Total cost: $%.2f\n", totalCost);
}

int main() {
    createDatabase();

    int choice;
    int movieChoice;
    char city[50];
    char state[50];
    printf("Assignment Name: PROJECT-1\n");
    printf("Program: Bachelor of Technology(BTECH)\n");
    printf("College: National Institute of Technology Delhi, 2023\n");
    printf("Branch:  Computer Science Engineering\n");
    printf("Year: 1st\n");
    printf("Semester: 2nd\n");
    printf("Submitted to: Dr.Jaspinder Mam\n");
    printf("\n");

    do {

        printf("                                                 WELCOME TO {DETRONE} TICKET BOOKING SYSTEM \n");
        printf("=================================================***************=========================================\n");
        printf("\n");
        printf("                                                   >> BOOK YOUR MOVIES AND SHOWS WITH US <<                \n");
        printf("\n");
        printf("\n");
        printf("MENU\n");
        printf("~~~                                                                   \n");
        printf("                                                                                    \n");
        printf("Press (1): List of movies or shows available                                         \n");
        printf("Press (2): Number of seats you want to book                                           \n");
        printf("Press (3): Timings for Movies or Shows                                                \n");
        printf("Press (4): Select your favorite theater                                                \n");
        printf("Press (5): Choose your city/state\n");
        printf("Press (6): Purchase your tickets          \n")  ;
        printf("                                                                                    \n");
        printf(">>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<                                           \n");
        printf("Press (0): CONFIRM BOOKING                                                       \n");
        printf(">>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<                                            \n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("=====================================\n");
                printf("        AVAILABLE MOVIES\n");
                printf("=====================================\n");
                displayMovies();
                printf("Enter the movie number you want to watch: ");
                scanf("%d", &movieChoice);
                printf("You have selected movie number %d for watching\n", movieChoice);
                printf("\n");
                printf("_______________________________\n");
                printf("> HINT : Now you can book your seat by >>Pressing 2<< for further booking process <\n");
                printf("_______________________________\n");
                break;
            case 2:
                printf("=====================================\n");
                printf("          NUMBER OF SEATS\n");
                printf("=====================================\n");
                getNumberOfSeats();
                printf("\n");
                printf("___________________________\n");
                printf("~> HINT : Now you can choose your time slot for your show by >> Pressing 3 <<\n");
                printf("____________________________\n");
                break;
            case 3:
                printf("=====================================\n");
                printf("         TIMINGS FOR MOVIES\n");
                printf("=====================================\n");
                getTimings();
                printf("\n");
                printf("________________________________________\n");
                printf(" HINT : Now you can book your preferred theater for watching the movie or show you have chosen by >> Pressing 4 <<\n");
                printf("_________________________________________\n");
                break;
            case 4:
                printf("=====================================\n");
                printf("     SELECT YOUR FAVORITE THEATER \n");
                printf("=====================================\n");
                getTheatres();
                printf("\n");
                printf("___________________________________\n");
                printf(" ~> HINT : You can select your city/state where you want to watch the show or movie >> Pressing 5 <<\n");
                printf("____________________________________\n");
                break;
            case 5:
                printf("Enter the city: ");
                 scanf("%s", city);

                printf("Enter the state: ");
                 scanf("%s", state);

                printf("You have selected City as %s\n", city);
                printf("You have selected %s as State\n", state);
                printf("___________________________________\n");
                printf(" ~> HINT : Now you can  buy ticket >> Pressing 6 <<\n");
                printf("____________________________________\n");
                break;
            case 6:
                printf("=====================================\n");
                printf("        PURCHASE TICKETS\n");
                printf("=====================================\n");
                purchaseTickets();
                printf("___________________\n");
                printf(" HINT : Now >> Press 0 << for Confirming your Ticket\n");
                printf("___________________\n");
                break;
            case 0:
                printf("==============================================\n");
                printf("               TICKET CONFIRMED \n");
                printf("==============================================\n");
                printf("\n");
                printf(" _________________\n");
                printf("|            #### BOOKING SUCCESSFUL ####      |\n");
                printf("|     Thank You for doing Your booking with us |\n");
                printf("|          * Enjoy Your Show *                 |\n");
                printf("|_________________|\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 0);
    printf("\n");
    printf("Creators : Anupam   (221210023)\n");
    printf("           Alfred   (221210016)\n");
    printf("           Ankit    (221210020)\n");
    printf("           Bhanot   (221210029)\n");
    printf("           Ayushman (221210028)\n");

    return 0;
}
