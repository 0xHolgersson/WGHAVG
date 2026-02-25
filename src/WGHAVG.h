/*
WGHAVG.h

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
 * \file  WGHAVG.h
 * \brief 
 * 
 */

#ifndef _WGHAVG_H_
#define _WGHAVG_H_

#include "WGHAVG_types.h"
#include <math.h>

/************************************************************************//**
 * \class tWGHAVG
 * \brief tWGHAVG class definition.
 * 
 *
 */
class tWGHAVG
{
protected:

public:
  /************************************************************************//**
   * \brief Makes the weight table from the provided parameters
   *
   * \param f function 
   * \param a a variable
   * \param b b variable
   * \param n number of elements
   */
  tWGHAVG(tWGHAVG_Fx f, float a, float b, unsigned int n);

  /************************************************************************//**
  * \brief Adds a value to the calculations and removes the oldest value
  *
  * \param x the value to add 
  */
  void addValue(float x);

  /************************************************************************//**
  * \brief Calculates and gets the result based on the weight table and the added values
  *
  */
  float getResult();

 

private:  
  unsigned int position = 0;
  unsigned int elements;
  float sumWeights;
  float result;
  // variable arrays
  float weights[];
  float values[];

  /************************************************************************//**
  * \brief Increases position by 1. Resets to 0 if the initial position == elements.
  *
  */
  void incPosition();
};
  #endif