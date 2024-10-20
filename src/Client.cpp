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

void Client::showTransactionHistory() const {
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
