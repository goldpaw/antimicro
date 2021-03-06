#ifndef CALIBRATION_H
#define CALIBRATION_H

#include "joycontrolstickeditdialog.h"

#include <SDL2/SDL_joystick.h>

#include <QWidget>
#include <QProgressBar>
#include <QList>
#include <QHash>

class JoyControlStick;
class InputDevice;

namespace Ui {
class Calibration;
}

class Calibration : public QWidget
{
    Q_OBJECT

public:
    explicit Calibration(QMap<SDL_JoystickID, InputDevice*>* joysticks, QWidget *parent = 0);
    ~Calibration();

    int chooseMinMax(QString min_max_sign, QList<int> ax_values);
    void setQuadraticZoneCalibrated(int &max_axis_val_x, int &min_axis_val_x, int &max_axis_val_y, int &min_axis_val_y);

protected:
    void setProgressBars(int inputDevNr, int setJoyNr, int stickNr);
    void setProgressBars(JoyControlStick* controlstick);
    void updateAxesBox();
    void restoreCalValues();
    bool enoughProb(int x_count, int y_count, QString character);
    int calibratedDeadZone(int center, int deadzone);


private:
    static int fakeMapFunc(const int &x);
    static void summarizeValues(int &numbFromList, const int &mappednumb);
    static void getMinVal(int &numbFromList, const int &mappednumb);
    static void getMaxVal(int &numbFromList, const int &mappednumb);

    Ui::Calibration *ui;
    QMap<SDL_JoystickID, InputDevice*>* joysticks;
    JoyControlStick *stick;
    JoyControlStickEditDialogHelper helper;
    JoyAxis* joyAxisX;
    JoyAxis* joyAxisY;
    QProgressBar *axisBarX;
    QProgressBar *axisBarY;
    QMultiHash<QString,int> x_es_val;
    QMultiHash<QString,int> y_es_val;
    int center_calibrated_x;
    int center_calibrated_y;
    int max_axis_val_x;
    int min_axis_val_x;
    int max_axis_val_y;
    int min_axis_val_y;
    int deadzone_calibrated_x;
    int deadzone_calibrated_y;
    int sumX;
    int sumY;
    bool calibrated;
    QString text;

public slots:
    void saveSettings();
    void checkX(int value);
    void checkY(int value);
    void createAxesConnection();
    void setController(QString controllerName);
    void startCalibration();
    void startSecondStep();
    void startLastStep();

protected slots:
    void resetSettings(bool silentReset, bool clicked = false);

signals:
    void deadZoneChanged(int value);
    void propertyUpdated();

};

#endif // CALIBRATION_H
