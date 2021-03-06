#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pmgphotocommandthread.h"


#include <QMainWindow>
#include <QComboBox>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QStandardItemModel>
#include <QMap>

#include <gphoto2/gphoto2-camera.h>

#define PM_PROP_CONFIG_KEY "configKey"
#define PM_PROP_OFFSET "offset"

#define PM_CONFIG_KEY_AUTOFOCUS_DRIVE "autofocusdrive"
#define PM_CONFIG_KEY_VIEWFINDER "viewfinder"
#define PM_CONFIG_KEY_F_NUMBER "f-number"
#define PM_CONFIG_KEY_SHUTTERSPEED "shutterspeed"
#define PM_CONFIG_KEY_MANUALFOCUSDRIVE "manualfocusdrive"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void addMessage(QString message);
private:
    void configureWidgets();

    Ui::MainWindow *ui;
    PMGPhotoCommandThread *commandThread;
    QComboBox cameraSelector;
    QStandardItemModel *logModel;
    QStandardItemModel *infosModel;
    QMap<QString, QWidget*> cameraWidgets;


public slots:
    void camerasDetected(QList<PMCamera*>* cameras);
    void cameraSelected(int index);
    void cameraOpened(int cameraNumber);
    void startLiveView();
    void stopLiveView();
    void manualFocusDrive();
    void liveViewStopped(int cameraNumber);
    void displayError(QString message);
    void displayStatus(QString message);
    void cameraSetWidgetValue();
    void startListingWidgets(int cameraNumber);
    void newWidget(int cameraNumber, CameraWidget* widget);
};

#endif // MAINWINDOW_H
