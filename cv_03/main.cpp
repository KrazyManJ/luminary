#include <iostream>

using namespace std;

/*

 Mějme informační systém balíkové služby. Do tohoto systému zaznamenáváme balíky, které převezmou kurýři nebo
 zaevidují pracovníci na pobočkách. Každá zásilka/balík má nějaké místo odkud je odesílán a místo kam je doručován.
 Pokud je zásilka převzata na pobočce, tak je zvážena a jí přidělena cena. Pokud zásilka nemá být pojištěna, není nutné
 ani zadávat cenu a nastaví se automaticky na 0 Kč. Pokud je zásilka převzata kurýrem, tak nemůže být zvážena,
 protože kurýr nemá váhu. Je tedy nutné ji pouze zadat místo odeslání,
 místo doručení a váhu musíme nastavit později (po jejím zvážení).

Dále udělejme metodu, která umožní vypsat všechny informace o balíku na obrazovku a případně si vymysleme další metody jako gettery na jednotlivé hodnoty.

 */

class Parcel {
private:
    string m_origin;
    string m_destination;
    float m_weight;
    float m_price;
    bool m_insured;
public:
    Parcel(const string &mOrigin, const string &mDestination, float mWeight, float mPrice, bool mInsured) : m_origin(
            mOrigin), m_destination(mDestination), m_price(mPrice), m_insured(mInsured) {
        setMWeight(mWeight);
    }

    Parcel(const string &mOrigin, const string &mDestination, float mWeight) : Parcel(mOrigin,mDestination,mWeight,0, false) {}

    Parcel(const string &mOrigin, const string &mDestination) : Parcel(mOrigin,mDestination,0,0,false) {}


    const string &getMOrigin() const {
        return m_origin;
    }

    void setMOrigin(const string &mOrigin) {
        m_origin = mOrigin;
    }

    const string &getMDestination() const {
        return m_destination;
    }

    void setMDestination(const string &mDestination) {
        m_destination = mDestination;
    }

    float getMWeight() const {
        return m_weight;
    }

    void setMWeight(float mWeight) {
        if (mWeight < 0) cout << "POZOR: vaha je mensi jak nula, to neni mozne Pepo >:c"<< endl;
        m_weight = (mWeight < 0 ? 0 : mWeight);
    }

    float getMPrice() const {
        return m_price;
    }

    void setMPrice(float mPrice) {
        m_price = mPrice;
    }

    bool isMInsured() const {
        return m_insured;
    }

    void setMInsured(bool mInsured) {
        m_insured = mInsured;
    }

    void printInfo(){
        cout << "Balik s parametry:"
        << "  \nodesilatel: " << m_origin
        << "  \nadresat: " << m_destination
        << "  \nvaha: " << m_weight
        << "  \ncena: " << m_price
        << "  \npojisteno: " << (m_insured ? "Ano" : "Ne")
        << endl;
    }

    virtual ~Parcel() {
        cout << "Destroyed ekesbokes" << endl;
    }
};


int main() {

    Parcel* p = new Parcel("Brno", "Boskovice", 500, 1000, false);
    p->printInfo();
    cout << p->getMWeight() << endl;
    p->setMWeight(5);
    cout << p->getMWeight() << endl;
    p->setMWeight(-18);
    cout << p->getMWeight() << endl;
    delete p;
    return 0;
}
