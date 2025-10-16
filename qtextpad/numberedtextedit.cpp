#include "numberedtextedit.h"

#include <QPainter>
#include <QPaintEvent>
#include <QTextBlock>
#include <QAbstractTextDocumentLayout>
#include <QScrollBar>

class LineNumberArea : public QWidget {
public:
    explicit LineNumberArea(NumberedTextEdit* ed) : QWidget(ed), editor(ed) {}
    QSize sizeHint() const override { return QSize(editor->lineNumberAreaWidth(), 0); }
protected:
    void paintEvent(QPaintEvent* e) override { editor->lineNumberAreaPaintEvent(e); }
private:
    NumberedTextEdit* editor;
};

NumberedTextEdit::NumberedTextEdit(QWidget* parent)
    : QTextEdit(parent)
{
    setAcceptRichText(false);             // plain-text behavior (optional)
    m_lineArea = new LineNumberArea(this);

    // Recompute margins when block count changes or font changes
    connect(document(), &QTextDocument::blockCountChanged,
            this, &NumberedTextEdit::updateLineNumberAreaWidth);

    // Scroll/contents changes → repaint gutter
    connect(verticalScrollBar(), &QScrollBar::valueChanged,
            this, &NumberedTextEdit::refreshLineNumberArea);
    connect(this, &QTextEdit::textChanged,
            this, &NumberedTextEdit::refreshLineNumberArea);

    // Document layout updates (e.g., rewrap) → repaint gutter
    connect(document()->documentLayout(), &QAbstractTextDocumentLayout::documentSizeChanged,
            this, &NumberedTextEdit::refreshLineNumberArea);

    connect(this, &QTextEdit::cursorPositionChanged,
            this, &NumberedTextEdit::highlightCurrentLine);

    updateLineNumberAreaWidth();
    highlightCurrentLine();
}

void NumberedTextEdit::setLineNumbersVisible(bool on)
{
    if (m_showLineNumbers == on) return;
    m_showLineNumbers = on;
    m_lineArea->setVisible(on);
    updateLineNumberAreaWidth();
    viewport()->update();
}

int NumberedTextEdit::lineNumberAreaWidth() const
{
    if (!m_showLineNumbers) return 0;
    int digits = 1;
    int max = qMax(1, document()->blockCount());
    while (max >= 10) { max /= 10; ++digits; }
    const int pad = 4;
    return pad + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits + pad;
}

void NumberedTextEdit::updateLineNumberAreaWidth()
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
    refreshLineNumberArea();
}

void NumberedTextEdit::refreshLineNumberArea()
{
    if (!m_showLineNumbers) return;
    const QRect vr = viewport()->rect();
    m_lineArea->update(0, vr.y(), m_lineArea->width(), vr.height());
}

void NumberedTextEdit::resizeEvent(QResizeEvent* e)
{
    QTextEdit::resizeEvent(e);
    const QRect cr = contentsRect();
    m_lineArea->setGeometry(QRect(cr.left(), cr.top(),
                                  lineNumberAreaWidth(), cr.height()));
}

void NumberedTextEdit::lineNumberAreaPaintEvent(QPaintEvent* event)
{
    if (!m_showLineNumbers) return;

    QPainter p(m_lineArea);
    p.fillRect(event->rect(), palette().window());
    p.setPen(palette().text().color());

    QAbstractTextDocumentLayout* layout = document()->documentLayout();

    // Document coordinates → viewport coordinates:
    const int yOffset = verticalScrollBar() ? verticalScrollBar()->value() : 0;
    const int viewHeight = viewport()->height();

    QTextBlock block = document()->firstBlock();
    int lineNumber = 0;

    while (block.isValid()) {
        const QRectF br = layout->blockBoundingRect(block);  // in doc coords
        const int top    = int(br.top())  - yOffset;
        const int bottom = int(br.bottom()) - yOffset;

        if (bottom >= 0 && top <= viewHeight) {
            // Visible → draw
            const QString num = QString::number(lineNumber + 1);
            const int h = fontMetrics().height();
            p.drawText(0, top, m_lineArea->width() - 4, h,
                       Qt::AlignRight | Qt::AlignVCenter, num);
        }

        if (top > viewHeight) break;      // past viewport
        block = block.next();
        ++lineNumber;
    }
}

void NumberedTextEdit::highlightCurrentLine()
{
    // Optional: highlight the current line background
    QList<QTextEdit::ExtraSelection> extras;
    QTextEdit::ExtraSelection sel;
    sel.format.setBackground(palette().alternateBase());
    sel.format.setProperty(QTextFormat::FullWidthSelection, true);
    sel.cursor = textCursor();
    sel.cursor.clearSelection();
    extras << sel;
    setExtraSelections(extras);

    // Also keep gutter repainted around caret
    refreshLineNumberArea();
}
