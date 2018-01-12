#ifndef PROXYPATTERN_H
#define PROXYPATTERN_H

#include <string>

#include "../Pattern.h"


class ProxyPattern : public Pattern
{
    public:
        ProxyPattern();
        virtual ~ProxyPattern();
        virtual void run();
        virtual std::string name() const { return "Proxy pattern"; }

    protected:

    private:
};

#endif // PROXYPATTERN_H
