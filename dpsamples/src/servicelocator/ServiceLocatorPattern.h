#ifndef SERVICELOCATORPATTERN_H
#define SERVICELOCATORPATTERN_H

#include <string>

#include "../Pattern.h"


class ServiceLocatorPattern : public Pattern
{
    public:
        ServiceLocatorPattern();
        virtual ~ServiceLocatorPattern();
        virtual void run();
        virtual std::string name() const { return "Service locator pattern"; }

    protected:

    private:
};

#endif // SERVICELOCATORPATTERN_H
