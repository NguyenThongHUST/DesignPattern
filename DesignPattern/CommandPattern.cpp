
#include<iostream>
#include<string>
#include"CommandPattern.h"

using namespace std;

int main()
{
	/*remote1 : LIGHT*/
	Light* light = new Light("Home");
	Command* turnOnLight = new LightOnCommand(light);
	Command* turnOffLight = new LightOffCommand(light);

	RemoteControl* remote1 = new RemoteControl(turnOnLight, turnOffLight);
	remote1->OnButtonWasPressed() ;
	remote1->OnButtonWasPressed();

	/*remote2: STEREO*/
	Stereo* stereo = new Stereo("Living room");
	Command* turnOnStereo = new StereoOnWithCDCommand(stereo);
	Command* turnOffStereo = new StereoOffCommand(stereo);

	RemoteControl* remote2 = new RemoteControl(turnOnStereo, turnOffStereo);
	remote2->OnButtonWasPressed();
	remote2->OffButtonWasPressed();

}