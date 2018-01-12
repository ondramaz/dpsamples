#ifndef DECORATORPATTERN_H
#define DECORATORPATTERN_H

#include <string>

#include "../Pattern.h"


class DecoratorPattern : public Pattern
{
    public:
        DecoratorPattern();
        virtual ~DecoratorPattern();
        virtual void run();
        virtual std::string name() const { return "Decorator pattern"; }

    protected:

    private:
};

#endif // DECORATORPATTERN_H
