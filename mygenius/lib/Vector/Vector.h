// ----------------------------------------------------------------------------
// Vector.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef VECTOR_H
#define VECTOR_H
#ifdef ARDUINO
#include <Arduino.h>
#else
#include <cstddef>
#endif
#include "VectorIterator.h"


template <typename T>
class Vector
{
public:
  Vector();
  template <size_t MAX_SIZE>
  Vector(T (&values)[MAX_SIZE],
    size_t size=0);
  template <size_t MAX_SIZE>
  void setStorage(T (&values)[MAX_SIZE],
    size_t size=0);
  void setStorage(T * values,
    size_t max_size,
    size_t size);
  const T & operator[](size_t index) const;
  T & operator[](size_t index);
  const T & at(size_t index) const;
  T & at(size_t index);
  T & front();
  T & back();
  void clear();
  template <typename U>
  void fill(const U & value);
  template <typename U,
    size_t N>
  void fill(const U (&values)[N]);
  template <typename U>
  void fill(const Vector<U> & values);
  template <typename U>
  void assign(size_t n,
    const U & value);
  template <typename U,
    size_t N>
  void assign(size_t n,
    const U (&values)[N]);
  template <typename U>
  void assign(size_t n,
    const Vector<U> & values);
  void push_back(const T & value);
  void pop_back();
  void remove(size_t index);
  size_t size() const;
  size_t max_size() const;
  bool empty() const;
  bool full() const;
  const T * data() const;
  T * data();
  typedef VectorIterator<T> iterator;
  iterator begin();
  iterator end();
  typedef VectorIterator<const T> const_iterator;
  const_iterator begin() const;
  const_iterator end() const;

private:
  T * values_;
  size_t max_size_;
  size_t size_;
};

#ifdef ARDUINO    /* `Print` is declared in the Arduino library and gives a compilation error elsewhere. */
template <typename T>
inline Print & operator <<(Print & stream,
  const Vector<T> & vector)
{
  stream.print("[");
  for (size_t i=0; i<vector.size(); ++i)
  {
    if (i != 0)
    {
      stream.print(",");
    }
    stream.print(vector[i]);
  }
  stream.print("]");
  return stream;
}
#endif

#include "VectorDefinitions.h"

#endif