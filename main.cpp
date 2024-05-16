#include "main.h"

using namespace std;

int main() {
    Account accounts_stat[2];

    float sum = 567;
    char name1[] = "John";
    char name2[] = "Jame";

    accounts_stat[1].set_number(5);
    accounts_stat[1].set_money(sum);
    accounts_stat[1].set_name(name1);

//    cin >> accounts_stat[0];
//
//    for (int i = 0; i < 2; i++) {
//        cout << accounts_stat[i] << "\n";
//    }
//
//    accounts_stat[0]--;
//
//    cout << accounts_stat[0].get_money() << "\n";

    Account *accounts_dynam = new Account[2];

    accounts_dynam[1].set_number(3);
    accounts_dynam[1].set_money(sum);
    accounts_dynam[1].set_name(name2);

    cout << accounts_dynam[1] << "\n" << accounts_stat[1] << "\n\n";

    accounts_stat[1].transferFromAccountToAccount(accounts_dynam[1], 100);

    cout << accounts_dynam[1] << "\n" << accounts_stat[1];

    delete[] accounts_dynam;
}
