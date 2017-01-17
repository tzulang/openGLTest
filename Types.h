#pragma once

#include <string>
#include <glm\glm.hpp>

typedef std::string String;
typedef glm::vec2 Vec2;
typedef glm::vec3 Vec3;
typedef glm::vec4 Vec4;
typedef glm::mat4 Tmat;

#define FAILURE 1
#define SUCCESS 0
#define GLEW_STATIC


enum RotationAngles { YAW=0, PITCH  , ROLL };
enum Direction { UP=0, DOWN, FORWARD, BACKWARD,LEFT, RIGT };