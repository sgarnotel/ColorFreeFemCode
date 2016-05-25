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

#include "MainWindow.h"

/*!
 * \brief MainWindow::InitVar
 *
 * Initialisation of QtWidgets
 */
void MainWindow::InitVar(){
    //Widget
    CentralWidget = new QWidget(this);

    //Grid
    Grid = new QGridLayout(CentralWidget);

    //Label
    LabelEdpFile = new QLabel(CentralWidget);
    LabelTexFile = new QLabel(CentralWidget);

    //LineEdit
    LineEdpFile = new QLineEdit(CentralWidget);
    LineTexFile = new QLineEdit(CentralWidget);

    //Button
    ButtonEdpFile = new QPushButton(CentralWidget);
    ButtonTexFile = new QPushButton(CentralWidget);
    ButtonEdp2Tex = new QPushButton(CentralWidget);

    //CheckBox
    CheckBoxGroup = new QButtonGroup(CentralWidget);
    CheckBoxAutoCompile = new QCheckBox(CentralWidget);
    CheckBoxAutoRead = new QCheckBox(CentralWidget);

    //Process
    ProcessPdfLatex = new QProcess(CentralWidget);
    ProcessEvince = new QProcess(CentralWidget);
}

/*!
 * \brief MainWindow::InitWin
 *
 * Construction of Window
 */
void MainWindow::InitWin(){
    //Widget
    setCentralWidget(CentralWidget);
    CentralWidget->setLayout(Grid);

    //Grid
    Grid->addWidget(LabelEdpFile, 10, 10, 1, 1);
    Grid->addWidget(LineEdpFile, 10, 11, 1, 1);
    Grid->addWidget(ButtonEdpFile, 10, 12, 1, 1);

    Grid->addWidget(LabelTexFile, 11, 10, 1, 1);
    Grid->addWidget(LineTexFile, 11, 11, 1, 1);
    Grid->addWidget(ButtonTexFile, 11, 12, 1, 1);

    Grid->addWidget(ButtonEdp2Tex, 12, 10, 1, 3);

    Grid->addWidget(CheckBoxAutoCompile, 10, 20, 1, 1);
    Grid->addWidget(CheckBoxAutoRead, 11, 20, 1, 1);

    //Label
    LabelEdpFile->setText("Input: .edp File");
    LabelTexFile->setText("Output: .tex File");

    //LineEdit
    //

    //Button
    ButtonEdpFile->setIcon(QIcon("img/folder.png"));
    ButtonTexFile->setIcon(QIcon("img/folder.png"));
    ButtonEdp2Tex->setIcon(QIcon("img/run.png"));
    ButtonEdp2Tex->setText("Convert");

    //CheckBox
    CheckBoxGroup->addButton(CheckBoxAutoCompile);
    CheckBoxGroup->addButton(CheckBoxAutoRead);
    CheckBoxGroup->setExclusive(false);
    CheckBoxAutoCompile->setText("Compile Latex");
    CheckBoxAutoRead->setText("Read PDF");
}

/*!
 * \brief MainWindow::InitSig
 *
 * Construction of Signals
 */
void MainWindow::InitSig(){
    //Button
    connect(ButtonEdpFile, SIGNAL(clicked()), this, SLOT(__ButtonEdpFile()));
    connect(ButtonTexFile, SIGNAL(clicked()), this, SLOT(__ButtonTexFile()));
    connect(ButtonEdp2Tex, SIGNAL(clicked()), this, SLOT(__ButtonEdp2Tex()));
}

/*!
 * \brief MainWindow::InitCss
 *
 * Declaration of CSS Style Sheet
 */
void MainWindow::InitCss(){
    //
}

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 *
 * Constructor of the Main Window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    InitVar();
    InitWin();
    InitSig();
    InitCss();
}

/*!
 * \brief MainWindow::__ButtonEdpFile
 *
 * Click on ButtonEdpFile
 */
void MainWindow::__ButtonEdpFile(){
    QString EdpFile = QFileDialog::getOpenFileName(this, "Select a FreeFem++ .edp file", "../../edp", "FreeFem++ (*.edp)");
    if (!EdpFile.isEmpty()){
        LineEdpFile->setText(EdpFile);
    }
}

/*!
 * \brief MainWindow::__ButtonTexFile
 *
 * Click on ButtonTexFile
 */
void MainWindow::__ButtonTexFile(){
    QString TexFile = QFileDialog::getSaveFileName(this, "Select a Latex .tex file name", "../../tex", "Latex (*.tex)");
    if (!TexFile.isEmpty()){
        LineTexFile->setText(TexFile);
    }
}

/*!
 * \brief MainWindow::__ButtonEdp2Tex
 *
 * Click on ButtonEdp2Tex
 */
void MainWindow::__ButtonEdp2Tex(){
    QString EdpFile = LineEdpFile->text();
    if (EdpFile.isEmpty()){
        QMessageBox::information(this, "Information", ".edp file name empty");
        return;
    }

    QString TexFile = LineTexFile->text();
    if (TexFile.isEmpty()){
        QMessageBox::information(this, "Information", ".tex file name empty");
        return;
    }

    if (!Edp2Tex(EdpFile, TexFile)){
        QMessageBox::warning(this, "Warning", "Unable to convert .edp file to .tex file");
        return;
    }

    if (CheckBoxAutoCompile->isChecked()){
        QString Program = "pdflatex";

        QString Directory = QString(TexFile);
        {
            int Pos = Directory.lastIndexOf("/");
            Directory = Directory.remove(Pos, Directory.length()-Pos);
        }

        QStringList Arguments;
        Arguments.append("-interaction=nonstopmode");
        Arguments.append("-output-directory="+Directory);
        Arguments.append(TexFile);

        ProcessPdfLatex->start(Program, Arguments);

        if (!ProcessPdfLatex->waitForFinished()){
            QMessageBox::warning(this, "Warning", "pdflatex command failed");
            return;
        }
    }

    if (CheckBoxAutoRead->isChecked()){
        QString Program = "evince";

        QString PdfFile = QString(TexFile);
        {
            int Pos = PdfFile.lastIndexOf(".tex");
            PdfFile.replace(Pos, 4, ".pdf");
        }

        QStringList Arguments;
        Arguments.append(PdfFile);

        ProcessEvince->start(Program, Arguments);
    }
}

void MainWindow::closeEvent(QCloseEvent *){
    //Process
    //TODO: avoid "QProcess: Destroyed while process ("evince") is still running."
}


