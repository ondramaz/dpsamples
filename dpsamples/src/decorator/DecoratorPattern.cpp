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
    std::cout << color << " shape:";
    shape.draw();
}



void DecoratorPattern::run()
{
    Rectangle r;
    r.draw();
    ColoredShape shape1(r,"red");
    shape1.draw();
}
