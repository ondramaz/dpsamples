#ifndef PROTOTYPEPATTERN_H
#define PROTOTYPEPATTERN_H

#include <string>

#include "../Pattern.h"

using namespace std;

class PrototypePattern : public Pattern
{
    public:
        PrototypePattern();
        virtual ~PrototypePattern();
        virtual void run();
        virtual string name() const { return "Prototype pattern"; }
    protected:

    private:
};

#endif // PROTOTYPEPATTERN_H
