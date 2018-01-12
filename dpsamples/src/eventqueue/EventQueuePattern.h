#ifndef EVENTQUEUEPATTERN_H
#define EVENTQUEUEPATTERN_H

#include "../Pattern.h"


class EventQueuePattern : public Pattern
{
    public:
        EventQueuePattern();
        virtual ~EventQueuePattern();
        virtual void run();
        virtual std::string name() const { return "Event queue pattern"; }

    protected:

    private:
};

#endif // EVENTQUEUEPATTERN_H
