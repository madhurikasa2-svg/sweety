#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    int accNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void loadAccounts(struct Account **accounts, int *count);
void saveAccounts(struct Account *accounts, int count);

int main()
{
    int choice;
    do
    {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}

// Create a new account
void createAccount()
{
    struct Account acc;
    FILE *file = fopen("accounts.dat", "ab");
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &acc.accNumber);
    printf("Enter name: ");
    scanf(" %[^\n]", acc.name);
    acc.balance = 0;

    fwrite(&acc, sizeof(struct Account), 1, file);
    fclose(file);

    printf("Account created successfully!\n");
}

// Deposit money
void deposit()
{
    int accNum;
    float amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    FILE *file = fopen("accounts.dat", "rb+");
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    struct Account acc;
    while(fread(&acc, sizeof(struct Account), 1, file))
    {
        if(acc.accNumber == accNum)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;

            fseek(file, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, file);
            printf("Deposit successful! New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if(!found) printf("Account not found.\n");

    fclose(file);
}

// Withdraw money
void withdraw()
{
    int accNum;
    float amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    FILE *file = fopen("accounts.dat", "rb+");
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    struct Account acc;
    while(fread(&acc, sizeof(struct Account), 1, file))
    {
        if(acc.accNumber == accNum)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(amount > acc.balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                acc.balance -= amount;
                fseek(file, -sizeof(struct Account), SEEK_CUR);
                fwrite(&acc, sizeof(struct Account), 1, file);
                printf("Withdrawal successful! New balance: %.2f\n", acc.balance);
            }
            found = 1;
            break;
        }
    }
    if(!found) printf("Account not found.\n");

    fclose(file);
}

// Check account balance
void checkBalance()
{
    int accNum;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    FILE *file = fopen("accounts.dat", "rb");
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    struct Account acc;
    while(fread(&acc, sizeof(struct Account), 1, file))
    {
        if(acc.accNumber == accNum)
        {
            printf("Account Holder: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if(!found) printf("Account not found.\n");

    fclose(file);
}
