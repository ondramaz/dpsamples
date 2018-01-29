#ifndef SANDBOXPATTERN_H
#define SANDBOXPATTERN_H

#include "../Pattern.h"

using namespace std;

class SandboxPattern : public Pattern
{
    public:
        SandboxPattern();
        virtual ~SandboxPattern();
        virtual void run();
        virtual string name() const { return "Sandbox pattern"; }

    protected:

    private:
};

#endif // SANDBOXPATTERN_H
