#include "iris_data.h"

#ifndef GUARD_graphLoop
#define GUARD_graphLoop

#include <iostream>
#include <string>
#include <vector>

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void graphLoop(int, char**, std::vector<Iris_data>);

#endif