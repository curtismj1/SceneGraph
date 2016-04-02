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

void SceneGraph::writeLocations(){
	for(vector<transNode>::iterator i = transNodes.begin(); i != transNodes.end(); ++i){
		
	}
}