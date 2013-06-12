#include "intauto.hpp"

namespace iat
{

intauto_t::intauto_t() throw(std::bad_alloc)
{
    data = new char[2];

    data[0] = '0'; data[1] = '\0';
}

intauto_t::intauto_t(const intauto_t &other) throw(std::runtime_error)
{
    throw std::runtime_error("intauto_t not implemented");
}

template < typename N >
intauto_t::intauto_t(const N &other) throw(std::runtime_error)
{
    throw std::runtime_error("intauto_t not implemented");
}

intauto_t::~intauto_t() noexcept
{
    delete[] data;
}

} //End iat namespace

