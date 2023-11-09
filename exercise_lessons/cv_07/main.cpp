/*
 Vytvořme informační systém, který bude spravovat zákazníky ve věrnostním programu pro eshop. Každý zákazník
 má jméno, unikátní klubové ID, evidujeme jakou má aktuálně slevu a jaký má součet výšek
 nákupů (tedy kolik utratil). Povinné je jméno, které se zadává konstruktorem. ID je generováno
 automaticky jako pořadové číslo. Sleva je ve výchozím stavu 5 %, ale můžeme ji také zadat jinou
 v konstruktoru. Můžeme přidat do celkového součtu nákupů nový nákup. Jméno, ID a
 aktuální výši slevy jsme schopni zjistit.

Každý zákazník také zvyšuje automaticky svoji slevu podle nákupů. Pokaždé, když překročí 10 tis. Kč,
 které utratil, tak se mu sleva zvýší o jedno procento. Maximálně však bude mít celkovou slevu 20 %.

Dále máme správce zákazníků, který nám pomáhá spravovat zákazníky
 našeho eshopu. Pokud si budeme chtít vytvořit nového zákazníka, tak jej
 nebudeme vytvářet přímo, ale použijeme na to našeho správce. U toho zavoláme metodu, která se jmenuje

např. createCustomer() a ta pro nás zákazníka vytvoří podle naší potřeby.
 Budeme počítat, že zákazníci jsou 3 typů: běžní zákazníci, ti dostanou výchozí slevu,
 pak firemní zákazníci, kteří ji mají nižší, pouze 3 % a VIP zákazníci, kteří ji mají 10 %.
 Této metodě předáme pouze typ zákazníka, jeho jméno a ona pro nás zákazníka vytvoří "na míru".
 Zákazníka si také zaeviduje do svého seznamu a umožní nám, abychom ho kdykoliv dohledali.

K tomu bude sloužit metoda findCustomerById(), které předáme ID zákazníka a ona ho buď
 vyhledá a vrátí nebo vypíše chybu. Dále budeme mít metodu findCustomersByName(), které předáme
 jméno a ona vrátí seznam všech zákazníků, kteří mají dané jméno.
 */
#include <iostream>
#include <vector>

using namespace std;

enum CustomerType { VIP, CORPORATE, REGULAR};

class Customer {
private:
    string m_name;
    int m_id;
    float m_discount;
    float m_totalPurchases;
    static int s_counter;
public:
    Customer(string name, float discount){
        s_counter++;
        m_name = name;
        m_discount = discount;
        m_id=s_counter;
        m_totalPurchases = 0;
    }
    Customer(string name) : Customer(name, 5) {}

    void addPurchase(float price){
        const int DISCOUNT_BORDER = 10000;
        if (price < 0) return;
        if (price > DISCOUNT_BORDER || (m_totalPurchases/DISCOUNT_BORDER != (m_totalPurchases+price)/DISCOUNT_BORDER && m_discount < 20))
            m_discount++;
        m_totalPurchases += price;
    }

    string getName() const {
        return m_name;
    }

    int getId() const {
        return m_id;
    }

    float getDiscount() const {
        return m_discount;
    }
};
int Customer::s_counter = 0;

class CustomerRegister {
private:
    vector<Customer*> m_customers;
public:
    void createCustomer(CustomerType type, string name){
        float discount;
        switch (type) {
            case VIP :
                discount = 10;
                break;
            case CORPORATE:
                discount = 3;
                break;
            case REGULAR:
                break;
        }
        m_customers.push_back((type == CustomerType::REGULAR) ? new Customer(name) : new Customer(name,discount));
    }
    Customer* findCustomerById(int id){
        for (Customer *customer : m_customers) {
            if (customer->getId() == id) return customer;
        }
        return nullptr;
    }
    vector<Customer*> findCustomersByName(string name){
        vector<Customer*> foundCustomers;
        for (Customer *customer : m_customers) {
            if (customer->getName() == name) foundCustomers.push_back(customer);
        }
        return foundCustomers;
    }
};

int main() {
    return 0;
}
