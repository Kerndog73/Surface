//
//  surface.hpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef surface_hpp
#define surface_hpp

#include <memory>
#include <cstdint>

using Byte = uint8_t;
using Size = uint32_t;
using BytesPerPixel = uint32_t;
using Pitch = int32_t;

class Surface {
public:
  using Data = std::unique_ptr<Byte>;
  
  Surface(Surface &&) = default;
  Surface &operator=(Surface &&) = default;
  
  Surface();
  Surface(Size, Size, BytesPerPixel);
  Surface(Size, Size, BytesPerPixel, Byte);
  Surface(Size, Size, BytesPerPixel, Pitch, Byte *);

  Byte *data();
  Byte *data(Size, Size);
  Byte *dataEnd();
  
  const Byte *data() const;
  const Byte *data(Size, Size) const;
  const Byte *dataEnd() const;

  size_t size() const;
  Pitch pitch() const;
  Size padding() const;
  
  Size width() const;
  Size widthBytes() const;
  Size height() const;
  
  BytesPerPixel bytesPerPixel() const;

private:
  Data mData;
  Pitch mPitch;                  //number of bytes between (x, y) and (x, y+1)
  Size mWidth;                   //width in pixels
  Size mHeight;                  //height in pixels
  BytesPerPixel mBytesPerPixel;  //bytes per pixel
};

#endif
