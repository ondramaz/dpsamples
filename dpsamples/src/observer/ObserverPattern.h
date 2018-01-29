#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include <string>

#include "../Pattern.h"

using namespace std;

class ObserverPattern : public Pattern
{
    public:
        ObserverPattern();
        virtual ~ObserverPattern();
        virtual void run();
        virtual string name() const { return "Observer pattern"; }

    protected:

    private:
};

#endif // OBSERVERPATTERN_H
