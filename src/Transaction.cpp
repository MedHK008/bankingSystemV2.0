#include "Transaction.h"
#include <iostream>

Transaction::Transaction(const std::string& type, double amount, const std::string& date, const std::string& currency)
    : type(type), amount(amount), date(date), currency(currency) {}

std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getDate() const {
    return date;
}

std::string Transaction::getCurrency() const {
    return currency;
}

void Transaction::logTransaction(const std::string& accountNumber) const {
    try {
        std::ofstream file(accountNumber + "_transactions.csv", std::ios::app);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open transaction file for account: " + accountNumber);
        }
        file << type << "," << amount << "," << date << "," << currency << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error logging transaction: " << e.what() << std::endl;
    }
}
