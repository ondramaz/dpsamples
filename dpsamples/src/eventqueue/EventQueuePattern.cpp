#include "EventQueuePattern.h"
#include <assert.h>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <chrono>

EventQueuePattern::EventQueuePattern()
{
    //ctor
}

EventQueuePattern::~EventQueuePattern()
{
    //dtor
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
  std::cout << "Compute: head: " << head_ << ", tail: " << tail_ << std::endl;

  assert((tail_ + 1) % MAX_PENDING != head_);

  // Add to the end of the list.
  pending_[tail_] = computingData;
  tail_ = (tail_ + 1) % MAX_PENDING;
}


void ComputingEngine::update()
{
  std::cout << "Update: head: " << head_ << ", tail: " << tail_ << std::endl;

  // If there are no pending requests, do nothing.
  if (head_ == tail_) return;

  ComputingData data = pending_[head_];

  // do something with data
  std::cout << "Data:" << data.i << std::endl;

  head_ = (head_ + 1) % MAX_PENDING;
}

void thread_function()
{
    while (true) {
        ComputingEngine::update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void EventQueuePattern::run()
{
    std::thread t(&thread_function);   // t starts running
    std::cout << "main thread\n";

     ComputingEngine::init();

    for (int i=0;i<1000;i++) {
         std::this_thread::sleep_for(std::chrono::milliseconds(15));
        ComputingData data;
        data.i = i;
        ComputingEngine::compute(data);
    }
    t.join();   // main thread waits for the thread t to finish

}
