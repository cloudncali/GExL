/**
 * Provides the templatized data type of a double dimensional Array.
 *
 * @file include/GExL/Core/templates/TArray2D.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
*/
#ifndef   CORE_TARRAY_2D_HPP_INCLUDED
#define   CORE_TARRAY_2D_HPP_INCLUDED

#include <GExL/GExL_types.hpp>
#include <GExL/logger/Log_macros.hpp>
#include "TArray.hpp"

namespace GExL
{
  /**
   * @brief Provides the fundamental two dimension Array data structure in a
   * templatized format.
   * @details Provides a robust two dimensional Array implementation for the
   * TYPE specified using the single Array implementation as the data store.
   * Example usage:
   *   GExL::TArray2D<int> integers(5, 5);
   *   for(GExL::Uint32 i=0; i<integers.rows(); ++i)
   *     for(GExL::Uint32 j=0; j<integers.columns(); ++j)
   *       integers[i][j] = i*integers.columns()+j;
   *
   *   int rawData[20];
   *   // Create 2D Array wrapper around rawData starting at index 5 with 3
   *   // rows and 3 columns and offset of 5.
   *   // This means row,column 0,0 of the 2D Array wrapper maps to index 5
   *   // of rawData.
   *   GExL::TArray2D<int> integers(rawData, 3, 3, 5);
   *   for(GExL::Uint32 i=0; i<integers.rows(); ++i)
   *     for(GExL::Uint32 j=0; j<integers.columns(); ++j)
   *       integers[i][j] = i*integers.columns()+j;
   *
   *   for(GExL::Uint32 i=0; i<20; ++i)
   *     printf("[%u] = %d\n", i, rawData[i]);
   */
  template <class TYPE>
  class TArray2D
  {
  public:
    /** Default constructor creates a TArray2D of 0 rows and columns in size
     */
    TArray2D();

    /** Alternative constructor creates a TArray2D of elements of rows*columns
     * in size.
     * @param[in] rows of array to create
     * @param[in] columns of array to create
     */
    TArray2D(Uint32 rows, Uint32 columns);

    /** Alternative constructor creates a reference array to another data
     * source of size and at offset specified.
     * @param[in] data pointer to original source
     * @param[in] rows of the reference array to create
     * @param[in] columns of the reference array to create
     * @param[in] offset into reference array that maps to row,column 0,0 (default 0)
     */
    TArray2D(TYPE* data, Uint32 rows, Uint32 columns, Uint32 offset = 0);

    /** Destructor for the 2D array template.
     */
    virtual ~TArray2D();

    /** Retrieve the number of rows in the 2D array. Typically used when
     * iterating over the array bounds.
     * @return Uint32
     *   number of rows for this 2D array
     */
    Uint32 rows() const;
    
    /** Retrieve the number of columns in the 2D array. Typically used when
     * iterating over the array bounds.
     * @return Uint32
     *   number of columns for this 2D array
     */
    Uint32 columns() const;
    
    /** Retrieve the reference to the row and column specified in the array
     * with bounds checking. If row or column exceeds the rows or columns of
     * the array then the last row and/or column in the array will be
     * returned. This method is faster than using the [] operator.
     * @param[in] row to retrieve reference to
     * @param[in] column to retrieve reference to
     * @return TYPE&
     *   reference to the element at row and column specified.
     */
    TYPE& indexOf(Uint32 row, Uint32 column);

    /** Retrieve a reference array of all the columns at the specified row with
     * bounds checking. If row exceeds the rows of the array then the last row
     * in the array will be returned.
     * @param[in] row to retrieve reference to
     * @return TArray<TYPE>
     *   reference array of all the columns at the row specified.
     */
    TArray<TYPE> operator[](Uint32 row);

  protected:
    /** Total number of rows for this 2D array
     */
    Uint32 mRows;

    /** Total number of columns for this 2D array
     */
    Uint32 mColumns;

    /** Single dimensional array that represents this 2D array using index arithmetic
     */
    TArray<TYPE> mArray;
  }; // class TArray2D

  /////////////////////////////////////////////////////////////////////////////
  // Template implementation details
  /////////////////////////////////////////////////////////////////////////////
  template <class TYPE>
  TArray2D<TYPE>::TArray2D() :
    mRows(0U),
    mColumns(0U),
    mArray()
  {
  }

  template <class TYPE>
  TArray2D<TYPE>::TArray2D(Uint32 rows, Uint32 columns) :
    mRows(rows),
    mColumns(columns),
    mArray(rows*columns)
  {
  }

  template <class TYPE>
  TArray2D<TYPE>::TArray2D(TYPE* data, Uint32 rows, Uint32 columns, Uint32 offset) :
    mRows(rows),
    mColumns(columns),
    mArray(data, rows*columns, offset)
  {
  }

  template <class TYPE>
  TArray2D<TYPE>::~TArray2D()
  {
  }

  template <class TYPE>
  Uint32 TArray2D<TYPE>::rows() const
  {
    return mRows;
  }

  template <class TYPE>
  Uint32 TArray2D<TYPE>::columns() const
  {
    return mColumns;
  }
    
  template <class TYPE>
  TYPE& TArray2D<TYPE>::indexOf(Uint32 row, Uint32 column)
  {
    if(row < mRows && column < mColumns)
    {
      return mArray[row*mColumns + column];
    }
    else if(column < mColumns && mRows > 0)
    {
      WLOG() << "TArray2D:indexOf(" << row << "," << column
        << ") row provided exceeds maximum rows of "
        << mRows << std::endl;
      return mArray[(mRows-1)*mColumns + column]; 
    }
    else if(row < mRows && mColumns > 0)
    {
      WLOG() << "TArray2D:indexOf(" << row << "," << column
        << ") column provided exceeds maximum columns of "
        << mColumns << std::endl;
      return mArray[row*mColumns + (mColumns-1)];
    }
    else if(mRows > 0 && mColumns > 0)
    {
      WLOG() << "TArray2D:indexOf(" << row << "," << column
        << ") row and column provided exceeds maximum row of "
        << mRows << " and column of " << mColumns << std::endl;
      return mArray[(mRows-1)*mColumns + (mColumns-1)];
    }
    else
    {
      ELOG() << "TArray2D:indexOf(" << row << "," << column
        << ") array is empty (no rows or columns)" << std::endl;
      return mArray[0];
    }
  }

  template <class TYPE>
  TArray<TYPE> TArray2D<TYPE>::operator[](Uint32 row)
  {
    if(row < mRows)
    {
      return TArray<TYPE>(mArray.data(), mColumns, row*mColumns + mArray.offset());
    }
    else
    {
      WLOG() << "TArray2D:operator[](" << row
        << ") row provided exceeds maximum rows of "
        << mRows << std::endl;
      return TArray<TYPE>(mArray.data(), mColumns, (mRows-1)*mColumns + mArray.offset());
    }
  }
} // namespace GExL

#endif // CORE_TARRAY_2D_HPP_INCLUDED

/**
 * @class GExL::TArray2D
 * @ingroup Core
 * The TArray2D template class is the template used to create a 2D array of the
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
