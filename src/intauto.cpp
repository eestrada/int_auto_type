#include "intauto.hpp"

_INTAUTO_NAMESPACE_START_

intauto_t::intauto_t() throw(std::bad_alloc)
{
    this->data.push_back(0);
}

intauto_t::intauto_t(const intmax_t &other) throw(std::runtime_error)
{
    *this = intauto_t();
    uintmax_t * u = &(this->data.front()); // Get pointer to front (and only) element of data
    intmax_t * s = reinterpret_cast<intmax_t *>(u); // Treat it as if it is signed
    *s = other; // Force a signed value into it
}

intauto_t::~intauto_t() noexcept
{
}

intauto_t & intauto_t::operator=(const intmax_t &other)
{
    *this = intauto_t(other);
    return *this;
}

const intauto_t::bit_container & intauto_t::get_data() const
{
    return this->data;
}
_INTAUTO_NAMESPACE_END_
