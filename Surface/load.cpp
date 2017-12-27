//
//  load.cpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "load.hpp"

#include <string>
#include "stb_image.h"

SurfaceLoadError::SurfaceLoadError(
  const std::string_view file,
  const std::string_view reason
) : std::runtime_error(
    std::string("Failed to load surface: \"")
    + file.data()
    + "\": "
    + reason.data()
  ) {}

namespace {
  Surface loadSurface(const std::string_view file, const int bpp) {
    int width, height;
    uint8_t *const data = stbi_load(file.data(), &width, &height, nullptr, bpp);
    if (data == nullptr) {
      throw SurfaceLoadError(file, stbi_failure_reason());
    }
    return Surface(width, height, bpp, width * bpp, data);
  }
}

Surface loadSurface(const std::string_view file) {
  int width, height, bytesPerPixel;
  uint8_t *const data = stbi_load(file.data(), &width, &height, &bytesPerPixel, 0);
  if (data == nullptr) {
    throw SurfaceLoadError(file, stbi_failure_reason());
  }
  return Surface(width, height, bytesPerPixel, width * bytesPerPixel, data);
}

Surface loadSurfaceRGB(const std::string_view file) {
  return loadSurface(file, STBI_rgb);
}

Surface loadSurfaceRGBA(const std::string_view file) {
  return loadSurface(file, STBI_rgb_alpha);
}
