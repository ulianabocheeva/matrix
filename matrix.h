#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "exceptions.h"
using namespace std;
template<typename T>
class Matrix
{
private:
    int height, width;
    T** matr;

public:
    class Iterator
        {
        private:
            Matrix<T>& matr;
            int it_matrix_row;
            int it_matrix_col;
        public:
            Iterator(Matrix <T> &container_obj, size_t rows, size_t cols);
            Iterator next();
            T value();
            bool is_begin();
            bool is_end();
            Iterator &operator++();
            T &operator*();
            bool operator ==(Iterator &b);
            bool operator !=(Iterator &b);
        };
    Matrix(unsigned int height, unsigned int width);
    Matrix( Matrix<T>& matr);
    Matrix(Matrix<T>&& matr);
    explicit Matrix(std::initializer_list<std::initializer_list<T>> lst);
    ~Matrix();
    Matrix<T>& operator =( Matrix<T>& matr);
    Matrix<T>& operator +=( Matrix<T>& matr);
    Matrix<T>& operator -=( Matrix<T>& matr);

    void setElem(unsigned int width, unsigned int height, T&elem);
    T& getElem(unsigned int width, unsigned int height);
    T& operator ()(unsigned int width, unsigned int height);
    bool is_square();
    unsigned int get_row() const;
    unsigned int get_columns() const;

    template<typename _T>
    friend Matrix<_T> operator +( Matrix<_T>& m1,Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator -( Matrix<_T>& m1,Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator *( Matrix<_T>& m1,Matrix<_T>& m2);

    template<typename _T>
    friend Matrix<_T> operator +( Matrix<_T>& m1,double num);

    template<typename _T>
    friend Matrix<_T> operator -( Matrix<_T>& m1,double num);

    template<typename _T>
    friend Matrix<_T> operator /( Matrix<_T>& m1,double num);

    template<typename _T>
    friend Matrix<_T> operator *( Matrix<_T>& m1,double num);

    template<typename _T>
    friend std::ostream& operator <<(std::ostream&os, Matrix<_T>& matr);

    Iterator iterator_begin();
    Iterator iterator_end();
};

template<typename T>
Matrix<T>::Matrix(unsigned int height, unsigned int width){ //создаем пустую матрицу по размерам
    try {
        this->height = height;
        this->width = width;
        this->matr = new T*[this->height];
        for (int h = 0; h < this->height; h++){
            this->matr[h] = new T[this->width];
            for (int w = 0; w < this->width; w++){
                this->matr[h][w] = 0;
            }
        }
    }catch(bad_alloc) {
        this->height = 0;
        this->width = 0;
        this->matr = nullptr;
        throw exceptions("bad allocation");
    }
}


template<typename T>
Matrix<T>::Matrix( Matrix<T>& matr){ // Конструктор копированиия
    try{
        this->height = matr.get_row();
        this->width = matr.get_columns();
        this->matr = new T*[this->height];
        for (int h = 0; h < this->height; h++){
            this->matr[h] = new T[this->width];
            for (int w = 0; w < this->width; w++){
                this->matr[h][w] = matr.getElem(h, w);
            }
        }
    }catch(bad_alloc) {
        this->height = 0;
        this->width = 0;
        this->matr = nullptr;
        throw exceptions("bad allocation");
    }
}


template<typename T>
Matrix<T>::Matrix(Matrix<T>&& matr){ // Конструктор перемещения
    try{
        this->height = matr.get_row();
        this->width = matr.get_columns();
        this->matr = new T*[this->height];
        for (int h = 0; h < this->height; h++){
            this->matr[h] = new T[this->width];
            for (int w = 0; w < this->width; w++){
                this->matr[h][w] = matr.getElem(h, w);
                T elem = 0;
                matr.setElem(h, w, elem);
            }
        }
    }catch(bad_alloc) {
        this->height = 0;
        this->width = 0;
        this->matr = nullptr;
        throw exceptions("bad allocation");
    }
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst){ //lst - список инициализаций (значений, которые будем закидывать в матрицу)
    try{
        this->height = lst.size();
        this->matr = new T*[this->height];
        int h = 0, w = 0;
        for (std::initializer_list<T> mas:lst){
            w = 0;
            this->width = mas.size();
            this->matr[h]= new T[this->width];
            for (T elem: mas){
                this->matr[h][w] = elem;
                w++;
            }
            h++;
        }
    }catch(bad_alloc) {
        this->height = 0;
        this->width = 0;
        this->matr = nullptr;
        throw exceptions("bad allocation");
    }
}

template<typename T>
Matrix<T>::~Matrix(){
    if (matr!=nullptr){
        for (int i =0; i < (this->height); i++){
            delete this->matr[i];
        }
        delete this->matr;
    }
}


template<typename T>
Matrix<T>& Matrix<T>::operator=( Matrix<T>& matr){ // Оператор присваивания для матриц
    if (height != matr.get_row() || width != matr.get_columns())
        throw exceptions ("Different size of matrix");
    for(int h = 0; h < this->height; h++){
        for(int w = 0; w < this->width; w++){
            this->matr[h][w] = matr.getElem(h, w);
        }
    }
//    Matrix<T>::~Matrix();
//    Matrix<T> ma(matr);
//    *this = ma;
    return *this;
}


template<typename T>
Matrix<T>& Matrix<T>::operator+=( Matrix<T>& matr){ // Оператор += для матриц
    if (height != matr.get_row() || width != matr.get_columns())
        throw exceptions ("Different size of matrix");
    for(int h = 0; h < this->height; h++){
        for(int w = 0; w < this->width; w++){
            this->matr[h][w] += matr.getElem(h, w);
        }
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=( Matrix<T>& matr){ // Оператор -= для матриц
    if (height != matr.get_row() || width != matr.get_columns())
        throw exceptions ("Different size of matrix");
    for(int h = 0; h < this->height; h++){
        for(int w = 0; w < this->width; w++){
            this->matr[h][w] -= matr.getElem(h, w);
        }
    }
    return *this;
}


template<typename T>
void Matrix<T>::setElem(unsigned int height, unsigned int width, T&elem){
    getElem(height,width) = elem;
}


template<typename T>
T& Matrix<T>::getElem(unsigned int height, unsigned int width){
    if (height < 0 || height >= get_row() || width < 0 || width >= get_columns())
        throw exceptions ("Incorrect index");
    return this->matr[height][width];
}


template<typename T>
T& Matrix<T>::operator()(unsigned int height, unsigned int width){
    if (height < 0 || height >= get_row() || width < 0 || width >= get_columns())
        throw exceptions ("Incorrect index");
    return getElem(height,width);
}


template<typename T>
bool Matrix<T>::is_square(){
    if (this->height == this->width){
        return true;
    }
    else{
        return false;
    }
}


template<typename T>
unsigned int Matrix<T>::get_columns() const{
    return this->width;
}


template<typename T>
unsigned int Matrix<T>::get_row() const{
    return this->height;
}


template<typename _T>
Matrix<_T> operator+( Matrix<_T>& m1,Matrix<_T>& m2){
    if ( m1.get_row()!= m2.get_row() || m2.get_columns() != m2.get_columns())
        throw exceptions ("Different size of matrix");
    Matrix<_T> newMatr(m1);
    newMatr += m2;
    return newMatr;
}


template<typename _T>
Matrix<_T> operator-( Matrix<_T>& m1,Matrix<_T>& m2){
    if ( m1.get_row()!= m2.get_row() || m1.get_columns() != m2.get_columns())
        throw exceptions ("Different size of matrix");
    Matrix<_T> newMatr(m1);
    newMatr -= m2;
    return newMatr;
}


template<typename _T>
Matrix<_T> operator*( Matrix<_T>& m1,Matrix<_T>& m2){
    if ( m1.get_columns()!= m2.get_row())
        throw exceptions ("Unsuitable matrix sizes for multiplication");
    Matrix<_T> newMatr(m2.get_columns(), m1.get_row());
    for(int i =0; i < m1.get_row(); i++){
        for(int j =0; j < m2.get_columns(); j++){
            _T elem = 0;
            for (int k=0; k< m1.get_columns();k++){
                elem += m1.getElem(i,k)*m2.getElem(k,j);
            }
            newMatr.setElem(i,j, elem);
        }
    }
    return newMatr;
}


template<typename _T>
Matrix<_T> operator+( Matrix<_T>& m1,double num){
    Matrix<_T> newMatr(m1);
    for(int h = 0; h < m1.get_row(); h++){
        for(int w =0; w < m1.get_columns(); w++){
            _T elem = m1.getElem(h, w) + num;
            newMatr.setElem(h, w, elem);
        }
    }
    return newMatr;
}


template<typename _T>
Matrix<_T> operator-( Matrix<_T>& m1,double num){
    Matrix<_T> newMatr(m1);
    for(int h = 0; h < m1.get_row(); h++){
        for(int w =0; w < m1.get_columns(); w++){
            _T elem = m1.getElem(h, w) - num;
            newMatr.setElem(h, w, elem);
        }
    }
    return newMatr;
}

template<typename _T>
Matrix<_T> operator/( Matrix<_T>& m1,double num){
    if (num==0)
        throw exceptions ("It is forbidden to divide by 0");
    Matrix<_T> newMatr(m1);
    for(int h = 0; h < m1.get_row(); h++){
        for(int w =0; w < m1.get_columns(); w++){
            _T elem = m1.getElem(h, w) / num;
            newMatr.setElem(h, w, elem);
        }
    }
    return newMatr;
}

template<typename _T>
Matrix<_T> operator*( Matrix<_T>& m1, double num){
    Matrix<_T> newMatr(m1);
    for(int h = 0; h < m1.get_row(); h++){
        for(int w =0; w < m1.get_columns(); w++){
            _T elem = m1.getElem(h, w) * num;
            newMatr.setElem(h, w, elem);
        }
    }
    return newMatr;
}

template<typename _T>
std::ostream& operator<<(std::ostream&os, Matrix<_T>& matr){
    for(int h = 0; h < matr.get_row(); h++){
        for (int w = 0; w < matr.get_columns(); w++){
            os<< matr.getElem(h, w) << " ";
        }
        os << std::endl;
    }
    return os;
}

template<typename Type>
typename Matrix<Type>::Iterator Matrix<Type>::iterator_begin()
{
    return Matrix<Type>::Iterator(*this, 0, 0);
}

template<typename Type>
typename Matrix<Type>::Iterator Matrix<Type>::iterator_end()
{
    return Matrix<Type>::Iterator(*this, get_row(), 0);
}

template <typename Type>
bool Matrix<Type>::Iterator::operator!=(Iterator &b)
{
    return ((it_matrix_row != b.it_matrix_row) || (it_matrix_col != b.it_matrix_col));
}

template <typename Type>
bool Matrix<Type>::Iterator::operator==(Iterator &b)
{
    return ((it_matrix_row == b.it_matrix_row) && (it_matrix_col == b.it_matrix_col));
}

template <typename Type>
Type &Matrix<Type>::Iterator::operator*()
{
    return matr(it_matrix_row,it_matrix_col);
}

template <typename Type>
typename Matrix<Type>::Iterator &Matrix<Type>::Iterator::operator++()
{
    if (!(this->is_end())){
        if (it_matrix_col == matr.get_columns()-1) {
            it_matrix_row++;
            it_matrix_col = 0;
        } else
            it_matrix_col++;
    }
    return *this;
}

template <typename Type>
typename Matrix<Type>::Iterator Matrix<Type>::Iterator::next()
{
    if (!(this->is_end())){
        if ((it_matrix_col == matr.get_columns()-1)) {
            it_matrix_row++;
            it_matrix_col = 0;
        } else
            it_matrix_col++;
    }
    return *this;
}

template <typename Type>
Type Matrix<Type>::Iterator::value()
{
    return **this;
}

template <typename Type>
Matrix<Type>::Iterator::Iterator(Matrix <Type> &container_obj, size_t rows, size_t cols):matr(container_obj), it_matrix_row(rows), it_matrix_col(cols)
{
    if (rows == -1 || cols == -1) {
        it_matrix_row = matr.get_row();
        it_matrix_col = matr.get_columns();
    }
}

template <typename Type>
bool Matrix<Type>::Iterator::is_end()
{
    bool result = false;
    if (it_matrix_row == matr.get_row() && it_matrix_col == 0)
        result = true;
    return result;
}

template <typename Type>
bool Matrix<Type>::Iterator::is_begin()
{
    bool result = false;
    if (it_matrix_row == 0 && it_matrix_col == 0)
        result = true;
    return result;
}


#endif // MATRIX_H

