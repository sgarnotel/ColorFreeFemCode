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

#include "header.h"

/*!
 * \brief Edp2Tex
 * \param EdpFileName
 * \param TexFileName
 * \return
 */
bool Edp2Tex(const QString EdpFileName, const QString TexFileName){
    //Read edpFile
    QVector<QString> Text;
    QFile edpFile(EdpFileName);
    if (edpFile.open(QIODevice::ReadOnly)){
        while (!edpFile.atEnd()){
            Text.append(edpFile.readLine());
        }
        edpFile.close();
    }
    else{
        std::cerr << "edpFile not readable" << std::endl;
        return false;
    }
    unsigned int edpFileNbLines = Text.count();
    std::cout << "edpFileNbLines = " << edpFileNbLines << std::endl;

    //Separator characters;
    unsigned int NbSeparators;
    QStringList *Separators = getSeparators(&NbSeparators);

    //Comment
    unsigned int NbComments;
    QStringList *Comments = getComments(&NbComments);
    QString CommentsColor = "DarkBlue";

    //Types
    unsigned int NbTypes;
    QStringList *Types = getTypes(&NbTypes);
    QString TypesColor = "DarkGreen";

    //Loops
    unsigned int NbLoops;
    QStringList *Loops = getLoops(&NbLoops);
    QString LoopsColor = "FireBrick";


    //GlobalVariables
    unsigned int NbGlobalVariables;
    QStringList *GlobalVariables = getGlobalVariables(&NbGlobalVariables);
    QString GlobalVariablesColor = "SeaGreen";

    //FESPaces
    unsigned int NbFESpaces;
    QStringList *FESpaces = getFESpaces(&NbFESpaces);
    QString FESpacesColor = "DarkOrchid";


    //Functions
    unsigned int NbFunctions;
    QStringList *Functions = getFunctions(&NbFunctions);
    QString FunctionsColor = "Purple";


    //Numbers
    //unsigned int NbNumbers;
    //QStringList *Numbers = getNumbers(&NbNumbers);
    QString NumbersColor = "Magenta";

    //Strings
    unsigned int NbStrings;
    QStringList *Strings = getStrings(&NbStrings);
    QString StringsColor = "Magenta";

    //Parameters
    unsigned int NbParameters;
    QStringList *Parameters = getParameters(&NbParameters);
    QString ParametersColor = "SeaGreen";


    //Modify Text
    QVector<QString> NewText;
    for (unsigned int i = 0; i < edpFileNbLines; i++){
        QString Line = Text.at(i);
        Line = Line.remove("\n");
        if (Line.compare("/*") == 0){
            while (Line.compare("*/") != 0){
                i++;
                Line = Text.at(i);
                Line = Line.remove("\n");
            }
        }
        else{
            //std::cout << "Line " << (i+1) << std::endl;

            int PosStrings = indexOf(Line, Strings);
            int PosComments = indexOf(Line, Comments);
            int PosSeparators = indexOf(Line, Separators);
            int OldPos = 0;

            while(PosStrings != -1 || PosComments != -1 || PosSeparators != -1){
                if (
                        ((PosStrings != -1) && (PosComments != -1) &&  (PosStrings < PosComments))
                        ||
                        ((PosStrings != -1) && (PosSeparators != -1) && (PosStrings < PosSeparators))
                        ||
                        ((PosComments == -1) && (PosSeparators == -1) && (PosStrings != -1))
                        ){
                    //std::cout << "This is a string" << std::endl;
                    Line.insert(PosStrings, "&fvtextcolor!"+StringsColor+"?!");
                    PosStrings = PosStrings + 13 + StringsColor.length() + 2;
                    OldPos = PosStrings + 1;
                    PosStrings = indexOf(Line, Strings, OldPos);
                    PosStrings = PosStrings + 1;
                    Line.insert(PosStrings, "?");

                    OldPos = PosStrings + 1;
                }
                else if ((PosComments != -1) && (PosComments == PosSeparators)){
                    //std::cout << "This is a comment" << std::endl;
                    Line.insert(PosComments, "&fvtextcolor!"+CommentsColor+"?!");
                    Line.append("?");
                    break;
                }
                else{
                    QString Word = Line.mid(OldPos, PosSeparators - OldPos);
                    Word.remove("\t");

                    for (unsigned int j = 0; j < NbTypes; j++){
                        if (Word.compare(Types->at(j)) == 0){
                            //std::cout << "This is a type" << std::endl;
                            Line.insert(OldPos, "&fvtextcolor!"+TypesColor+"?!");
                            PosSeparators = PosSeparators + 13 + TypesColor.length() + 2;
                            Line.insert(PosSeparators, "?");
                        }
                    }

                    for (unsigned int j = 0; j < NbLoops; j++){
                        if (Word.compare(Loops->at(j)) == 0){
                            //std::cout << "This is a loop" << std::endl;
                            Line.insert(OldPos, "&fvtextcolor!"+LoopsColor+"?!");
                            PosSeparators = PosSeparators + 13 + LoopsColor.length() + 2;
                            Line.insert(PosSeparators, "?");
                        }
                    }

                    for (unsigned int j = 0; j < NbGlobalVariables; j++){
                        if (Word.compare(GlobalVariables->at(j)) == 0){
                            //std::cout << "This is a global variable" << std::endl;
                            Line.insert(OldPos, "&fvtextcolor!"+GlobalVariablesColor+"?!");
                            PosSeparators = PosSeparators + 13 + GlobalVariablesColor.length() + 2;
                            Line.insert(PosSeparators, "?");
                        }
                    }

                    for (unsigned int j = 0; j < NbFESpaces; j++){
                        if (Word.compare(FESpaces->at(j)) == 0){
                            //std::cout << "This is a FE space" << std::endl;
                            Line.insert(OldPos, "&fvtextcolor!"+FESpacesColor+"?!");
                            PosSeparators = PosSeparators + 13 + FESpacesColor.length() + 2;
                            Line.insert(PosSeparators, "?");
                        }
                    }

                    for (unsigned int j = 0; j < NbFunctions; j++){
                        if (Word.compare(Functions->at(j)) == 0){
                            //std::cout << "This is a fuction" << std::endl;
                            Line.insert(OldPos, "&fvtextcolor!"+FunctionsColor+"?!");
                            PosSeparators = PosSeparators + 13 + FunctionsColor.length() + 2;
                            Line.insert(PosSeparators, "?");
                        }
                    }

                    for (unsigned int j = 0; j < NbParameters; j++){
                        if (Word.compare(Parameters->at(j)) == 0){
                            //std::cout << "This is a parameter" << std::endl;
                            Line.insert(OldPos, "&fvtextcolor!"+ParametersColor+"?!");
                            PosSeparators = PosSeparators + 13 + ParametersColor.length() + 2;
                            Line.insert(PosSeparators, "?");
                        }
                    }

                    bool Res;
                    Word.toDouble(&Res);
                    if (Res){
                        //std::cout << "This is a number" << std::endl;
                        Line.insert(OldPos, "&fvtextcolor!"+NumbersColor+"?!");
                        PosSeparators = PosSeparators + 13 + NumbersColor.length() + 2;
                        Line.insert(PosSeparators, "?");
                    }

                    OldPos = PosSeparators + 1;

                    PosSeparators = indexOf(Line, Separators, OldPos);
                    if (PosSeparators == -1){
                        Word = Line.mid(OldPos, -1);

                        //
                    }
                }

                PosStrings = indexOf(Line, Strings, OldPos-1);
                PosComments = indexOf(Line, Comments, OldPos);
                PosSeparators = indexOf(Line, Separators, OldPos);
            }

            NewText.append(Line);
        }
    }
    unsigned int texFileNbLines = NewText.count();

    //Write texFile
    QFile texFile(TexFileName);
    if (texFile.open(QIODevice::WriteOnly)){

        texFile.write("\\documentclass{article}\n");
        texFile.write("\\usepackage[utf8]{inputenc}\n");
        texFile.write("\\usepackage[T1]{fontenc}\n");
        texFile.write("\n");
        texFile.write("\\usepackage{fancyvrb}\n");
        texFile.write("\\usepackage[svgnames]{xcolor}\n");
        texFile.write("\\DefineVerbatimEnvironment{MyVerbatim}{Verbatim}{fontfamily=courier}\n");
        texFile.write("\\newcommand*{\\fvtextcolor}[2]{\\textcolor{#1}{#2}}\n");
        texFile.write("\n");
        texFile.write("\\begin{document}\n");
        texFile.write("\\begin{MyVerbatim}[commandchars=&!?]\n");

        for (unsigned int i = 0; i < texFileNbLines; i++){
            texFile.write(NewText.at(i).toStdString().c_str());
            texFile.write("\n");
        }

         texFile.write("\\end{MyVerbatim}\n");
         texFile.write("\\end{document}\n");

        texFile.close();
    }
    else{
        std::cerr << "texFile not writable" << std::endl;
        return false;
    }

    return true;
}






//Split words
/*QRegExp Separator("[+]|=|;| |,|[(]|[)]|/|[*]|[[]|[]]|-|[}]|[{]");   //[^]
QStringList Words = Text.split(Separator, QString::SkipEmptyParts);
unsigned int edpFileNbWords = Words.count();

//Modify words

//Write
QString NewText = "";
for (unsigned int i = 0; i < edpFileNbWords; i++){
    NewText.append(Words.at(i));
}

std::cout << NewText.toStdString() << std::endl;
*/


