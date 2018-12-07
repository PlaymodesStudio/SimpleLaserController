#include "ofApp.h"
#include "graphicPatternGenerator.h"
#include "ildaController.h"
#include "positionsSaver.h"
#include "vector_op_registrator.h"
#include "scriptModule.h"
#include "scriptModule.h"
#include "valueEaser.h"
#include "midiGateIn.h"
#include "envelopeGenerator.h"
#include "delta.h"
#include "vectorItemOperations.h"
#include "positionsCreator.h"
#include "positionsRotator.h"
#include "vectorModulator.h"
#include "manualOscillatorBank.h"

#include "ofxOceanodeBPMController.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetEscapeQuitsApp(false);
    ofDisableArbTex();
    ofSetVerticalSync(false);
    ofSetFrameRate(120);
    
    auto reg = make_shared<ofxOceanodeNodeRegistry>();
    auto treg = make_shared<ofxOceanodeTypesRegistry>();
    reg->registerModel<graphicPatternGenerator>("ESPILLS");
    reg->registerModel<ildaController>("ESPILLS");
    reg->registerModel<positionSaver>("ESPILLS");
    reg->registerModel<scriptModule>("Scripting");
    reg->registerModel<midiGateIn>("Midi");
    reg->registerModel<envelopeGenerator>("Midi");
    reg->registerModel<delta>("OP");
    reg->registerModel<positionsCreator>("ESPILLS");
    reg->registerModel<positionsRotator>("ESPILLS");
    reg->registerModel<vectorModulator>("Mirrors");
    reg->registerModel<valueEaser>("Easing");
    reg->registerModel<manualOscillatorBank>("Generators");
    
    registerVectorOp(reg);
    treg->registerType<vector<pair<ofPolyline, ofColor>>>();
    treg->registerType<vector<ofPoint>>();
    
    container = make_shared<ofxOceanodeContainer>(reg, treg);
    canvas.setContainer(container);
    canvas.setup();
    
    controls = new ofxOceanodeControls(container);
    controls->get<ofxOceanodeBPMController>()->setBPM(80);
    
    container->loadPersistent();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofGetFrameRate(), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(ofGetKeyPressed(OF_KEY_COMMAND)){
        if(key == 'c'){
            container->collapseGuis();
        }else if(key == 'e'){
            container->expandGuis();
        }
    }
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
