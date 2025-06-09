#include <iostream>
#include <cmath>

const double PI = acos(-1.0);

class Point {
public:
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual ~Point() {}
};

class BasicPoint : public Point {
private:
    double x, y;
public:
    BasicPoint(double x, double y) : x(x), y(y) {}

    double getX() const override { return x; }
    double getY() const override { return y; }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }

    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
};

class Shape {
public:
    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;
    virtual ~Shape() {}
};

class Line : public Shape {
private:
    BasicPoint start, end;
public:
    Line(double x1, double y1, double x2, double y2)
        : start(x1, y1), end(x2, y2) {}

    void draw() const override {
        std::cout << "Рисуется линия от точки (" << start.getX() << ", " << start.getY()
                  << ") до точки (" << end.getX() << ", " << end.getY() << ")" << std::endl;
    }

    void erase() const override {
        std::cout << "Стирается линия" << std::endl;
    }

    void move(double dx, double dy) override {
        start.move(dx, dy);
        end.move(dx, dy);
    }

    void rotate(double angle) override {
        double radians = angle * PI / 180.0;
        double dx = end.getX() - start.getX();
        double dy = end.getY() - start.getY();
        double newX = dx * cos(radians) - dy * sin(radians);
        double newY = dx * sin(radians) + dy * cos(radians);
        end.setX(start.getX() + newX);
        end.setY(start.getY() + newY);
    }
};

class Rectangle : public Shape {
protected:
    BasicPoint topLeft;
    double width, height;
public:
    Rectangle(double x, double y, double w, double h)
        : topLeft(x, y), width(w), height(h) {}

    void draw() const override {
        std::cout << "Рисуется прямоугольник с левой верхней точкой в (" << topLeft.getX() << ", " << topLeft.getY()
                  << "), ширина: " << width << ", высота: " << height << std::endl;
    }

    void erase() const override {
        std::cout << "Стирается прямоугольник" << std::endl;
    }

    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
    }

     void rotate(double angle) override {
        double radians = angle * PI / 180.0;


        double x1 = topLeft.getX();
        double y1 = topLeft.getY();
        double x2 = x1 + width;
        double y2 = y1;
        double x3 = x1 + width;
        double y3 = y1 + height;
        double x4 = x1;
        double y4 = y1 + height;


  
        double centerX = x1 + width / 2.0;
        double centerY = y1 + height / 2.0;



        double newX1 = centerX + (x1 - centerX) * cos(radians) - (y1 - centerY) * sin(radians);
        double newY1 = centerY + (x1 - centerX) * sin(radians) + (y1 - centerY) * cos(radians);

        double newX2 = centerX + (x2 - centerX) * cos(radians) - (y2 - centerY) * sin(radians);
        double newY2 = centerY + (x2 - centerX) * sin(radians) + (y2 - centerY) * cos(radians);

        double newX3 = centerX + (x3 - centerX) * cos(radians) - (y3 - centerY) * sin(radians);
        double newY3 = centerY + (x3 - centerX) * sin(radians) + (y3 - centerY) * cos(radians);

        double newX4 = centerX + (x4 - centerX) * cos(radians) - (y4 - centerY) * sin(radians);
        double newY4 = centerY + (x4 - centerX) * sin(radians) + (y4 - centerY) * cos(radians);
        
  
        std::cout << "Координаты после поворота:" << std::endl;
        std::cout << "Верхняя левая: (" << newX1 << ", " << newY1 << ")" << std::endl;
        std::cout << "Верхняя правая: (" << newX2 << ", " << newY2 << ")" << std::endl;
        std::cout << "Нижняя правая: (" << newX3 << ", " << newY3 << ")" << std::endl;
        std::cout << "Нижняя левая: (" << newX4 << ", " << newY4 << ")" << std::endl;
topLeft.setX(newX1);
        topLeft.setY(newY1);
    }
};

class Square : public Rectangle {
public:
    Square(double x, double y, double side)
        : Rectangle(x, y, side, side) {}

    void draw() const override {
        std::cout << "Рисуется квадрат с левой верхней точкой в (" << topLeft.getX() << ", " << topLeft.getY()
                  << "), сторона: " << width << std::endl;
    }

    void erase() const override {
        std::cout << "Стирается квадрат" << std::endl;
    }

    void rotate(double angle) override {
        double radians = angle * PI / 180.0;

     
        double x1 = topLeft.getX();
        double y1 = topLeft.getY();
        double x2 = x1 + width;
        double y2 = y1;
        double x3 = x1 + width;
        double y3 = y1 + height;
        double x4 = x1;
        double y4 = y1 + height;


    
        double centerX = x1 + width / 2.0;
        double centerY = y1 + height / 2.0;


    
        double newX1 = centerX + (x1 - centerX) * cos(radians) - (y1 - centerY) * sin(radians);
        double newY1 = centerY + (x1 - centerX) * sin(radians) + (y1 - centerY) * cos(radians);

        double newX2 = centerX + (x2 - centerX) * cos(radians) - (y2 - centerY) * sin(radians);
        double newY2 = centerY + (x2 - centerX) * sin(radians) + (y2 - centerY) * cos(radians);

        double newX3 = centerX + (x3 - centerX) * cos(radians) - (y3 - centerY) * sin(radians);
        double newY3 = centerY + (x3 - centerX) * sin(radians) + (y3 - centerY) * cos(radians);

        double newX4 = centerX + (x4 - centerX) * cos(radians) - (y4 - centerY) * sin(radians);
        double newY4 = centerY + (x4 - centerX) * sin(radians) + (y4 - centerY) * cos(radians);

        std::cout << "Координаты после поворота:" << std::endl;
        std::cout << "Верхняя левая: (" << newX1 << ", " << newY1 << ")" << std::endl;
        std::cout << "Верхняя правая: (" << newX2 << ", " << newY2 << ")" << std::endl;
        std::cout << "Нижняя правая: (" << newX3 << ", " << newY3 << ")" << std::endl;
        std::cout << "Нижняя левая: (" << newX4 << ", " << newY4 << ")" << std::endl;

        topLeft.setX(newX1);
        topLeft.setY(newY1);
    }
};

class Parallelogram : public Shape {
protected:
    BasicPoint topLeft;
    double base, height, offset;
public:
    Parallelogram(double x, double y, double b, double h, double o)
        : topLeft(x, y), base(b), height(h), offset(o) {}

    void draw() const override {
        std::cout << "Рисуется параллелограмм с левой верхней точкой в (" << topLeft.getX() << ", " << topLeft.getY()
                  << "), основание: " << base << ", высота: " << height
                  << ", смещение: " << offset << std::endl;
    }

    void erase() const override {
        std::cout << "Стирается параллелограмм" << std::endl;
    }

    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
    }

  void rotate(double angle) override {
        double radians = angle * PI / 180.0;

     
        double x1 = topLeft.getX();
        double y1 = topLeft.getY();
        double x2 = x1 + base;
        double y2 = y1;
        double x3 = x1 + offset;
        double y3 = y1 + height;
        double x4 = x2 + offset;
        double y4 = y2 + height;


  
        double centerX = x1 + base / 2.0;
        double centerY = y1 + height / 2.0;



        double newX1 = centerX + (x1 - centerX) * cos(radians) - (y1 - centerY) * sin(radians);
        double newY1 = centerY + (x1 - centerX) * sin(radians) + (y1 - centerY) * cos(radians);

        double newX2 = centerX + (x2 - centerX) * cos(radians) - (y2 - centerY) * sin(radians);
        double newY2 = centerY + (x2 - centerX) * sin(radians) + (y2 - centerY) * cos(radians);

        double newX3 = centerX + (x3 - centerX) * cos(radians) - (y3 - centerY) * sin(radians);
        double newY3 = centerY + (x3 - centerX) * sin(radians) + (y3 - centerY) * cos(radians);
double newX4 = centerX + (x4 - centerX) * cos(radians) - (y4 - centerY) * sin(radians);
        double newY4 = centerY + (x4 - centerX) * sin(radians) + (y4 - centerY) * cos(radians);

  
        std::cout << "Координаты после поворота:" << std::endl;
        std::cout << "Верхняя левая: (" << newX1 << ", " << newY1 << ")" << std::endl;
        std::cout << "Верхняя правая: (" << newX2 << ", " << newY2 << ")" << std::endl;
        std::cout << "Нижняя левая: (" << newX3 << ", " << newY3 << ")" << std::endl;
        std::cout << "Нижняя правая: (" << newX4 << ", " << newY4 << ")" << std::endl;

        topLeft.setX(newX1);
        topLeft.setY(newY1);
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double x, double y, double d1, double d2)
        : Parallelogram(x, y, d1, d2, 0) {}

    void draw() const override {
        std::cout << "Рисуется ромб с левой верхней точкой в (" << topLeft.getX() << ", " << topLeft.getY()
                  << "), диагонали: " << base << " и " << height << std::endl;
    }

    void erase() const override {
        std::cout << "Стирается ромб" << std::endl;
    }
     void rotate(double angle) override {
        double radians = angle * PI / 180.0;

   
        double x1 = topLeft.getX();
        double y1 = topLeft.getY();
        double x2 = x1 + base;
        double y2 = y1;
        double x3 = x1 + offset;
        double y3 = y1 + height;
        double x4 = x2 + offset;
        double y4 = y2 + height;


     
        double centerX = x1 + base / 2.0;
        double centerY = y1 + height / 2.0;


   
        double newX1 = centerX + (x1 - centerX) * cos(radians) - (y1 - centerY) * sin(radians);
        double newY1 = centerY + (x1 - centerX) * sin(radians) + (y1 - centerY) * cos(radians);

        double newX2 = centerX + (x2 - centerX) * cos(radians) - (y2 - centerY) * sin(radians);
        double newY2 = centerY + (x2 - centerX) * sin(radians) + (y2 - centerY) * cos(radians);

        double newX3 = centerX + (x3 - centerX) * cos(radians) - (y3 - centerY) * sin(radians);
        double newY3 = centerY + (x3 - centerX) * sin(radians) + (y3 - centerY) * cos(radians);

        double newX4 = centerX + (x4 - centerX) * cos(radians) - (y4 - centerY) * sin(radians);
        double newY4 = centerY + (x4 - centerX) * sin(radians) + (y4 - centerY) * cos(radians);


        std::cout << "Координаты после поворота:" << std::endl;
        std::cout << "Верхняя левая: (" << newX1 << ", " << newY1 << ")" << std::endl;
        std::cout << "Верхняя правая: (" << newX2 << ", " << newY2 << ")" << std::endl;
        std::cout << "Нижняя левая: (" << newX3 << ", " << newY3 << ")" << std::endl;
        std::cout << "Нижняя правая: (" << newX4 << ", " << newY4 << ")" << std::endl;

        topLeft.setX(newX1);
        topLeft.setY(newY1);
    }
};

void demo(Shape* shape) {
    shape->draw();
    shape->move(5, 5);
    shape->rotate(45);
    shape->draw();
    shape->erase();
}

int main() {
    Square sq(0, 0, 10);
    Line ln(0, 0, 5, 5);
    Rectangle rect(1, 1, 8, 4);
    Parallelogram pg(2, 2, 6, 4, 3);
    Rhombus rh(3, 3, 5, 7);

    std::cout << "Демонстрация: Квадрат" << std::endl;
    demo(&sq);

    std::cout << "\nДемонстрация: Линия" << std::endl;
    demo(&ln);

    std::cout << "\nДемонстрация: Прямоугольник" << std::endl;
    demo(&rect);

    std::cout << "\nДемонстрация: Параллелограмм" << std::endl;
    demo(&pg);

    std::cout << "\nДемонстрация: Ромб" << std::endl;
    demo(&rh);

    return 0;
}