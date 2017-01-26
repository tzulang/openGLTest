#pragma once

#include <string>
#include <glm\glm.hpp>
#include <iostream>
#include <glm/gtx/string_cast.hpp>

typedef std::string String;
typedef glm::vec2 Vec2;
typedef glm::vec3 Vec3;
typedef glm::vec4 Vec4;
typedef glm::mat4 Tmat;

#define FAILURE 1
#define SUCCESS 0
#define GLEW_STATIC


enum RotationAngles { YAW=0, PITCH  , ROLL };
enum Direction { FORWARD=0, BACKWARD,LEFT, RIGHT, UP, DOWN };


struct AbsoluteDirections {	
		Vec3 forward;
		Vec3 up;
	};
	
static AbsoluteDirections absoluteDirections={Vec3(0.0f,0.0f,-1.0f), Vec3(0.0f,1.0f,0.0f)};


class Print
{
public:
	static inline String toString(Vec3 &v){

			return String ("{" +  std::to_string(v.x)+", " +std::to_string(v.y) + ", "+ std::to_string(v.z) + "}" );
	}
};

