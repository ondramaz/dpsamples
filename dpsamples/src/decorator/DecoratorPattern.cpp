#include "DecoratorPattern.h"
#include <iostream>

DecoratorPattern::DecoratorPattern()
{
}

DecoratorPattern::~DecoratorPattern()
{
}

class Shape
{
    public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
    public:
    virtual void draw();
};

void Rectangle::draw()
{
    cout << "Rectange" << endl;
}

class Circle : public Shape
{
    public:
    virtual void draw();
};

void Circle::draw()
{
    cout << "Circle" << endl;
}


class ColoredShape : public Shape {

    Shape &shape;
    string color;

public:
    ColoredShape(Shape &shape, string color) : shape(shape), color(color) {}

    virtual void draw();
};

void ColoredShape::draw()
{
    cout << color << " ";
    shape.draw();
}

void DecoratorPattern::run()
{
     cout << "Normal shape:";
	Rectangle r;
    r.draw();

     cout << "Decorated shape:";
    ColoredShape shape1(r,"Red");
    shape1.draw();
}
