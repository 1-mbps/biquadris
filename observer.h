#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Observer {
 public:
  // c is the Cell that called the notify method so we can get its state
  virtual void notify() = 0;
  virtual ~Observer() = default;
};
#endif
