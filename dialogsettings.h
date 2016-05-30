#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include "header.h"

class DialogSettings : public QDialog
{
    Q_OBJECT
public:
    DialogSettings(QWidget *parent = 0);

private slots:
    void __Directory();
    void __PdfLatex();
    void __PdfViewer();

    void __Cancel();
    void __Valid();

private:
    //Methods
    void InitVar();
    void InitWin();
    void InitSig();
    void InitCss();

    //Grid
    QGridLayout *Grid;

    //Label
    QLabel *LabelDirectory;
    QLabel *LabelPdfLatex;
    QLabel *LabelPdfLatexOption;
    QLabel *LabelPdfViewer;

    //LineEdit
    QLineEdit *LineEditDirectory;
    QLineEdit *LineEditPdfLatex;
    QLineEdit *LineEditPdfLatexOption;
    QLineEdit *LineEditPdfViewer;

    //PushButton
    QPushButton *PushButtonDirectory;
    QPushButton *PushButtonPdfLatex;
    QPushButton *PushButtonPdfViewer;
    QPushButton *PushButtonCancel;
    QPushButton *PushButtonValid;
};

#endif // DIALOGSETTINGS_H
