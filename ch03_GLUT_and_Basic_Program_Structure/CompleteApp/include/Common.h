#ifndef COMMON_H
#define COMMON_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <direct.h>

#define TINYOBJLOADER_IMPLEMENTATION
#include "../Include/TinyOBJ/tiny_obj_loader.h"

#define GLM_SWIZZLE
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "gtx/rotate_vector.hpp"


#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define __FILEPATH__(x) ((std::string(__FILE__).substr(0, std::string(__FILE__).rfind('\\'))+(x)).c_str())

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

#define deg2rad(x) ((x)*((3.1415926f)/(180.0f)))
#define rad2deg(x) ((180.0f) / ((x)*(3.1415926f)))

typedef struct _TextureData
{
	_TextureData() : width(0), height(0), data(0) {}
	int width;
	int height;
	unsigned char* data;
} TextureData;

class Common
{
public:
	
	static void DumpInfo(void);
	static void ShaderLog(GLuint shader);
	static void PrintGLError();
	static TextureData Load_png(const char* path);
	static char** LoadShaderSource(const char* file);
	static void FreeShaderSource(char** srcp);

};

#endif  // COMMON_H
