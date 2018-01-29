#include "EventQueuePattern.h"
#include <assert.h>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <chrono>

EventQueuePattern::EventQueuePattern()
{
}

EventQueuePattern::~EventQueuePattern()
{
}

struct ComputingData
{
    int i;
};

class ComputingEngine
{

  public:
  static void init()
  {
    head_ = 0;
    tail_ = 0;
  }

  static void compute(const ComputingData &computingData);
  static void update();


  // Other stuff...
private:
  static const int MAX_PENDING = 16;

  static ComputingData pending_[MAX_PENDING];

  static int head_;
  static int tail_;
};

int ComputingEngine::head_;
int ComputingEngine::tail_;
ComputingData ComputingEngine::pending_[MAX_PENDING];

void ComputingEngine::compute(const ComputingData &computingData)
{
  cout << "Compute: head: " << head_ << ", tail: " << tail_ << endl;

  assert((tail_ + 1) % MAX_PENDING != head_);

  // Add to the end of the list.
  pending_[tail_] = computingData;
  tail_ = (tail_ + 1) % MAX_PENDING;
}


void ComputingEngine::update()
{
  cout << "Update: head: " << head_ << ", tail: " << tail_ << endl;

  // If there are no pending requests, do nothing.
  if (head_ == tail_) return;

  ComputingData data = pending_[head_];

  // do something with data
  cout << "Data:" << data.i << endl;

  head_ = (head_ + 1) % MAX_PENDING;
}

void thread_function()
{
    while (true) {
        ComputingEngine::update();
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void EventQueuePattern::run()
{
    thread t(&thread_function);   // t starts running
    cout << "main thread\n";

     ComputingEngine::init();

    for (int i=0;i<1000;i++) {
         this_thread::sleep_for(chrono::milliseconds(15));
        ComputingData data;
        data.i = i;
        ComputingEngine::compute(data);
    }
    t.join();   // main thread waits for the thread t to finish

}
