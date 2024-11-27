#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

namespace cocobolo 
{

template <typename T, size_t N>
class array
{
public:

    using value_type        = T;
    using size_type         = std::size_t;
    using difference_type   = std::ptrdiff_t;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using pointer           = value_type*;
    using const_pointer     = const value_type*;


public:
    class const_iterator
    {
    public:

        friend array<T, N>;

        using iterator_category = std::contiguous_iterator_tag;

        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using reference         = value_type&;
        using const_reference   = const value_type&;
        using pointer           = value_type*;
        using const_pointer     = const value_type*;
        
    protected:
        explicit const_iterator(pointer ptr);

    public:
        const_iterator();
        const_iterator(const const_iterator& rhv) = default;
        const_iterator(const_iterator&& rhv) = default;

    public:

        const_iterator& operator=(const const_iterator& rhv) = default;
        const_iterator& operator=(const_iterator&& rhv) = default;

    public:

        const_reference operator*() const;
        const_pointer   operator->() const;
        const_reference operator[](size_type idx) const;
        const_iterator& operator++();
        const_iterator  operator++(int);
        const_iterator& operator--();
        const_iterator  operator--(int);
        const_iterator& operator+=(size_type);
        const_iterator& operator-=(size_type);
        const_iterator  operator+(size_type) const;
        const_iterator  operator-(size_type) const;
        difference_type operator-(const const_iterator& rhv) const;

    public:

        bool operator<=>(const const_iterator& rhv) const = default;


    private:
        pointer ptr;
    };


    class iterator : public const_iterator
    {
    
    public:

        friend array<T, N>;
        using iterator_category = std::contiguous_iterator_tag;

    protected:
        explicit iterator(pointer);

    public:

        iterator();
        iterator(const iterator& rhv) = default;
        iterator(iterator&& rhv) = default;

    // no asg. operators

    public:


        const_reference operator*() const;
        const_pointer   operator->() const;
        const_reference operator[](size_type idx) const;

        reference operator*();
        pointer   operator->();
        reference operator[](size_type idx);

    };


    class const_reverse_iterator : public const_iterator
    {
    public:
        friend array<value_type, N>;

    protected:
        explicit const_reverse_iterator(pointer ptr);

    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv) = default;
        const_reverse_iterator(const_reverse_iterator&& rhv) = default;

    public:

        const_reverse_iterator& operator++();
        const_reverse_iterator  operator++(int);
        const_reverse_iterator& operator--();
        const_reverse_iterator  operator--(int);
        const_reverse_iterator& operator+=(size_type);
        const_reverse_iterator& operator-=(size_type);
        const_reverse_iterator  operator+(size_type) const;
        const_reverse_iterator  operator-(size_type) const;
        difference_type         operator-(const const_reverse_iterator& rhv) const;

    };


    class reverse_iterator : public const_reverse_iterator
    {
    public:

        friend array<T, N>;

    protected:
        explicit reverse_iterator(pointer);

    public:

        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv) = default;
        reverse_iterator(reverse_iterator&& rhv) = default;

    public:

        const_reference operator*() const;
        const_pointer   operator->() const;
        const_reference operator[](size_type idx) const;

        reference operator*();
        pointer   operator->();
        reference operator[](size_type idx);
    };


public:

    array() = default;
    array(const array& rhv) = default;
    array(array&& rhv) = default;
    array(std::initializer_list<T> list);

public:

    array&          operator=(const array& rhv) = default;
    array&          operator=(array&& rhv) = default;

    bool            operator==(const array& rhv) const;

    const_reference operator[](size_type idx) const noexcept;
    reference       operator[](size_type idx) noexcept;

public:

    const_reference at(size_type idx) const; 
    reference       at(size_type idx); 
    

public:

    const_iterator          begin() const;
    iterator                begin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rbegin();

    const_iterator          end() const;
    iterator                end();
    const_reverse_iterator  rend() const;




private:

    T arr[N];

};


#include "array.tpp"


};


#endif // __ARRAY_HPP__
