#pragma once
#ifndef SQUARE_H_
#define SQUARE_H_
#include <stdio.h>  ///< подключает заголовочный файл stdio.h
#include <assert.h>
#include <math.h>
const double DOUBLE_RANGE = 0.00001; ///< Константа, содержащая значение минимального возможного отличия чисел типа double, при котором они будут различимы.
int CompareTwoDouble(double number1, double number2);
/// Набор возможных количетсв корней уравнения

typedef enum
{
    NO_ROOTS = 0,  ///< Ноль корней у уравнения
    ONE_ROOT = 1,  ///< Один корень у уравнения
    TWO_ROOTS = 2, ///< Два корня у уравнения
    INF_ROOTS = 3 ///< Бесконечное количество корней у уравнения
}NUM_OF_ROOTS;



const int NUM_READ_SCANF = 3; ///< Константа, обозначающая необходимое количество распознанных функцией scanf() введённых значений коэффициентов уравнения в функции input_coef()

/**
    Функция, решающая линейное уравнение вида а * х + b = 0
    \param[in] b  Коэффициент уравнения перед переменной х
    \param[in] с  Свободный член уравнения
    \param[out] x1 Переменная, значением которй является адресс ячейки памяти, содержащей значение корня уравнения х1
    \return Возвращает количество корней решаемого уравнения
*/
NUM_OF_ROOTS SolveLinEq(double b, double c, double* x1, double* x2);


/**
    Присваивает коэффициентам уравнения а, b и с соответствующие значения, введённые пользователем
    \param[in] a Переменная, значением которй является адресс ячейки памяти, содержащей значение коэффициента а уравнения
    \param[in] b Переменная, значением которй является адресс ячейки памяти, содержащей значение коэффициента b уравнения
    \param[in] c Переменная, значением которй является адресс ячейки памяти, содержащей значение коэффициента c уравнения
    \return

*/
void input_coef(double* a, double* b, double* c);


/**
    Решает квадратное уравнение вида а * х^2 + b * x + c = 0
    \param[in] a  Коэффициент а уравнения
    \param[in] b  Коэффициент b уравнения
    \param[in] c  Коэффициент c уравнения
    \param[out] x1 Переменная, значением которй является адресс ячейки памяти, содержащей значение корня уравнения х1
    \param[out] x2 Переменная, значением которй является адресс ячейки памяти, содержащей значение корня уравнения х2
    \return Возвращает количиство корней решаемого уравнения
*/
NUM_OF_ROOTS SolveSquareEq(double a, double b, double c, double* x1, double* x2);


/**
    Сравнивает два числа типа double
    \param[in] number1 Число, которое сравнивается с number2
    \param[in] number2 Число, которое сравнивается с number1
    \return Возвращает значение 1 (истина), если number1 равен number2, или значение 0 (ложь), если number1 не равен number2
*/
int CompareTwoDouble(double number1, double number2);


/**
    Проверяет правильность работы функции SolveSquareEq()
    \param[in] x1            Первый корень уравнения
    \param[in] x2            Второй корень уравнения
    \param[in] correct1      Первый корень уравнения из программы тестировщика
    \param[in] correct2      Второй корень уравнения из программы тестировщика
    \param[in] correctnumber Верное количество корней в программе тестировщике
*/
int TestProgram(double coefa, double coefb, double coefc, double correct1, double correct2, NUM_OF_ROOTS correct_number);


int AllTestForProgram(void);

#endif /*SQUARE_H_*/
