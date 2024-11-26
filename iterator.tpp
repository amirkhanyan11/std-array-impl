#ifndef __ITERATOR_TPP__
#define __ITERATOR_TPP__

#include "const_iterator.tpp"


template <typename T, size_t N>
array<T, N>::iterator::iterator(pointer p) : const_iterator{p} {}


template <typename T, size_t N>
array<T, N>::iterator::iterator() : const_iterator{} {}


template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::iterator::operator*() const
{
    return this->const_iterator::operator*();
}

template <typename T, size_t N>
typename array<T, N>::const_pointer array<T, N>::iterator::operator->() const
{
    return this->const_iterator::operator->();
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::iterator::operator[](size_type idx) const
{
    return this->const_iterator::operator[](idx);
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::iterator::operator*()
{
    return const_cast<reference> (
        
        (static_cast<const iterator*>(this))->operator*()

    );
}

template <typename T, size_t N>
typename array<T, N>::pointer array<T, N>::iterator::operator->()
{
    return const_cast<pointer> (
        
        (static_cast<const iterator*>(this))->operator->()

    );
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::iterator::operator[](size_type idx)
{
    return const_cast<reference> (
        
        (static_cast<const iterator*>(this))->operator[](idx)

    );
}

#endif // __ITERATOR_TPP__