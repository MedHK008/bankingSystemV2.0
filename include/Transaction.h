#pragma once
#include <string>
#include <fstream>

class Transaction {
private:
    std::string type;
    double amount;
    std::string date;
    std::string currency;

public:
    Transaction(const std::string& type, double amount, const std::string& date, const std::string& currency);
    
    /// @brief gets the type of the transaction
    std::string getType() const;
    /// @brief gets the amount of the transaction
    double getAmount() const;
    /// @brief gets the date of the transaction
    std::string getDate() const;
    /// @brief gets the currency of the transaction
    std::string getCurrency() const;

    /**
     * @brief Logs the transaction to a CSV file.
     * @param accountNumber The account number associated with the transaction.
     */
    void logTransaction(const std::string& accountNumber) const;
};
