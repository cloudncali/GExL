  #include <GExL/Config.hpp>
  namespace GExL
  {
  //Basic 2d Vector class.
  template <class TYPE>
  struct Vector2
  {
    explicit Vector2(TYPE theX = 0.0f, TYPE theY = 0.0f) : x(theX), y(theY)
    {}

    TYPE x, y;
    Vector2<TYPE> operator+(Vector2<TYPE> theValue)
    {
      return Vector2<TYPE>(x + theValue.x, y + theValue.y);
    }
    Vector2<TYPE> operator-(Vector2<TYPE> theValue)
    {
      return Vector2<TYPE>(x - theValue.x, y - theValue.y);
    }
  };
  typedef Vector2<float> Vector2f;
  typedef Vector2<int> Vector2i;

  template <class TYPE>
  struct Rect
  {
    Rect(TYPE theX = 0.0f, TYPE theY = 0.0f, TYPE theW = 0.0f, TYPE theH = 0.0f) : x(theX), y(theY), w(theW), h(theH)
    {}
    TYPE x, y, w, h;

    bool intersectRect(Rect<TYPE> OtherRect)
    {
      bool xOverlap = valueInRange(x, OtherRect.x, OtherRect.x + OtherRect.w) ||
        valueInRange(OtherRect.x, x, x + w);

      bool yOverlap = valueInRange(y, OtherRect.y, OtherRect.y + OtherRect.h) ||
        valueInRange(OtherRect.y, y, y + h);

      return xOverlap && yOverlap;
    }
    bool intersectRect(Rect<TYPE> theOtherRect, Vector2<TYPE>& theDepth)
    {
      bool xOverlap = valueInRange(x, theOtherRect.x, theOtherRect.x + theOtherRect.w) ||
        valueInRange(theOtherRect.x, x, x + w);

      bool yOverlap = valueInRange(y, theOtherRect.y, theOtherRect.y + theOtherRect.h) ||
        valueInRange(theOtherRect.y, y, y + h);

      IntRect anIntersection;
      anIntersection.x = std::max(x, theOtherRect.x);
      anIntersection.y = std::max(y, theOtherRect.y);
      anIntersection.w = std::min(x + w, theOtherRect.x + theOtherRect.w) - anIntersection.x;
      anIntersection.h = std::min(y + h, theOtherRect.y + theOtherRect.h) - anIntersection.y;

      theDepth.x = anIntersection.w;
      theDepth.y = anIntersection.h;
      return xOverlap && yOverlap;
    }
  };
  struct FloatRect : Rect<float>
  {
    FloatRect(float theX = 0.0f, float theY = 0.0f, float theW = 0.0f, float theH = 0.0f) : Rect(theX, theY, theW, theH)
    {}
  };
  struct IntRect : Rect<Int32>
  {
    IntRect(Int32 theX = 0, Int32 theY = 0, Int32 theW = 0, Int32 theH = 0) :
      Rect<Int32>(theX,theY,theW,theH)
    {}
  };
  }