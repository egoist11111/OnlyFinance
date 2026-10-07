//
//  main.cpp
//  onlyfinance
//
//  Created by Daniil Dziubenko on 27.09.26.
//

#include <iostream>
#include "bookkeeping.hpp"

int main() {
    Bookkeeping yourFinance(20);
    bool exit = false;
    while(!exit) {
        int menu;
        
        do{
            std::cout << "\nBalance:\n";
            yourFinance.showBalances();
            std::cout << "Press 1 to add an account\n";
            std::cout << "Press 2 to delete an account\n";
            std::cout << "Press 3 to add money to your account\n";
            std::cout << "Press 4 to reduce money from your account\n";
            std::cout << "Press 5 to show all data\n";
            std::cout << "Press 6 to exit\n";
            std::cout << "Enter: ";
            
            std::cin >> menu;
        }while(menu < 1 || menu > 6);
        switch(menu) {
            case 1: {
                if(yourFinance.getAmount() >= 20) {
                    std::cout << "Error! You have too many accounts.\n";
                    break;
                }
                std::string name;
                float balance;
                accountType type;
                currency currency;
                int flag;
                
                std::cout << "Enter a name of your new account: ";
                std::cin >> name;
                std::cout << "Enter a balance of your new account: ";
                std::cin >> balance;
                do{
                    std::cout << "Press 1 to Bank\n";
                    std::cout << "Press 2 to Cash\n";
                    std::cout << "Press 3 to Savings\n";
                    std::cout << "Enter: ";
                    std::cin >> flag;
                }while(flag < 1 || flag > 3);
                if(flag == 1) {
                    type = accountType::Bank;
                } else if(flag == 2) {
                    type = accountType::Cash;
                } else if(flag == 3) {
                    type = accountType::Savings;
                }
                do{
                    std::cout << "Press 1 to UAH\n";
                    std::cout << "Press 2 to EUR\n";
                    std::cout << "Press 3 to USD\n";
                    std::cout << "Enter: ";
                    std::cin >> flag;
                }while(flag < 1 || flag > 3);
                if(flag == 1) {
                    currency = currency::UAH;
                } else if(flag == 2) {
                    currency = currency::EUR;
                } else if(flag == 3) {
                    currency = currency::USD;
                }
                
                if(yourFinance.addAccount(name, balance, type, currency)) {
                    std::cout << "Succeed.\n";
                    break;
                } else {
                    std::cout << "The name is already taken.\n";
                    break;
                }
            }
            case 2: {
                std::string name;
                std::cout << "Enter the name: ";
                std::cin >> name;
                
                if(yourFinance.delAccount(name)) {
                    std::cout << "Succeed.\n";
                    break;
                } else {
                    std::cout << "Name doesn't match.\n";
                    break;
                }
            }
            case 3:
            case 4: {
                if (yourFinance.getAmount() == 0) {
                    std::cout << "No accounts available.\n";
                    break;
                }
                
                float value;
                std::cout << "Enter the amount of money: ";
                std::cin >> value;

                if (value <= 0) {
                    std::cout << "Amount must be positive.\n";
                    break;
                }

                std::string name;
                while (true) {
                    std::cout << "Choose an account: ";
                    std::cin >> name;

                    bool success;
                    if (menu == 3) {
                        success = yourFinance.plusMoney(name, value);
                    } else {
                        success = yourFinance.minusMoney(name, value);
                    }

                    if (success) {
                        std::cout << "Succeed.\n";
                        break;
                    }

                    std::cout << "The name doesn't match. Try one more time.\n";
                }

                break;
            }
            case 5:
                yourFinance.output();
                break;
            case 6:
                exit = true;
                break;
        }
        
    }
        
    return 0;
}
