

#ifndef FacadePattern_hpp
#define FacadePattern_hpp

#include<iostream>

using namespace std;
using std::string;

class Tuner
{
public:
    void on()
    {
        cout << "Tuner on" << endl;
    }
    void off()
    {
        cout << "Tuner off" << endl;
    }
    void setAm()
    {
        cout << "setAm" << endl;
    }
    void setFm()
    {
        cout << "setFm" << endl;
    }
};

class Screen
{
public:
    void up()
    {
        cout << "screen up" << endl;
    }
    void down()
    {
        cout << "screen down" << endl;
    }
};

class Amplifier
{
public:
    void on()
    {
        cout << "Ampli on" << endl;
    }
    void off()
    {
        cout << "Ampli on" << endl;
    }
    void setStereoSound()
    {
        cout << "set Stereo Sound" << endl;
    }
    void setSurroundSound()
    {
        cout << "set Surround Sound" << endl;
    }
    void setVolume()
    {
        cout << "set Volume" << endl;
    }
};
class CdPlayer
{
public:
    void on()
    {
        cout << "CD on" << endl;
    }
    void off()
    {
        cout << "CD off" << endl;
    }
    void eject()
    {
        cout << "CD eject" << endl;
    }
    void pause()
    {
        cout << "CD pause" << endl;
    }
    void play()
    {
        cout << "CD play" << endl;
    }
    void stop()
    {
        cout << "CD stop" << endl;
    }
};


class HomeTheaterFacade
{
public:
    Tuner* mTuner;
    CdPlayer* mCdPlayer;
    Amplifier* mAmplifier;
    Screen* mScreen;

    HomeTheaterFacade(Tuner* tuner , CdPlayer* cdPlayer, Amplifier* amplifier, Screen* screen)
    {
        mTuner = tuner;
        mCdPlayer = cdPlayer;
        mAmplifier = amplifier;
        mScreen = screen;
    }

    void watchMovie()
    {
        cout << "Get ready to watch movie!" << endl;
        mCdPlayer->on();
        mAmplifier->on();
        mScreen->up();
    }
    
    void endMovie()
    {
        cout << "Shutting movie theater down..." << endl;
        mAmplifier->off();
        mCdPlayer->off();
        mScreen->down();
    }

    void listenToRadio()
    {
        cout << "Tuning in the airwaves..." << endl;
        mTuner->on();
        mAmplifier->on();
    }

    void endRadio()
    {
        cout << "Shutting down the tuner..." << endl;
        mTuner->off();
        mAmplifier->off();
    }
};

#endif
