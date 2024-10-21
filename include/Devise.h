#pragma once

#include <iostream>

// @brief not private because we need to access it in the Bank class, also not a sensible information to hide, has MAD USD EURO.
enum class Currency { MAD, USD, EURO };

/**
 * @class Devise
 * @brief Represents a monetary amount in a specific currency.
 *
 * The Devise class provides functionality to handle monetary amounts,
 * including conversion between different currencies and arithmetic operations.
 *
 * @note This class assumes that the Currency type and conversion rates are defined elsewhere.
 *
 * @details
 * The Devise class supports the following operations:
 * - Conversion to a target currency.
 * - Addition and subtraction of monetary amounts.
 * - Comparison of monetary amounts.
 * - Output to an output stream.
 *
 * Example usage:
 * @code
 * Devise usd(100.0, Currency::USD);
 * Devise eur = usd.convertTo(Currency::EUR);
 * usd += eur;
 * if (usd >= eur) {
 *     std::cout << "USD is greater than or equal to EUR" << std::endl;
 * }
 * std::cout << usd << std::endl;
 * @endcode
 */
class Devise {
public:
    Devise(double amount, Currency currency);
    /**
     * @brief Converts the amount to a target currency.
     * @param targetCurrency The target currency to convert to.
     * @return The converted amount.
     */
    double convertTo(Currency targetCurrency) const;
    // overloads the += operator
    Devise& operator+=(const Devise& other);
    // overloads the -= operator
    Devise& operator-=(const Devise& other);
    // overloads the >= operator
    bool operator>=(const Devise& other) const;
    // getter for amount
    double getAmount() const;
    // getter for currency
    Currency getCurrency() const;
    /**
     * @brief Overloads the << operator for output streams.
     * @param os The output stream.
     * @param devise The Devise object to output.
     * @return The output stream.
     */
    void change_account_currency(int currency);
    friend std::ostream& operator<<(std::ostream& os, const Devise& devise);
private:
    double amount;
    Currency currency;
};

