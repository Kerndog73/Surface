//
//  load.inl
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include <string>
#include "realloc.hpp"

#define STBI_NO_GIF
#define STB_IMAGE_STATIC
#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#define STBI_MALLOC(SIZE) operator new(SIZE)
#define STBI_REALLOC_SIZED(PTR, OLD_SIZE, NEW_SIZE) reallocMem(PTR, OLD_SIZE, NEW_SIZE)
#define STBI_FREE(PTR) operator delete(PTR)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcomma"
#pragma clang diagnostic ignored "-Wunused-function"

#include "stb_image.h"

#pragma clang diagnostic pop

inline SurfaceLoadError::SurfaceLoadError(
  const std::string_view file,
  const std::string_view reason
) : std::runtime_error(
    std::string("Failed to load surface: \"")
    + file.data()
    + "\": "
    + reason.data()
  ) {}

inline Surface loadSurface(const std::string_view file, const int bpp) {
  int width, height;
  uint8_t *const data = stbi_load(file.data(), &width, &height, nullptr, bpp);
  if (data == nullptr) {
    throw SurfaceLoadError(file, stbi_failure_reason());
  }
  return Surface(width, height, bpp, width * bpp, data);
}

inline Surface loadSurface(const std::string_view file) {
  int width, height, bytesPerPixel;
  uint8_t *const data = stbi_load(file.data(), &width, &height, &bytesPerPixel, 0);
  if (data == nullptr) {
    throw SurfaceLoadError(file, stbi_failure_reason());
  }
  return Surface(width, height, bytesPerPixel, width * bytesPerPixel, data);
}

inline Surface loadSurfaceRGB(const std::string_view file) {
  return loadSurface(file, STBI_rgb);
}

inline Surface loadSurfaceRGBA(const std::string_view file) {
  return loadSurface(file, STBI_rgb_alpha);
}
