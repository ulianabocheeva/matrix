#include <iostream>
#include "matrix.h"
#define MESSAGE endl << "[Matrix::" << __FUNCTION__ << "]" << endl

using namespace std;

void test_constructor();//конструктор по длине
void test_init_list();//конструктор со списком инициализации
void test_copy();//копирование
void test_transfer();//перенос
void test_operator_eq();//перегрузка оператора присваивания
void test_operator_plus_and_equall();//перегрузка оператора +=
void test_operator_minus_and_equall();//перегрузка оператора -=
void test_plus();//сложение двух матриц
void test_minus();//вычитание двух матриц
void test_multiple();//умножение двух матриц
void test_plus_matr_and_num();//сложение матрицы и числа
void test_minus_matr_and_num();//вычитание матрицы и числа
void test_multiple_matr_and_num();//умножение матрицы и числа
void test_devide_solo_matr_and_num();//деление матрицы и числа
void test_get_elem();//получение элемента
void test_square();//проверка на квадратность
void test_get_rows_cols();//тест на размер
void test_set_elem();//добавление элемента
void test_iterator_begin_end();
void test_iterator_next_increment();
void test_iterator_value();
void test_iterator_operators();

int main(){
    test_constructor();
    test_init_list();
    test_copy();
    test_transfer();
    test_operator_eq();
    test_operator_plus_and_equall();
    test_operator_minus_and_equall();
    test_plus();
    test_minus();
    test_multiple();
    test_plus_matr_and_num();
    test_minus_matr_and_num();
    test_multiple_matr_and_num();
    test_devide_solo_matr_and_num();
    test_get_elem();
    test_square();
    test_get_rows_cols();
    test_set_elem();
    test_iterator_begin_end();
    test_iterator_next_increment();
    test_iterator_value();
    test_iterator_operators();
}

void test_constructor()
{
    try {
        Matrix<int> matr(1,3);
        cout << MESSAGE << matr << endl;
        Matrix<int> matr2(2,2);
        cout << MESSAGE << matr2 << endl;
        Matrix<int> matr3(-1,-1);
        cout << MESSAGE << matr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix<int> matr4(0,0);
        cout << MESSAGE << matr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_init_list()//конструктор со списком инициализации
{
    try {
        Matrix<int> matr_init{{1,2,3}, {4,5,6}};
        cout << MESSAGE << matr_init << endl;
        Matrix<int> matr_init1{{1,2}, {3,4}};
        cout << MESSAGE << matr_init1 << endl;
        Matrix<int> matr_init2{};
        cout << MESSAGE << matr_init2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_copy()//копирование
{
    try {
        Matrix<int> matr1(1,3);
        Matrix<int> matr2=matr1;
        cout << MESSAGE << matr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_transfer()//перенос
{
    try {
        Matrix<int> matr1(1,3);
        Matrix<int> matr2=std::move(matr1);
        cout << MESSAGE << matr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_operator_eq()//перегрузка оператора присваивания
{
    try {
        Matrix <int> init_matrix ({{1, 2}, {3, 4}});
        Matrix <int> equal_matrix = init_matrix;
        cout << MESSAGE << equal_matrix << endl;
        Matrix <int> init_matrix2 ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> equal_matrix2 ({{4, 5, 6}, {2, 3, 6}});
        equal_matrix2 = init_matrix2;
        cout << MESSAGE << equal_matrix2 << endl;
        Matrix <int> matr (1,1);
        equal_matrix = matr;
        cout << MESSAGE << equal_matrix << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_operator_plus_and_equall(){
    try {
        Matrix<int> matr{{1,2,3}, {4,5,6}};
        Matrix<int> matr2(2,3);
        matr2 = matr;
        cout << MESSAGE << matr2 << endl;
        Matrix<int> matr3(2,2);
        matr3 = matr;
        cout << MESSAGE << matr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_operator_minus_and_equall(){
    try {
        Matrix<int> matr{{1,2,3}, {4,5,6}};
        Matrix<int> matr2(2,3);
        matr2 = matr;
        cout << MESSAGE << matr2 << endl;
        Matrix<int> matr3(2,2);
        matr3 = matr;
        cout << MESSAGE << matr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_plus(){
    Matrix <int> initMatr({{1, 2, 3}, {4, 5, 6}});
    Matrix <int> initMatr2 ({{1, 2, 3}, {4, 5, 6}});
    Matrix <int> matr (1,1);
    Matrix <int> emptyMatr(0,0);
    try {
        Matrix <int> resMatr = initMatr+initMatr2;
        cout << MESSAGE << resMatr << endl;
        Matrix <int> resMatr2 = initMatr+matr;
        cout << MESSAGE << resMatr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr3 = matr+emptyMatr;
        cout << MESSAGE << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr4 = emptyMatr+emptyMatr;
        cout << MESSAGE << resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_minus(){
    Matrix <int> initMatr({{1, 2, 3}, {4, 5, 6}});
    Matrix <int> initMatr2 ({{0, 1, 2}, {3, 4, 5}});
    Matrix <int> matr (1,1);
    Matrix <int> emptyMatr(0,0);
    try {
        Matrix <int> resMatr = initMatr-initMatr2;
        cout << MESSAGE << resMatr << endl;
        Matrix <int> resMatr2 = initMatr-matr;
        cout << MESSAGE << resMatr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr3 = matr-emptyMatr;
        cout << MESSAGE << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr4 = emptyMatr-emptyMatr;
        cout << MESSAGE << resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_multiple(){
    Matrix <int> initMatr({{1, 2}, {3, 4}});
    Matrix <int> initMatr2 ({{1, 2}, {3, 4}});
    Matrix <int> initMatr3 ({{1, 2, 3},{4,5,6}});
    Matrix <int> initMatr4 ({{1, 2},{3,4},{5,6}});
    Matrix <int> matr (1,1);
    Matrix <int> emptyMatr(0,0);
    try {
        Matrix <int> resMatr = initMatr*initMatr2;
        cout << MESSAGE << resMatr << endl;
        Matrix <int> resMatr2 = initMatr3*initMatr4;
        cout << MESSAGE << resMatr2 << endl;
        Matrix <int> resMatr3 = initMatr*initMatr4;
        cout << MESSAGE << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr3 = matr*emptyMatr;
        cout << MESSAGE << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr4 = emptyMatr*emptyMatr;
        cout << MESSAGE << resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_plus_matr_and_num(){}
void test_minus_matr_and_num(){}
void test_multiple_matr_and_num(){}
void test_devide_solo_matr_and_num(){}
void test_get_elem(){}
void test_square(){}
void test_get_rows_cols(){}
void test_set_elem(){}
void test_iterator_begin_end(){}
void test_iterator_next_increment(){}
void test_iterator_value(){}
void test_iterator_operators(){}
