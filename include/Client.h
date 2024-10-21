
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <memory>
#include "Transaction.h"
#include "Devise.h"
/**
 * @class Client
 * @brief Represents a client in the banking system.
 *
 * The Client class encapsulates the details of a client, including their name, account number,
 * balance, and transaction history. It provides methods for depositing, withdrawing, and transferring
 * funds, as well as displaying the transaction history and retrieving client details.
 *
 * @file Client.h
 */
class Client {
public:
    Client(const std::string& name, const std::string& accountNumber, std::unique_ptr<Devise> initialBalance);

    /**
     * @brief Deposits an amount into the client's account.
     * @param amount The amount to deposit.
     */
    void deposit(const Devise& amount);

    /**
     * @brief Withdraws an amount from the client's account.
     * @param amount The amount to withdraw.
     * @return True if the withdrawal was successful, false otherwise.
     */
    bool withdraw(const Devise& amount);

    /**
     * @brief Transfers an amount from this client's account to another client's account.
     * @param toClient The client to transfer the amount to.
     * @param amount The amount to transfer.
     * @return True if the transfer was successful, false otherwise.
     */
    bool transfer(Client& toClient, const Devise& amount);
    
    /**
     * @brief Loads transactions from a CSV file.
     * @param filename The name of the CSV file.
     */
    void loadTransactions(const std::string& filename);

    /**
     * @brief Displays the transaction history of the client's account.
     */
    void showTransactionHistory() const;

    /**
     * @brief Gets the balance of the client's account.
     * @return The balance of the client's account.
     */
    Devise getBalance() const;

    /**
     * @brief Gets the name of the client.
     * @return The name of the client.
     */
    std::string getName() const;

    /**
     * @brief Gets the account number of the client.
     * @return The account number of the client.
     */
    std::string getAccountNumber() const;

    void changeCurrency(int currency);

private:
    std::string name;
    std::string accountNumber;
    std::vector<std::shared_ptr<Transaction>> transactions;
    std::unique_ptr<Devise> balance;
};

#endif // CLIENT_H
