#include <iostream>
#include <cmath>

class Point {
public:
    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
private:
    double x, y, z;
};

class Vector {
public:
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    Vector(double x1, double y1, double z1) {
        x = x1;
        y = y1;
        z = z1;
    }

    Vector(Point point1, Point point2) {
        x = point2.getX() - point1.getX();
        y = point2.getY() - point1.getY();
        z = point2.getZ() - point1.getZ();
    }


    Vector vectorAddition(Vector secondVector) {
        return Vector(x + secondVector.x, y + secondVector.y, z + secondVector.z);
    }

    Vector vectorSubtraction(Vector secondVector) {
        return Vector(x - secondVector.x, y - secondVector.y, z - secondVector.z);
    }

    Vector negativeVector() {
        return Vector(-x, -y, -z);
    }

    double length() {
        return sqrt(x * x + y * y + z * z);
    }
    //единичный вектор 
    Vector unitVector() {
        double len = length();
        if (len > 0) {
            return Vector(x / len, y / len, z / len);
        }
        else {
            return *this;
        }
    }
    // скалярное проивзедение 
    double dotProduct(Vector secondVector) {
        return x * secondVector.getX() + y * secondVector.getY() + z * secondVector.getZ();
    }
    //векторное произведение 
    Vector crossProduct(Vector secondVector) {
        return Vector(
            y * secondVector.getZ() - z * secondVector.getY(),
            z * secondVector.getX() - x * secondVector.getZ(),
            x * secondVector.getY() - y * secondVector.getX()
        );
    }
    //смешанное произведение 
    double tripleProduct(Vector secondVector, Vector thirdVector) {
        return this->dotProduct(secondVector.crossProduct(thirdVector));
    }

    bool isCollinear(Vector secondVector) {
        // Векторы коллинеарны, если их векторное произведение равно нулю
        return this->crossProduct(secondVector).length() == 0;
    }

    bool isCoplanar(Vector secondVector, Vector thirdVector) {
        // Три вектора компланарны, если их смешанное произведение равно нулю
        return this->tripleProduct(secondVector, thirdVector) == 0;
    }

    // 180.pi≈57.2958 приближенное значение для конвертации радиан в градусы.  acos возвращает угол в радианах а мы обратно в градусы 
    double angleWith(Vector otherVector) {
        // Угол между векторами
        double scalarProd = dotProduct(otherVector);
        double len1 = length();
        double len2 = otherVector.length();
        return 57.2958 * acos(scalarProd / (len1 * len2));
    }
private:
    double x, y, z;
};

int main() {
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

    std::cout << "Enter the coordinates of the first point: ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Enter the coordinates of the second point: ";
    std::cin >> x2 >> y2 >> z2;
    std::cout << "Enter the coordinates of the second vector: ";
    std::cin >> x3 >> y3 >> z3;
    std::cout << "Enter the coordinates of the third vector: ";
    std::cin >> x4 >> y4 >> z4;

    Point point1(x1, y1, z1);
    Point point2(x2, y2, z2);

    Vector vector1(point1, point2);
    Vector vector2(x3, y3, z3);
    Vector vector3(x4, y4, z4);

    std::cout << "Vector 1: " << vector1.getX() << " " << vector1.getY() << " " << vector1.getZ() << std::endl;
    std::cout << "Vector 2: " << vector2.getX() << " " << vector2.getY() << " " << vector2.getZ() << std::endl;
    std::cout << "Vector 3: " << vector3.getX() << " " << vector3.getY() << " " << vector3.getZ() << std::endl;

    Vector sum = vector1.vectorAddition(vector2);
    Vector difference = vector1.vectorSubtraction(vector2);
    Vector negative = vector1.negativeVector();
    Vector unit = vector1.unitVector();
    double scalarProd = vector1.dotProduct(vector2);
    Vector vectorProd = vector1.crossProduct(vector2);
    double mixedProd = vector1.tripleProduct(vector2, vector3);
    bool collinear = vector1.isCollinear(vector2);
    bool coplanar = vector1.isCoplanar(vector2, Vector(1, 2, 3));
    double angle = vector1.angleWith(vector2);

    std::cout << "Addition: " << sum.getX() << " " << sum.getY() << " " << sum.getZ() << std::endl;
    std::cout << "Subtraction: " << difference.getX() << " " << difference.getY() << " " << difference.getZ() << std::endl;
    std::cout << "Inverse vector: " << negative.getX() << " " << negative.getY() << " " << negative.getZ() << std::endl;
    std::cout << "Unit vector: " << unit.getX() << " " << unit.getY() << " " << unit.getZ() << std::endl;
    std::cout << "Dot product: " << scalarProd << std::endl;
    std::cout << "Vector product: " << vectorProd.getX() << " " << vectorProd.getY() << " " << vectorProd.getZ() << std::endl;
    std::cout << "Mixed product: " << mixedProd << std::endl;
    std::cout << "Collinear: " << (collinear ? "Yes" : "No") << std::endl;
    std::cout << "Coplanar: " << (coplanar ? "Yes" : "No") << std::endl;
    std::cout << "Angle between vectors: " << angle << " degrees" << std::endl;

    return 0;
}
