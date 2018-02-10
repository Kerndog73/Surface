//
//  surface.inl
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

inline Surface::Surface()
  : mData(nullptr),
    mPitch(0),
    mWidth(0),
    mHeight(0),
    mBytesPerPixel(0) {}

inline Surface::Surface(const Size width, const Size height, const BytesPerPixel bpp)
  : mData(static_cast<Surface::Byte *>(operator new(width * height * bpp))),
    mPitch(width * bpp),
    mWidth(width),
    mHeight(height),
    mBytesPerPixel(bpp) {}

inline Surface::Surface(const Size width, const Size height, const BytesPerPixel bpp, const Byte byte)
  : Surface(width, height, bpp) {
  std::memset(mData.get(), byte, height * mPitch);
}

inline Surface::Surface(
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

inline Surface::Byte *Surface::data() {
  return mData.get();
}

inline Surface::Byte *Surface::data(const Size x, const Size y) {
  return mData.get() + (y * mPitch + x * mBytesPerPixel);
}

inline Surface::Byte *Surface::dataEnd() {
  return mData.get() + (mHeight * mPitch);
}

inline const Surface::Byte *Surface::data() const {
  return mData.get();
}

inline const Surface::Byte *Surface::data(const Size x, const Size y) const {
  return mData.get() + (y * mPitch + x * mBytesPerPixel);
}

inline const Surface::Byte *Surface::dataEnd() const {
  return mData.get() + (static_cast<Pitch>(mHeight) * mPitch);
}

inline size_t Surface::size() const {
  return std::abs(static_cast<Pitch>(mHeight) * mPitch);
}

inline Surface::Pitch Surface::pitch() const {
  return mPitch;
}

inline Surface::Size Surface::padding() const {
  return mPitch - widthBytes();
}

inline Surface::Size Surface::width() const {
  return mWidth;
}

inline Surface::Size Surface::widthBytes() const {
  return mWidth * mBytesPerPixel;
}

inline Surface::Size Surface::height() const {
  return mHeight;
}

inline Surface::BytesPerPixel Surface::bytesPerPixel() const {
  return mBytesPerPixel;
}
