#ifndef _INTAUTO_HPP_
#define _INTAUTO_HPP_

#include <stdexcept>

namespace iat
{

class intauto_t
{
public:
    intauto_t() throw(std::runtime_error);
    ~intauto_t() noexcept;
private:
};

} //End iat namespace

#endif //defined _INTAUTO_HPP_
