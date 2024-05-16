#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>

class Account {
protected:
    int number;
    float money;
    char *accountHolder;
public:
    Account();

    Account(int, float, char *);

    Account(const Account &);

    ~Account();

    void set_number(int);

    int get_number();

    void set_money(float);

    float get_money();

    void set_name(char *);

    char *get_name();

    void putMoney(float);

    void getMoney(float);

    void transferFromAccountToAccount(Account &, float);

    Account& operator=(Account&);

    Account operator--();
    Account operator--(int);

    friend std::istream& operator>>(std::istream&, Account&);
    friend std::ostream& operator<<(std::ostream&, Account&);
};