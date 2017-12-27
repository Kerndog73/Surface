//
//  write.cpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "write.hpp"

#include <string>
#include "stb_image_write.h"

SurfaceWriteError::SurfaceWriteError(const std::string_view file)
  : std::runtime_error(
      std::string("Failed to write surface to file \"")
      + file.data()
      + "\""
    ) {}

void writeSurface(const std::string_view file, const Surface &surface) {
  const int success = stbi_write_png(
    file.data(),
    static_cast<int>(surface.width()),
    static_cast<int>(surface.height()),
    static_cast<int>(surface.bytesPerPixel()),
    surface.data(),
    static_cast<int>(surface.pitch())
  );
  
  if (success == 0) {
    throw SurfaceWriteError(file);
  }
}
