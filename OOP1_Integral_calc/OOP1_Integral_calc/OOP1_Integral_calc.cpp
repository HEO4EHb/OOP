#include <iostream>
#include <functional>
#include <cmath>
#include <stdexcept>

// Базовый класс для вычисления интегралов
class IntegralCalc {
public:
    IntegralCalc(int numPoints, double lowerBound, double upperBound) {
        double step=(upperBound-lowerBound)/(numPoints-1);
        std::cout << step << std::endl;
        // Проверка корректности входных данных
        if (numPoints < 2 || step <= 0.0)
            throw std::invalid_argument("Incorrect input");
        else {
            this->numPoints = numPoints;//обращаемся внутри класса и делаем присвоение через this
            this->step = step;
        }
    }

    // Виртуальная функция для вычисления интеграла, должна быть переопределена в производных классах
    virtual double Calc(const std::function<double(double)>& integralFunc, double lowerBound, double upperBound) const = 0;

protected:
    int numPoints;
    double step;
};

// Класс для вычисления интеграла методом трапеций
class TrapezoidalIntegrator : public IntegralCalc {
public:
    TrapezoidalIntegrator(int numPoints, double lowerBound, double upperBound) : IntegralCalc(numPoints, lowerBound, upperBound) {}

    // Переопределение метода для вычисления интеграла
    double Calc(const std::function<double(double)>& integralFunc, double lowerBound, double upperBound) const override {
        double result = 0.0;
        double x = lowerBound;

        // Сумма значений функции * шага / 2
        for (int i = 0; i < numPoints; ++i) {
            double fx = integralFunc(x);
            x += step;
            result += fx;
        }
        result += (integralFunc(upperBound) - integralFunc(lowerBound)) / 2.0;
        result *= step;

        return result;
    }
};

// Класс для вычисления интеграла методом Симпсона
class SimpsonIntegrator : public IntegralCalc {
public:
    SimpsonIntegrator(int numPoints, double lowerBound, double upperBound) : IntegralCalc(numPoints, lowerBound, upperBound) {
        // Проверка, что количество точек кратно двум (требование метода Симпсона)
        if (numPoints % 2 != 0)
            throw std::invalid_argument("Incorrect input: the number of points must be a multiple of two");
    }

    // Переопределение метода для вычисления интеграла
    double Calc(const std::function<double(double)>& integralFunc, double lowerBound, double upperBound) const override {
        double result = integralFunc(lowerBound) + integralFunc(upperBound);
        double x = lowerBound + step;

        // Сумма f(x) + 2 * f(x + step) + 4 * f(x + 2 * step) * шаг / 3
        for (int i = 1; i < numPoints; ++i) {
            double fx = integralFunc(x);
            x += step;

            if (i % 2 == 0)
                result += 2 * fx;
            else
                result += 4 * fx;
        }

        result *= step / 3.0;

        return result;
    }
};

int main() {
    try {
        // Параметры для вычисления интеграла
        int numPoints = 1000;
        double step = 0.001;
        double lowerBound = 0.0;
        double upperBound = 1.0;

        // Интегрирование функции x^2 методом трапеций
        TrapezoidalIntegrator trapezoidal(numPoints, lowerBound, upperBound);
        auto integralFunc = [](double x) { return x * x; };
        double integralResult = trapezoidal.Calc(integralFunc, lowerBound, upperBound);
        std::cout << "Trapezoidal: " << integralResult << std::endl;

        // Интегрирование функции x^2 методом Симпсона
        SimpsonIntegrator simpson(numPoints, lowerBound, upperBound);
        integralResult = simpson.Calc(integralFunc, lowerBound, upperBound);
        std::cout << "Simpson: " << integralResult << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
