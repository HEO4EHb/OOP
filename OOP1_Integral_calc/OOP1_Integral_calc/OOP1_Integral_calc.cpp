#include <iostream>
#include <functional>
#include <cmath>
#include <stdexcept>

class IntegralCalculation {
public:
    IntegralCalculation(int numPoints, double step) {
        if (numPoints < 2 || step <= 0.0)
            throw std::invalid_argument("Incorrect input"); // Очистка памяти как в сегодняшней лекции не требуется, так как не используется оператор new
        else {
            this->numPoints = numPoints;
            this->step = step;
        }
    }

    // Метод виртуальный, тк хотим его изменить в наследуемых классах
    virtual double Calc(const std::function<double(double)>& integralFunc, double lowerBound, double upperBound) const = 0;

protected:
    int numPoints;
    double step;
};

class Trapezoidal : public IntegralCalculation {
public:
    Trapezoidal(int numPoints, double step) : IntegralCalculation(numPoints, step) {}

    // Переопределяем Calc
    double Calc(const std::function<double(double)>& integralFunc, double lowerBound, double upperBound) const override {
        double result = 0.0;
        double x = lowerBound;

        // Сумма функций * шага / 2
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

class Simpson : public IntegralCalculation {
public:
    //Используется интерполяция квадратичными полиномами, которая требует кратность двум
    Simpson(int numPoints, double step) : IntegralCalculation(numPoints, step) {
        if (numPoints % 2 != 0)
            throw std::invalid_argument("Incorrect input: the number of points must be a multiple of two");
    }

    // Переопределяем Calc
    double Calc(const std::function<double(double)>& integralFunc, double lowerBound, double upperBound) const override {
        double result = integralFunc(lowerBound) + integralFunc(upperBound);
        double x = lowerBound + step;

        // Сумма f(x) + 2 * f(x + step) + 4 * f*(x + 2 * step) * step / 3
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
        int numPoints = 1000;
        double step = 0.001;
        double lowerBound = 0.0;
        double upperBound = 1.0;

        Trapezoidal trapezoidal(numPoints, step);
        auto integralFunc = [](double x) { return x * x; };
        double integralResult = trapezoidal.Calc(integralFunc, lowerBound, upperBound);
        std::cout << "Trapezoidal: " << integralResult << std::endl;

        Simpson simpson(numPoints, step);
        integralResult = simpson.Calc(integralFunc, lowerBound, upperBound);
        std::cout << "Simpson: " << integralResult << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}