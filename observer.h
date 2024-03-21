#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include <map>
#include <vector>

class Observer {
  public:
    virtual void notify(std::vector<std::pair<int,int>> &old_coords, std::vector<std::pair<int,int>> &new_coords, char c) = 0;
    virtual ~Observer() = default;
};
#endif
