#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class vect {
private:
    int dim;
    double* b;
    int num;
    static int count;

public:
    vect(int dim) : dim(dim), num(++count) {
        b = new double[dim]();
        cout << "Создан вектор " << num << endl;
    }
    
    vect(vect& v) : dim(v.dim), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; i++) b[i] = v.b[i];
        cout << "Скопирован вектор " << num << endl;
    }
    
    ~vect() {
        delete[] b;
        cout << "Удален вектор " << num << endl;
    }
    
    vect operator+(vect& v);
    vect operator-(vect& v);
    vect operator-();
    double operator*(vect& v);
    vect operator*(double k);
    vect& operator=(vect& v);

    void setValues();
    void display();
};

int vect::count = 0;

vect vect::operator+(vect& v) {
    vect res(dim);
    for (int i = 0; i < dim; i++)
        res.b[i] = b[i] + v.b[i];
    return res;
}

vect vect::operator-(vect& v) {
    vect res(dim);
    for (int i = 0; i < dim; i++)
        res.b[i] = b[i] - v.b[i];
    return res;
}

vect vect::operator-() {
    vect res(dim);
    for (int i = 0; i < dim; i++)
        res.b[i] = -b[i];
    return res;
}

double vect::operator*(vect& v) {
    double sum = 0;
    for (int i = 0; i < dim; i++)
        sum += b[i] * v.b[i];
    return sum;
}

vect vect::operator*(double k) {
    vect res(dim);
    for (int i = 0; i < dim; i++)
        res.b[i] = b[i] * k;
    return res;
}

vect& vect::operator=(vect& v) {
    if (this != &v) {
        delete[] b;
        dim = v.dim;
        b = new double[dim];
        for (int i = 0; i < dim; i++)
            b[i] = v.b[i];
    }
    return *this;
}

void vect::setValues() {
    cout << "Введите " << dim << " элементов: ";
    for (int i = 0; i < dim; i++)
        cin >> b[i];
}

void vect::display() {
    cout << "Вектор: ";
    for (int i = 0; i < dim; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main() {
    vect v1(3), v2(3);
    v1.setValues();
    v2.setValues();
    
    vect v3 = v1 + v2;
    vect v4 = v1 - v2;
    vect v5 = -v1;
    double dot = v1 * v2;
    vect v6 = v1 * 2.0;
    
    v3.display();
    v4.display();
    v5.display();
    cout << "Скалярное произведение: " << dot << endl;
    v6.display();
    
    return 0;
}
