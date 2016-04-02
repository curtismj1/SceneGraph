#include "glm\gtx\transform.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using glm::vec3;
using glm::vec4;
using glm::mat4;
using namespace std;

struct transNode{
	string geomType;
	float xIndex;
	float zIndex;
	float rotation;
	vec3 scale;
};
class SceneGraph{
public:
	SceneGraph(vector<string> files);
	float xsize;
	float zsize;
	float numItems;
	vector<transNode> transNodes;
	void writeLocations();
};