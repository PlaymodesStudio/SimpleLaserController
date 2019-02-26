//
//  polylinesSVGRenderer.h
//  SimpleLaserController
//
//  Created by Eduard Frigola Bagué on 26/02/2019.
//

#ifndef polylinesSVGRenderer_h
#define polylinesSVGRenderer_h

#include "ofxOceanodeNodeModelExternalWindow.h"

class polylinesSVGRenderer : public ofxOceanodeNodeModelExternalWindow{
public:
    polylinesSVGRenderer() : ofxOceanodeNodeModelExternalWindow("Polylines SVG Renderer"){};
    
    void setup();
private:
    void drawInExternalWindow(ofEventArgs &a);
    
    ofParameter<vector<pair<ofPolyline, ofColor>>> polylinesIn;
    ofParameter<int> width;
    ofParameter<int> height;
    ofParameter<bool> invert;
    ofParameter<void> renderButton;
    
    ofEventListeners listeners;
    bool renderActive;
    };

#endif /* polylinesSVGRenderer_h */
