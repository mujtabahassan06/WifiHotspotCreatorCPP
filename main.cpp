#include "WifiHotspotCreator.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	WifiHotspotCreator wifi;
	wifi.startHotspot();
	wifi.printStatus();
	char stop = 'n';
	cout<<"Do You Want to Stop Hotspot ( Y | N ) : ";
	cin>>stop;
	while(!(stop == 'y' || stop == 'Y')) {
		if(!(stop == 'n' || stop == 'N')){
			cout<<"Invalid Input"<<endl<<endl;
		}
		cout<<"Do You Want to Stop Hotspot ( Y | N ) : ";
		cin>>stop;
	}
	wifi.stopHotspot();
	cout<<"Press any Key to Exit. . .";
	getch();
	return 0;
}