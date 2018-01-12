#ifndef PROTOTYPEPATTERN_H
#define PROTOTYPEPATTERN_H

#include <string>

#include "../Pattern.h"


class PrototypePattern : public Pattern
{
    public:
        PrototypePattern();
        virtual ~PrototypePattern();
        virtual void run();
        virtual std::string name() const { return "Prototype pattern"; }
    protected:

    private:
};

#endif // PROTOTYPEPATTERN_H
