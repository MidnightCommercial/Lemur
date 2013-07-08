//
//  LemurUtils.h
//  Lemur
//
//  Created by Omer Shapira on 08/07/13.
//
//
#pragma once

namespace Lemur {
    
    //TODO: ofParameter does this much better.
    template<typename T>
    class Property{
        T _value;
        string _name;
    public:
        Property(string name="Unnamed Property"): _name(name){}
        
        T operator()(){ return _value; }
        T & operator=(const T &rhs){
            _value = rhs;
        }
        
                string getString(){
                    ostringstream output;
                    output<<ofToString(_name)<<" : "<<ofToString(_value);
                    return output.str();
                }
        
        //TODO: Complete operator overloading
        friend ostream& operator<<(ostream&, const Lemur::Property<T>&);
    };
    
}

//template<typename T>
//ostream& operator<<(ostream& strm, const Lemur::Property<T>& t) {
//    strm << t._name <<" : "<< t.value;
//    return strm;
//    }

    
    namespace Lemur{
        typedef Property<float> LFloat;
        typedef Property<int>   LInt;
        typedef Property<string> LString;
    }

    
