/*
 Vytvořme informační systém, který bude evidovat úkoly a pracovníky, kteří na úkolech pracují.
 Každý úkol bude mít automaticky generovaný identifikátor skládající se z "UK" a pořadového
 čísla úkolu (napr. "UK1", "UK2" atď.) . Toto číslo bude sekvenční index, který se s každým
 úkolem inkrementuje o jedna. Každý úkol bude mít navíc počet hodin, které stojí jeho implementace a název.

 Při vytvoření úkolu se vždy zadává pouze jméno a počet hodin. Kód se generuje sám, jak bylo řečeno.
 Všechny údaje o úkolu jsme schopni vracet.

 Zaměstnanec bude mít u sebe evidováno jméno, velikost úvazku na intervalu <0, 1> a
 kolik odpracoval v daném týdnu hodin. Počítejme, že úvazek má velikost 40 hodin týdně.
 Hodnoty jména a úvazku zadáváme v konstruktoru a jsme schopni je vracet. Počet odpracovaných hodin je na počátku 0.

 Dále můžeme změnit velikost úvazku a zaevidovat úkol, který dotyčný vytvořil.
 To uděláme tak, že předáme úkol, který zpracoval a:
   - pokud je počet odpracovaných hodin v týdnu menší, než je délka úkolu, tak je vše OK a zaevidujeme
   - pokud již odpracoval dost, tak vypíšeme chybu, že mu již nelze úkol přidělit/zaevidovat.

*/
#include <iostream>

using namespace std;

class Task {
private:
    static unsigned int s_count;
    string m_name;
    float m_hours;
    string m_id;
public:
    Task(string name, float hours) {
        m_name = name;
        if (hours < 0){
            cerr << "Negative hours in input!" << endl;
            m_hours = 0;
        }
        else m_hours = hours;
        s_count++;
        m_id = "UK"+ to_string(s_count);
    }

    string getName() {
        return m_name;
    }

    float getHours() {
        return m_hours;
    }

    string getId() {
        return m_id;
    }
    void printInfo(){
        cout << endl << "Task data:"
             << "  ID: " << m_id << endl
             << "  Name: " << m_name << endl
             << "  Time to complete: " << m_hours << endl
             << endl;
    }
};
unsigned int Task::s_count = 0;


class Employee {
private:
    float m_workedHours;
    float m_workRatio;
    string m_name;

    float calcMaxWorkHours(){
        float DEFAULT_WORK_HOURS = 40;
        return m_workRatio * DEFAULT_WORK_HOURS;
    }
public:
    Employee(string name, float workRatio){
        m_name = name;
        setWorkRatio(workRatio);
        m_workedHours = 0;
    }

    float getWorkRatio() {
        return m_workRatio;
    }

    void setWorkRatio(float workRatio) {
        if (workRatio < 0 || workRatio > 1){
            cerr << "You entered a wrong ratio! Used default value instead!" << endl;
            m_workRatio = 1;
        }
        else m_workRatio = workRatio;
    }

    string getName() {
        return m_name;
    }

    float getWorkedHours(){
        return m_workedHours;
    }

    void work(Task* task) {
        if (calcMaxWorkHours() < m_workedHours+task->getHours()){
            cerr << "Employee " << m_name << " cannot work anymore :( " << endl;
            return;
        }
        m_workedHours+=task->getHours();
        cout << "Employee " << m_name << " worked on this and he actually did!" << endl;
    }

    void printInfo(){
        cout << endl << "Employee data:"
            << "  Name: " << m_name << endl
            << "  Ratio: " << m_workRatio << endl
            << "  Worked Hours: " << m_workedHours << endl
            << endl;
    }
};


int main() {
    //Task testing
    Task* task1 = new Task("Chillin", 8);
    task1->printInfo();
    Task* task2 = new Task("Do da dishes", 20);
    task2->printInfo();

    Task* wrongTask = new Task("Enter black hole", -50);
    //Employee
    Employee* employee = new Employee("Jarda Kortshak", 0.5);
    employee->printInfo();
    employee->work(task1);
    employee->printInfo();
    employee->work(task2);
    employee->printInfo();

    return 0;
}
