#include <getopt.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    int opt;
    
     if(argc == 1) { 
        cout << "Калькулятор, который выполняет умножение и деление" << endl;
        cout << "Для опции -op есть два возможных значения: mul (умножение) и div (деление)" << endl;
        cout << "Пример ./имя_файла -op mul 3 4" << endl;
        return 0;
    }
    
    double x = 0;
    double y = 0;
    double z = 0;
    double w = 0;
    
    while((opt = getopt(argc, argv, "o:p:")) != -1) { 
        switch(opt) {
            case 'o':
                string type = string(optarg);
                x = atof(argv[3]);
                y = atof(argv[4]);
                z = atof(argv[5]);
                w = atof(argv[6]);
                if (type == "m") {
                    double result = x * y * z * w;
                    cout << "Умножение: " << result << endl;
                }
                else if (type == "d") {
                    if (y!= 0) {
                        double result = (x / y)/(z / w);
                        cout << "Деление: " << result << endl;
                    }
                    else if (argc == 5) {
                    double result = (x / y) / z;
                    cout << result << endl;
                    }
                    else if (argc == 6) {
                    double result = ((x / y) / z) / w;
                    cout << result << endl;}
                    else {
                        cout << "Невозможно выполнить деление на ноль" << endl;
                        return 0;
                    }
                }
                else {
                    cout << "Неизвестная операция" << endl;
                    return 0;
                }
                break;
        }
    }
    return 0;
}
