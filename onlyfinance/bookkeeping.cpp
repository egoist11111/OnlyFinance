//
//  bookkeeping.cpp
//  onlyfinance
//
//  Created by Daniil Dziubenko on 27.09.26.
//

#include <iostream>
#include "bookkeeping.hpp"

Bookkeeping::Bookkeeping(int maxAccounts)
            :   m_maxAccounts(maxAccounts)
{
}

float Bookkeeping::getBalance() const {
    float balance = 0;

    for(int i = 0; i < m_accounts.size(); i++) {
        balance += m_accounts[i].getBalance();
    }
    
    return balance;
}

int Bookkeeping::getAmount() const {
    return static_cast<int>(m_accounts.size());;
}

bool Bookkeeping::addAccount(std::string name, float balance, accountType type, currency currency) {
    for(int i = 0; i < m_accounts.size(); i++) {
        if(name == m_accounts[i].getName()) {
            return false;
        }
    }
    
    m_accounts.push_back(Account(name, balance, type, currency));
    return true;
}

bool Bookkeeping::delAccount(std::string name) {
    for(int i = 0; i < m_accounts.size(); i++) {
        if(name == m_accounts[i].getName()) {
            m_accounts.erase(m_accounts.begin() + i);
            return true;
        }
    }
    
    return false;
}

void Bookkeeping::output() {
    std::cout << "Type" << "     Name     " << "Balance" << "     Currency\n";
    for(int i = 0; i < m_accounts.size(); i++) {
        m_accounts[i].output();
    }
    std::cout << "Balance: " << getBalance() << "\n";
}
