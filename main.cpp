#include <iostream>
#include "matrix.h"
#define MESSAGE endl << "[Matrix::" << __FUNCTION__ << "]" << endl

using namespace std;

void test_constructor();//конструктор по длине
void test_init_list();//конструктор со списком инициализации
void test_copy();//копирование
void test_transfer();//перенос
void test_operator_eq();//перегрузка оператора присваивания
void test_operator_plus_and_equall();//перегрузка оператора присваивания
void test_operator_minus_and_equall();//перегрузка оператора присваивания
void test_get_and_get_elem();//получениеи добавление элемента
void test_square();//проверка на квадратность
void test_size();//проверка на размер
void test_plus();//сложение двух матриц
void test_minus();//вычитание двух матриц
void test_multiple();//умножение двух матриц
void test_plus_matr_and_num();//сложение матрицы и числа
void test_minus_matr_and_num();//вычитание матрицы и числа
void test_multiple_matr_and_num();//умножение матрицы и числа
void test_devide_solo_matr_and_num();//деление матрицы и числа

int main(){
    test_constructor();
    test_init_list();
    test_copy();
    test_transfer();
    test_operator_eq();
    test_operator_plus_and_equall();
}

void test_constructor()
{
    try {
        Matrix<int> matr(1,3);
        cout << MESSAGE << matr << endl;
        Matrix<int> matr1(-1,-1);
        cout << MESSAGE << matr1 << endl;
        Matrix<int> matr2(0,0); // не доходит до сюда
        cout << MESSAGE << matr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception says: " << e.what() << endl;
    }
}

void test_init_list()//конструктор со списком инициализации
{
    try {
        Matrix<int> matrInit{{1,2,3}, {4,5,6}};
        cout << MESSAGE << matrInit << endl;
        Matrix<int> matrInit1{};
        cout << MESSAGE << matrInit1 << endl;
    } catch(exceptions &e) {
        cout << "Exception says: " << e.what() << endl;
    }
}
void test_copy()//копирование
{
    try {
        Matrix<int> matr1(1,3);
        Matrix<int> matr2=matr1;
        cout << MESSAGE << matr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception says: " << e.what() << endl;
    }
}
void test_transfer()//перенос
{
    try {
        Matrix<int> matr1(1,3);
        Matrix<int> matr2=std::move(matr1);
        cout << MESSAGE << matr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception says: " << e.what() << endl;
    }
}

void test_operator_eq()//перегрузка оператора присваивания
{
    try {
        Matrix<int> matrCopy{{1,2,3}, {4,5,6}};
        Matrix<int> matrCopy2(2,3);
        matrCopy2 = matrCopy;
        cout << MESSAGE << matrCopy2 << endl;
    } catch(exceptions &e) {
        cout << "Exception says: " << e.what() << endl;
    }
}

void test_operator_plus_and_equall(){
    /*try {
        Matrix<int> matrCopy{{1,2,3}, {4,5,6}};
        Matrix<int> matrCopy2(2,3);
        matrCopy2 = matrCopy;
        cout << MESSAGE << matrCopy2 << endl;
    } catch(exceptions &e) {
        cout << "Exception says: " << e.what() << endl;
    }*/
}
