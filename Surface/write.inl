//
//  write.inl
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include <string>
#include "realloc.hpp"

#define STB_IMAGE_WRITE_STATIC
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_MALLOC(SIZE) operator new(SIZE)
#define STBIW_REALLOC_SIZED(PTR, OLD_SIZE, NEW_SIZE) reallocMem(PTR, OLD_SIZE, NEW_SIZE)
#define STBIW_FREE(PTR) operator delete(PTR)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcomma"
#pragma clang diagnostic ignored "-Wunused-function"

#include "stb_image_write.h"

#pragma clang diagnostic pop

inline SurfaceWriteError::SurfaceWriteError(const std::string_view file)
  : std::runtime_error(
      std::string("Failed to write surface to file \"")
      + file.data()
      + "\""
    ) {}

inline void writeSurface(const std::string_view file, const Surface &surface) {
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
