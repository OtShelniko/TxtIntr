#include <iostream>
#include <cmath>
#include <cstdlib>

void printUsage() {
    std::cout << "Использование:\n";
    std::cout << "  calculator -o circle <радиус>\n";
    std::cout << "  calculator -o triangle <сторона1> <сторона2> <сторона3>\n";
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateTriangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2; // Полупериметр
    return std::sqrt(s * (s - a) * (s - b) * (s - c)); // Площадь по формуле Герона
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printUsage();
        return 1;
    }

    std::string operation = argv[1];
    if (operation == "-o" || operation == "--operation") {
        std::string shape = argv[2];

        if (shape == "circle") {
            if (argc != 4) {
                std::cerr << "Для площади круга требуется один параметр (радиус).\n";
                return 1;
            }
            double radius = std::atof(argv[3]);
            double area = calculateCircleArea(radius);
            std::cout << "Площадь круга с радиусом " << radius << " равна " << area << ".\n";
        } 
        else if (shape == "triangle") {
            if (argc != 6) {
                std::cerr << "Для площади треугольника требуется три параметра (стороны).\n";
                return 1;
            }
            double a = std::atof(argv[3]);
            double b = std::atof(argv[4]);
            double c = std::atof(argv[5]);
            double area = calculateTriangleArea(a, b, c);
            std::cout << "Площадь треугольника со сторонами " << a << ", " << b << " и " << c << " равна " << area << ".\n";
        } 
        else {
            std::cerr << "Неизвестная операция: " << shape << ".\n";
            printUsage();
            return 1;
        }
    } 
    else {
        std::cerr << "Неизвестный флаг: " << operation << ".\n";
        printUsage();
        return 1;
    }

    return 0;
}
