//
//  Doodle.h
//  Lemur
//
//  Created by Omer Shapira on 07/07/13.
//
//

#pragma once
#include "Drawable.h"

class Doodle : public Drawable {
    ofPolyline bounds;
public:
  
    
    void setBounds(ofPolyline& l){
        bounds = l;
    }
    
    
};