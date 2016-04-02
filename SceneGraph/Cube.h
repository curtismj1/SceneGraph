#include "glm\gtx\transform.hpp"

using glm::vec3;
using glm::vec4;
using glm::mat4;

class face{
	public:
		vec3 points[4];
		face(vec3 p1, vec3 p2, vec3 p3, vec3 p4){
			points[0] = p1;
			points[1] = p2;
			points[2] = p3;
			points[3] = p4;
		}
		face(){
		}
};
class cube{
	public:
		face faces[6]; 
		float position;
		cube(){
			//bottom face
			faces[0] = face(vec3(-0.5, -0.5, -0.5), vec3(0.5, -0.5, -0.5), vec3(-0.5, 0.5, -0.5), vec3(0.5, 0.5, -0.5)); 
			//top face
			faces[1] = face(vec3(-0.5, -0.5, 0.5), vec3(0.5, -0.5, 0.5), vec3(-0.5, 0.5, 0.5), vec3(0.5, 0.5, 0.5));
			//left face
			faces[2] = face(vec3(-0.5, -0.5, -0.5), vec3(-0.5, -0.5, 0.5), vec3(-0.5, 0.5, -0.5), vec3(-0.5, 0.5, 0.5)); 
			//right face
			faces[3] = face(vec3(0.5, -0.5, -0.5), vec3(0.5, -0.5, 0.5), vec3(0.5, 0.5, -0.5), vec3(0.5, 0.5, 0.5));
			//front face
			faces[4] = face(vec3(-0.5, -0.5, -0.5), vec3(-0.5, -0.5, 0.5), vec3(0.5, -0.5, -0.5), vec3(0.5, -0.5, 0.5));
			//back face
			faces[4] = face(vec3(-0.5, 0.5, -0.5), vec3(-0.5, 0.5, 0.5), vec3(0.5, 0.5, -0.5), vec3(0.5, 0.5, 0.5));
		}
};

