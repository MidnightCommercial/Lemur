//
//  SVGPath.cpp
//  Lemur
//
//  Created by Omer Shapira on 01/07/13.
//
//

#include "SVGPath.h"


void SVGPath::loadFile(string _filepath){
    filepath = _filepath;
    ofxSVG svg;
    svg.load(filepath);
    float ratio = MAX(svg.getWidth(), svg.getHeight());
    for (int i = 0 ; i < svg.getNumPath(); i++){
        //TODO: use a different method of copying these once you get comfortable with this code (OmerShapira)
        //TODO: Now comes the point where you actually need to convert ofPath to ofPoly (OmerShapira)
        ofPath path = svg.getPathAt(i);
        //TODO: Make sure this isn't destructive. generatePolylinesFromPaths is not the only thing that happens there (OmerShapira)
        path.setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector<ofPolyline>& polylines = path.getOutline();
        for (int j = 0; j < polylines.size(); j++) {
            ofxIlda::Poly p1;
            vector<ofVec3f> pts = polylines[j].getVertices();
            for(int i = 0; i < pts.size(); i++){
                p1.addVertex(ofPoint(pts[i].x/ratio, pts[i].y/ratio));
            }
            p1 = p1.getResampledByCount(1500);
            p1.color = svg.getPathAt(i).getFillColor();
            polys.push_back(p1);
        }
    }
    //TODO: Check if the file is really disposed now - we're not supposed to need it anymore (OmerShapira)
}

void SVGPath::draw(){
    for(int i = 0; i < polys.size(); i++){
        polys[i].draw();
    }
}