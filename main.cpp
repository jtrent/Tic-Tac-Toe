/*
 * Copyright (c) 2010 Jon Trent
 * For usage information see COPYING for copyright and usage information.
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication    a(argc, argv);
    MainWindow      w;

    w.show();

    return a.exec();
}
