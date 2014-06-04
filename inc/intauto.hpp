#ifndef _INTAUTO_HPP_
#define _INTAUTO_HPP_

#include <cstdint>
#include <stdexcept>
#include <vector>
#include <ostream>

#define _INTAUTO_NAMESPACE_ std 
#define _INTAUTO_NAMESPACE_START_ namespace _INTAUTO_NAMESPACE_ {
#define _INTAUTO_NAMESPACE_END_ }

_INTAUTO_NAMESPACE_START_

class intauto_t
{
public:
    /*
     * Typedefs
     */
    typedef std::vector<uintmax_t> bit_container;
public:

    /*
     * Constructors
     */
    intauto_t() throw(std::bad_alloc);

    intauto_t(const intmax_t &other) throw(std::runtime_error);

    intauto_t(const intauto_t &other) = default;

    intauto_t(intauto_t &&other) = default;

    /*
     * Destructor
     */
    ~intauto_t() noexcept;

    /*
     * Assignment operations
     */
    intauto_t & operator=(const intauto_t &other) = default;
    intauto_t & operator=(intauto_t &&other) = default;

    intauto_t & operator=(const intmax_t &other);

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

    const bit_container & get_data() const;
protected:

    bit_container data;
};

_INTAUTO_NAMESPACE_END_

inline ::std::ostream & operator<<(::std::ostream &out, const _INTAUTO_NAMESPACE_::intauto_t &iat)
{
    const _INTAUTO_NAMESPACE_::intauto_t::bit_container data = iat.get_data();
    for(auto i = data.rbegin(); i != data.rend(); ++i)
    {
        const uintmax_t * u = &(*i);
        const intmax_t * s = reinterpret_cast<const intmax_t *>(u);
        out << *s; 
    }
    return out;
}

#endif //defined _INTAUTO_HPP_
