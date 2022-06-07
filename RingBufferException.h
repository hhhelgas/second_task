//
// Created by basya on 05.06.2022.
//

#ifndef SECOND_TASK_RINGBUFFEREXCEPT_H
#define SECOND_TASK_RINGBUFFEREXCEPT_H

#include <stdexcept>

class RingBufferException : public std::exception {
    const char *message;
public:
    RingBufferException(const char *msg) : message(msg) {};

    const char *what() const noexcept { return message; };
};

#endif SECOND_TASK_RINGBUFFEREXCEPT_H
