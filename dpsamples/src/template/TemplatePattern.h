#ifndef TEMPLATEPATTERN_H
#define TEMPLATEPATTERN_H

#include <string>

#include "../Pattern.h"

using namespace std;

class TemplatePattern : public Pattern
{
    public:
        TemplatePattern();
        virtual ~TemplatePattern();
        void run();
        virtual string name() const { return "Template pattern"; }

    protected:

    private:
};

#endif // TEMPLATEPATTERN_H
