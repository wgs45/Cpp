#include <iostream>

int main() {
    double weight = 0.0;
    int planet_num = 8;

    std::cout << "Enter current weight based on Earth mass: ";
    std::cin >> weight;

    std::cout << "Enter planet destination in numbers: ";
    std::cin >> planet_num;

    switch (planet_num) {
        case 1:
            weight = weight * 0.38;
            std::cout << "Weight in Mercury: " << weight << "\n";
            break;
        case 2:
            weight = weight * 0.91;
            std::cout << "Weight in Venus: " << weight << "\n";
            break;
        case 3:
            weight = weight * 0.38;
            std::cout << "Weight in Mars: " << weight << "\n";
            break;
        case 4:
            weight = weight * 2.34;
            std::cout << "Weight in Jupyter: " << weight << "\n";
            break;
        case 5:
            weight = weight * 1.06;
            std::cout << "Weight in Saturn: " << weight << "\n";
            break;
        case 6:
            weight = weight * 0.92;
            std::cout << "Weight in Uranus: " << weight << "\n";
        case 7:
            weight = weight * 1.19;
            std::cout << "Weight in Neptune: " << weight << "\n";
            break;
        default:
            std::cout << "Weight in Earth: " << weight << "\n";
    }
    
    return 0;
}
