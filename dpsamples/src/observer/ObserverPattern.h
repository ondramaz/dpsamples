#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include <string>

#include "../Pattern.h"


class ObserverPattern : public Pattern
{
    public:
        ObserverPattern();
        virtual ~ObserverPattern();
        virtual void run();
        virtual std::string name() const { return "Observer pattern"; }

    protected:

    private:
};

#endif // OBSERVERPATTERN_H
