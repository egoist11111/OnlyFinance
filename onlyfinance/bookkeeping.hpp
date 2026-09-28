//
//  bookkeeping.hpp
//  onlyfinance
//
//  Created by Daniil Dziubenko on 27.09.26.
//

#ifndef bookkeeping_hpp
#define bookkeeping_hpp

#include <vector>
#include "account.hpp"

class Bookkeeping {
private:
    std::vector<Account> m_accounts;
    int m_maxAccounts;
public:
    Bookkeeping(int maxAccounts);
    
    float getBalance() const;
    int getAmount() const;
    
    bool addAccount(std::string name, float balance, accountType type, currency currency);
    bool delAccount(std::string name);
    
    void output();
};

#endif /* bookkeeping_hpp */
