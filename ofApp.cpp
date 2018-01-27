#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();

	ofEnableLighting();
	this->light.setAmbientColor(ofFloatColor(0.1, 0.1, 0.5, 1.0));
	this->light.setDiffuseColor(ofFloatColor(0.2, 0.2, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.enable();
}

//--------------------------------------------------------------
void ofApp::update() { }

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	this->light.setPosition(this->cam.getPosition());

	float assembly_size = ofGetWidth() > ofGetHeight() ? ofGetWidth() : ofGetHeight();
	int box_size = 30;
	for (int x = -assembly_size / 2 ; x <= assembly_size / 2; x += box_size) {

		for (int y = -assembly_size / 2; y <= assembly_size / 2; y += box_size) {

			for (int z = -assembly_size / 2; z <= assembly_size / 2; z += box_size) {

				float noise_value = ofNoise(ofVec3f(x, y, z).length() * 0.008 - ofGetFrameNum() * 0.03);
				if (noise_value < 0.4) {

					ofDrawBox(ofPoint(x, y, z), box_size, box_size, box_size);
				}
			}
		}
	}

	this->cam.end();
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}