#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "WifiHotspotCreator.h"

using namespace std;

WifiHotspotCreator :: WifiHotspotCreator() {
	ifstream ifile("config.ini");
	if(!ifile) {
		cout<<"Enter SSID For Your Network : ";
		cin>>ssid;
		cout<<"Enter Password For Your Network : ";
		cin>>password;
	}
	else{
		ifile>>ssid>>password;
		ifile.close();
	}
	isStarted = false;
}

WifiHotspotCreator :: ~WifiHotspotCreator() {
	ofstream ofile("config.ini");
	ofile<<ssid<<endl<<password;
	ofile.close();
}

void WifiHotspotCreator :: startHotspot() {
	string setWlanNetworkCommand = "netsh wlan set hostednetwork mode=allow ssid=" + ssid + " key=" + password;
	system(setWlanNetworkCommand.c_str());
	system("netsh wlan start hostednetwork");
}

void WifiHotspotCreator :: stopHotspot() {
	system("cls");
	system("netsh wlan stop hostednetwork");
}

void WifiHotspotCreator :: changeSSID(string ssid) {
	this->ssid = ssid;
	startHotspot();
}

void WifiHotspotCreator :: changePassword(string password) {
	this->password = password;
	startHotspot();
}

void WifiHotspotCreator :: printStatus() {
	system("netsh wlan show hostednetwork");
}

