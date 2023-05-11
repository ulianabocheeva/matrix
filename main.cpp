#include <iostream>
#include "matrix.h"
#define MESSAGE endl << "<<Test function  --  " << __FUNCTION__ <<">>" << endl

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
void test_iterator();

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
    test_iterator();
}

void test_constructor()
{
    cout<<MESSAGE<<endl;
    try {
        Matrix<int> matr(1,3);
        cout << matr << endl;
        Matrix<int> matr2(2,2);
        cout <<  matr2 << endl;
        Matrix<int> matr3(-1,-1);
        cout << matr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix<int> matr4(0,0);
        cout << matr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_init_list()//конструктор со списком инициализации
{
    cout<<MESSAGE<<endl;
    try {
        Matrix<int> matr_init{{1,2,3}, {4,5,6}};
        cout <<  matr_init << endl;
        Matrix<int> matr_init1{{1,2}, {3,4}};
        cout <<  matr_init1 << endl;
        Matrix<int> matr_init2{};
        cout <<  matr_init2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_copy()//копирование
{
    cout<<MESSAGE<<endl;
    try {
        Matrix<int> matr1(1,3);
        Matrix<int> matr2=matr1;
        cout << matr2 << endl;
        Matrix<int> matr3{{1,2,3},{4,5,6}};
        Matrix<int> matr4=matr3;
        cout<<matr4<<endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_transfer()//перенос
{
    cout<<MESSAGE<<endl;
    try {
        Matrix<int> matr1(1,3);
        Matrix<int> matr2=std::move(matr1);
        cout << matr2 << endl;
        Matrix<int> initMatr{{1,2,3},{4,5,6}};
        Matrix<int> matr3=std::move(initMatr);
        cout << matr3 << endl;
        Matrix<int> emptyMatr(0,0);
        Matrix<int> matr4=std::move(emptyMatr);
        cout << matr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_operator_eq()//перегрузка оператора присваивания
{
    cout<<MESSAGE<<endl;
    try {
        Matrix <int> init_matrix ({{1, 2}, {3, 4}});
        Matrix <int> equal_matrix = init_matrix;
        cout <<  equal_matrix << endl;
        Matrix <int> init_matrix2 ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> equal_matrix2 ({{4, 5, 6}, {2, 3, 6}});
        equal_matrix2 = init_matrix2;
        cout <<  equal_matrix2 << endl;
        Matrix <int> matr (1,1);
        equal_matrix = matr;
        cout <<  equal_matrix << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_operator_plus_and_equall(){
    cout<<MESSAGE<<endl;
    try {
        Matrix<int> matr{{1,2,3}, {4,5,6}};
        Matrix<int> matr2(2,3);
        matr2 = matr;
        cout  << matr2 << endl;
        Matrix<int> matr3(2,2);
        matr3 = matr;
        cout << matr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_operator_minus_and_equall(){
    cout<<MESSAGE<<endl;
    try {
        Matrix<int> matr{{1,2,3}, {4,5,6}};
        Matrix<int> matr2(2,3);
        matr2 = matr;
        cout  << matr2 << endl;
        Matrix<int> matr3(2,2);
        matr3 = matr;
        cout << matr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_plus(){
    cout<<MESSAGE<<endl;
    Matrix <int> initMatr({{1, 2, 3}, {4, 5, 6}});
    Matrix <int> initMatr2 ({{1, 2, 3}, {4, 5, 6}});
    Matrix <int> matr (1,1);
    Matrix <int> emptyMatr(0,0);
    try {
        Matrix <int> resMatr = initMatr+initMatr2;
        cout  << resMatr << endl;
        Matrix <int> resMatr2 = initMatr+matr;
        cout  << resMatr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr3 = matr+emptyMatr;
        cout  << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr4 = emptyMatr+emptyMatr;
        cout <<  resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_minus(){
    cout<<MESSAGE<<endl;
    Matrix <int> initMatr({{1, 2, 3}, {4, 5, 6}});
    Matrix <int> initMatr2 ({{0, 1, 2}, {3, 4, 5}});
    Matrix <int> matr (1,1);
    Matrix <int> emptyMatr(0,0);
    try {
        Matrix <int> resMatr = initMatr-initMatr2;
        cout  << resMatr << endl;
        Matrix <int> resMatr2 = initMatr-matr;
        cout  << resMatr2 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr3 = matr-emptyMatr;
        cout  << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr4 = emptyMatr-emptyMatr;
        cout  << resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_multiple(){
    cout<<MESSAGE<<endl;
    Matrix <int> initMatr({{1, 2}, {3, 4}});
    Matrix <int> initMatr2 ({{1, 2}, {3, 4}});
    Matrix <int> initMatr3 ({{1, 2, 3},{4,5,6}});
    Matrix <int> initMatr4 ({{1, 2},{3,4},{5,6}});
    Matrix <int> matr (1,1);
    Matrix <int> emptyMatr(0,0);
    try {
        Matrix <int> resMatr = initMatr*initMatr2;
        cout << resMatr << endl;
        Matrix <int> resMatr2 = initMatr3*initMatr4;
        cout << resMatr2 << endl;
        Matrix <int> resMatr3 = initMatr*initMatr4;
        cout << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr3 = matr*emptyMatr;
        cout << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> resMatr4 = emptyMatr*emptyMatr;
        cout << resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_plus_matr_and_num(){
    cout<<MESSAGE<<endl;
    try {
        double a = 5.1;
        Matrix <double> initDoubleMatr ({{1.8, 1.8, 1.8}, {1.8, 1.8, 1.8}});
        Matrix <double> resMatr = initDoubleMatr + a;
        cout << resMatr << endl;
        Matrix <int> initIntMatr ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> resMatr2 = initIntMatr + a;
        cout << resMatr2 << endl;
        Matrix <int> initEmptyMatr (0,0);
        Matrix <int> resMatr3 = initEmptyMatr + a;
        cout << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_minus_matr_and_num(){
    cout<<MESSAGE<<endl;
    try {
        double a = 5.1;
        Matrix <double> initDoubleMatr ({{1.8, 1.8, 1.8}, {1.8, 1.8, 1.8}});
        Matrix <double> resMatr = initDoubleMatr - a;
        cout << resMatr << endl;
        Matrix <int> initIntMatr ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> resMatr2 = initIntMatr - a;
        cout << resMatr2 << endl;
        Matrix <int> initEmptyMatr (0,0);
        Matrix <int> resMatr3 = initEmptyMatr - a;
        cout << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_multiple_matr_and_num(){
    cout<<MESSAGE<<endl;
    try {
        double a = 5.1;
        Matrix <double> initDoubleMatr ({{1.8, 1.8, 1.8}, {1.8, 1.8, 1.8}});
        Matrix <double> resMatr = initDoubleMatr * a;
        cout << resMatr << endl;
        Matrix <int> initIntMatr ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> resMatr2 = initIntMatr * a;
        cout << resMatr2 << endl;
        Matrix <int> initEmptyMatr (0,0);
        Matrix <int> resMatr3 = initEmptyMatr * a;
        cout << resMatr3 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_devide_solo_matr_and_num(){
    cout<<MESSAGE<<endl;
    try {
        double a = 5.1;
        int b=0;
        Matrix <double> initDoubleMatr ({{1.8, 1.8, 1.8}, {1.8, 1.8, 1.8}});
        Matrix <double> resMatr = initDoubleMatr / a;
        cout << resMatr << endl;
        Matrix <int> initIntMatr ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> resMatr2 = initIntMatr / a;
        cout << resMatr2 << endl;
        Matrix <int> initEmptyMatr (0,0);
        Matrix <int> resMatr3 = initEmptyMatr / a;
        cout << resMatr3 << endl;
        Matrix <int> resMatr4 = initIntMatr / b;
        cout << resMatr4 << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}
void test_get_elem(){
    cout<<MESSAGE<<endl;
    try {
        Matrix <int> initMatr ({{1, 2, 3}, {4, 5, 6}});
        cout <<initMatr<< "Matrix 1 1 elem:" <<initMatr.getElem(1,1)<< endl;
        cout <<initMatr<< "Matrix 4 4 elem:" <<initMatr.getElem(4,4)<< endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> initEmptyMatr (0,0);
        cout <<initEmptyMatr<< "Matrix 0 0 elem:" <<initEmptyMatr.getElem(0,0)<< endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_square(){
    cout<<MESSAGE<<endl;
    try {
        Matrix <int> initRectangle ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> initSquare ({{1, 2}, {3, 4}});
        if (initRectangle.is_square())
            cout <<initRectangle<< "Matrix is square" << endl;
        else
            cout <<initRectangle<< "Matrix isn't square" << endl;
        if (initSquare.is_square())
            cout << initSquare <<"Matrix is square" << endl;
        else
            cout << initSquare << "Matrix isn't square" << endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_get_rows_cols(){
    cout<<MESSAGE<<endl;
    try {
        Matrix <int> initMatr ({{1, 2, 3}, {4, 5, 6}});
        Matrix <int> initEmptyMatr (0,0);
        cout <<initMatr<< "Matrix number of rows:" <<initMatr.get_row()<< endl;
        cout << "Matrix number of columns:" <<initMatr.get_columns()<< endl;
        cout <<initEmptyMatr<< "Matrix number of rows:" <<initEmptyMatr.get_row()<< endl;
        cout << "Matrix number of columns:" <<initEmptyMatr.get_columns()<< endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_set_elem(){
    cout<<MESSAGE<<endl;
    int elem=0;
    try {
        Matrix <int> initMatr ({{1, 2, 3}, {4, 5, 6}});
        cout <<initMatr;
        initMatr.setElem(1,1,elem);
        cout << "Set element at 1,1 position in matrix:\n" <<initMatr<< endl;
        cout <<initMatr;
        initMatr.setElem(4,4,elem);
        cout << "Set element at 4 4 position in matrix:\n" <<initMatr<< endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
    try {
        Matrix <int> initEmptyMatr (0,0);
        initEmptyMatr.setElem(0,0,elem);
        cout <<initEmptyMatr<< "Set element at 0 0 position in matrix:\n" <<initEmptyMatr<< endl;
    } catch(exceptions &e) {
        cout << "Exception is: " << e.what() << endl;
    }
}

void test_iterator(){
    cout<<MESSAGE<<endl;
    try {
        Matrix <int> matr{{1,2,3},{4,5,6},{7,8,9}};
        Matrix <int>::Iterator it = matr.iterator_begin();
        cout << MESSAGE << it.value() << endl;
        cout << MESSAGE << *it << endl;
        cout << MESSAGE << (++it).value() << endl;
        Matrix <int> matr2{{1,2,3},{4,5,6},{7,8,9}};
        Matrix <int>::Iterator it2 = matr2.iterator_end();
        cout << MESSAGE << it2.value() << endl;
        cout << MESSAGE << (it == it2) << endl;
        cout << MESSAGE << (it != it2) << endl;
        Matrix <int> matr3{};
        Matrix<int> move = std::move(matr);
        } catch(exceptions &e) {
            cout << "Exception says: " << e.what() << endl;
        }
}
