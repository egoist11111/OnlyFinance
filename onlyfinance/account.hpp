//
//  account.hpp
//  onlyfinance
//
//  Created by Daniil Dziubenko on 27.09.26.
//

#ifndef account_hpp
#define account_hpp

#include <string>

enum class accountType {
    Bank,
    Cash,
    Savings
};

enum class currency {
    UAH,
    EUR,
    USD
};

class Account {
private:
    std::string m_name;
    float m_balance;
    accountType m_type;
    currency m_currency;
    
public:
    Account(std::string name, float balance, accountType type, currency currency);
    
    std::string getName() const;
    float getBalance() const;
    currency getCurr() const;
    
    std::string accountTypetoString(accountType type);
    static std::string currencyToString(currency currency);
    
    void output();
};

#endif /* account_hpp */
