//
//  Bird.h
//  Lemur
//
//  Created by Omer Shapira on 01/08/13.
//
//

#pragma once
#include "Drawable.h"


class Bird : public Drawable {
    
    
public:
//    ~Bird();
    Bird(ofPoint center=ofPoint(0.5,0.5), float size=0.1, string name="Bird"){
        Drawable::center=center;
        Drawable::size=size;
        Drawable::name=name;
        setup();
    }
    
    
    void setup(){
        polys.push_back(Poly(ofFloatColor(1,1,1,1)));
        polys.push_back(Poly(ofFloatColor(1,1,1,1)));

    }
    
    
    void update(){
        for (int i = 0 ; i<2 ; i++){
            float sgn = (i>0)? 1.0 : -1.0;
            polys[i].clear(); //TODO: find a better way
            polys[i].lineTo(center);
            polys[i].bezierTo(center + ofPoint(sgn * size * 0.5, sin(time * PI * 2.0      ) * 0.2 * size),
                              center + ofPoint(sgn * size * 0.3, sin(time * PI * 2.0 + 0.8) * 0.3 * size),
                              center + ofPoint(sgn * size,       sin(time * PI * 2.0 + 1.2) * 0.5 * size));
        }
        
        
         }	    
    
};