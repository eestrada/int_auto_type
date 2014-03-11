#ifndef _INTAUTO_HPP_
#define _INTAUTO_HPP_

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace iat
{

class intauto_t
{
public:
    /*
     * Typedefs
     */
    typedef std::vector<bool> bit_container;
public:

    /*
     * Constructors
     */
    intauto_t() throw(std::bad_alloc);

    intauto_t(const intauto_t &other) throw(std::runtime_error);

    intauto_t(const intmax_t &other) throw(std::runtime_error);

    /*
     * Destructor
     */
    ~intauto_t() noexcept;

    /*
     * Assignment operations
     */
    intauto_t & operator=(const intauto_t &other);

    template < typename N >
    intauto_t & operator=(const N &other);

    /*
     * Bitwise operations
     */
    intauto_t & operator<<=(const intauto_t &other);

    template < typename N >
    intauto_t & operator<<=(const N &other);

    intauto_t operator<<(const intauto_t &other) const;

    template < typename N >
    intauto_t operator<<(const N &other) const;

    intauto_t & operator>>=(const intauto_t &other);

    template < typename N >
    intauto_t & operator>>=(const N &other);

    intauto_t operator>>(const intauto_t &other) const;

    template < typename N >
    intauto_t operator>>(const N &other) const;

    intauto_t & operator&=(const intauto_t &other);

    template < typename N >
    intauto_t & operator&=(const N &other);

    intauto_t operator&(const intauto_t &other) const;

    template < typename N >
    intauto_t operator&(const N &other) const;

    intauto_t & operator|=(const intauto_t &other);

    template < typename N >
    intauto_t & operator|=(const N &other);

    intauto_t operator|(const intauto_t &other) const;

    template < typename N >
    intauto_t operator|(const N &other) const;

    intauto_t & operator^=(const intauto_t &other);

    template < typename N >
    intauto_t & operator^=(const N &other);

    intauto_t operator^(const intauto_t &other) const;

    template < typename N >
    intauto_t operator^(const N &other) const;

    /* 
     * Unary Operators
     */
    /* Unary Invert. ie, NOT */
    intauto_t operator~() const;

    /* Unary positive */
    intauto_t operator+() const;

    /* Unary negate */
    intauto_t operator-() const;

    /* Unary prefix increment */
    intauto_t & operator++();

    /* Unary postfix increment */
    intauto_t operator++(int);

    /* Unary prefix decrement */
    intauto_t & operator--();

    /* Unary prefix decrement */
    intauto_t operator--(int);

    /*
     * Arithmetic operations
     */
    /* Addition operator */
    intauto_t & operator+=(const intauto_t &other);

    template < typename N >
    intauto_t & operator+=(const N &other);

    intauto_t operator+(const intauto_t &other) const;

    template < typename N >
    intauto_t operator+(const N &other) const;

    /* Subtraction operator */
    intauto_t & operator-=(const intauto_t &other);

    template < typename N >
    intauto_t & operator-=(const N &other);

    intauto_t operator-(const intauto_t &other) const;

    template < typename N >
    intauto_t operator-(const N &other) const;

    /* Multiplication operator */
    intauto_t & operator*=(const intauto_t &other);

    template < typename N >
    intauto_t & operator*=(const N &other);

    intauto_t operator*(const intauto_t &other) const;

    template < typename N >
    intauto_t operator*(const N &other) const;

    /* Division operator */
    intauto_t & operator/=(const intauto_t &other);

    template < typename N >
    intauto_t & operator/=(const N &other);

    intauto_t operator/(const intauto_t &other) const;

    template < typename N >
    intauto_t operator/(const N &other) const;

    /* Modulo operator */
    intauto_t & operator%=(const intauto_t &other);

    template < typename N >
    intauto_t & operator%=(const N &other);

    intauto_t operator%(const intauto_t &other) const;

    template < typename N >
    intauto_t operator%(const N &other) const;
private:

    bit_container data;
};

} //End iat namespace

#endif //defined _INTAUTO_HPP_
