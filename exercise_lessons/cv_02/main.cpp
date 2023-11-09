#include <iostream>

using namespace std;

/*
 * Vytvořte třídu, které bude reprezentovat **křižníky impéria**. Každý křižník má
 * výrobce, model, třídu (lehký, střední, težký), a cenu. Každý křižník má metodu `printInfo()`
 * vypisující veškeré informace o křižníku na obrazovku. Dále má metody (_setry_) možňující
 * nastavit nastavit jednotlivé vlastnosti. Uvnitř metod testujte rozumné vstupní hodnoty.
 * Nakonec má také _getry_ umožňující vracet jednotlivé vlastnosti.
 */

enum CruiserType {
    LIGHT,
    NORMAL,
    HEAVY
};

class ImperialCruiser {
public:
    string vendor;
    string model;
    CruiserType cls;
    unsigned int price;

    void printInfo() const {
        cout << "Cruiser info: \nVendor: " << vendor << "\nModel: " << model << "\nClass: "
             << ((cls == 0) ? "Light" : ((cls == 1) ? "Normal" : "Heavy")) << "\nPrice "
             << price << endl;
    }

    const string &getVendor() const {
        return vendor;
    }

    void setVendor(const string &vendor) {
        ImperialCruiser::vendor = vendor;
    }

    const string &getModel() const {
        return model;
    }

    void setModel(const string &model) {
        ImperialCruiser::model = model;
    }

    CruiserType getCls() const {
        return cls;
    }

    void setCls(CruiserType cls) {
        ImperialCruiser::cls = cls;
    }

    unsigned int getPrice() const {
        return price;
    }

    void setPrice(unsigned int price) {
        ImperialCruiser::price = price;
    }

};

int main() {
    auto* cruiser = new ImperialCruiser();
    cruiser->setVendor("KUAT");
    cruiser->setModel("Bojova Kriznikoptera 3000");
    cruiser->setCls(HEAVY);
    cruiser->setPrice(500);
    cruiser->printInfo();
    cruiser->setPrice(cruiser->getPrice()*2);
    cruiser->printInfo();
    delete cruiser;
    return 0;
}
