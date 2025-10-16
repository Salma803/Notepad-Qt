#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

    QString findText() const;
    QString replaceText() const;
    Qt::CaseSensitivity caseSensitivity() const;

signals:
    void findNextRequested();
    void replaceOneRequested();
    void replaceAllRequested();

private:
    Ui::ReplaceDialog *ui;
};

#endif // REPLACEDIALOG_H
