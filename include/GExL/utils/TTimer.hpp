/**
* Provides a generic Timer Class.
*
* @file include/GExL/Core/templates/TTimer.hpp
* @author Jacob Dix
* @date 20140912 - Initial Release
*/
#ifndef TTIMER_HPP_INCLUDE
#define TTIMER_HPP_INCLUDE
#include <GExL/GExL_types.hpp>

namespace GExL
{
  /**
  * @brief Provides a generic Timer Class.
  * @details Provides a generic Timer Class using the
  * TYPE specified.
  * Example usage:
  *   GExL::TTimer<int> anTimer;
  *   anTimer.start(anCurrentTicks);
  *   GExL::Uint32 anTicks = anTimer.GetTicks(anCurrentTicks);
  */
  template<class TYPE>
  class TTimer
  {
  public:
    /** Constructor.
    */
    TTimer()
    {
      //Initialize the variables
      mStartTicks = 0;
      mPausedTicks = 0;

      mPaused = false;
      mStarted = false;
    }

    /** start the timer given the current tick.
    * @param[in] the current ticks,
    */
    void start(TYPE theTicks)
    {
      //Start the timer
      mStarted = true;

      //Unpause the timer
      mPaused = false;

      //Get the current clock time
      mStartTicks = theTicks;
      mPausedTicks = 0;
    }
    /** stop the timer and reset values.
    */
    void stop()
    {
      //Stop the timer
      mStarted = false;

      //Unpause the timer
      mPaused = false;

      //Clear tick variables
      mStartTicks = 0;
      mPausedTicks = 0;
    }
    /** pause the timer and start counting pause ticks.
    * @param[in] the current ticks,
    */
    void pause(TYPE theTicks)
    {
      //If the timer is running and isn't already paused
      if (mStarted && !mPaused)
      {
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPausedTicks = theTicks - mStartTicks;
        mStartTicks = 0;
      }
    }

    /** unpause the timer and stop counting pause ticks.
    * @param[in] the current ticks,
    */
    void unpause(TYPE theTicks)
    {
      //If the timer is running and paused
      if (mStarted && mPaused)
      {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = theTicks - mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;
      }
    }
    /** return the amount of ticks passed since start() was called.
    * @param[in] the current ticks,
    * @return the ticks passed.
    */
    TYPE getTicks(TYPE theTicks)
    {
      //The actual timer time
      TYPE time = 0;

      //If the timer is running
      if (mStarted)
      {
        //If the timer is paused
        if (mPaused)
        {
          //Return the number of ticks when the timer was paused
          time = mPausedTicks;
        }
        else
        {
          //Return the current time minus the start time
          time = theTicks - mStartTicks;
        }
      }
      return time;
    }
    /** return wether or not the timer is started.
    * @return a true if the timer is started.
    */
    bool isStarted()
    {
      //Timer is running and paused or unpaused
      return mStarted;
    }
    /** return wether or not the timer is paused.
    * @return a true if the timer is paused.
    */
    bool isPaused()
    {
      //Timer is running and paused
      return mPaused && mStarted;
    }
  private:
    //The clock time when the timer started
    TYPE mStartTicks;

    //The ticks stored when the timer was paused
    TYPE mPausedTicks;

    //The timer status
    bool mPaused;
    bool mStarted;
  };
}
#endif