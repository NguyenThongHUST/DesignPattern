
#include<iostream>
#include<string>
#include"FacadePattern.h"


int main()
{
	Tuner* tuner = new Tuner();
	Amplifier* amp = new Amplifier();
	CdPlayer* cdplayer = new CdPlayer();
	Screen* screen = new Screen();

	HomeTheaterFacade* home = new HomeTheaterFacade(tuner, cdplayer, amp, screen);

	home->watchMovie();
	cout << "******" << endl;
	home->endMovie();
	cout << "******" << endl;
	home->listenToRadio();
	cout << "******" << endl;
	home->endRadio();
	return 0;
}
