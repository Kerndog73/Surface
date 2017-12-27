//
//  write.hpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef surface_write_hpp
#define surface_write_hpp

#include <stdexcept>
#include "surface.hpp"
#include <string_view>

#pragma GCC visibility push(default)

class SurfaceWriteError final : public std::runtime_error {
public:
  explicit SurfaceWriteError(std::string_view);
};

void writeSurface(std::string_view, const Surface &);

#pragma GCC visibility pop

#endif
