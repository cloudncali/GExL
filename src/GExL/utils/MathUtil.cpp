/**
 * Provides several math functions and methods used throughout
 * the GExL namespace.
 *
 * @file include/GExL/utils/MathUtil.hpp
 * @author Jacob Dix
 * @date 20151125 - Initial Release
 */

#include <time.h>
#include <random>
#include <GExL/utils/MathUtil.hpp>
#include <GExL/GExL_types.hpp>
namespace GExL
{
  void setSeed(Uint32 theSeed)
  {
    srand(theSeed);
  }

  Uint32 random(Uint32 theMin, Uint32 theMax)
  {
    return static_cast<GExL::Uint32>(rand() % theMax + theMin);
  }

  void normalizeVector(float& theX, float& theY)
  {
    float anMagnitude = sqrt((theX*theX) + (theY*theY));
    theX = theX / anMagnitude;
    theY = theY / anMagnitude;
  }

  float dotProduct(float& theFirstX, float& theFirstY, float& theSecondX, float& theSecondY)
  {
    return ((theFirstX*theSecondX) + (theFirstY*theSecondY));
  }

}
