/**
 * Provides the templatized data type of a three dimensional Array.
 *
 * @file include/GExL/Core/templates/TArray3D.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
*/
#ifndef   CORE_TARRAY_3D_HPP_INCLUDED
#define   CORE_TARRAY_3D_HPP_INCLUDED

#include <GExL/GExL_types.hpp>
#include <GExL/logger/Log_macros.hpp>
#include "TArray2D.hpp"

namespace GExL
{
  /**
   * @brief Provides the fundamental three dimension Array data structure in a
   * templatized format.
   * @details Provides a robust three dimensional Array implementation for the
   * TYPE specified using the single Array implementation as the data store.
   * Example usage:
   *   GExL::TArray3D<int> integers(5, 5, 5);
   *   for(GExL::Uint32 i=0; i<integers.levels(); ++i)
   *     for(GExL::Uint32 j=0; j<integers.rows(); ++j)
   *       for(GExL::Uint32 k=0; k<integers.columns(); ++k)
   *         integers[i][j][k] = i*integers.rows()*integers.columns()+j*integers.columns()+k;
   */
  template <class TYPE>
  class TArray3D
  {
  public:
    /** Default constructor creates a TArray3D of 0 levels, rows, and columns
     * in size.
     */
    TArray3D();

    /** Alternative constructor creates a TArray3D of elements of
     * levels*rows*columns in size.
     * @param[in] levels of array to create
     * @param[in] rows of array to create
     * @param[in] columns of array to create
     */
    TArray3D(Uint32 levels, Uint32 rows, Uint32 columns);

    /** Destructor for the 3D array template.
     */
    virtual ~TArray3D();

    /** Retrieve the number of levels in the 3D array. Typically used when
     * iterating over the array bounds.
     * @return Uint32
     *   number of leves for this 3D array
     */
    Uint32 levels() const;
    
    /** Retrieve the number of rows in the 3D array. Typically used when
     * iterating over the array bounds.
     * @return Uint32
     *   number of rows for this 3D array
     */
    Uint32 rows() const;
    
    /** Retrieve the number of columns in the 3D array. Typically used when
     * iterating over the array bounds.
     * @return Uint32
     *   number of columns for this 3D array
     */
    Uint32 columns() const;
    
    /** Retrieve the reference to the level, row, and column specified in the
     * array with bounds checking. If level, row, and/or column exceeds the
     * levels, rows, and/or columns of the array then the last level, row,
     * and/or column in the array will be returned. This method is faster than
     * using the [] operator.
     * @param[in] level to retrieve element reference to
     * @param[in] row to retrieve element reference to
     * @param[in] column to retrieve element reference to
     * @return TYPE&
     *   reference to the element at row and column specified.
     */
    TYPE& indexOf(Uint32 level, Uint32 row, Uint32 column);

    /** Retrieve a reference 2D array of all the rows and columns for the level
     * specified with bounds checking. If level exceeds the levels of the array
     * then the last level in the array will be returned.
     * @param[in] level to retrieve reference 2D array for
     * @return TArray2D<TYPE>
     *   reference 2D array of all the rows and columns at the level specified.
     */
    TArray2D<TYPE> operator[](Uint32 level);
  protected:
    /** Total number of levels for this 3D array
     */
    Uint32 mLevels;

    /** Total number of rows for this 3D array
     */
    Uint32 mRows;

    /** Total number of columns for this 3D array
     */
    Uint32 mColumns;

    /** Single dimensional array that represents this 3D array using index arithmetic
     */
    TArray<TYPE> mArray;
  }; // class TArray3D

  /////////////////////////////////////////////////////////////////////////////
  // Template implementation details
  /////////////////////////////////////////////////////////////////////////////
  template <class TYPE>
  TArray3D<TYPE>::TArray3D() :
    mLevels(0U),
    mRows(0U),
    mColumns(0U),
    mArray()
  {
  }

  template <class TYPE>
  TArray3D<TYPE>::TArray3D(Uint32 levels, Uint32 rows, Uint32 columns) :
    mLevels(levels),
    mRows(rows),
    mColumns(columns),
    mArray(levels*rows*columns)
  {
  }

  template <class TYPE>
  TArray3D<TYPE>::~TArray3D()
  {
  }

  template <class TYPE>
  Uint32 TArray3D<TYPE>::levels() const
  {
    return mLevels;
  }

  template <class TYPE>
  Uint32 TArray3D<TYPE>::rows() const
  {
    return mRows;
  }

  template <class TYPE>
  Uint32 TArray3D<TYPE>::columns() const
  {
    return mColumns;
  }
    
  template <class TYPE>
  TYPE& TArray3D<TYPE>::indexOf(Uint32 level, Uint32 row, Uint32 column)
  {
    if(level < mLevels && row < mRows && column < mColumns)
    {
      return mArray[level*mRows*mColumns + row*mColumns + column];
    }
    // Bad level value provided
    else if(row < mRows && column < mColumns && mLevels > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") level provided exceeds maximum levels of "
        << mLevels << std::endl;
      return mArray[(mLevels-1)*mRows*mColumns + row*mColumns + column]; 
    }
    // Bad row value provided
    else if(level < mLevels && column < mColumns && mRows > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") row provided exceeds maximum rows of "
        << mRows << std::endl;
      return mArray[level*mRows*mColumns + (mRows-1)*mColumns + column]; 
    }
    // Bad column value provided
    else if(level < mLevels && row < mRows && mColumns > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") column provided exceeds maximum columns of "
        << mColumns << std::endl;
      return mArray[level*mRows*mColumns + row*mColumns + (mColumns-1)];
    }
    // Bad level and row values provided
    else if(column < mColumns && mLevels > 0 && mRows > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") level and row provided exceeds maximum levels of "
        << mLevels << " and rows of " << mRows << std::endl;
      return mArray[(mLevels-1)*mRows*mColumns + (mRows-1)*mColumns + column];
    }
    // Bad level and column values provided
    else if(row < mRows && mLevels > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") level and column provided exceeds maximum levels of "
        << mLevels << " and columns of " << mColumns << std::endl;
      return mArray[(mLevels-1)*mRows*mColumns + row*mColumns + (mColumns-1)];
    }
    // Bad row and column values provided
    else if(level < mLevels && mRows > 0 && mColumns > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") row and column provided exceeds maximum rows of "
        << mRows << " and columns of " << mColumns << std::endl;
      return mArray[level*mRows*mColumns + (mRows-1)*mColumns + (mColumns-1)];
    }
    // All values provided were bad
    else if(mLevels > 0 && mRows > 0 && mColumns > 0)
    {
      WLOG() << "TArray3D:indexOf(" << level << "," << row << "," << column
        << ") level, row, and column provided exceeds maximum level of "
        << mLevels << " and rows of " << mRows << " and columns of " << mColumns << std::endl;
      return mArray[(mLevels-1)*mRows*mColumns + (mRows-1)*mColumns + (mColumns-1)];
    }
    else
    {
      ELOG() << "TArray3D:indexOf(" << row << "," << column
        << ") array is empty (no levels, rows, or columns)" << std::endl;
      return mArray[0];
    }
  }

  template <class TYPE>
  TArray2D<TYPE> TArray3D<TYPE>::operator[](Uint32 level)
  {
    if(level < mLevels)
    {
      return TArray2D<TYPE>(mArray.data(), mRows, mColumns, level*mRows*mColumns + mArray.offset());
    }
    else
    {
      WLOG() << "TArray3D:operator[](" << row
        << ") level provided exceeds maximum levels of "
        << mLevels << std::endl;
      return TArray2D<TYPE>(mArray.data(), mRows, mColumns, (mLevels-1)*mRows*mColumns + mArray.offset());
    }
  }
} // namespace GExL

#endif // CORE_TARRAY_3D_HPP_INCLUDED

/**
 * @class GExL::TArray3D
 * @ingroup Core
 * The TArray3D template class is the template used to create a 3D array of the
 * type provided.
 *
 * Copyright (c) 2014 Ryan Lindeman
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
