#include "realloc.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#define STBI_MALLOC(SIZE) operator new(SIZE)
#define STBI_REALLOC_SIZED(PTR, OLD_SIZE, NEW_SIZE) reallocMem(PTR, OLD_SIZE, NEW_SIZE)
#define STBI_FREE(PTR) operator delete(PTR)

#include "stb_image.h"
