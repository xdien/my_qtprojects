/****************************************************************************
 *   Copyright 2014 Unknown <bdienw@gmail.com>								*
 * 																			*
 * This program is free software; you can redistribute it and/or modify		*
 * it under the terms of the GNU General Public License as published by		*
 * the Free Software Foundation; either version 2 of the License, or		*
 * (at your option) any later version.										*
 * 																			*
 * This program is distributed in the hope that it will be useful,			*
 * but WITHOUT ANY WARRANTY; without even the implied warranty of			*
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			*
 * GNU General Public License for more details.								*
 * 																			*
 * You should have received a copy of the GNU General Public License		*
 * along with this program; if not, write to the Free Software				*
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,				*
 * MA 02110-1301, USA.                  		                            *
 *                                                                    		*
 ***************************************************************************/

#ifndef DIALOG_CHONQUY_H
#define DIALOG_CHONQUY_H

#include <QDialog>

namespace Ui {
class dialog_chonquy;
}

class dialog_chonquy : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_chonquy(QWidget *parent = 0);
    ~dialog_chonquy();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::dialog_chonquy *ui;
};

#endif // DIALOG_CHONQUY_H
