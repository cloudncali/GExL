/**
 * Provides several math functions and methods used throughout
 * the GExL namespace.
 *
 * @file include/GExL/utils/MathUtil.hpp
 * @author Jacob Dix
 * @date 20151125 - Initial Release
 */
#ifndef MATH_UTIL_HPP_INCLUDED
#define MATH_UTIL_HPP_INCLUDED

/// PI constant
#define PI 3.14159265f

#include <math.h>
#include <string>
#include <GExL/Config.hpp>
namespace GExL
{
  /** Sets the starting seed value used by the random generator method Random.
   * @param[in] theSeed to set
   */
  void GExL_API setSeed(Uint32 theSeed);

  /** Returns a random unsigned 32 bit integer point value between theMin and
   * theMax values provided.
   * @param[in] theMin value to return
   * @param[in] theMax value to return
   * @return a random unsigned 32 bit integer value between theMin and theMax
   */
  Uint32 GExL_API random(Uint32 theMin, Uint32 theMax);

  /** Normalize vector using the x and y values provided.
   * @param[in] x reference value to normalize
   * @param[in] y reference value to normalize
   */
  void GExL_API normalizeVector(float& theX, float& theY);

  /** Computes the dot product of the two x and y coordinates provided.
   * @param[in] theFirstX reference value to compute dot product from.
   * @param[in] theFirstY reference value to compute dot product from.
   * @param[in] theSecondX reference value to compute dot product from.
   * @param[in] theSecondY reference value to compute dot product from.
   * @return the dot product computed from the two x and y coordinates.
   */
  float GExL_API dotProduct(float& theFirstX, float& theFirstY, float& theSecondX, float& theSecondY);
  
  /** Determines weither a value is with in a given range
   * @param[in] theValue the value being tested.
   * @param[in] theMin The low value.
   * @param[in] theMax The high value.
   * @return true if theValue is with the range of [theMin,theMax]
   */
  template<class TYPE>
  bool GExL_API valueInRange(TYPE theValue, TYPE theMin, TYPE theMax)
  {
    return (theValue >= theMin) && (theValue <= theMax);
  }
}

#endif // MATH_UTIL_HPP_INCLUDED

/**
 * @ingroup GExL
 * Provides several math functions and methods used throughout
 * the GExL namespace.
 *
 *
 * Copyright (c) 2014-2015 Jacob Dix
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
