#ifndef WIFI_HOTSPOT_CREATOR_H
#define WIFI_HOTSPOT_CREATOR_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

class WifiHotspotCreator {
	private:
		string ssid;
		string password;
		bool isStarted;
	public:
		WifiHotspotCreator();
		~WifiHotspotCreator();
		void startHotspot();
		void stopHotspot();
		void printStatus();
		void changeSSID(string ssid);
		void changePassword(string password);
};

#endif

