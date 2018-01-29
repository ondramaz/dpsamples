#ifndef EVENTQUEUEPATTERN_H
#define EVENTQUEUEPATTERN_H

#include "../Pattern.h"

using namespace std;

class EventQueuePattern : public Pattern
{
    public:
        EventQueuePattern();
        virtual ~EventQueuePattern();
        virtual void run();
        virtual string name() const { return "Event queue pattern"; }

    protected:

    private:
};

#endif // EVENTQUEUEPATTERN_H
