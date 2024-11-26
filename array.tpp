#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include <exception>
#include "array.hpp"
#include "iterators.hpp"


// using namespace cocobolo;

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<T> list)
{
    T* ptr = this->arr;

    for (auto i : list)
    {
        *(ptr++) = i;
    }
}


template <typename T, size_t N>
bool array<T, N>::operator==(const array& rhv) const
{
    return this->arr == rhv.arr;
}


template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::operator[](size_type idx) const
{
    return this->arr[idx];
}


template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type idx)
{
    return const_cast<reference> (

        (static_cast<const array *>(this))->operator[](idx)
    );
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::at(size_type idx) const noexcept
{
    if (idx >= N)
        throw std::out_of_range();

    return this->operator[](idx);
}


template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type idx) noexcept
{
    return const_cast<reference> (

        (static_cast<const array *>(this))->at(idx)
    );
}


template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::begin() const
{
    return const_iterator((const_cast<array<T, N>*>(this))->arr); // meh
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin()
{
    return iterator(this->arr);
}


template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator array<T, N>::rbegin() const
{
    return const_reverse_iterator((const_cast<array<T, N>*>(this))->arr + N - 1);
}

template <typename T, size_t N>
typename array<T, N>::reverse_iterator array<T, N>::rbegin()
{
    return reverse_iterator(this->arr + N - 1);
}

template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::end() const
{
    return iterator((const_cast<array<T, N>*>(this))->arr + N);
}

template <typename T, size_t N>
typename array<T, N>::const_reverse_iterator array<T, N>::rend() const
{
    return reverse_iterator((const_cast<array<T, N>*>(this))->arr - 1);
}

#endif // __ARRAY_TPP__