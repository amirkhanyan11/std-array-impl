#ifndef __CONST_ITERATOR_TPP__
#define __CONST_ITERATOR_TPP__


#include <iostream>
#include <exception>

#include "array.hpp"


template <typename T, size_t N>
array<T, N>::const_iterator::const_iterator(pointer p) : ptr{p} {}

template <typename T, size_t N>
array<T, N>::const_iterator::const_iterator() : ptr{nullptr} {}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::const_iterator::operator*() const
{
    return (*ptr);
}

template <typename T, size_t N>
typename array<T, N>::const_pointer array<T, N>::const_iterator::operator->() const
{
    return (ptr);
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::const_iterator::operator[](size_type idx) const
{
    return ptr[idx];
}

template <typename T, size_t N>
typename array<T, N>::const_iterator& array<T, N>::const_iterator::operator++()
{
    ++ptr;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator& array<T, N>::const_iterator::operator--()
{
    --ptr;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::const_iterator::operator--(int)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator& array<T, N>::const_iterator::operator+=(size_type k)
{
    this->ptr += k;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator& array<T, N>::const_iterator::operator-=(size_type k)
{
    this->ptr -= k;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::const_iterator::operator+(size_type k) const
{
    return (const_iterator(this->ptr + k));
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::const_iterator::operator-(size_type k) const
{
    return (const_iterator(this->ptr - k));
}

template <typename T, size_t N>
typename array<T, N>::difference_type array<T, N>::const_iterator::operator-(const const_iterator& rhv) const
{
    return (this->ptr - rhv.ptr);
}
               
#endif // __CONST_ITERATOR_TPP__