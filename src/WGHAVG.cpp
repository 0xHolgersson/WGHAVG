/*
WGHAVG.cpp

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

#include "WGHAVG.h"

/************************************************************************//**
* \brief Makes the weight table from the provided parameters
*
* \param f function 
* \param a a variable
* \param b b variable
* \param n number of elements
*/
tWGHAVG::tWGHAVG(tWGHAVG_Fx f, float a, float b, unsigned int n){
  float tempFloat;
  sumWeights = 0;
  elements = n;
  switch(f){
    case WGHAVG_Fx_Linear:///< -a * (x * (1/n)) + 1 + b | a=negative gradient | x=element | n=number of elements | b=y-intersect
      for (unsigned int i = 0 ; i < n ; i++){
        tempFloat = -a*(i*1/n)+1+b;
        sumWeights += tempFloat;
        weights[i] = tempFloat;
      }
      for (unsigned int i = 0 ; i < n ; i++){
        weights[i] /= sumWeights;
      }
      break;

    case WGHAVG_Fx_Exponential:///< a * (x * (1/n) + 1) ^ -b | a=base multiplier | x=element | n=number of elements | b=negative exponent 
      for (unsigned int i = 0 ; i < n ; i++){
        tempFloat = a*(i*1/n)+1*-b*-b;
        sumWeights += tempFloat;
        weights[i] = tempFloat;
      }
      for (unsigned int i = 0 ; i < n ; i++){
        weights[i] /= sumWeights;
      }
      break;

    case WGHAVG_Fx_Cosine:///< a * cos(x * (pi/n)) + 1 + b | a=cosine amplitude | x=element | n=number of elements | b=weight last element
      for (unsigned int i = 0 ; i < n ; i++){
        tempFloat = float(a*cos(float(i)*M_PI/float(n))+1+b); //Cos() takes float as a parameter and returns a double
        sumWeights += tempFloat;
        weights[i] = tempFloat;
      }
      for (unsigned int i = 0 ; i < n ; i++){
        weights[i] /= sumWeights;
      }
      break;
  }
};

/************************************************************************//**
* \brief Increases position by 1. Resets to 0 if the initial position == elements.
*
*/
void tWGHAVG::incPosition(){
  if (position == elements - 1){
    position = 0;
  }
  else{
    position++;
  }
};

/************************************************************************//**
* \brief Adds a value to the calculations and removes the oldest value
*
* \param x the value to add 
*/
void tWGHAVG::addValue(float x){
  tWGHAVG::incPosition();
  values[position] = x; 
};

/************************************************************************//**
* \brief Calculates and gets the result based on the weight table and the added values
*
*/
float tWGHAVG::getResult(){
  unsigned int tempUint = position;
  result = 0;
  for (unsigned int i = 0 ; i < elements ; i++){
    result += weights[i]*values[tempUint];
    if (tempUint == 0){
    tempUint = elements - 1;
    }
    else{
      tempUint--;
    }
  }
  
  return result;
};