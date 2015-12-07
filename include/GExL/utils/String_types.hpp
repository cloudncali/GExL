/**
* Provides types for string manipulation.
*
* @file include/GExL/utils/String_types.hpp
* @author Jacob Dix
* @date 20151202 - Initial Release
*/
  #include <GExL/utils/TParser.hpp>
  namespace GExL
  {
	  
  /// Forward declare TParser types and cause them to be instantiated
  typedef GExL_API TParser<bool>   BoolParser;   ///< Boolean parser class
  typedef GExL_API TParser<Int8>   Int8Parser;   ///< 8 bit signed integer parser class
  typedef GExL_API TParser<Int16>  Int16Parser;  ///< 16 bit signed integer parser class
  typedef GExL_API TParser<Int32>  Int32Parser;  ///< 32 bit signed integer parser class
  typedef GExL_API TParser<Int64>  Int64Parser;  ///< 64 bit signed integer parser class
  typedef GExL_API TParser<Uint8>  Uint8Parser;  ///< 8 bit unsigned integer parser class
  typedef GExL_API TParser<Uint16> Uint16Parser; ///< 16 bit unsigned integer parser class
  typedef GExL_API TParser<Uint32> Uint32Parser; ///< 32 bit unsigned integer parser class
  typedef GExL_API TParser<Uint64> Uint64Parser; ///< 64 bit unsigned integer parser class
  typedef GExL_API TParser<float>  FloatParser;  ///< floating point parser class
  typedef GExL_API TParser<double> DoubleParser; ///< double floating point parser class
  }
  /**
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
