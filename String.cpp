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
 * \brief indexOf
 * \param string
 * \param separators
 * \param from
 * \return
 */
int indexOf(const QString string, const QStringList *separators, const int from){
    unsigned int NbSep = separators->count();
    if (NbSep == 0) return -1;

    QVector<unsigned int> Pos;

    for (unsigned int i = 0; i < NbSep; i++){
        int pos = string.indexOf(separators->at(i), from);
        if (pos != -1){
            Pos.append(pos);
        }
    }

    unsigned int NbPos = Pos.count();
    if (NbPos == 0) return -1;

    unsigned int MinPos = Pos.at(0);
    for (unsigned int i = 0; i < NbPos; i++){
        if (MinPos > Pos.at(i)) MinPos = Pos.at(i);
    }
    return (int)MinPos;
}


