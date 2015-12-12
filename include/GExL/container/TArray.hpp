/**
 * Provides the templatized data type of single dimensional Array.
 *
 * @file include/GExL/Core/templates/TArray.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
 */
#ifndef   CORE_TARRAY_HPP_INCLUDED
#define   CORE_TARRAY_HPP_INCLUDED

#include <GExL/GExL_types.hpp>
#include <GExL/logger/Log_macros.hpp>
#include <new>

namespace GExL
{
  /**
   * @brief Provides the fundamental Array data structure in a templatized format.
   * @details Provides a robust single dimensional Array implementation for the
   * TYPE specified.
   * Example usage:
   *   GExL::TArray<int> integers(10);
   *   for(GExL::Uint32 i=0; i<integers.size(); ++i)
   *     integers[i] = i;
   *
   *   int rawData[20];
   *   // Create Array wrapper around rawData starting at index 5 with size 10.
   *   // This means index 0 of Array wrapper maps to index 5 of rawData and
   *   // index 9 of Array wrapper maps to index 14 of rawData
   *   GExL::TArray<int> integers(rawData, 5, 10);
   *   for(GExL::Uint32 i=0; i<integers.size(); ++i)
   *     integers[i] = i;
   *
   *   for(GExL::Uint32 i=0; i<20; ++i)
   *     printf("[%u] = %d\n", i, rawData[i]);
   */
  template <class TYPE>
  class TArray
  {
  public:
    /** Default constructor creates a TArray of 0 elements in size
     */
    TArray();

    /** Alternative constructor creates a TArray of size elements in size
     * @param[in] size of array to create
     */
    explicit TArray(Uint32 size);

    /** Alternative constructor creates a reference array to another data
     * source of size and at offset specified.
     * @param[in] data pointer to original source
     * @param[in] size of reference array
     * @param[in] offset into reference array that maps to index 0 (default 0)
     */
    TArray(TYPE* data, Uint32 size, Uint32 offset = 0);

    /** Destructor for array will delete the array if not a reference array.
     */
    virtual ~TArray();

    /** Copy constructor for array
     * @param[in] copy to construct new array from
     */
    TArray(TArray const& copy);

    /** Assignment operator
     * @param[in] right side of assignment operator
     * @return TArray address reference to left side of assignment operator
     */
    TArray& operator=(TArray const& right);

    /** Retrieve reference to internal raw data array. Typically used to create
     * sub reference arrays of original array (see @ref TArray2D or @ref TArray3D).
     * @return TYPE const*
     *   pointer to internal raw data array
     */
    TYPE* data() const;

    /** Retrieve the size of the array. Typically used when iterating over the array
     * bounds.
     * @return Uint32
     *   size of array.
     */
    Uint32 size() const;

    /** Retrieve the offset of the array. Typically used when creating a reference
     * array from another reference array (see @ref TArray2D)
     * @return Uint32
     *   offset of reference array
     */
    Uint32 offset() const;

    /** Retrieve the reference to the position specified in the array with bounds
     * checking. If position exceeds the size of the array then the last element in
     * the array will be returned.
     * @param[in] position in array to return reference to
     * @return TYPE&
     *   reference to the element at position specified.
     */
    TYPE& indexOf(Uint32 position);

    /** Retrieve a constant reference to the position specified in the array with
     * bounds checking. If position exceeds the size of the array then the last
     * element in the array will be returned.
     * @param[in] position in array to return reference to
     * @return TYPE const&
     *   constant reference to the element at position specified.
     */
    TYPE const& operator[] (Uint32 position) const;

    /** Retrieve the reference to the position specified in the array with bounds
     * checking. If position exceeds the size of the array then the last element in
     * the array will be returned.
     * @param[in] position in array to return reference to
     * @return TYPE&
     *   reference to the element at position specified.
     */
    TYPE& operator[] (Uint32 position);

  protected:
    /** Single dimensional array of elements
     */
    TYPE* mData;

    /** Size of single dimensional array of elements
     */
    Uint32 mSize;

    /** Offset into data for position 0. Often used for reference arrays.
     */
    Uint32 mOffset;

    /** Indicates this is a reference array and should not be deleted on destruction
     */
    bool mReference;

  private:
    /** Helper function used by assignment operator to swap between a copy of
     * the array and this array.
     * @param[inout] reference to copy to swap with this array
     */
    void transfer(TArray<TYPE>& copy);

  }; // class TArray

  /////////////////////////////////////////////////////////////////////////////
  // Template implementation details
  /////////////////////////////////////////////////////////////////////////////
  template <class TYPE>
  TArray<TYPE>::TArray() :
    mData(new (std::nothrow) TYPE[0]),
    mSize(0U),
    mOffset(0U),
    mReference(false)
  {
  }

  template <class TYPE>
  TArray<TYPE>::TArray(Uint32 size) :
    mData(new (std::nothrow) TYPE[size]),
    mSize(size),
    mOffset(0U),
    mReference(false)
  {
  }

  template <class TYPE>
  TArray<TYPE>::TArray(TYPE* data, Uint32 size, Uint32 offset) :
    mData(data),
    mSize(size),
    mOffset(offset),
    mReference(true)
  {
  }

  template <class TYPE>
  TArray<TYPE>::~TArray()
  {
    if (!mReference)
    {
      delete[] mData;
    }
    // Don't keep data address around
    mData = 0;
    mSize = 0U;
  }

  template <class TYPE>
  TArray<TYPE>::TArray(TArray<TYPE> const& copy) :
    mData(new (std::nothrow) TYPE[copy.mSize]),
    mSize(copy.mSize),
    mOffset(copy.mOffset),
    mReference(false)
  {
    for (Uint32 i = 0; i < mSize; ++i)
    {
      mData[i] = copy.mData[i];
    }
  }

  template <class TYPE>
  TArray<TYPE>& TArray<TYPE>::operator=(TArray<TYPE> const& right)
  {
    // If not self reference then copy new array into existing array
    if (this != &right)
    {
      // Transfer copy of array to this array
      transfer(TArray<TYPE>(right));
    }
    return *this;
  }

  template <class TYPE>
  TYPE* TArray<TYPE>::data() const
  {
    return mData;
  }

  template <class TYPE>
  Uint32 TArray<TYPE>::size() const
  {
    return mSize;
  }

  template <class TYPE>
  Uint32 TArray<TYPE>::offset() const
  {
    return mOffset;
  }

  template <class TYPE>
  TYPE const& TArray<TYPE>::operator[](Uint32 position) const
  {
    return indexOf(position);
  }

  template <class TYPE>
  TYPE& TArray<TYPE>::indexOf(Uint32 position)
  {
    if (position < mSize)
    {
      return mData[position + mOffset];
    }
    else if (mSize > 0)
    {
      /*WLOG() << "TArray:indexOf(" << position
        << ") position provided exceeds size of "
        << mSize << std::endl;
      */
      return mData[(mSize - 1) + mOffset];
    }
    else
    {/*
      ELOG() << "TArray:indexOf(" << position
        << ") array is empty (size is 0)" << std::endl;
       */
      return mData[mOffset];
    }
  }

  template <class TYPE>
  TYPE& TArray<TYPE>::operator[](Uint32 position)
  {
    return indexOf(position);
  }

  template <class TYPE>
  void TArray<TYPE>::transfer(TArray<TYPE>& copy)
  {
    using std::swap;
    swap(mData, copy.mData);
    swap(mSize, copy.mSize);
    swap(mOffset, copy.mOffset);
    swap(mReference, copy.mReference);
  }
} // namespace GExL

#endif // CORE_TARRAY_HPP_INCLUDED

/**
 * @class GExL::TArray
 * @ingroup Core
 * The TArray template class is the template used to create an array of the
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
