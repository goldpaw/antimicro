

#include "globalvariables.h"
#include "common.h"

#include <cmath>



// ---- JOYBUTTON --- //

const QString GlobalVariables::JoyButton::xmlName = "button";

// Set default values for many properties.
const int GlobalVariables::JoyButton::ENABLEDTURBODEFAULT = 100;
const double GlobalVariables::JoyButton::DEFAULTMOUSESPEEDMOD = 1.0;
double GlobalVariables::JoyButton::mouseSpeedModifier = GlobalVariables::JoyButton::DEFAULTMOUSESPEEDMOD;
const int GlobalVariables::JoyButton::DEFAULTKEYREPEATDELAY = 600; // 600 ms
const int GlobalVariables::JoyButton::DEFAULTKEYREPEATRATE = 40; // 40 ms. 25 times per second
const bool GlobalVariables::JoyButton::DEFAULTTOGGLE = false;
const int GlobalVariables::JoyButton::DEFAULTTURBOINTERVAL = 0;
const bool GlobalVariables::JoyButton::DEFAULTUSETURBO = false;
const int GlobalVariables::JoyButton::DEFAULTMOUSESPEEDX = 50;
const int GlobalVariables::JoyButton::DEFAULTMOUSESPEEDY = 50;
const int GlobalVariables::JoyButton::DEFAULTSETSELECTION = -1;
const int GlobalVariables::JoyButton::DEFAULTSPRINGWIDTH = 0;
const int GlobalVariables::JoyButton::DEFAULTSPRINGHEIGHT = 0;
const double GlobalVariables::JoyButton::DEFAULTSENSITIVITY = 1.0;
const int GlobalVariables::JoyButton::DEFAULTWHEELX = 20;
const int GlobalVariables::JoyButton::DEFAULTWHEELY = 20;
const bool GlobalVariables::JoyButton::DEFAULTCYCLERESETACTIVE = false;
const int GlobalVariables::JoyButton::DEFAULTCYCLERESET = 0;
const bool GlobalVariables::JoyButton::DEFAULTRELATIVESPRING = false;
const double GlobalVariables::JoyButton::DEFAULTEASINGDURATION = 0.5;
const double GlobalVariables::JoyButton::MINIMUMEASINGDURATION = 0.2;
const double GlobalVariables::JoyButton::MAXIMUMEASINGDURATION = 5.0;
const int GlobalVariables::JoyButton::MINCYCLERESETTIME = 10;
const int GlobalVariables::JoyButton::MAXCYCLERESETTIME = 60000;

const int GlobalVariables::JoyButton::DEFAULTMOUSEHISTORYSIZE = 10;
const double GlobalVariables::JoyButton::DEFAULTWEIGHTMODIFIER = 0.2;
const int GlobalVariables::JoyButton::MAXIMUMMOUSEHISTORYSIZE = 100;
const double GlobalVariables::JoyButton::MAXIMUMWEIGHTMODIFIER = 1.0;
const int GlobalVariables::JoyButton::MAXIMUMMOUSEREFRESHRATE = 16;
int GlobalVariables::JoyButton::IDLEMOUSEREFRESHRATE = (5 * 20);
const int GlobalVariables::JoyButton::DEFAULTIDLEMOUSEREFRESHRATE = 100;
const double GlobalVariables::JoyButton::DEFAULTEXTRACCELVALUE = 2.0;
const double GlobalVariables::JoyButton::DEFAULTMINACCELTHRESHOLD = 10.0;
const double GlobalVariables::JoyButton::DEFAULTMAXACCELTHRESHOLD = 100.0;
const double GlobalVariables::JoyButton::DEFAULTSTARTACCELMULTIPLIER = 0.0;
const double GlobalVariables::JoyButton::DEFAULTACCELEASINGDURATION = 0.1;
const int GlobalVariables::JoyButton::DEFAULTSPRINGRELEASERADIUS = 0;

// Keep references to active keys and mouse buttons.
QHash<int, int> GlobalVariables::JoyButton::activeKeys;
QHash<int, int> GlobalVariables::JoyButton::activeMouseButtons;

// History buffers used for mouse smoothing routine.
QList<double> GlobalVariables::JoyButton::mouseHistoryX;
QList<double> GlobalVariables::JoyButton::mouseHistoryY;

// Carry over remainder of a cursor move for the next mouse event.
double GlobalVariables::JoyButton::cursorRemainderX = 0.0;
double GlobalVariables::JoyButton::cursorRemainderY = 0.0;

double GlobalVariables::JoyButton::weightModifier = 0;
// Mouse history buffer size
int GlobalVariables::JoyButton::mouseHistorySize = 1;

int GlobalVariables::JoyButton::mouseRefreshRate = 5;
int GlobalVariables::JoyButton::springModeScreen = -1;
int GlobalVariables::JoyButton::gamepadRefreshRate = 10;


// ---- ANTIMICROSETTINGS --- //

const bool GlobalVariables::AntimicroSettings::defaultDisabledWinEnhanced = false;
const bool GlobalVariables::AntimicroSettings::defaultAssociateProfiles = true;
const int GlobalVariables::AntimicroSettings::defaultSpringScreen = -1;
const int GlobalVariables::AntimicroSettings::defaultSDLGamepadPollRate = 10; // unsigned

// ---- INPUTDEVICE ---- //

const int GlobalVariables::InputDevice::NUMBER_JOYSETS = 8;
const int GlobalVariables::InputDevice::DEFAULTKEYPRESSTIME = 100;
const int GlobalVariables::InputDevice::RAISEDDEADZONE = 20000;
const int GlobalVariables::InputDevice::DEFAULTKEYREPEATDELAY = 660; // 660 ms
const int GlobalVariables::InputDevice::DEFAULTKEYREPEATRATE = 40; // 40 ms. 25 times per second

//QRegExp GlobalVariables::InputDevice::emptyGUID("^[0]+$");
QRegExp GlobalVariables::InputDevice::emptyUniqueID("^[0]+$");

// ---- JOYAXIS ---- //

// Set default values for many properties.
const int GlobalVariables::JoyAxis::AXISMIN = -32767;
const int GlobalVariables::JoyAxis::AXISMAX = 32767;
const int GlobalVariables::JoyAxis::AXISDEADZONE = 6000;
const int GlobalVariables::JoyAxis::AXISMAXZONE = 32000;

// Speed in pixels/second
const float GlobalVariables::JoyAxis::JOYSPEED = 20.0;

const QString GlobalVariables::JoyAxis::xmlName = "axis";


#if defined(Q_OS_UNIX)
    #ifdef WITH_X11

// ---- X11EXTRAS ---- //

const QString GlobalVariables::X11Extras::mouseDeviceName = PadderCommon::mouseDeviceName;
const QString GlobalVariables::X11Extras::keyboardDeviceName = PadderCommon::keyboardDeviceName;
const QString GlobalVariables::X11Extras::xtestMouseDeviceName = QString("Virtual core XTEST pointer");

QString GlobalVariables::X11Extras::_customDisplayString = QString("");

    #endif
#endif


// ---- GameController ---- //

const QString GlobalVariables::GameController::xmlName = "gamecontroller";


// ---- GameControllerDPad ---- //

const QString GlobalVariables::GameControllerDPad::xmlName = "dpad";


// ---- GameControllerTrigger ---- //

const int GlobalVariables::GameControllerTrigger::AXISDEADZONE = 2000;
const int GlobalVariables::GameControllerTrigger::AXISMAXZONE = 32000;

const QString GlobalVariables::GameControllerTrigger::xmlName = "trigger";


// ---- GameControllerTriggerButton ---- //

const QString GlobalVariables::GameControllerTriggerButton::xmlName = "triggerbutton";


// ---- InputDaemon ---- //

const int GlobalVariables::InputDaemon::GAMECONTROLLERTRIGGERRELEASE = 16384;


// ---- VDPad ---- //

const QString GlobalVariables::VDPad::xmlName = "vdpad";


// ---- SetJoystick ---- //

const int GlobalVariables::SetJoystick::MAXNAMELENGTH = 30;
const int GlobalVariables::SetJoystick::RAISEDDEADZONE = 20000;


// ---- Joystick ---- //

const QString GlobalVariables::Joystick::xmlName = "joystick";


// ---- JoyDPad ---- //

const QString GlobalVariables::JoyDPad::xmlName = "dpad";
const int GlobalVariables::JoyDPad::DEFAULTDPADDELAY = 0;


// ---- JoyControlStick ---- //

// Define Pi here.
const double GlobalVariables::JoyControlStick::PI = acos(-1.0);

// Set default values used for stick properties.
const int GlobalVariables::JoyControlStick::DEFAULTDEADZONE = 8000;
const int GlobalVariables::JoyControlStick::DEFAULTMAXZONE = GlobalVariables::GameControllerTrigger::AXISMAXZONE;
const int GlobalVariables::JoyControlStick::DEFAULTDIAGONALRANGE = 90;
const double GlobalVariables::JoyControlStick::DEFAULTCIRCLE = 0.0;
const int GlobalVariables::JoyControlStick::DEFAULTSTICKDELAY = 0;


// ---- JoyButtonSlot ---- //

const int GlobalVariables::JoyButtonSlot::JOYSPEED = 20;
const QString GlobalVariables::JoyButtonSlot::xmlName = "slot";
const int GlobalVariables::JoyButtonSlot::MAXTEXTENTRYDISPLAYLENGTH = 40;



// ---- AdvanceButtonDialog ---- //

const int GlobalVariables::AdvanceButtonDialog::MINIMUMTURBO = 2;


// ---- JoyAxisButton ---- //

const QString GlobalVariables::JoyAxisButton::xmlName = "axisbutton";


// ---- JoyControlStickButton ---- //

const QString GlobalVariables::JoyControlStickButton::xmlName = "stickbutton";


// ---- JoyControlStickModifierButton ---- //

const QString GlobalVariables::JoyControlStickModifierButton::xmlName = "stickmodifierbutton";


// ---- JoyDPadButton ---- //

const QString GlobalVariables::JoyDPadButton::xmlName = "dpadbutton";
