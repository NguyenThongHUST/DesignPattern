

#ifndef CommandPattern_hpp
#define CommandPattern_hpp

#include<iostream>
#include<string>

using std::string;
using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};


class Light
{
private:
    string mLocation;
public:
    Light(string location)
    {
        mLocation = location;
    }

    void on()
    {
        cout << mLocation << " light is on" << endl;
    }

    void off()
    {
        cout << mLocation << " light off" << endl;
    }
};

class Stereo
{
public:
    string mLocation;

    Stereo(string location)
    {
        mLocation = location;
    }
    void on()
    {
        cout << mLocation << " stereo is on" << endl;
    }

    void off()
    {
        cout << mLocation << " stereo is off" << endl;
    }

    void setCD() 
    {
        cout << mLocation << " stereo is set for CD input" << endl;
    }

    void setDVD()
    {
        cout << mLocation << " stereo is set for DVD input" << endl;
    }

    void setRadio() 
    {
        cout << mLocation << " stereo is set for Radio" << endl;
    }

    void setVolume(int volume) 
    {
        cout << mLocation << " stereo volume set to " << volume << endl;
    }
};

class TV 
{
public:
    string mLocation;
    int mChannel;

    TV(string location)
    {
        mLocation = location;
    }

    void on()
    {
        cout << "TV is on" << endl;
    }

    void off()
    {
        cout << "TV is off" << endl;
    }

    void setInputChannel(int channel)
    {
        mChannel = channel;
        cout << "Channel is set for VCR" << endl;
    }

};


class LightOnCommand: public Command
{
public:
    Light* mLight;

    LightOnCommand(Light* light)
    {
        mLight = light;
    }

    void execute()
    {
        mLight->on();
    }
};

class LightOffCommand : public Command
{
public:
    Light* mLight;

    LightOffCommand(Light* light)
    {
        mLight = light;
    }

    void execute()
    {
        mLight->off();
    }
};

class StereoOnWithCDCommand : public Command 
{
public:
    Stereo* mStereo;

    StereoOnWithCDCommand(Stereo* stereo)
    {
        mStereo = stereo;
    }

    void execute()
    {
        mStereo->on();
        mStereo->setCD();
        mStereo->setVolume(10);
    }
};

class StereoOffCommand : public Command
{
public:
    Stereo* mStereo;

    StereoOffCommand(Stereo* stereo)
    {
        mStereo = stereo;
    }

    void execute()
    {
        mStereo->off();
    }
};

class RemoteControl
{
public:
    Command* mTurnOnCommand;
    Command* mTurnOffCommand;
    
    RemoteControl(Command* turnoncommand, Command* turnoffcommand)
    {
        mTurnOnCommand = turnoncommand;
        mTurnOffCommand = turnoffcommand;
    }

    void OnButtonWasPressed()
    {
        mTurnOnCommand->execute();
    }

    void OffButtonWasPressed()
    {
        mTurnOffCommand->execute();
    }
};

#endif