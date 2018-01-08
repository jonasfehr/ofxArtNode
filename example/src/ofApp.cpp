#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	node.setup();
	node.sendPoll();
}

//--------------------------------------------------------------
void ofApp::update(){

	node.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (node.readyFps(40)) {
		ArtDmx * dmx = node.createDmx();
		dmx->Data[0] = 255;
		node.sendDmx(dmx);
	}
    
    if(node.getNumNodes() > 0){
        string info;
        info += "NumberOfNodes: " + ofToString(node.getNumNodes());
        info += "\nIP           : " + node.getNodeIp(0);
        //        info += "\nSortName     : " + ofToString(artNode.getNode(0)->ShortName);
        //        info += "\nStartChannel : " + ofToString(artNode.getNode(0)->LongName);
        //        info += "\nStartAddress :" + ofToString(artNode.getNode(0)->getPortAddress(0));
        ofDrawBitmapStringHighlight(info, 315, ofGetHeight()-4*15);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
