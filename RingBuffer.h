//
//

#ifndef SECOND_TASK_RINGBUFFER_H
#define SECOND_TASK_RINGBUFFER_H

#include "RingBufferException.h"

///class RingBuffer
template<typename T>
class RingBuffer {

private:

    //friend class Iterator;
    T *array;
    size_t startIndex;
    size_t arraySize;
    size_t arrayMaxSize;//+1buff elem

public:

    RingBuffer(size_t);

    void push(const T &element);

    T &pop();

    T &front() const;

    size_t size() const;

    void clear();

    bool isEmpty();

    ~RingBuffer();

    class Iterator {

    private:

        friend class RingBuffer;

        T *current;
        RingBuffer<T> *buffer;

    public:

        Iterator(RingBuffer<T> &buff) : buffer(&buff), current(nullptr) {};

        void start() { current = &buffer->array[buffer->startIndex]; };

        void next() {
            if (current + 1 == buffer->array + buffer->arrayMaxSize) current = buffer->array;
            else current++;

        };

        bool finish() {
            size_t index = (buffer->startIndex + buffer->arraySize) % buffer->arrayMaxSize;
            return current == &buffer->array[index];
        };

        T &getValue() const { return *current; };

        ~Iterator() { current = nullptr; }

    };

};

template<typename T>
RingBuffer<T>::RingBuffer(size_t n) :startIndex(0), arraySize(0), arrayMaxSize(n + 1) {
    array = new T[arrayMaxSize + 1];
}


template<typename T>
void RingBuffer<T>::push(const T &element) {

    if (arraySize + 1 == arrayMaxSize) throw RingBufferException("Buffer is overflow");

    array[(startIndex + arraySize) % arrayMaxSize] = element;
    arraySize++;


}

template<typename T>
T &RingBuffer<T>::pop() {

    if (arraySize == 0) throw RingBufferException("Buffer is empty");

    arraySize--;
    startIndex = (startIndex + 1) % arrayMaxSize;
    return array[startIndex];

}

template<typename T>
T &RingBuffer<T>::front() const {

    if (arraySize == 0) throw RingBufferException("Buffer is empty");
    return array[startIndex];

}

template<typename T>
size_t RingBuffer<T>::size() const {
    return this->arraySize;
}

template<typename T>
void RingBuffer<T>::clear() {
    delete[] array;
    array = nullptr;
}

template<typename T>
bool RingBuffer<T>::isEmpty() {
    return (arraySize == 0);
}

template<typename T>
RingBuffer<T>::~RingBuffer() {
    this->clear();
}


#endif //SECOND_TASK_RINGBUFFER_H
