#ifndef __REVERSE_ITERATOR_TPP__
#define __REVERSE_ITERATOR_TPP__


#include "const_reverse_iterator.tpp"


template <typename T, size_t N>
array<T, N>::reverse_iterator::reverse_iterator(pointer p) : const_reverse_iterator{p} {}


template <typename T, size_t N>
array<T, N>::reverse_iterator::reverse_iterator() : const_reverse_iterator{} {}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::reverse_iterator::operator*() const
{
    return this->const_reverse_iterator::operator*();
}

template <typename T, size_t N>
typename array<T, N>::const_pointer array<T, N>::reverse_iterator::operator->() const
{
    return this->const_reverse_iterator::operator->();
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::reverse_iterator::operator[](size_type idx) const
{
    return this->const_reverse_iterator::operator[](idx);
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::reverse_iterator::operator*()
{
    return const_cast<reference> (
        
        (static_cast<const reverse_iterator*>(this))->operator*()

    );
}

template <typename T, size_t N>
typename array<T, N>::pointer array<T, N>::reverse_iterator::operator->()
{
    return const_cast<pointer> (
        
        (static_cast<const reverse_iterator*>(this))->operator->()

    );
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::reverse_iterator::operator[](size_type idx)
{
    return const_cast<reference> (
        
        (static_cast<const reverse_iterator*>(this))->operator[](idx)

    );
}



#endif // __REVERSE_ITERATOR_TPP__
