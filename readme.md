# BankingSystem

## Overview
BankingSystem is a C++ project with the purpose of learning OOP, so if anything is made in a bad way, my purpose was to learn and not to make a fully functioning system.

## Requirements
- C++17
- CMake 3.10 or higher

## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/MedHK008/bankingSystemV2.0.git
    ```
2. I trust that you know the next steps.

## Usage
1. Run the executable:
    ```sh
    ./BankingSystem
    ```
2. Test all the functionalities as you like.

## File Structure
- `src/`: Contains the source code files.
- `include/`: Contains the header files.
- `CMakeLists.txt`: CMake configuration file.
- `readme.md`: Project documentation.
- `main.cpp`: The main file.

## Code Overview
You can access the documentation of the class from the `.h` file, but here I will explain the logic behind the design choices made in the classes, rather than how they work.
### `Bank`

The `Bank` class is not intended to manage the bank itself. Instead, it serves as a container for client accounts. It acts as a parent class for clients, handling the creation, retrieval, saving, and loading of accounts, thereby providing centralized access to all accounts.

One notable feature used in this class is `unordered_map`. To be honest, this was suggested by GitHub Copilot during coding, and it proved to be a sensible choice after I looked it up. Besides offering fast access, it ensures that no two accounts share the same number. Additionally, although not directly related to code, it does not impose any order on the clients (equality, right? hh).

### `Client`
Balance is `unique_ptr` because each client has only one balance and no sharing is needed. Transaction is `shared_ptr` since it may concern more than one client, so ownership is not exclusive, and also we ensure that access to transaction history can be done through multiple references at the same time.

### `Devise`
In this class, we specify the currency that we pre-stored in an enum, and an amount. The methods are standard, nothing fancy.

### `Transaction`
This class is used to structure the storing of the transaction in the account log. It was a question of structuring the operation of storing, nothing more. Also, it was a way to use more classes in the project.

### `main.cpp`
Two test functions that I used to test the methods if they are good. The menu is declared in its own function to easily switch between showing the menu and testing things.

## Conclusion

Pull a branch and change the code (to a better one hopefully) if you want to change the way things work.

