#ifndef NUMBEREDTEXTEDIT_H
#define NUMBEREDTEXTEDIT_H

#pragma once
#include <QTextEdit>

class LineNumberArea;

class NumberedTextEdit : public QTextEdit {
    Q_OBJECT
public:
    explicit NumberedTextEdit(QWidget* parent = nullptr);

    void setLineNumbersVisible(bool on);
    bool lineNumbersVisible() const { return m_showLineNumbers; }

    int  lineNumberAreaWidth() const;
    void lineNumberAreaPaintEvent(QPaintEvent* e);

protected:
    void resizeEvent(QResizeEvent* e) override;

private slots:
    void updateLineNumberAreaWidth();
    void refreshLineNumberArea();
    void highlightCurrentLine();

private:
    LineNumberArea* m_lineArea = nullptr;
    bool m_showLineNumbers = true;
};
#endif // NUMBEREDTEXTEDIT_H

