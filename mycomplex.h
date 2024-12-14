#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_

#include <iostream>
using namespace std;

/**
 * @class Complex
 * @brief Класс для работы с комплексными числами.
 *
 * Класс предоставляет функциональность для выполнения базовых операций
 * с комплексными числами, включая арифметические операции, сравнение и вычисление модуля.
 */
class Complex {
    double Re; ///< Действительная часть комплексного числа.
    double Im; ///< Мнимая часть комплексного числа.

public:
    /**
     * @brief Конструктор с параметрами.
     * @param aRe Действительная часть (по умолчанию 0).
     * @param aIm Мнимая часть (по умолчанию 0).
     */
    Complex(double aRe = 0, double aIm = 0);

    /**
     * @brief Конструктор копирования.
     * @param other Объект класса Complex для копирования.
     */
    Complex(const Complex& other);

    /**
     * @brief Деструктор.
     */
    ~Complex();

    /**
     * @brief Устанавливает новое значение для комплексного числа.
     * @param aRe Новое значение действительной части.
     * @param aIm Новое значение мнимой части (по умолчанию 0).
     */
    void Set(double aRe, double aIm = 0);

    /**
     * @brief Преобразование объекта к типу double.
     *
     * Возвращает модуль комплексного числа.
     */
    operator double();

    /**
     * @brief Вычисляет модуль комплексного числа.
     * @return Модуль числа.
     */
    double abs();

    /**
     * @brief Оператор ввода из потока.
     * @param stream Входной поток.
     * @param c Объект класса Complex для записи данных.
     * @return Ссылка на входной поток.
     */
    friend istream& operator>>(istream& stream, Complex& c);

    /**
     * @brief Оператор вывода в поток.
     * @param stream Выходной поток.
     * @param c Объект класса Complex для вывода данных.
     * @return Ссылка на выходной поток.
     */
    friend ostream& operator<<(ostream& stream, Complex& c);

    /**
     * @brief Оператор сложения двух комплексных чисел.
     * @param other Второе комплексное число.
     * @return Результат сложения.
     */
    Complex operator+(const Complex& other);

    /**
     * @brief Оператор вычитания двух комплексных чисел.
     * @param other Второе комплексное число.
     * @return Результат вычитания.
     */
    Complex operator-(const Complex& other);

    /**
     * @brief Оператор сложения комплексного числа и действительного числа.
     * @param val Действительное число.
     * @return Результат сложения.
     */
    Complex operator+(const double& val);

    /**
     * @brief Дружественный оператор сложения действительного и комплексного числа.
     * @param val Действительное число.
     * @param other Комплексное число.
     * @return Результат сложения.
     */
    friend Complex operator+(const double& val, const Complex& other);

    /**
     * @brief Оператор вычитания действительного числа из комплексного.
     * @param val Действительное число.
     * @return Результат вычитания.
     */
    Complex operator-(const double& val);

    /**
     * @brief Дружественный оператор вычитания комплексного числа из действительного.
     * @param val Действительное число.
     * @param other Комплексное число.
     * @return Результат вычитания.
     */
    friend Complex operator-(const double& val, const Complex& other);

    /**
     * @brief Оператор умножения двух комплексных чисел.
     * @param other Второе комплексное число.
     * @return Результат умножения.
     */
    Complex operator*(const Complex& other);

    /**
     * @brief Оператор умножения комплексного числа на действительное.
     * @param val Действительное число.
     * @return Результат умножения.
     */
    Complex operator*(const double& val);

    /**
     * @brief Дружественный оператор умножения действительного числа на комплексное.
     * @param val Действительное число.
     * @param other Комплексное число.
     * @return Результат умножения.
     */
    friend Complex operator*(const double& val, const Complex& other);

    /**
     * @brief Оператор деления комплексного числа на действительное.
     * @param val Действительное число.
     * @return Результат деления.
     */
    Complex operator/(const double& val);

    /**
     * @brief Оператор сложения с присваиванием для комплексных чисел.
     * @param other Второе комплексное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator+=(const Complex& other);

    /**
     * @brief Оператор вычитания с присваиванием для комплексных чисел.
     * @param other Второе комплексное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator-=(const Complex& other);

    /**
     * @brief Оператор умножения с присваиванием для комплексных чисел.
     * @param other Второе комплексное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator*=(const Complex& other);

    /**
     * @brief Оператор сложения с присваиванием для действительных чисел.
     * @param val Действительное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator+=(const double& val);

    /**
     * @brief Оператор вычитания с присваиванием для действительных чисел.
     * @param val Действительное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator-=(const double& val);

    /**
     * @brief Оператор умножения с присваиванием для действительных чисел.
     * @param val Действительное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator*=(const double& val);

    /**
     * @brief Оператор деления с присваиванием для действительных чисел.
     * @param val Действительное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator/=(const double& val);

    /**
     * @brief Оператор присваивания для комплексных чисел.
     * @param other Второе комплексное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator=(const Complex& other);

    /**
     * @brief Оператор присваивания для действительных чисел.
     * @param val Действительное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator=(const double& val);
};

#endif
