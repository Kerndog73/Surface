//
//  blit.cpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "blit.hpp"

FormatError::FormatError()
  : std::runtime_error("Cannot blit surfaces with different bytesPerPixel") {}

void blit(Surface &dst, const Surface &src) {
  blit(dst, src, 0, 0);
}

void blit(Surface &dst, const Surface &src, const Surface::Size srcX, const Surface::Size srcY) {
  if (dst.bytesPerPixel() != src.bytesPerPixel()) {
    throw FormatError();
  }

  const ptrdiff_t dstPitch = dst.pitch();
  const ptrdiff_t srcPitch = src.pitch();
  const size_t width = src.widthBytes();
  uint8_t *dstRow = dst.data(srcX, srcY);
  const uint8_t *srcRow = src.data();
  const uint8_t *const srcEnd = src.dataEnd();
  
  while (srcRow != srcEnd) {
    std::memcpy(dstRow, srcRow, width);
    dstRow += dstPitch;
    srcRow += srcPitch;
  }
}
