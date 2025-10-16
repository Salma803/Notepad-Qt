/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QLineEdit *lineFind;
    QLineEdit *lineReplace;
    QCheckBox *checkCase;
    QPushButton *btnReplaceAll;
    QPushButton *btnReplace;
    QPushButton *btnFindNext;
    QPushButton *btnClose;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName("ReplaceDialog");
        ReplaceDialog->resize(400, 300);
        lineFind = new QLineEdit(ReplaceDialog);
        lineFind->setObjectName("lineFind");
        lineFind->setGeometry(QRect(32, 40, 331, 28));
        lineReplace = new QLineEdit(ReplaceDialog);
        lineReplace->setObjectName("lineReplace");
        lineReplace->setGeometry(QRect(30, 90, 331, 28));
        checkCase = new QCheckBox(ReplaceDialog);
        checkCase->setObjectName("checkCase");
        checkCase->setGeometry(QRect(140, 130, 121, 25));
        btnReplaceAll = new QPushButton(ReplaceDialog);
        btnReplaceAll->setObjectName("btnReplaceAll");
        btnReplaceAll->setGeometry(QRect(210, 260, 90, 29));
        btnReplace = new QPushButton(ReplaceDialog);
        btnReplace->setObjectName("btnReplace");
        btnReplace->setGeometry(QRect(110, 260, 90, 29));
        btnFindNext = new QPushButton(ReplaceDialog);
        btnFindNext->setObjectName("btnFindNext");
        btnFindNext->setGeometry(QRect(10, 260, 90, 29));
        btnClose = new QPushButton(ReplaceDialog);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(310, 260, 90, 29));

        retranslateUi(ReplaceDialog);

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QCoreApplication::translate("ReplaceDialog", "Dialog", nullptr));
        checkCase->setText(QCoreApplication::translate("ReplaceDialog", "case sensitive", nullptr));
        btnReplaceAll->setText(QCoreApplication::translate("ReplaceDialog", "Replace All", nullptr));
        btnReplace->setText(QCoreApplication::translate("ReplaceDialog", "Replace", nullptr));
        btnFindNext->setText(QCoreApplication::translate("ReplaceDialog", "Find Next", nullptr));
        btnClose->setText(QCoreApplication::translate("ReplaceDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
