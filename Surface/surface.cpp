//
//  surface.cpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "surface.hpp"

namespace {
  Byte *alloc(const Size width, const Size height, const BytesPerPixel bpp) {
    return static_cast<Byte *>(operator new(width * height * bpp));
  }
}

Surface::Surface()
  : mData(nullptr),
    mPitch(0),
    mWidth(0),
    mHeight(0),
    mBytesPerPixel(0) {}

Surface::Surface(const Size width, const Size height, const BytesPerPixel bpp)
  : mData(alloc(width, height, bpp)),
    mPitch(width * bpp),
    mWidth(width),
    mHeight(height),
    mBytesPerPixel(bpp) {}

Surface::Surface(const Size width, const Size height, const BytesPerPixel bpp, const Byte byte)
  : Surface(width, height, bpp) {
  std::memset(mData.get(), byte, height * mPitch);
}

Surface::Surface(
  const Size width,
  const Size height,
  const BytesPerPixel bpp,
  const Pitch pitch,
  Byte *const data
) : mData(data),
    mPitch(pitch),
    mWidth(width),
    mHeight(height),
    mBytesPerPixel(bpp) {}

Byte *Surface::data() {
  return mData.get();
}

Byte *Surface::data(const Size x, const Size y) {
  return mData.get() + (y * mPitch + x * mBytesPerPixel);
}

Byte *Surface::dataEnd() {
  return mData.get() + (mHeight * mPitch);
}

const Byte *Surface::data() const {
  return mData.get();
}

const Byte *Surface::data(const Size x, const Size y) const {
  return mData.get() + (y * mPitch + x * mBytesPerPixel);
}

const Byte *Surface::dataEnd() const {
  return mData.get() + (static_cast<Pitch>(mHeight) * mPitch);
}

size_t Surface::size() const {
  return std::abs(static_cast<Pitch>(mHeight) * mPitch);
}

Pitch Surface::pitch() const {
  return mPitch;
}

Size Surface::padding() const {
  return mPitch - widthBytes();
}

Size Surface::width() const {
  return mWidth;
}

Size Surface::widthBytes() const {
  return mWidth * mBytesPerPixel;
}

Size Surface::height() const {
  return mHeight;
}

BytesPerPixel Surface::bytesPerPixel() const {
  return mBytesPerPixel;
}
