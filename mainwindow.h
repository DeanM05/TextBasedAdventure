#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Room.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_nB_clicked();

    void on_eB_clicked();

    void on_wB_clicked();


    void on_execB_clicked();


    void on_sB_clicked();

private:
    Room *currentRoom;
    Ui::MainWindow *ui;

        Parser parser;
        void createRooms();
        void printWelcome();
        void processCommand(Command command);
//        void printHelp();
   //     void goRoom(Command command);
        void createItems();
        void displayItems();
        void setDesc();
        QPixmap aI, bI, cI, dI, eI, fI, gI, hI, iI, jI;
};

#endif // MAINWINDOW_H
