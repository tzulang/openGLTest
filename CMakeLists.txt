cmake_minimum_required (VERSION 2.6)
PROJECT(BuildingYourOwnOpenglApp C CXX)

find_package(OpenGL REQUIRED)

# Ask the user to give the paths to GLFW, GLEW and GLM.
# On Linux this can be found automatically with pkg-config; 
# see http://stackoverflow.com/questions/6889264/cmake-flags-for-opengl-using-glew-and-glfw, for instance.

set(GLFW_INCLUDE_PATH "C:/Development/openGL/glfw-3.2.1-x64/include" )
set(GLFW_LIBRARY "C:/Development/openGL/glfw-3.2.1-x64/lib-mingw-w64/libglfw3.a" )

set(GLEW_INCLUDE_PATH "C:/Development/openGL/glew-2.0.0/include" )
set(GLEW_LIBRARY "C:/Development/openGL/glew-2.0.0/lib/Release/x64/glew32.lib")

set(GLM_INCLUDE_PATH "C:/Development/openGL/glm" )



FILE(GLOB MY_HEADER_FILES
	 
	*.h
)

FILE(GLOB MY_SOURCE_FILES
 
	 *.cpp	
 

)



include_directories(
	${GLFW_INCLUDE_PATH}
	${GLEW_INCLUDE_PATH}
	${GLM_INCLUDE_PATH}
)
add_executable(BuildingYourOwnOpenglApp
	${MY_HEADER_FILES}
	${MY_SOURCE_FILES}
)
target_link_libraries(BuildingYourOwnOpenglApp
	${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
	${GLFW_LIBRARY}
	${GLEW_LIBRARY}
)




 