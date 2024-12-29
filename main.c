#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char name[100];
    int accountNum;
    int balance;
    char type[10];
    int limit;
} account;

account bank[1000];
int count = 0;

void accountCreation() {
    printf("Enter name: \n");
    getchar(); // Clear the buffer
    fgets(bank[count].name, 100, stdin);
    bank[count].name[strcspn(bank[count].name, "\n")] = 0; // Remove newline

    printf("Enter account number:\n");
    scanf("%d", &bank[count].accountNum);
    getchar(); // Clear newline

    bank[count].balance = 0;

    printf("Enter type (savings/checking):\n");
    fgets(bank[count].type, 10, stdin);
    bank[count].type[strcspn(bank[count].type, "\n")] = 0; // Remove newline

    if (strcmp(bank[count].type, "savings") == 0) { //use strcmp and not compare directly == as str is in char form
        printf("Set withdrawal limit:\n");
        scanf("%d", &bank[count].limit);
    } else if (strcmp(bank[count].type, "checking") == 0) {
        bank[count].limit = 0;
    } else {
        printf("Invalid account type. Defaulting to checking.\n");
        strcpy(bank[count].type, "checking");
        bank[count].limit = 0;
    }
    count++;
    printf("Account created successfully!\n");
}

void displayAccount() {
    int tempt, index = -1;
    printf("Enter your account number:\n");
    scanf("%d", &tempt);

    for (int i = 0; i < count; i++) {
        if (tempt == bank[i].accountNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Account name: %s\n", bank[index].name);
    printf("Account number: %d\n", bank[index].accountNum);
    printf("Balance: %d\n", bank[index].balance);
    printf("Type: %s\n", bank[index].type);
    printf("Withdrawal limit: %d\n", bank[index].limit);
}

void deposit() {
    int accountNum, amount, index = -1;
    printf("Enter your account number:\n");
    scanf("%d", &accountNum);

    for (int i = 0; i < count; i++) {
        if (accountNum == bank[i].accountNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Deposit amount:\n");
    scanf("%d", &amount);

    if (amount > 0) {
        bank[index].balance += amount;
        printf("Deposit successful! New balance: %d\n", bank[index].balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdrawal() {
    int accountNum, amount, index = -1;
    printf("Enter your account number:\n");
    scanf("%d", &accountNum);

    for (int i = 0; i < count; i++) {
        if (accountNum == bank[i].accountNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter withdrawal amount:\n");
    scanf("%d", &amount);

    if (amount > bank[index].limit) {
        printf("Withdrawal failed. Exceeds withdrawal limit!\n");
    } else if (bank[index].balance - amount >= 0) {
        bank[index].balance -= amount;
        printf("Withdrawal successful! New balance: %d\n", bank[index].balance);
    } else {
        printf("Withdrawal failed! Insufficient balance.\n");
    }
}

int main() {
    int choice, notExit = 1;

    while (notExit) {
        printf("\nSelect choice (1.Account creation 2.Display your account 3.Deposit 4.Withdrawal 5.Exit):\n");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                accountCreation();
                break;
            case 2:
                displayAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdrawal();
                break;
            case 5:
                notExit = 0;
                printf("Exit successful.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
