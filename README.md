Lemur
=====

![Stupid Logo](https://github.com/NoContour/Lemur/blob/master/bin/data/Assets/Lemur.jpg?raw=true)

Lemur is a drawing app based on ofxIlda. It's suitable for any vector-drawing machine, but works on laser projectors.

##Structure:
* Drawables - The program contains Drawables, which are groups of piecewise-polygonal drawings. 'Drawable' is just an interface to ouput ofPolyLines with an input of a time value- but inside, it can be anything. The way we're using them is to generate vector particle systems, and other time-based animations. Right now we have an SVG importer drawable.
* Time Function: Some effects make more sense with timesteps, sin() functions, etc. In order to simplify development, we built chainable time function units, each manipulating values between 0 and 1.
* Behavior: a behavior resides inside a drawable, and reacts to a time value. Harmonic motion can be a behavior, but so can "tween", "simplify" and so on.

## Goals:
We want to make a GUI-Based app, controlled by duration or other OSC inputs, that allows stacking and node-based connection of elements for live performance.

##Dependencies
* [ofxIlda](https://github.com/OmerShapira/ofxIlda): Omer Shapira's fork - for now.
* [ofxEtherdream](https://github.com/memo/ofxEtherdream)
* ofxOsc
* ofxXmlSettings
* [ofxRange](https://github.com/Flightphase/ofxRange)
* [ofxDuration](https://github.com/YCAMInterlab/ofxDuration)
* [ofxUI](https://github.com/rezaali/ofxUI)
