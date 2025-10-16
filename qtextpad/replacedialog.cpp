#include "replacedialog.h"
#include "ui_replacedialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);

    // Brancher les boutons aux signaux “métier” du dialog
    connect(ui->btnFindNext,    &QPushButton::clicked, this, &ReplaceDialog::findNextRequested);
    connect(ui->btnReplace,     &QPushButton::clicked, this, &ReplaceDialog::replaceOneRequested);
    connect(ui->btnReplaceAll,  &QPushButton::clicked, this, &ReplaceDialog::replaceAllRequested);
    connect(ui->btnClose,       &QPushButton::clicked, this, &QDialog::close);

}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

QString ReplaceDialog::findText() const    { return ui->lineFind->text(); }
QString ReplaceDialog::replaceText() const { return ui->lineReplace->text(); }
Qt::CaseSensitivity ReplaceDialog::caseSensitivity() const {
    return ui->checkCase->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
}
