//
//  load surface.hpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef surface_load_hpp
#define surface_load_hpp

#include <stdexcept>
#include <string_view>
#include "surface.hpp"

class SurfaceLoadError final : public std::runtime_error {
public:
  SurfaceLoadError(std::string_view, std::string_view);
};

///Load a surface with the same bytesPerPixel as the file
Surface loadSurface(std::string_view);
///Load a surface with the specified bytesPerPixel
Surface loadSurface(std::string_view, int);
///Load a surface with a bytesPerPixel of 3
Surface loadSurfaceRGB(std::string_view);
///Load a surface with a bytesPerPixel of 4
Surface loadSurfaceRGBA(std::string_view);

#include "load.inl"

#endif
