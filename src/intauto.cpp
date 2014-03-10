#include "intauto.hpp"

namespace iat
{

intauto_t::intauto_t() throw(std::bad_alloc)
{
    data.push_back(0);
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
}

} //End iat namespace

