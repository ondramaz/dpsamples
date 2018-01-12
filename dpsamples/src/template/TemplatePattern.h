#ifndef TEMPLATEPATTERN_H
#define TEMPLATEPATTERN_H

#include <string>

#include "../Pattern.h"


class TemplatePattern : public Pattern
{
    public:
        TemplatePattern();
        virtual ~TemplatePattern();
        void run();
        virtual std::string name() const { return "Template pattern"; }

    protected:

    private:
};

#endif // TEMPLATEPATTERN_H
