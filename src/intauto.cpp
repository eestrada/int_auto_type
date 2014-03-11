#include "intauto.hpp"

namespace iat
{

intauto_t::intauto_t() throw(std::bad_alloc)
{
    data.push_back(0);
}

intauto_t::intauto_t(const intauto_t &other) throw(std::runtime_error)
{
    this->data = other.data;
}

intauto_t::intauto_t(const intmax_t &other) throw(std::runtime_error)
{
    throw std::runtime_error("intauto_t not implemented");
}

intauto_t::~intauto_t() noexcept
{
}

} //End iat namespace

