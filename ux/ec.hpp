#ifndef _EC_HPP_
#define _EC_HPP_

#include <pthread.h>
#include "ux.hpp"

char *syserrmsgtype(char *buf, size_t buf_max, const char *msg,
                    int s_errno, EC_ERRTYPE type);
void ec_push(const char *fcn, const char *file, int line,
             const char *str, int errno_arg, EC_ERRTYPE type);
void ec_print(void);

#endif /* _EC_HPP_ */
