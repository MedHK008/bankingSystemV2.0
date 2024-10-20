#pragma once
#include <memory>
#include <unordered_map>
#include "Client.h"

class Bank {
private:
    std::unordered_map<std::string, std::unique_ptr<Client>> clients;
public:
    /**
     * @brief Creates a new account in the bank.
     * @param name The name of the account holder.
     * @param accountNumber The account number.
     * @param initialBalance The initial balance of the account.
     * @return True if the account was created successfully, false if the account already exists.
     */
    bool createAccount(const std::string& name, const std::string& accountNumber, std::unique_ptr<Devise> initialBalance);

    /**
     * @brief Finds an account in the bank by account number.
     * @param accountNumber The account number to search for.
     * @return A pointer to the client if the account is found, nullptr otherwise.
     */
    Client* findAccount(const std::string& accountNumber);

    /**
     * @brief Saves all accounts to a CSV file.
     * @param filename The name of the CSV file.
     */
    void saveAccounts(const std::string& filename) const;

    /**
     * @brief Loads accounts from a CSV file.
     * @param filename The name of the CSV file.
     */
    void loadAccounts(const std::string& filename);
};
