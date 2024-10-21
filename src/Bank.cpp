#include "Bank.h"
#include <fstream>
#include <sstream>

bool Bank::createAccount(const std::string& name, const std::string& accountNumber, std::unique_ptr<Devise> initialBalance) {
    if (clients.find(accountNumber) != clients.end()) {
        return false; // Account already exists
    }
    clients[accountNumber] = std::make_unique<Client>(name, accountNumber, std::move(initialBalance));
    return true;
}

Client* Bank::findAccount(const std::string& accountNumber) {
    auto it = clients.find(accountNumber);
    if (it != clients.end()) {
        return it->second.get();
    }
    return nullptr;
}

void Bank::saveAccounts(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open accounts file for saving.");
    }
    for (const auto& pair : clients) {
        const auto& client = pair.second;
        file << client->getName() << "," << client->getAccountNumber() << "," << client->getBalance() << std::endl;
    }
}

void Bank::loadAccounts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open accounts file for loading.");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name, accountNumber, currencyStr;
        double amount;
        int currency;
        std::getline(ss, name, ',');
        std::getline(ss, accountNumber, ',');
        ss >> amount;
        ss.ignore(1, ',');
        ss >> currency;
        createAccount(name, accountNumber, std::make_unique<Devise>(amount, static_cast<Currency>(currency)));
        std::cout << "Account loaded: " << name << " " << accountNumber << " " << amount << " " << currency << std::endl;
        const std::string& Transactionfilename = "transactions/"+ accountNumber +"_transactions.csv";
        clients[accountNumber]->loadTransactions(Transactionfilename);
    }
}