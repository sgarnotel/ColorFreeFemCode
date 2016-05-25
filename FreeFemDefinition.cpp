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

//List of types, global variables, ...
//build with FreeFem++ v3.43-2

/*!
 * \brief getSeparators
 * \param NbSeparators
 * \return
 */
QStringList *getSeparators(unsigned int *NbSeparators){
    QStringList *Separators = new QStringList();

    Separators->append(" ");
    Separators->append(",");
    Separators->append(";");
    Separators->append("(");
    Separators->append(")");
    Separators->append("{");
    Separators->append("}");
    Separators->append("[");
    Separators->append("]");
    Separators->append("=");
    Separators->append("+");
    Separators->append("-");
    Separators->append("*");
    Separators->append("/");
    Separators->append("^");
    Separators->append("&");
    Separators->append("|");
    Separators->append("%");
    Separators->append("\"");
    Separators->append("<");
    Separators->append(">");

    (*NbSeparators) = Separators->count();
    return Separators;
}

/*!
 * \brief getComments
 * \param NbComments
 * \return
 */
QStringList *getComments(unsigned int *NbComments){
    QStringList *Comments = new QStringList();

    Comments->append("//");

    (*NbComments) = Comments->count();
    return Comments;
}

/*!
 * \brief getTypes
 * \param NbTypes
 * \return
 */
QStringList *getTypes(unsigned int *NbTypes){
    QStringList *Types = new QStringList();

    Types->append("bool");
    Types->append("border");
    Types->append("complex");
    Types->append("fespace");
    Types->append("func");
    Types->append("ifstream");
    Types->append("include");
    Types->append("int");
    Types->append("load");
    Types->append("matrix");
    Types->append("mesh");
    Types->append("mesh3");
    Types->append("ofstream");
    Types->append("problem");
    Types->append("real");
    Types->append("solve");
    Types->append("string");
    Types->append("varf");

    (*NbTypes) = Types->count();
    return Types;
}

/*!
 * \brief getLoops
 * \param NbLoops
 * \return
 */
QStringList *getLoops(unsigned int *NbLoops){
    QStringList *Loops = new QStringList();

    Loops->append("break");
    Loops->append("catch");
    Loops->append("continue");
    Loops->append("else");
    Loops->append("for");
    Loops->append("if");
    Loops->append("return");
    Loops->append("throw");
    Loops->append("try");
    Loops->append("while");

    (*NbLoops) = Loops->count();
    return Loops;
}

/*!
 * \brief getGlobalVariables
 * \param NbGlobalVariables
 * \return
 */
QStringList *getGlobalVariables(unsigned int *NbGlobalVariables){
    QStringList *GlobalVariables = new QStringList();

    GlobalVariables->append("ARGV");
    GlobalVariables->append("CG");
    GlobalVariables->append("Cholesky");
    GlobalVariables->append("CPUTime");
    GlobalVariables->append("Crout");
    GlobalVariables->append("GMRES");
    GlobalVariables->append("HaveUMFPACK");
    GlobalVariables->append("LU");
    GlobalVariables->append("N");
    GlobalVariables->append("NoGraphicWindow");
    GlobalVariables->append("NoUseOfWait");
    GlobalVariables->append("P");
    GlobalVariables->append("UMFPACK");
    GlobalVariables->append("append");
    GlobalVariables->append("area");
    GlobalVariables->append("binary");
    GlobalVariables->append("cerr");
    GlobalVariables->append("cin");
    GlobalVariables->append("cout");
    GlobalVariables->append("endl");
    GlobalVariables->append("false");
    GlobalVariables->append("hTriangle");
    GlobalVariables->append("havesparsesolver");
    GlobalVariables->append("inside");
    GlobalVariables->append("label");
    GlobalVariables->append("lenEdge");
    GlobalVariables->append("nTonEdge");
    GlobalVariables->append("newconvect");
    GlobalVariables->append("nuEdge");
    GlobalVariables->append("nuTriangle");
    GlobalVariables->append("pi");
    GlobalVariables->append("qf1pE");
    GlobalVariables->append("qf1pElump");
    GlobalVariables->append("qf1pT");
    GlobalVariables->append("qf1pTlump");
    GlobalVariables->append("qf2pE");
    GlobalVariables->append("qf2pT");
    GlobalVariables->append("qf2pT4P1");
    GlobalVariables->append("qf3pE");
    GlobalVariables->append("qf4pE");
    GlobalVariables->append("qf5pE");
    GlobalVariables->append("qf5pT");
    GlobalVariables->append("qf7pT");
    GlobalVariables->append("qf9pT");
    GlobalVariables->append("qfV1");
    GlobalVariables->append("qfV1lump");
    GlobalVariables->append("qfV2");
    GlobalVariables->append("qfV5");
    GlobalVariables->append("region");
    GlobalVariables->append("searchMethod");
    GlobalVariables->append("sparsesolver");
    GlobalVariables->append("sparsesolverSym");
    GlobalVariables->append("true");
    GlobalVariables->append("verbosity");
    GlobalVariables->append("version");
    GlobalVariables->append("volume");
    GlobalVariables->append("wait");
    GlobalVariables->append("x");
    GlobalVariables->append("y");
    GlobalVariables->append("z");


    (*NbGlobalVariables) = GlobalVariables->count();
    return GlobalVariables;
}

/*!
 * \brief getFESpaces
 * \param NbFESPaces
 * \return
 */
QStringList *getFESpaces(unsigned int *NbFESPaces){
    QStringList *FESpaces = new QStringList();

    FESpaces->append("Edge03d");
    FESpaces->append("P0");
    FESpaces->append("P03d");
    FESpaces->append("P0VF");
    FESpaces->append("P0edge");
    FESpaces->append("P1");
    FESpaces->append("P13d");
    FESpaces->append("P1b");
    FESpaces->append("P1b3d");
    FESpaces->append("P1dc");
    FESpaces->append("P1nc");
    FESpaces->append("P2");
    FESpaces->append("P23d");
    FESpaces->append("P2b");
    FESpaces->append("P2dc");
    FESpaces->append("P2h");
    FESpaces->append("RT0");
    FESpaces->append("RT03d");
    FESpaces->append("RT0Ortho");
    FESpaces->append("RTmodif");

    (*NbFESPaces) = FESpaces->count();
    return FESpaces;
}

/*!
 * \brief getFunctions
 * \param NbFunctions
 * \return
 */
QStringList *getFunctions(unsigned int *NbFunctions){
    QStringList *Functions = new QStringList();

    Functions->append("AddLayers");
    Functions->append("AffineCG");
    Functions->append("AffineGMRES");
    Functions->append("BFGS");
    Functions->append("Cofactor");
    Functions->append("EigenValue");
    Functions->append("LinearCG");
    Functions->append("LinearGMRES");
    Functions->append("NLCG");
    Functions->append("Nan");
    Functions->append("Newton");
    Functions->append("SameMesh");
    Functions->append("ShowAlloc");
    Functions->append("Unique");
    Functions->append("abs");
    Functions->append("acos");
    Functions->append("acosh");
    Functions->append("adaptmesh");
    Functions->append("arealevelset");
    Functions->append("arg");
    Functions->append("asin");
    Functions->append("asinh");
    Functions->append("assert");
    Functions->append("atan");
    Functions->append("atan2");
    Functions->append("atanh");
    Functions->append("atof");
    Functions->append("atoi");
    Functions->append("average");
    Functions->append("boundingbox");
    Functions->append("buildmesh");
    Functions->append("bluidmeshborder");
    Functions->append("ceil");
    Functions->append("change");
    Functions->append("checkmovemesh");
    Functions->append("chtmpdir");
    Functions->append("clock");
    Functions->append("complexEigenValue");
    Functions->append("conj");
    Functions->append("convect");
    Functions->append("cos");
    Functions->append("cosh");
    Functions->append("defaultUMFPACK");
    Functions->append("defaultsolver");
    Functions->append("defaulttoCG");
    Functions->append("defaulttoGMRES");
    Functions->append("defaulttoUMFPACK");
    Functions->append("det");
    Functions->append("dumptable");
    Functions->append("dx");
    Functions->append("dxx");
    Functions->append("dxy");
    Functions->append("dxz");
    Functions->append("dy");
    Functions->append("dyx");
    Functions->append("dyy");
    Functions->append("dyz");
    Functions->append("dz");
    Functions->append("dzx");
    Functions->append("dzy");
    Functions->append("dzz");
    Functions->append("emptymesh");
    Functions->append("erf");
    Functions->append("erfc");
    Functions->append("exec");
    Functions->append("exit");
    Functions->append("exp");
    Functions->append("floor");
    Functions->append("getline");
    Functions->append("hypot");
    Functions->append("image");
    Functions->append("int1d");
    Functions->append("int2d");
    Functions->append("int3d");
    Functions->append("intallVFedges");
    Functions->append("intalledges");
    Functions->append("intallfaces");
    Functions->append("interplotematrix");
    Functions->append("intterpolate");
    Functions->append("isInf");
    Functions->append("isNan");
    Functions->append("isNormal");
    Functions->append("j0");
    Functions->append("j1");
    Functions->append("jn");
    Functions->append("jump");
    Functions->append("lgamma");
    Functions->append("log");
    Functions->append("log10");
    Functions->append("lrint");
    Functions->append("lround");
    Functions->append("ltime");
    Functions->append("max");
    Functions->append("mean");
    Functions->append("medit");
    Functions->append("min");
    Functions->append("movemesh");
    Functions->append("norm");
    Functions->append("on");
    Functions->append("otherside");
    Functions->append("plot");
    Functions->append("polar");
    Functions->append("pow");
    Functions->append("randinit");
    Functions->append("randinit31");
    Functions->append("randinit32");
    Functions->append("randreal1");
    Functions->append("randreal2");
    Functions->append("randreal3");
    Functions->append("randres53");
    Functions->append("readmesh");
    Functions->append("readmesh3");
    Functions->append("renumbering");
    Functions->append("restrict");
    Functions->append("rint");
    Functions->append("round");
    Functions->append("savemesh");
    Functions->append("savesurfacemesh");
    Functions->append("set");
    Functions->append("sin");
    Functions->append("sinh");
    Functions->append("sort");
    Functions->append("splitmesh");
    Functions->append("sqrt");
    Functions->append("square");
    Functions->append("storagetotal");
    Functions->append("storageused");
    Functions->append("system");
    Functions->append("tan");
    Functions->append("tanh");
    Functions->append("tgamma");
    Functions->append("time");
    Functions->append("toCarry");
    Functions->append("roRarray");
    Functions->append("toZarray");
    Functions->append("triangulate");
    Functions->append("trunc");
    Functions->append("volumelevelset");
    Functions->append("y0");
    Functions->append("y1");
    Functions->append("yn");

    (*NbFunctions) = Functions->count();
    return Functions;
}

/*!
 * \brief getNumbers
 * \param NbNumbers
 * \return
 */
QStringList *getNumbers(unsigned int *NbNumbers){
   QStringList *Numbers = new QStringList();

   (*NbNumbers) = Numbers->count();
   return Numbers;
}

/*!
 * \brief getStrings
 * \param NbStrings
 * \return
 */
QStringList *getStrings(unsigned int *NbStrings){
    QStringList *Strings = new QStringList();

    Strings->append("\"");

    (*NbStrings) = Strings->count();
    return Strings;
}

/*!
 * \brief getParameters
 * \param NbParameters
 * \return
 */
QStringList *getParameters(unsigned int *NbParameters){
    QStringList *Parameters = new QStringList();

    Parameters->append("aspectratio");
    Parameters->append("bb");
    Parameters->append("boundary");
    Parameters->append("bw");
    Parameters->append("cmm");
    Parameters->append("coef");
    Parameters->append("dim");
    Parameters->append("fill");
    Parameters->append("grey");
    Parameters->append("hsv");
    Parameters->append("nbarrow");
    Parameters->append("nbiso");
    Parameters->append("labeldown");
    Parameters->append("labelmid");
    Parameters->append("labelup");
    Parameters->append("ps");
    Parameters->append("solver");
    Parameters->append("value");
    Parameters->append("varrow");
    Parameters->append("viso");
    Parameters->append("wait");
    Parameters->append("WindowIndex");
    Parameters->append("zbound");

    (*NbParameters) = Parameters->count();
    return Parameters;
}


