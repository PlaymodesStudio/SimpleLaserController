//
//  polylinesSVGRenderer.cpp
//  SimpleLaserController
//
//  Created by Eduard Frigola Bagué on 26/02/2019.
//

#include "polylinesSVGRenderer.h"

void polylinesSVGRenderer::setup(){
    parameters->add(polylinesIn.set("Polylines", {make_pair(ofPolyline(), ofColor())}));
    parameters->add(width.set("Width", 100, 10, 2000));
    parameters->add(height.set("Height", 100, 10, 2000));
    parameters->add(invert.set("Invert", false));
    parameters->add(renderButton.set("Render"));
    
    listeners.push(renderButton.newListener([this](){
        renderActive = true;
    }));
}

void polylinesSVGRenderer::drawInExternalWindow(ofEventArgs &a){
    if(invert) ofBackground(255);
    else ofBackground(0);
    if(renderActive){
        ofBeginSaveScreenAsSVG("TEst.svg");
    }
    ofPushStyle();
    ofPushMatrix();
    ofScale(ofGetWidth(), ofGetHeight());
    ofSetLineWidth(1);
    for(auto line : polylinesIn.get()){
        if(invert) ofSetColor(line.second.invert());
        else ofSetColor(line.second);
        line.first.draw();
    }
    ofPopMatrix();
    ofPopStyle();
    if(renderActive){
        ofEndSaveScreenAsSVG();
    }
    renderActive = false;
}
