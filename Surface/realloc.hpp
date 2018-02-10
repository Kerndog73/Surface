//
//  realloc.hpp
//  Surface
//
//  Created by Indi Kernick on 27/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef surface_realloc_hpp
#define surface_realloc_hpp

#include <cstring>

inline void *reallocMem(void *const ptr, const size_t oldSize, const size_t newSize) {
  void *const newPtr = operator new(newSize);
  std::memcpy(newPtr, ptr, oldSize);
  operator delete(ptr);
  return newPtr;
}

#endif
