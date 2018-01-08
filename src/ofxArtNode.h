#pragma once

#include "ofMain.h"
#include "ArtNode.h"
#include "ofxArtDmx.h"
#include "ofxUDPManager.h"

class ofxArtNode : public ArtNode {
public:
	void setup(string host = "2.255.255.255");

	void update();

	int getNumNodes();
	ArtPollReply * getNode(int index);
	string getNodeIp(int index);
    void clearNodes();
    
    
	void sendPoll();
	void sendDmx(ArtDmx * dmx);
	void sendSync();
    
    void setNodeAddress(int index, int universe, string shortName, string longName);

	ofxArtDmx * createArtDmx(int net, int sub, int universe);

	void sendMultiCast(char * data, int length);
	void sendMultiCast();
	bool sendUniCast(int net, int subnet, int universe, char * data, int length);
	bool sendUniCast(int net, int subnet, int universe);
    bool sendUniCast(int index);


	bool readyFps(float frameRate);
	void doneFps();

//protected:
	ofxUDPManager udp;
	map<string,ArtPollReply> nodes;
	uint64_t lastFrameTime;

	string getBroadcastIp();
};
