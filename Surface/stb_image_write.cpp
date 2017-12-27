#include "realloc.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_MALLOC(SIZE) operator new(SIZE)
#define STBIW_REALLOC_SIZED(PTR, OLD_SIZE, NEW_SIZE) reallocMem(PTR, OLD_SIZE, NEW_SIZE)
#define STBIW_FREE(PTR) operator delete(PTR)

#include "stb_image_write.h"
