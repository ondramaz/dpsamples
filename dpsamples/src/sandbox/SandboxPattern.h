#ifndef SANDBOXPATTERN_H
#define SANDBOXPATTERN_H

#include "../Pattern.h"


class SandboxPattern : public Pattern
{
    public:
        SandboxPattern();
        virtual ~SandboxPattern();
        virtual void run();
        virtual std::string name() const { return "Sandbox pattern"; }

    protected:

    private:
};

#endif // SANDBOXPATTERN_H
