#include "main.h"

/**
*init_prams - clear struct fields and reset buf
* @prams: parameters struct
* @list: argument pointer
*
*Return: void
*/

void init_prams(prams_t *prams, va_list list)
{
prams->unsign = 0;
prams->plus_flag = 0;
prams->hashtag_flag = 0;
prams->zero_flag = 0;
prams->minus_flag = 0;
prams->width = 0;
prams->precision = 0;
prams->h_modifier = 0;
prams->l_modifier = 0;
(void)list;
}
