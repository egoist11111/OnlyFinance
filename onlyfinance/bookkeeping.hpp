//
//  bookkeeping.hpp
//  onlyfinance
//
//  Created by Daniil Dziubenko on 27.09.26.
//

#ifndef bookkeeping_hpp
#define bookkeeping_hpp

#include <vector>
#include <map>
#include "account.hpp"

class Bookkeeping {
private:
    std::vector<Account> m_accounts;
    int m_maxAccounts;
public:
    Bookkeeping(int maxAccounts);
    
    std::map<currency, float> getBalances() const;
    int getAmount() const;
    
    void showBalances() const;
    
    bool addAccount(std::string name, float balance, accountType type, currency currency);
    bool delAccount(std::string name);
    
    bool minusMoney(const std::string& name, float value);
    bool plusMoney(const std::string& name, float value);
    
    void output();
};

#endif /* bookkeeping_hpp */
