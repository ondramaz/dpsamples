#ifndef COMMANDPATTERN_H
#define COMMANDPATTERN_H

#include "../Pattern.h"

class CommandPattern : public Pattern
{
    public:
        CommandPattern();
        virtual ~CommandPattern();
        virtual void run();
        virtual std::string name() const { return "Command pattern"; }
    protected:

    private:
};

#endif // COMMANDPATTERN_H
