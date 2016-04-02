#include <iostream>
#include <fstream>
#include "SceneGraph.h"
#include "glm\gtx\transform.hpp"

using glm::vec3;
using glm::vec4;
using glm::mat4;
using namespace std;

const int NUM_OF_FILES = 2;

int main(){
	vector<string> files;
	files.push_back("scene1.txt");
	files.push_back("scene2.txt");
	SceneGraph myGraph(files);

	return 0;
}
