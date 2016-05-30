/****************************************************************************
**  This is a part of ColorFreeFeCode                                      **
**  Copyright (C) 2016  Simon Garnotel                                     **
**                                                                         **
**  This program is free software: you can redistribute it and/or modify   **
**  it under the terms of the GNU General Public License as published by   **
**  the Free Software Foundation, either version 3 of the License, or      **
**  (at your option) any later version.                                    **
**                                                                         **
**  This program is distributed in the hope that it will be useful,        **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**  GNU General Public License for more details.                           **
**                                                                         **
**  You should have received a copy of the GNU General Public License      **
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.  **
**                                                                         **
** **************************************************************************
**                                                                         **
** Author: Simon Garnotel                                                  **
** Contact: simon.garnotel@gmail.com                                       **
** Date: 04/2016                                                           **
** Version: 1.0                                                            **
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "header.h"
#include "dialogsettings.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    //Method
    void InitVar();
    void InitWin();
    void InitSig();
    void InitCss();

    void closeEvent(QCloseEvent *);

    //Menu
    QMenu *MenuEdit;
    QMenu *MenuHelp;

    //Action
    QAction *ActionEditSettings;
    QAction *ActionHelpAboutQt;
    QAction *ActionHelpAbout;

    //Widget
    QWidget *CentralWidget;

    //Gird
    QGridLayout *Grid;

    //Label
    QLabel *LabelEdpFile;
    QLabel *LabelTexFile;

    //LineEdit
    QLineEdit *LineEdpFile;
    QLineEdit *LineTexFile;

    //Button
    QPushButton *ButtonEdpFile;
    QPushButton *ButtonTexFile;
    QPushButton *ButtonEdp2Tex;

    //CheckBox
    QButtonGroup *CheckBoxGroup;
    QCheckBox *CheckBoxAutoCompile;
    QCheckBox *CheckBoxAutoRead;

    //Process
    QProcess *ProcessPdfLatex;
    QProcess *ProcessEvince;

    //String
    QString StringDirectory;
    QString StringLatex;
    QString StringLatexOption;
    QString StringViewer;

signals:

public slots:

private slots:
    void __ButtonEdpFile();
    void __ButtonTexFile();
    void __ButtonEdp2Tex();

    void __Settings();
    void __AboutQt();
    void __About();
};

#endif // MAINWINDOW_H


