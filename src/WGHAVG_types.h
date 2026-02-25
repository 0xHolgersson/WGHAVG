/*
WGHAVG_types.h

Copyright (c) 2026 Anton Holgersson

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*************************************************************************//**
 * \file  WGHAVG_types.h
 * \brief WGHAVG type definitions.
 *
 */

#ifndef _WGHAVG_TYPES_H_
#define _WGHAVG_TYPES_H_

#include <stdint.h>


/*************************************************************************//**
* \enum tWGHAVG_Fx
* \brief Function types for the weight part
* 
*
*/
enum tWGHAVG_Fx {
                  WGHAVG_Fx_Linear=0,                  ///< -a * (x * (1/n)) + 1 + b | a=negative gradient | x=element | n=number of elements | b=y-intersect
                  WGHAVG_Fx_Exponential=1,             ///< a * (x * (1/n) + 1) ^ -b | a=base multiplier | x=element | n=number of elements | b=negative exponent      
                  WGHAVG_Fx_Cosine=2,                  ///< a * cos(x * (pi/n)) + 1 + b | a=cosine amplitude | x=element | n=number of elements | b=weight last element
                };

#endif
