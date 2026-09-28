//
//  account.cpp
//  onlyfinance
//
//  Created by Daniil Dziubenko on 27.09.26.
//

#include <iostream>
#include "account.hpp"

Account::Account(std::string name, float balance, accountType type, currency currency)
        :   m_name(name), m_balance(balance), m_type(type), m_currency(currency)
{
}

std::string Account::getName() const {
    return m_name;
}
float Account::getBalance() const {
    return m_balance;
}

std::string Account::accountTypetoString(accountType type) {
    switch (type) {
        case accountType::Bank:
            return "Bank";
        case accountType::Cash:
            return "Cash";
        case accountType::Savings:
            return "Savings";
    }
}

std::string Account::currencyToString(currency currency) {
    switch (currency) {
        case currency::UAH:
            return "UAH";
        case currency::EUR:
            return "EUR";
        case currency::USD:
            return "USD";
    }
}

void Account::output() {
    std::cout << accountTypetoString(m_type) << "     " << m_name << "     " << m_balance <<
    "     " << currencyToString(m_currency) << std::endl;
}
