# Simple Banking System

A C-based program that simulates a basic banking system, allowing users to create accounts, view account details, deposit money, and withdraw money. 

## Features
- **Account Creation**: Create a savings or checking account with a unique account number.
- **Display Account**: Retrieve and display account details including balance and withdrawal limits.
- **Deposit**: Add funds to the account balance.
- **Withdrawal**: Withdraw funds while ensuring compliance with balance and withdrawal limits.
- **User-friendly Menu**: Easy-to-use interface for navigating features.

## Project Structure
- **Account Creation**: Allows the user to input account details and set up an account with a default balance of 0.
- **Display Account**: Fetches account details based on the provided account number.
- **Deposit**: Increases the balance of a specified account.
- **Withdrawal**: Decreases the balance, provided the withdrawal does not exceed the account balance or withdrawal limit.

## Prerequisites
- C compiler (e.g., GCC)
- Basic understanding of C programming and command-line operations.

## How to Run
1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/simple-banking-system.git
    cd simple-banking-system
    ```
2. Compile the program:
    ```bash
    gcc banking_system.c -o banking_system
    ```
3. Run the executable:
    ```bash
    ./banking_system
    ```

## Example Usage
### Menu Options:
1. **Account creation**: Input required details:
