/*
 * RingBuffer.h
 *
 *  Created on: May 19, 2014
 *      Author: sni
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <memory>
#include <typeinfo>
#include <mutex>

using namespace std;

namespace msl
{

//* RingBuffer
/**
 * Ring buffer of shared_ptr of a given data type. Not thread save!
 *
 */
template<typename T>
  class RingBuffer
  {
  public:
  /*!
   * \brief Default constructor.
   *
   * Default constructor.
   *
   * \param bufferSize Number of elements which can be stored within the ring buffer
   */
    inline RingBuffer(const int bufferSize)
    {
      this->bufferSize = bufferSize;
      this->identifierCounter = 0;
      this->index = -1;
      this->ringBuffer = new std::shared_ptr<T>[this->bufferSize];
    }

    /*!
     * \brief Default destructor.
     *
     * Default destructor.
     */
    inline virtual ~RingBuffer()
    {
      //nothing to do
    }

    /*!
     * \brief Returns the last element or NULL if no element exists.
     *
     * Returns the last element or NULL if no element exists.
     */
    std::shared_ptr<T> getLast()
    {
      return this->getLast(0);
    }

    /*!
     * \brief Returns the n-th last element or NULL.
     *
     * Returns the n-th last element. Returns NULL if no element exists or n > maxBuffer.
     *
     * \param n The n-th last element, 0 will return the newest one.
     */
    std::shared_ptr<T> getLast(int n)
    {
      std::shared_ptr<T> ptr;
      lock_guard<mutex> guard(mtx_);

      if (this->index < 0 || this->bufferSize <= n || this->identifierCounter <= n)
      {
        return ptr;
      }

      int index = (this->index - n) % this->bufferSize;

      ptr = this->ringBuffer[index];

      return ptr;
    }

    /*!
     * \brief Adds a new element to the ring buffer and returns the identifier.
     *
     * Adds a new element to the ring buffer and returns the identifier.
     *
     * \param element The element to add.
     */
    int add(std::shared_ptr<T> element)
    {
      lock_guard<mutex> guard(mtx_);

      int index = (++this->index) % this->bufferSize;

      this->ringBuffer[index] = element;

      return this->identifierCounter++;
    }

    /*!
     * \brief Return the buffer size.
     *
     * Return the buffer size.
     */
    const int getBufferSize() const
    {
      return this->bufferSize;
    }

    /*!
     * \brief Returns the current count of elements within the ring buffer.
     *
     * Returns the current count of elements within the ring buffer.
     */
    const int getSize() const
    {
      return (this->bufferSize < this->identifierCounter) ? this->bufferSize : this->identifierCounter;
    }

    /*!
     * \brief Clears the buffer.
     *
     * Clears the buffer. If cleanBuffer is false only the index structure is reseted, but the
     * buffer still exists (old elements are not accessible). If cleanBuffer is true the
     * pointers from the buffer are cleared as well.
     *
     * \param cleanBuffer True to clear the buffer.
     */
    int clear(bool cleanBuffer)
    {
      lock_guard<mutex> guard(mtx_);
      this->index = -1;
      this->identifierCounter = 0;

      if (false == cleanBuffer)
        return 0;

      std::shared_ptr<T> ptr;
      for (int i = 0; i < this->bufferSize; ++i)
        this->ringBuffer[i] = ptr;

      return 0;
    }

    /*!
     *\brief Returns the type_info of the used template type.
     *
     * Returns the type_info of the used template type.
     */
    const std::type_info* getTypeInfo() const
    {
      return &typeid(T);
    }

  private:
    mutex mtx_;
    std::shared_ptr<T>* ringBuffer; /**< Ring buffer of elements */
    int bufferSize; /**< number of stored elements */
    ulong identifierCounter; /**< Counter of elements added to the ring buffer */
    long index; /**< Current index of the last added element */
  };

} /* namespace ice */

#endif /* RINGBUFFER_H_ */
