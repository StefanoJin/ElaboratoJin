//
// Created by Admin on 2025/2/9.
//

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

#endif //OBSERVER_H
