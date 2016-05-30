#include "header.h"

bool SetDirectory(const QString Directory){
    QFile File("system/directory.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(Directory.toStdString().c_str());
        File.close();
        return true;
    }
    return false;
}

bool GetDirectory(QString *Directory){
    QFile File("system/directory.dat");
    if (File.open(QIODevice::ReadOnly)){
        QString Line = File.readLine();
        Line.remove("\n");
        (*Directory) = Line;
        File.close();
        return true;
    }
    return false;
}

bool SetPdfLatex(const QString Latex, const QString LatexOption){
    QFile File("system/pdflatex.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(Latex.toStdString().c_str());
        File.write("\n");
        File.write(LatexOption.toStdString().c_str());
        File.close();
        return true;
    }
    return false;
}

bool GetPdfLatex(QString *Latex, QString *LatexOption){
    QFile File("system/pdflatex.dat");
    if(File.open(QIODevice::ReadOnly)){
        QString Line = File.readLine();
        Line.remove("\n");
        (*Latex) = Line;
        Line = File.readLine();
        Line.remove("\n");
        (*LatexOption) = Line;
        File.close();
        return true;
    }
    return false;
}

bool SetPdfViewer(const QString Viewer){
    QFile File("system/viewer.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(Viewer.toStdString().c_str());
        File.close();
        return true;
    }
    return false;
}

bool GetPdfViewer(QString *Viewer){
    QFile File("system/viewer.dat");
    if(File.open(QIODevice::ReadOnly)){
        QString Line = File.readLine();
        Line.remove("\n");
        (*Viewer) = Line;
        File.close();
        return true;
    }
    return false;
}
