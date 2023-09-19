#include <iostream>
#include <cmath>

struct squareRoots {
    double positive;
    double negative;
};

double discriminant(int a, int b, int c) {
    return b * b - 4 * a * c;
}

squareRoots squareEquation(int a, int b, int c) {
    return {
            .positive = (-b + sqrt(discriminant(a, b, c))) / (2 * a),
            .negative = (-b - sqrt(discriminant(a, b, c))) / (2 * a)
    };
}

void greet(const std::string& name){
    std::cout << "Hey "+name+"!" << std::endl;
}

std::string getName() {
    std::string name;
    std::cin >> name;
    return name;
}

int main() {
    std::string readName;
    std::cout << "What's your readName?" << std::endl;
    std::cin >> readName;
    std::cout << "Hello " + readName + "!" << std::endl;

    squareRoots roots = squareEquation(2, -11, +14);

    std::cout << "Positive: " << roots.positive << std::endl;
    std::cout << "Negative: " << roots.negative << std::endl;

    greet("Jarda!");
    std::cout << "What is your readName?" << std::endl;
    std::string readUserName = getName();
    std::cout << "User readName: " + readUserName << std::endl;

    return 0;
}
