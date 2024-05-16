#define _CRT_SECURE_NO_WARNINGS
#include "account.h"

Account::Account() {
    this->number = 0;
    this->money = 0;
    this->accountHolder = nullptr;
}

Account::Account(int num, float money, char *name) {
    this->number = num;
    this->money = money;
    this->accountHolder = new char[strlen(name) + 1];
    strcpy(this->accountHolder, name);
}

Account::Account(const Account &acc) {
    this->number = acc.number;
    this->money = acc.money;
    this->accountHolder = new char[strlen(acc.accountHolder) + 1];
    strcpy(this->accountHolder, acc.accountHolder);
}

Account::~Account() {
    this->number = 0;
    this->money = 0;
    delete[] this->accountHolder;
}

void Account::set_number(int num) {
    this->number = num;
}

int Account::get_number() {
    return this->number;
}

void Account::set_money(float money) {
    this->money = money;
}

float Account::get_money() {
    return this->money;
}

void Account::set_name(char *name) {
    delete[] this->accountHolder;
    this->accountHolder = new char[strlen(name) + 1];
    strcpy(this->accountHolder, name);
}

char *Account::get_name() {
    char *name_return = new char[strlen(this->accountHolder) + 1];
    strcpy(name_return, this->accountHolder);
    return name_return;
}

void Account::putMoney(float money) {
    this->money += money;
}

void Account::getMoney(float money) {
    this->money -= money;
}

void Account::transferFromAccountToAccount(Account &to, float money) {
    this->money -= money;
    to.money += money;
}

Account& Account::operator=(Account &acc) {
    if (&acc != this) {
        this->set_money(acc.get_money());
        this->set_name(acc.get_name());
        this->set_number(acc.get_number());
    }
    return *this;
}

Account Account::operator--()
{
    this->money -= 10;
    return *this;
}

Account Account::operator--(int)
{
    Account old_acc(*this);
    this->money -= 10;
    return old_acc;
}

std::istream& operator>>(std::istream& is, Account& acc)
{
    std::cout << "Введите номер счёта: ";
    is >> acc.number;
    std::cout << "Введите кол-во денег на счету: ";
    is >> acc.money;
    std::cout << "Введите имя владельца: ";
    char name[256];
    is >> name;
    acc.set_name(name);
    return is;
}

std::ostream& operator<<(std::ostream& os, Account& acc)
{
    os  << "Номер счёта: " << acc.get_number() << "\n";
    os << "Кол-во денег на счету: " << acc.get_money() << "\n";
    os << "Имя владельца счета: " << acc.get_name() << "\n";
    return os;
}
