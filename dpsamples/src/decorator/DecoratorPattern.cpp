#include "DecoratorPattern.h"
#include <iostream>

DecoratorPattern::DecoratorPattern()
{
    //ctor
}

DecoratorPattern::~DecoratorPattern()
{
    //dtor
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
    std::cout << "Rectange" << std::endl;
}

class Circle : public Shape
{
    public:
    virtual void draw();
};

void Circle::draw()
{
    std::cout << "Circle" << std::endl;
}


class ColoredShape : public Shape {

    Shape &shape;
    std::string color;

public:
    ColoredShape(Shape &shape, std::string color) : shape(shape), color(color) {}

    virtual void draw();

};

void ColoredShape::draw()
{
    std::cout << color << " ";
    shape.draw();
}



void DecoratorPattern::run()
{
    std:: cout << "Normal shape:";
	Rectangle r;
    r.draw();

    std:: cout << "Decorated shape:";
    ColoredShape shape1(r,"Red");
    shape1.draw();
}
