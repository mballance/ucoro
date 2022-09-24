/*****************************************************************************
 * ucoro.h
 *****************************************************************************/
#ifndef INCLUDED_UCORO_H
#define INCLUDED_UCORO_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct coro_s *coro_t;
typedef struct ucoro_join_s *ucoro_join_t;

coro_t ucoro_fork(coro_t coro);

void ucoro_await(coro_t coro);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_UCORO_H */
