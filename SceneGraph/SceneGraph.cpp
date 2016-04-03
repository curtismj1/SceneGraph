#include "SceneGraph.h"

SceneGraph::SceneGraph(vector<string> files){
	ifstream fin;
	for(int i = 0; i < files.size(); i++){
		fin.open(files[i]);
		if(fin.fail()){
			cout << "Couldn't open file " << i << endl;
			return;
		}
		fin >> xsize >> zsize >> numItems;
		while(!fin.eof()){
			transNode temp;
			fin >> temp.geomType;
			fin >> temp.xIndex >> temp.zIndex;
			fin >> temp.rotation;
			fin >> temp.scale.x >> temp.scale.y >> temp.scale.z;
			transNodes.push_back(temp);
		}
		fin.close();
	}
}

void SceneGraph::stackCubes(){
	//get the last cube
	cube test = outCubes[outCubes.size()-1];
	for(int j = outCubes.size() - 2; j > 0; j--){
		if(test.position.x < outCubes[j].position.x + 0.5 && test.position.x > outCubes[j].position.x + 0.5 && test.position.z < outCubes[j].position.z + 0.5
			&& test.position.z > outCubes[j].position.z - 0.5){
				for(int a = 0; a < 6; a ++){
					for(int b = 0; b< 4; b++){
						outCubes[outCubes.size()-1].faces[a].points[b].y = outCubes[j].position.y + 0.5;
					}
				}
			}
	}
}
void SceneGraph::writeLocations(){
	ofstream fout;
	fout.open("output1.txt");
	int index = 1;
	for(vector<transNode>::iterator i = transNodes.begin(); i != transNodes.end(); ++i){
		fout << "Trans " << index << endl;
		index++;
		cube outCube;
		float theta = i->rotation * 3.14159/180.0;
		//verify this is correct rotation matrix
		mat4 rotMatrix(cos(theta), 0.0, sin(theta), 0.0,
			0.0, 1.0, 0.0, 0.0,
			-sin(theta), 0.0, cos(theta), 0.0,
			0.0, 0.0, 0.0, 1.0);
		for(int a = 0; a < 6; a++){
			vec3 points[4];
			face tempFace;
			for(int b = 0; b < 4; b++){
				points[b] = baseCube.faces[a].points[b] * i->scale;
				//question: dealing with vec3 to vec4, do we just add 0.0 to the w val?
				vec4 temp = rotMatrix * vec4(points[b], 0.0);
				tempFace.points[b] = vec3(temp.x + i->xIndex, temp.y, temp.z + i->zIndex);
			}
			outCube.faces[a] = tempFace;
		}
		outCube.position = vec3(i->xIndex, 0.5, i->zIndex);
		outCubes.push_back(outCube);
		stackCubes();
		for(int q = 0; q < 6; q++){
			for(int w = 0; w < 4; w++){
				fout << "X pos: " << outCube.faces[q].points[w].x << " Y Pos: " << outCube.faces[q].points[w].y << " Z Pos: " << outCube.faces[q].points[w].z << endl;
			}
		}
		fout << "x Pos " << outCube.position.x << " Y Pos:" << outCube.position.y << " Z Pos:" <<  outCube.position.z << endl;
	}
}