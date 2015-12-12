/**
 * Provides the templatized data type of singely linked list.
 *
 * @file include/GExL/Core/templates/TList.hpp
 * @author Ryan Lindeman
 * @date 20140912 - Initial Release
*/
#ifndef   CORE_TLIST_HPP_INCLUDED
#define   CORE_TLIST_HPP_INCLUDED

#include <GExL/GExL_types.hpp>
#include <GExL/logger/Log_macros.hpp>
#include <new>

namespace GExL
{
  // Forward declare the TList class used in TListElement below
  template <class T>
  class TList;

  /**
   * @brief Provides the list element container for the fundamental single
   * linked list data structure in a templatized format.
   * @details Provides a robust list element container for the fundamental
   * single linked list implementation for the TYPE specified.
   * Example usage:
   *   see @ref TList
   */
  template <class TYPE>
  class TListElement
  {
  public:
    /** Return reference to the element item in this linked list element.
     * @return TYPE constant reference to the item this linked list element points to
     */
    TYPE const& item() const;

    /** Return constant pointer to the next linked list element in the list.
     * @return TListElement constant pointer to next linked list element in the
     * list.
     */
    TListElement const* next() const;

  private:
    /** Constructor for creating TListElement instances which can only be
     * called by the TList friend class.
     * @param[in] item constant reference to item in linked list
     * @param[in] next pointer to next list element item in linked list
     */
    TListElement(TYPE const& item, TListElement* next = 0);

    /** The element item in the linked list
     */
    TYPE mItem;

    /** The next element in the linked list
     */
    TListElement* mNext;

    /** Only allow the TList class to create list elements */
    friend TList<TYPE>;
  }; // class TListElement

  /**
   * @brief Provides the fundamental single linked list data structure in a
   * templatized format.
   * @details Provides a robust single linked list implementation for the
   * TYPE specified.
   * Example usage:
   *   GExL::TList<int> intlist;
   *
   *   for(GExL::Uint32 i=0; i<10; ++i)
   *     intlist.append(i);
   *
   *   GExL::TListElement<int> const* ptr;
   *   for(ptr = intlist.head(); ptr != 0; ptr = ptr->next())
   *     printf("%d\n", ptr->item());
   */
  template <class TYPE>
  class TList
  {
  public:
    /** Default constructor creates a TList of 0 elements in size
     */
    TList();

    /** Destructor for array will delete the array if not a reference array.
     */
    virtual ~TList();
    
    /** Copy constructor for linked list
     * @param[in] copy of TList to be copied in this constructor
     */
    TList(TList<TYPE> const& copy);
    
    /** Assignment operator for linked list
     * @param[in] right side reference of assignment operator
     * @return TList reference to left side of assignment operator
     */
    TList& operator=(TList const& right);
    
    /** Retrieve the head list element at the beginning of the linked list
     * @return TListElement<TYPE>
     *   head list element at the beginning of the linked list or 0 if empty
     */
    TListElement<TYPE> const* head() const;

    /** Retrieve the tail list element at the end of the linked list
     * @return TListElement<TYPE>
     *   tail list element at the end of the linked list or 0 if empty
     */
    TListElement<TYPE> const* tail() const;

    /** Determine if the linked list contains no elements
     * @return bool
     *   - true if linked list contains no elements
     *   - false if linked list contains one or more elements
     */
    bool isEmpty() const;

    /** Append the item provided to the end of the linked list
     * @param[in] item to add to the end of the linked list
     */
    void append(TYPE const& item);

    /** Append the item provided to the beginning of the linked list.
     * @param[in] item to add to the beginning of the linked list
     */
    void prepend(TYPE const& item);

    /** Delete all list elements in the linked list (not the items
     * themselves)
     */
    void clear();

    /** Remove the list element that matches the item provided.
     * @param[in] item to match against each list element in the list
     * @return true if item found and removed, false otherwise
     */
    bool remove(TYPE const& item);

    /** Inserts the item provided after the list element provided.
     * @param[in] element add item after
     * @param[in] item to add as a new list element after element specified
     */
    void insertAfter(TListElement<TYPE> const* element, TYPE const& item);

    /** Inserts the item provided before the list element provided.
     * @param[in] element add item before
     * @param[in] item to add as a new list element before element specified
     */
    void insertBefore(TListElement<TYPE> const* element, TYPE const& item);

  private:
    /** The head of the linked list for easy prepending to the linked list
     */
    TListElement<TYPE>* mHead;

    /** The tail of the linked list for easy appending to the linked list
     */
    TListElement<TYPE>* mTail;
  }; // class TList

  /////////////////////////////////////////////////////////////////////////////
  // Template implementation details
  /////////////////////////////////////////////////////////////////////////////
  template <class TYPE>
  TListElement<TYPE>::TListElement(TYPE const& item, TListElement<TYPE>* next) :
    mItem(item),
    mNext(next)
  {
  }

  template <class TYPE>
  TYPE const& TListElement<TYPE>::item() const
  {
    return mItem;
  }

  template <class TYPE>
  TListElement<TYPE> const* TListElement<TYPE>::next() const
  {
    return mNext;
  }

  template <class TYPE>
  TList<TYPE>::TList() :
    mHead(0),
    mTail(0)
  {
  }

  template <class TYPE>
  TList<TYPE>::~TList()
  {
    // Clear the linked list of all its elements
    clear();
  }

  template <class TYPE>
  TList<TYPE>::TList(TList<TYPE> const& copy) :
    mHead(0),
    mTail(0)
  {
    TListElement<TYPE> const* ptr;
    for(ptr = copy.mHead; ptr != 0; ptr = ptr->mNext)
    {
      append(ptr->mItem);
    }
  }

  template <class TYPE>
  TList<TYPE>& TList<TYPE>::operator=(TList<TYPE> const& right)
  {
    // If not self reference then copy new array into existing array
    if(this != &right)
    {
      // Clear current list of items
      clear();
      TListElement<TYPE> const* ptr;
      for(ptr = right.mHead; ptr != 0; ptr = ptr->mNext)
      {
        append(ptr->mItem);
      }
    }
    return *this;
  }

  template <class TYPE>
  TListElement<TYPE> const* TList<TYPE>::head() const
  {
    return mHead;
  }

  template <class TYPE>
  TListElement<TYPE> const* TList<TYPE>::tail() const
  {
    return mTail;
  }

  template <class TYPE>
  bool TList<TYPE>::isEmpty() const
  {
    return mHead == 0;
  }

  template <class TYPE>
  void TList<TYPE>::append(TYPE const& item)
  {
    TListElement<TYPE>* const tmp = new (std::nothrow) TListElement<TYPE>(item);
    if(mHead == 0)
    {
      mHead = tmp;
    }
    else
    {
      mTail->mNext = tmp;
    }
    mTail = tmp;
  }

  template <class TYPE>
  void TList<TYPE>::prepend(TYPE const& item)
  {
    TListElement<TYPE>* const tmp = new (std::nothrow) TListElement<TYPE>(item, mHead);
    if(mHead == 0)
    {
      mTail = tmp;
    }
    mHead = tmp;
  }

  template <class TYPE>
  void TList<TYPE>::clear()
  {
    while(mHead != 0)
    {
      TListElement<TYPE>* const tmp = mHead;
      mHead = mHead->mNext;
      delete tmp;
    }
    mTail = 0;
  }

  template <class TYPE>
  bool TList<TYPE>::remove(TYPE const& item)
  {
    // Default to item not found
    bool found = false;

    TListElement<TYPE>* ptr = mHead;
    TListElement<TYPE>* prevPtr = 0;
    while(ptr != 0 && ptr->mItem != item)
    {
      prevPtr = ptr;
      ptr = ptr->mNext;
    }
    if(ptr != 0)
    {
      // Item was found
      found = true;

      // Is the item found at the head of the linked list?
      if(ptr == mHead)
      {
        // Point head to next item in the list
        mHead = ptr->mNext;
      }
      else
      {
        // Remove this item from the middle of the linked list
        prevPtr->mNext = ptr->mNext;
      }
      // Is the item found at the tail of the linked list?
      if(ptr == mTail)
      {
        // Fix tail pointer if item was the last item in the list
        mTail = prevPtr;
      }
      // Delete the detached item
      delete ptr;
    }
    else
    {
      // item provided was not found in the list, need to throw/log an warning
      WLOG() << "TList:remove() item not found!" << std::endl;
    }

    // Return found and removed status
    return found;
  }

  template <class TYPE>
  void TList<TYPE>::insertAfter(TListElement<TYPE> const* element, TYPE const& item)
  {
    TListElement<TYPE>* ptr = const_cast<TListElement<TYPE>*>(element);
    if(ptr != 0)
    {
      TListElement<TYPE>* const tmp = new (std::nothrow) TListElement<TYPE>(item, ptr->mNext);
      ptr->mNext = tmp;
      if(mTail == ptr)
      {
        mTail = tmp;
      }
    }
  }

  template <class TYPE>
  void TList<TYPE>::insertBefore(TListElement<TYPE> const* element, TYPE const& item)
  {
    TListElement<TYPE>* ptr = const_cast<TListElement<TYPE>*>(element);
    if(ptr != 0)
    {
      // Create new list element for the item provided
      TListElement<TYPE>* const tmp = new (std::nothrow) TListElement<TYPE>(item, ptr);

      // The element provided was the head so update the head
      if(mHead == ptr)
      {
        mHead = tmp;
      }
      else
      {
        // Find previous linked list element that matches the element provided
        TListElement<TYPE>* prevPtr = mHead;
        while(prevPtr != 0 && prevPtr->mNext != ptr)
        {
          prevPtr = prevPtr->mNext;
        }
        if(prevPtr != 0)
        {
          prevPtr->mNext = tmp;
        }
        else
        {
          // element provided wasn't found, need to throw/log an error here
          ELOG() << "TList:insertBefore() before element provided not found"
            << std::endl;
        }
      }
    }
  }

} // namespace GExL

#endif // CORE_TLIST_HPP_INCLUDED

/**
 * @class GExL::TList
 * @ingroup Core
 * The TList template class is the template used to create a singly linked list
 * of the type provided.
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
