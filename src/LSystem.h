//
//  LSystem.h
//  Lemur
//
//  Created by Omer Shapira on 03/07/13.
//
//

#pragma once
#include "ofMain.h"
#define UNIT 0.1
#define ZROT 30

using namespace Lemur;

class LSystem : public Drawable {
    
    class matrixStack {
        stack<ofMatrix4x4> _stack;
        ofMatrix4x4 current;
    public:
        matrixStack(){
            clear();
        }
        void push(){
            _stack.push(current);
            current = ofMatrix4x4(current);
        }
        void pop(){
            if (_stack.size() > 0) {
                current = _stack.top();
                _stack.pop();
            }}
        void clear(){
            while(!_stack.empty()){
                _stack.pop();
            }
            current =  ofMatrix4x4::newIdentityMatrix();
        }
        ofPoint getPoint(ofPoint p){return current.preMult(p);}
        inline void translate(const ofVec3f& v){current.translate(v);}
        inline void rotate(float angle){current.rotate(angle,0,0,1);}
        inline void scale(const ofVec3f& v){current.scale(v);}
    };
    
    ofPoint start;
    string rule;
    vector<std::string> stages;
    matrixStack _mtx;
    bool changed;
    int level;
public:
    
    LSystem(){
//        rule = "F[-F]F+F";
        rule = "F+F";
        stages.push_back(string("F"));
        setup();
    }
    
    void setup(){
        //    default setup for all drawables
        start = ofPoint(0.5, 0.2);
        setLevel(1);
        setTime(0);
    }
    
    string extendString(string s){
        //Takes a copy of the string!
        int i = 0;
        while(i < s.size()) {
            if (s[i]==*"F"){
                //TODO: Make this a fully-specified L-System ruleset
                s.erase(i,1);
                s.insert(i,rule);
                i += rule.size();
            }
            i++;
        }
        return s;
    }
    
    void setLevel(int l){
        level = l;
        changed = true;
    }
    
    void growToStage(int i){
        if (stages.size() < i){
            //if it's at size i, then index i is the next one. if not, recurse
            growToStage(i - 1);
        }
        //stage size will change
        if(stages.size() == i) {
            stages.push_back(extendString(stages[i - 1]));
        }
    }
    
    void setTime(float t){
        //Does nothing for now
        toPolys();
    }
    
    
private:
    
    void toPolys(){
        if ((changed) || (stages.size() >= level + 1)){
            polys.clear();
            //FIXME: Right now this evaluates to the previous level if no change has been made.
            if (stages.size() < level + 1){
                growToStage(level);
            }
            stack<int> counters;
            int stackCounter = 0;
            string& s = stages[level];
            cout << level       << endl;
            cout << s.size()    << endl;
            cout << s           << endl;
            
            _mtx.translate(start);
            
            for (int j = 0 ; j<s.size() ; j++) {
                switch (s[j]) {
                    case '[':
                    {
                        _mtx.push();
                        counters.push(stackCounter);
                        stackCounter = 0;
                        break;
                    }
                    case ']':
                    {
                        while (stackCounter>0) {
                            _mtx.pop();
                            stackCounter--;
                        }
                        stackCounter=counters.top();
                        counters.pop();
//                        _mtx.push();
                        break;
                    }
                    case '+':
                    {
                        _mtx.rotate(ZROT);
                        stackCounter++;
                        _mtx.push();
                        break;
                    }
                    case '-':
                    {
                        _mtx.rotate(-ZROT);
                        stackCounter++;
                        _mtx.push();
                         break;
                    }
                    case 'F':
                    {
                        //float damper = icon? 1 : (float) (Math.pow(scale, depth));
                        //strokeWeight(w*damper);

                        ofxIlda::Poly p;
                        p.lineTo(_mtx.getPoint(ofVec3f(0,0,0)));
                        cout << _mtx.getPoint(ofVec3f(0,0,0))<<endl;
                        p.lineTo(_mtx.getPoint(ofVec3f(0,UNIT,0)));
                        polys.push_back(p);
                        
                        _mtx.translate(ofVec3f(0, UNIT, 0));
                        _mtx.push();
                        stackCounter++;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
            _mtx.clear();
        }
    }
    
    
};