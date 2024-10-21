#include "Client.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

Client::Client(const std::string& name, const std::string& accountNumber, std::unique_ptr<Devise> initialBalance)
    : name(name), accountNumber(accountNumber), balance(std::move(initialBalance)) {}

void Client::deposit(const Devise& amount) {
    *balance += amount;
    transactions.push_back(std::make_shared<Transaction>("Deposit", amount.getAmount(), "2024-10-20", "MAD"));
    transactions.back()->logTransaction(accountNumber);
}

bool Client::withdraw(const Devise& amount) {
    if (*balance >= amount) {
        *balance -= amount;
        transactions.push_back(std::make_shared<Transaction>("Withdrawal", amount.getAmount(), "2024-10-20", "MAD"));
        transactions.back()->logTransaction(accountNumber);
        return true;
    }
    return false;
}

bool Client::transfer(Client& toClient, const Devise& amount) {
    if (withdraw(amount)) {
        toClient.deposit(amount);
        transactions.push_back(std::make_shared<Transaction>("Transfer", amount.getAmount(), "2024-10-20", "MAD"));
        transactions.back()->logTransaction(accountNumber);
        return true;
    }
    return false;
}

void Client::loadTransactions(const std::string& filename){
    std::ifstream file(filename);
    std::cout << "Loading transactions from " << filename << std::endl;
    if (!file.is_open()) {
        std::cerr << "Failed to open transactions file for loading." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, type, currency;
        double amount;
        std::getline(ss, date, ',');
        std::getline(ss, type, ',');
        ss >> amount;
        ss.ignore(1, ',');
        ss >> currency;
        transactions.push_back(std::make_shared<Transaction>(type, amount, date, currency));
    }
}
void Client::showTransactionHistory() const {
    std::cout << "Transaction history for account: " << accountNumber << std::endl;
    for (const auto& transaction : transactions) {
        std::cout << transaction->getDate() << " - " << transaction->getType() << ": " << transaction->getAmount() << " " << transaction->getCurrency() << std::endl;
    }
}


Devise Client::getBalance() const {
    return *balance;
}

std::string Client::getName() const {
    return name;
}

std::string Client::getAccountNumber() const {
    return accountNumber;
}

void Client::changeCurrency(int currency)
{
    balance->change_account_currency(currency);
}
