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

#ifndef HEADER_H
#define HEADER_H

#include <iostream>

#include <QtWidgets>

#define DEFAULT_DIRECTORY           "/home"
#define DEFAULT_PDF_LATEX           "pdflatex"
#define DEFAULT_PDF_LATEX_OPTIONS   "-interaction=nonstopmode"
#define DEFAULT_PDF_VIEWER          "evince"

//FreeFemDefinitions
QStringList *getSeparators(unsigned int *NbSeparators);
QStringList *getComments(unsigned int *NbComments);
QStringList *getTypes(unsigned int *NbTypes);
QStringList *getLoops(unsigned int *NbLoops);
QStringList *getGlobalVariables(unsigned int *NbGlobalVariables);
QStringList *getFESpaces(unsigned int *NbFESPaces);
QStringList *getFunctions(unsigned int *NbFunctions);
QStringList *getNumbers(unsigned int *NbNumbers);
QStringList *getStrings(unsigned int *NbStrings);
QStringList *getParameters(unsigned int *NbParameters);

//String
int indexOf(const QString string, const QStringList *separators, const int from=0);

//Edp2Tex
bool Edp2Tex(const QString EdpFileName, const QString TexFileName);

//io
bool SetDirectory(const QString Directory);
bool GetDirectory(QString *Directory);
bool SetPdfLatex(const QString Latex, const QString LatexOption);
bool GetPdfLatex(QString *Latex, QString *LatexOption);
bool SetPdfViewer(const QString Viewer);
bool GetPdfViewer(QString *Viewer);

#endif // HEADER_H


