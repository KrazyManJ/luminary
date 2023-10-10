/*
Skúsme naprogramovať triedu účet, ktorá by mala byť v budúcnosti súčasťou vačšieho
 bankovného systému. Pri návrhu dbajme na zapúzdrenosť.

U každého účtu si evidujeme meno vlastníka, aktuálny zostatok, limit pre výber
 hotovosti a to, či sa jedná o transparentný účet. Transparentný účet je typický
 tým, že pri jeho výpise je vidieť aj jeho zostatok a limity. Pri vytváraní účtu
 je potrebné zadať meno vlastníka a limit pre výber. Účet je vždy vytvorený ako
 netransparentný. Budeme potrebovať metódy pre získanie zostatku na účte a jeho majiteľa.

S týmto účtom budeme chcieť prevádzať nasledujúce operácie:

- vklad hotovosti (nie je možné vložiť zápornú čiastku)
- výber hotovosti (čiastka musí vyhovovať nastavenému limitu a samozrejme zostatku na účte)
- zmeniť limit pre výber (nie je možné zmeniť limit na záporné číslo)
- výpis údajov o účte (podľa typu účtu)
- zmeniť meno majiteľa účtu
- zmeniť typ účtu na transparentní (opačně to nejde)


Zároveň si potrebujeme evidovať každú operáciu, ktorá na účte prebehla do
 loggeru (pre začiatok stačí ako jeden text). Do logu chceme zaznamenávať ako
 aj úspešné udalosti, tak aj chyby, ktoré nastali. Úspešná operácia sa zapíše
 do logu ako "Udalost: <popis udalosti> \n", chyba sa zapíše
 ako "Chyba: <popis chyby> \n". Chyby chceme vypisovať rovno aj na obrazovku.
 Ďalej budeme potrebovať metódu pre vypísanie logu.

V hlavnom programe vytvorte účet, skúste na ňom previesť různe
 operácie (napr. vložiť/vybrať peniaze, zmeniť majiteľa...) a následne vypíšte
 logy. Na overenie funkčnosti programu skúste použiť aj nevalidné hodnoty.
*/


#include <iostream>

using namespace std;

class Account {
private:
    string m_owner;
    float m_balance;
    float m_withdrawalLimit;
    bool m_isTransparent;
    string m_log;

    void logError(string message) {
        m_log += "Error: "+message+"\n";
        cerr << "Error: " << message << endl;
    }
    void logSuccess(string message) {
        m_log += "Event: "+message+"\n";
        cout << "Event: " << message << endl;
    }
public:
    Account(const string &mOwner, float mWithdrawalLimit) : m_owner(mOwner), m_withdrawalLimit(mWithdrawalLimit) {
        m_balance = 0;
        m_isTransparent = false;
    }

    const string &getOwner() const {
        return m_owner;
    }

    float getBalance() const {
        return m_balance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            m_balance += amount;
            logSuccess("Successfully deposited " + to_string(amount)+ "CZK.");
        }
        else logError("Negative num was used for deposit value.");

    }

    void withdraw(float amount) {
        if (amount < 0) {
            logError("Negative num was used for deposit value.");
            return;
        }
        if (amount > m_withdrawalLimit) {
            logError("Withdraw amount is bigger than limit.");
            return;
        }
        if (amount > m_balance) {
            logError("Withdraw amount is bigger than balance.");
            return;
        }
        m_balance -= amount;
        logSuccess("Successfully withdrawed "+ to_string(amount)+ "CZK.");
    }

    // m_balance += amount;
    // m_balance = m_balance + amount;

    void setWithdrawLimit(float newLimit) {
        if (newLimit >= 0) {
            m_withdrawalLimit = newLimit;
            logSuccess("Successfully set withdraw limit to "+ to_string(newLimit)+"CZK.");
        }
        else logError("Negative num was used for setting withdraw limit value.");
    }

    void printInfo() {
        cout << endl << "Account of owner " << m_owner << ":" << endl << "  - transparent: "
             << (m_isTransparent ? "yes" : "hell naw") << endl;
        if (m_isTransparent)
            cout << "  - balance: " << m_balance << endl << "  - withdraw limit: " << m_withdrawalLimit << endl;
    }

    void changeOwner(const string &mOwner) {
        m_owner = mOwner;
    }

    void makeTransparent() {
        m_isTransparent = true;
    }

    void printLog(){
        cout << endl << "[LOG START]" << m_log << "[LOG END]" << endl;
    }

};

int main() {
    // correct usage
    Account *account = new Account("Jarda Korcak", 2000);
    account->deposit(50000);
    account->printInfo();
    account->makeTransparent();
    account->printInfo();
    account->setWithdrawLimit(500);
    account->printInfo();
    account->changeOwner("Alex Lysek");
    account->printInfo();
    account->deposit(3500);
    account->printInfo();
    account->withdraw(500);
    account->printInfo();
    cout << endl << "Owner: " << account->getOwner() << " | Balance: " << account->getBalance() << endl;
    // wrong usage
    account->deposit(-500);
    account->printInfo();
    account->withdraw(-500);
    account->printInfo();
    account->withdraw(3500);
    account->printInfo();
    account->printLog();
    return 0;
}
