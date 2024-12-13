#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void restaurant(int n);
float calculateBill(float prices[], int numItems);
bool isValidEmail(const char *email);

char registeredUsername[20];
char registeredEmail[50];
char registeredPassword[20];
char deliveryAddress[100];


bool isValidEmail(const char *email) {
    int atSymbol = -1, dotSymbol = -1;
    int length = strlen(email);

    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atSymbol = i;
        } else if (atSymbol != -1 && email[i] == '.') {
            dotSymbol = i;
        }
    }
    return (atSymbol > 0 && dotSymbol > atSymbol + 1 && dotSymbol < length - 1);
}


void signUp() {
    printf("\t\t\t\t\t\tWELCOME TO FOODIES\n\n\n");
    printf("---- Sign Up ----\n");
    printf("Enter username: ");
    scanf("%s", registeredUsername);


    do {
        printf("Enter email: ");
        scanf("%s", registeredEmail);
        if (!isValidEmail(registeredEmail)) {
            printf("Invalid email format. Please enter a valid email.\n");
        }
    } while (!isValidEmail(registeredEmail));


    do {
        printf("Enter password: ");
        scanf("%s", registeredPassword);

        if (strcmp(registeredUsername, registeredPassword) == 0) {
            printf("Username and password cannot be the same. Please enter different values.\n");
        }
    } while (strcmp(registeredUsername, registeredPassword) == 0);

    printf("Signup successful!\n\n");
}


int login() {
    char input[50], password[20];
    printf("---- Login ----\n");
    printf("Enter username or email: ");
    scanf("%s", input);
    printf("Enter password: ");
    scanf("%s", password);

    if ((strcmp(input, registeredUsername) == 0 || strcmp(input, registeredEmail) == 0) && strcmp(password, registeredPassword) == 0) {
        printf("Login successful!\n\n");
        return 1;
    } else {
        printf("Invalid username/email or password. Try again.\n\n");
        return 0;
    }
}

void restaurant(int n) {
    if (n == 1) {
        printf("\nYou chose KFC\n\nFood Menu of KFC");
        printf("\n 1. Snack box                 Price 312 BDT");
        printf("\n 2. Zinger meal               Price 733 BDT");
        printf("\n 3. Hot wings                 Price 460 BDT");
        printf("\n 4. Fried chicken             Price 200 BDT");
        printf("\n\n");
    } else if (n == 2) {
        printf("\nYou chose Chillox\n\nFood Menu of Chillox");
        printf("\n 1. Mushroom chicken burger   Price 180 BDT");
        printf("\n 2. Beef cheese               Price 200 BDT");
        printf("\n 3. Naga drums                Price 90 BDT");
        printf("\n 4. Oreo shake                Price 150 BDT");
        printf("\n\n");
    } else if (n == 3) {
        printf("\nYou chose Pizza Hut\n\nFood Menu of Pizza Hut");
        printf("\n 1. Classic beef pizza        Price 859 BDT");
        printf("\n 2. Beef pepperoni            Price 549 BDT");
        printf("\n 3. Mushroom pasta            Price 329 BDT");
        printf("\n 4. Garlic bread slice        Price 119 BDT");
        printf("\n\n");
    } else if (n == 4) {
        printf("\nYou chose Crimson Cup\n\nFood Menu of Crimson Cup");
        printf("\n 1. French toast              Price 200 BDT");
        printf("\n 2. Flavored Latte            Price 200 BDT");
        printf("\n 3. Cappuccino                Price 180 BDT");
        printf("\n 4. Espresso                  Price 130 BDT");
        printf("\n\n");
    } else if (n == 5) {
        printf("\nYou chose Sultan's Dine\n\nFood Menu of Sultan's Dine");
        printf("\n 1. Kacchi Biriani            Price 250 BDT");
        printf("\n 2. Jali Kabab                Price 50 BDT");
        printf("\n 3. Mutton Korma              Price 460 BDT");
        printf("\n 4. Leg Roast                 Price 150 BDT");
        printf("\n\n");
    } else {
        printf("Restaurant not in this list. Input correctly.\n");
    }
}

float calculateBill(float prices[], int numItems) {
    int itemNumber, quantity;
    float vat = 0.15, total = 0.0;

    while (1) {
        printf("Enter item number: ");
        scanf("%d", &itemNumber);

        if (itemNumber < 1 || itemNumber > numItems) {
            printf("\nItem is not in this list. Input correctly.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total += (prices[itemNumber - 1] * quantity) + ((prices[itemNumber - 1] * quantity) * vat);
        printf("\nTotal Amount = %.2f Taka (including 15%% VAT)\n", total);

        printf("\nEnter your delivery address: ");
        scanf(" %[^\n]", deliveryAddress);

        printf("\nWould you like to:\n1. Add more quantity\n2. Proceed to payment method\n");
        printf("Enter your choice: ");
        int selection;
        scanf("%d", &selection);

        if (selection == 1) {
            continue;
        } else if (selection == 2) {
            return total;
        } else {
            printf("Invalid selection.\n");
        }
    }
}

int main() {
    int choice;
    int loggedIn = 0;
    int method;
    float totalAmount;
    int returnToHomePage;


    signUp();


    while (!loggedIn) {
        loggedIn = login();
    }

    do {

        printf("\t\t    _________________________________________________________\n");
        printf("\t\t\t    Welcome to our online food ordering system \n");
        printf("\t\t\t    Hey FOODIES! Are you hungry? Want some food?\n");


        printf("\nChoose a restaurant\n\n");
        printf("1. KFC \n2. Chillox \n3. Pizza Hut \n4. Crimson Cup \n5. Sultan's Dine\n");
        printf("\nEnter your choice by serial number: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            restaurant(choice);

            float prices1[] = {312, 733, 460, 200};
            float prices2[] = {180, 200, 90, 150};
            float prices3[] = {859, 549, 329, 119};
            float prices4[] = {200, 200, 180, 130};
            float prices5[] = {250, 50, 460, 150};

            switch (choice) {
                case 1: totalAmount = calculateBill(prices1, 4); break;
                case 2: totalAmount = calculateBill(prices2, 4); break;
                case 3: totalAmount = calculateBill(prices3, 4); break;
                case 4: totalAmount = calculateBill(prices4, 4); break;
                case 5: totalAmount = calculateBill(prices5, 4); break;
                default: printf("Invalid restaurant choice. Exiting...\n"); return 0;
            }

            printf("\n\nSelect payment method:\n");
            printf("1. Bkash \n2. Cash \n3. Credit card \n4. Rocket \n5. Nagad");
            printf("\nEnter method number: ");
            scanf("%d", &method);

            if (method >= 1 && method <= 5) {
                if (method == 2) {
                    printf("\nYour order has been received. Thank you!\n");
                    printf("Your order will be delivered to: %s\n", deliveryAddress);
                    printf("\nTotal Payable Amount: %.2f Taka", totalAmount);
                } else {
                    char accountNumber[20];
                    printf("\nEnter your account/phone number: ");
                    scanf("%s", accountNumber);

                    printf("\nProcessing payment...\n\nPayment successful!\n");
                }
                printf("\n\nOrder successful! Your order is on the way. Expected delivery: 30 minutes.\n");
                printf("Your order will be delivered to: %s\n", deliveryAddress);
            } else {
                printf("\nInvalid payment method. Order cancelled.\n");
            }
        } else {
            printf("\nInvalid restaurant choice.\n");
        }

        printf("\nPress 1 to return to the home page, or 0 to exit: ");
        scanf("%d", &returnToHomePage);

    } while (returnToHomePage == 1);

    printf("\nThank you for using our service!\n");
    return 0;
}

