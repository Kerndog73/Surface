//
//  blit.hpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef surface_blit_hpp
#define surface_blit_hpp

#include <stdexcept>
#include "surface.hpp"

class FormatError final : public std::runtime_error {
public:
  FormatError();
};

void blit(Surface &, const Surface &);
void blit(Surface &, const Surface &, Surface::Size, Surface::Size);

#include "blit.inl"

#endif
