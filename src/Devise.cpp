#include "Devise.h"

Devise::Devise(double amount, Currency currency) : amount(amount), currency(currency) {}

double Devise::convertTo(Currency targetCurrency) const {
    // Exchange rate logic (for simplicity)
    double rate = 1.0;
    if (currency == Currency::MAD && targetCurrency == Currency::USD) rate = 0.1;
    else if (currency == Currency::USD && targetCurrency == Currency::MAD) rate = 10.0;
    else if (currency == Currency::EURO && targetCurrency == Currency::USD) rate = 1.1;
    // Add more cases
    return amount * rate;
}

Devise& Devise::operator+=(const Devise& other) {
    this->amount += other.convertTo(this->currency);
    return *this;
}

Devise& Devise::operator-=(const Devise& other) {
    this->amount -= other.convertTo(this->currency);
    return *this;
}

bool Devise::operator>=(const Devise& other) const {
    return this->amount >= other.convertTo(this->currency);
}

double Devise::getAmount() const {
    return amount;
}

Currency Devise::getCurrency() const {
    return currency;
}

std::ostream& operator<<(std::ostream& os, const Devise& devise) {

    os << devise.amount << "," << static_cast<int>(devise.currency);

    return os;

}