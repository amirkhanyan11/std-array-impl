#ifndef __CONST_REVERSE_ITERATOR_TPP__
#define __CONST_REVERSE_ITERATOR_TPP__

#include "const_iterator.tpp"


template <typename T, size_t N>
array<T, N>::const_reverse_iterator::const_reverse_iterator(pointer p) : const_iterator{p} {}

template <typename T, size_t N>
array<T, N>::const_reverse_iterator::const_reverse_iterator() : const_iterator{} {}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator& array<T, N>::const_reverse_iterator::operator++()
{
    --this->ptr;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator array<T, N>::const_reverse_iterator::operator++(int)
{
    const_reverse_iterator tmp = *this;

    ++(*this);

    return tmp;
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator& array<T, N>::const_reverse_iterator::operator--()
{
    ++this->ptr;

    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator array<T, N>::const_reverse_iterator::operator--(int)
{
    const_reverse_iterator tmp = *this;

    --(*this);

    return tmp;
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator& array<T, N>::const_reverse_iterator::operator+=(size_type k)
{
    this->ptr -= k;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator& array<T, N>::const_reverse_iterator::operator-=(size_type k)
{
    this->ptr += k;
    return *this;
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator array<T, N>::const_reverse_iterator::operator+(size_type k) const
{
    return (const_reverse_iterator(this->ptr - k));
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator array<T, N>::const_reverse_iterator::operator-(size_type k) const
{
    return (const_reverse_iterator(this->ptr + k));
}



#endif // __CONST_REVERSE_ITERATOR_TPP__