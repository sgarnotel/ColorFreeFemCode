#include "dialogsettings.h"

void DialogSettings::InitVar(){
    //Grid
    Grid = new QGridLayout(this);

    //Label
    LabelDirectory = new QLabel(Grid->widget());
    LabelPdfLatex = new QLabel(Grid->widget());
    LabelPdfLatexOption = new QLabel(Grid->widget());
    LabelPdfViewer = new QLabel(Grid->widget());

    //LineEdit
    LineEditDirectory = new QLineEdit(Grid->widget());
    LineEditPdfLatex = new QLineEdit(Grid->widget());
    LineEditPdfLatexOption = new QLineEdit(Grid->widget());
    LineEditPdfViewer = new QLineEdit(Grid->widget());

    //PushButton
    PushButtonDirectory = new QPushButton(Grid->widget());
    PushButtonPdfLatex = new QPushButton(Grid->widget());
    PushButtonPdfViewer = new QPushButton(Grid->widget());
    PushButtonCancel = new QPushButton(Grid->widget());
    PushButtonValid = new QPushButton(Grid->widget());
}

void DialogSettings::InitWin(){
    //Dialog
    this->setLayout(Grid);

    //Grid
    Grid->addWidget(LabelDirectory, 0, 0, 1, 1);
    Grid->addWidget(LineEditDirectory, 0, 1, 1, 1);
    Grid->addWidget(PushButtonDirectory, 0, 2, 1, 1);
    Grid->addWidget(LabelPdfLatex, 1, 0, 1, 1);
    Grid->addWidget(LineEditPdfLatex, 1, 1, 1, 1);
    Grid->addWidget(PushButtonPdfLatex, 1, 2, 1, 1);
    Grid->addWidget(LabelPdfLatexOption, 2, 0, 1, 1);
    Grid->addWidget(LineEditPdfLatexOption, 2, 1, 1, 2);
    Grid->addWidget(LabelPdfViewer, 3, 0, 1, 1);
    Grid->addWidget(LineEditPdfViewer, 3, 1, 1, 1);
    Grid->addWidget(PushButtonPdfViewer, 3, 2, 1, 1);

    Grid->addWidget(PushButtonCancel, 10, 0, 1, 1);
    Grid->addWidget(PushButtonValid, 10, 1, 1, 1);

    //Label
    LabelDirectory->setText("Directory");
    LabelPdfLatex->setText("PDF Latex compilator");
    LabelPdfLatexOption->setText("PDF Latex options");
    LabelPdfViewer->setText("PDF viewer");

    //LineEdit
    {
        QString TMPDirectory;
        bool Res = GetDirectory(&TMPDirectory);
        if (Res){
            LineEditDirectory->setText(TMPDirectory);
        }
    }
    {
        QString TMPLatex;
        QString TMPLatexOption;
        bool Res = GetPdfLatex(&TMPLatex, &TMPLatexOption);
        if (Res){
            LineEditPdfLatex->setText(TMPLatex);
            LineEditPdfLatexOption->setText(TMPLatexOption);
        }
    }
    {
        QString TMPViewer;
        bool Res = GetPdfViewer(&TMPViewer);
        if (Res){
            LineEditPdfViewer->setText(TMPViewer);
        }
    }

    //PushButton
    PushButtonDirectory->setIcon(QIcon("img/folder.png"));
    PushButtonPdfLatex->setIcon(QIcon("img/folder.png"));
    PushButtonPdfViewer->setIcon(QIcon("img/folder.png"));
    PushButtonCancel->setText("Cancel");
    PushButtonValid->setText("Valid");
}

void DialogSettings::InitSig(){
    //PushButton
    connect(PushButtonDirectory, SIGNAL(clicked(bool)), this, SLOT(__Directory()));
    connect(PushButtonPdfLatex, SIGNAL(clicked(bool)), this, SLOT(__PdfLatex()));
    connect(PushButtonPdfViewer, SIGNAL(clicked(bool)), this, SLOT(__PdfViewer()));
    connect(PushButtonCancel, SIGNAL(clicked(bool)), this, SLOT(__Cancel()));
    connect(PushButtonValid, SIGNAL(clicked(bool)), this, SLOT(__Valid()));
}

void DialogSettings::InitCss(){
    //Dialog
    this->setWindowTitle("Settings");
}

DialogSettings::DialogSettings(QWidget *parent) : QDialog(parent)
{
    InitVar();
    InitWin();
    InitSig();
    InitCss();
}

void DialogSettings::__Directory(){
    QString Directory = QFileDialog::getExistingDirectory(this, "Select the directory", LineEditDirectory->text());
    if (!Directory.isEmpty()) LineEditDirectory->setText(Directory);
}

void DialogSettings::__PdfLatex(){
    QString PdfLatex = QFileDialog::getOpenFileName(this, "Select the PDF Latex compilator", "/");
    if (!PdfLatex.isEmpty()) LineEditPdfLatex->setText(PdfLatex);
}

void DialogSettings::__PdfViewer(){
    QString PdfViewer = QFileDialog::getOpenFileName(this, "Select the PDF viewer", "/");
    if (!PdfViewer.isEmpty()) LineEditPdfLatex->setText(PdfViewer);
}

void DialogSettings::__Cancel(){
    reject();
}

void DialogSettings::__Valid(){
    QString Directory = LineEditDirectory->text();
    SetDirectory(Directory);

    QString PdfLatex = LineEditPdfLatex->text();
    QString PdfLatexOption = LineEditPdfLatexOption->text();
    SetPdfLatex(PdfLatex, PdfLatexOption);

    QString PdfViewer = LineEditPdfViewer->text();
    SetPdfViewer(PdfViewer);

    accept();
}
