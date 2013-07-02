//
//  SVGPath.cpp
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#include "SVGPath.h"
#include "ofxIldaPoly.h"

void Lemur::SVGPath::loadFile(string _filepath){
    filepath = _filepath;
    //load an SVG
    ofxSVG svg;
    svg.load(filepath);
    //convert stuff from Polylines to Polys
    //dispose of SVG
    
    for (int i = 0 ; i < svg.getNumPath(); i++){
        //TODO: use a different method of copying these once you get comfortable with this code
        //TODO: Now comes the point where you actually need to convert ofPath to ofPoly
        ofPath path = svg.getPathAt(i); 
        //TODO: Make sure this isn't destructive. generatePolylinesFromPaths is not the only thing that happens there
        vector<ofPolyline>& polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            
            //TODO: Check if this isn't returning a pointer
            
            polys.push_back(ofxIlda::Poly(polylines[j]));
        }
    }
    //And now the stack disposes of the file
}
