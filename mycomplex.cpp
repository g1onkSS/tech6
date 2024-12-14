#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Класс для работы с комплексными числами.
 */

/**
 * @brief Конструктор по умолчанию.
 * @param aRe Действительная часть.
 * @param aIm Мнимая часть.
 */
Complex::Complex(double aRe, double aIm) : Re(aRe), Im(aIm) {}

/**
 * @brief Конструктор копирования.
 * @param aRval Ссылка на объект типа Complex.
 */
Complex::Complex(const Complex& aRval) : Re(aRval.Re), Im(aRval.Im) {}

/**
 * @brief Деструктор.
 * Обнуляет значения действительной и мнимой частей.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Устанавливает значения действительной и мнимой частей.
 * @param aRe Новое значение действительной части.
 * @param aIm Новое значение мнимой части.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразование объекта Complex в вещественное число (модуль числа).
 * @return Модуль комплексного числа.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисляет модуль комплексного числа.
 * @return Модуль (длина вектора) комплексного числа.
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Оператор сложения двух комплексных чисел.
 * @param aRval Комплексное число для сложения.
 * @return Новый объект Complex, представляющий сумму.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Оператор сложения комплексного числа и вещественного числа.
 * @param aVal Вещественное число для сложения.
 * @return Новый объект Complex, представляющий сумму.
 */
Complex Complex::operator+(const double& aVal) {
    Complex Result;
    Result.Re = Re + aVal;
    Result.Im = Im;
    return Result;
}

/**
 * @brief Оператор вычитания двух комплексных чисел.
 * @param aRval Комплексное число для вычитания.
 * @return Новый объект Complex, представляющий разность.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Оператор вычитания вещественного числа из комплексного.
 * @param aVal Вещественное число для вычитания.
 * @return Новый объект Complex, представляющий разность.
 */
Complex Complex::operator-(const double& aVal) {
    Complex Result(*this);
    Result.Re = Re - aVal;
    return Result;
}

/**
 * @brief Оператор умножения двух комплексных чисел.
 * @param aRval Комплексное число для умножения.
 * @return Новый объект Complex, представляющий произведение.
 */
Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
 * @brief Оператор умножения комплексного числа на вещественное число.
 * @param aVal Вещественное число для умножения.
 * @return Новый объект Complex, представляющий произведение.
 */
Complex Complex::operator*(const double& aVal) {
    Complex Result;
    Result.Re = Re * aVal;
    Result.Im = Im * aVal;
    return Result;
}

/**
 * @brief Оператор деления комплексного числа на вещественное число.
 * @param aVal Вещественное число для деления.
 * @return Новый объект Complex, представляющий результат деления.
 */
Complex Complex::operator/(const double& aVal) {
    Complex Result;
    Result.Re = Re / aVal;
    Result.Im = Im / aVal;
    return Result;
}

/**
 * @brief Оператор сложения с присваиванием.
 * @param aRval Комплексное число для сложения.
 * @return Ссылка на текущий объект Complex.
 */
Complex& Complex::operator+=(const Complex& aRval) {
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

// Далее аналогично добавляем комментарии к оставшимся методам.
