#ifndef _INTAUTO_HPP_
#define _INTAUTO_HPP_

#include <stdexcept>

namespace iat
{

class intauto_t
{
public:
    intauto_t() throw(std::bad_alloc);

    intauto_t(const intauto_t &other) throw(std::runtime_error);

    template < typename N >
    intauto_t(const N &other) throw(std::runtime_error);

    ~intauto_t() noexcept;

    intauto_t & operator=(const intauto_t &other);

    template < typename N >
    intauto_t & operator=(const N &other);

    intauto_t operator+(const intauto_t &other);

    intauto_t operator-(const intauto_t &other);

    intauto_t operator*(const intauto_t &other);

    intauto_t operator/(const intauto_t &other);
private:

    char *data;
};

} //End iat namespace

#endif //defined _INTAUTO_HPP_
