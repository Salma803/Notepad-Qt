#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QCloseEvent>
#include <iostream>
#include <QSettings>
#include <QFontDialog>
#include<QCursor>
#include<QInputDialog>
#include<QTextBlock>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent) :
	QMainWindow(parent),
	settings("ENSIIE", "QTextPad"),
	ui(new Ui::MainWindow)
{
	nvCount = 1;
	ui->setupUi(this);
	ui->tabWidget->removeTab(0);
	on_actionNouveau_triggered();

	documentPaths.clear();
	documentPaths = settings.value("recentDocuments").toStringList();

    //question1
    QVariant v = settings.value("editorFont",QFont("Times",12));
    m_editorFont = v.value<QFont>();
    applyEditorFont(m_editorFont);


    //Question2
    m_cursorLabel = new QLabel(this);
    ui->statusBar->addPermanentWidget(m_cursorLabel);
    m_cursorLabel -> setText(tr("Ligne 1, Col 1"));


	updateRecentMenu();
	connect(ui->menuDocuments_r_cents, SIGNAL(triggered(QAction *) ),
            this, SLOT(openRecent(QAction *) ));
}

MainWindow::~MainWindow()
{
	settings.setValue("recentDocuments", documentPaths);
    //question1
    settings.setValue("editorFont",m_editorFont);

	delete ui;
}

void MainWindow::on_actionNouveau_triggered()
{
    //question1 is adding this editor and don't forget to change the new QTextEditor inise addTab
    QTextEdit * editor = new QTextEdit();
    editor -> setFont(m_editorFont);
    editor->document()->setDefaultFont(m_editorFont);
	int ct = ui->tabWidget->addTab(
        editor, "Nouveau document " + QString::number(nvCount++));
	ui->tabWidget->setCurrentIndex(ct);

    //question2
    connectEditorSignals(editor);
}

void MainWindow::on_actionCouper_triggered()
{
	currentTextEdit()->cut();
}

void MainWindow::on_actionCopier_triggered()
{
	currentTextEdit()->copy();
}

void MainWindow::on_actionColler_triggered()
{
	currentTextEdit()->paste();
}

void MainWindow::on_actionS_lectionner_tout_triggered()
{
	currentTextEdit()->selectAll();
}

void MainWindow::on_actionD_faire_triggered()
{
	currentTextEdit()->undo();
}

void MainWindow::on_actionRefaire_triggered()
{
	currentTextEdit()->redo();
}

void MainWindow::on_actionEnregistrer_sous_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(
		this, "Enregister sous...", "", "Fichiers texte (*.txt)");
	if (!fileName.isEmpty())
	{
		saveFile(fileName);
	}
}

void MainWindow::on_actionEnregistrer_triggered()
{
	if (currentTextEdit()->property("fileName").isValid())
	{
		saveFile(currentTextEdit()->property("fileName").toString());
	}
	else
	{
		on_actionEnregistrer_sous_triggered();
	}
}

void MainWindow::saveFile(const QString & fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly))
	{
		manageRecentDocument(fileName);
		QTextStream ts(&file);
		ts << currentTextEdit()->toPlainText();
		ts.flush();
		file.close();
		currentTextEdit()->setProperty("fileName", fileName);
		currentTextEdit()->document()->setModified(false);
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),
								  QFileInfo(fileName).fileName());
	}
	else
		QMessageBox::critical(
			this,
			"Echec de sauvegarde",
			"Le fichier " + fileName + " n'a pas pu être sauvegarde.");
}




inline QTextEdit * MainWindow::currentTextEdit()
{
	return dynamic_cast<QTextEdit *>(ui->tabWidget->currentWidget());
}

void MainWindow::readFile(const QString & fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly))
	{
		manageRecentDocument(fileName);
		on_actionNouveau_triggered();
		QTextStream ts(&file);
		currentTextEdit()->setPlainText(ts.readAll());
		currentTextEdit()->setProperty("fileName", fileName);
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),
								  QFileInfo(fileName).fileName());
		file.close();
	}
}
void MainWindow::updateRecentMenu()
{
	ui->menuDocuments_r_cents->clear();

	for (int i = 0; i < documentPaths.length(); i++)
	{
		if (!QFile::exists(documentPaths[i]))
		{
			documentPaths.removeAll(documentPaths[i]);
			i--;
		}
		else
		{
			ui->menuDocuments_r_cents->addAction(documentPaths[i]);
		}
	}
}

void MainWindow::on_actionOuvrir_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(
		this, "Ouvrir un fichier", "", "Text files (*.txt)");
	if (!fileName.isEmpty())
	{
		readFile(fileName);
	}
}

void MainWindow::on_actionFermer_triggered()
{
	if (currentTextEdit()->document()->isModified())
	{
		if (QMessageBox::question(this,
								  "Modification détectée",
								  "Le fichier en cours d'édition a été "
								  "modifié.\nVoulez-vous le sauvegarder ?",
								  QMessageBox::Yes,
								  QMessageBox::No) == QMessageBox::Yes)
			on_actionEnregistrer_triggered();
	}
	ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::closeEvent(QCloseEvent * ce)
{
	bool allSaved = true;

	for (int i = 0; i < ui->tabWidget->count(); i++)
	{
		QTextEdit * editor = dynamic_cast<QTextEdit *>(ui->tabWidget->widget(i));
		if (editor != NULL)
		{
			allSaved = allSaved && (!editor->document()->isModified());
		}
	}

	if (!allSaved)
	{
		// demande et sauve les fichiers.
		int button =
			QMessageBox::question(this,
								  "Documents modifiés non sauvegardés",
								  "Des fichiers n'ont pas été "
								  "sauvegardés.\nVoulez vous les enregistrer ?",
								  QMessageBox::NoAll,
								  QMessageBox::YesAll,
								  QMessageBox::Cancel);
		if (button == QMessageBox::Cancel)
		{
			ce->ignore();
			return;
		}
		if (button == QMessageBox::YesAll)
		{
			for (int i = 0; i < ui->tabWidget->count(); i++)
			{
				ui->tabWidget->setCurrentIndex(i);
				if (currentTextEdit()->document()->isModified())
				{
					on_actionEnregistrer_triggered();
				}
			}
		}
	}
	ce->accept();
}



void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
	ui->tabWidget->setCurrentIndex(index);
	on_actionFermer_triggered();
}

void MainWindow::manageRecentDocument(const QString & s)
{
	if (documentPaths.contains(s))
	{
		documentPaths.removeAll(s);
	}

	documentPaths.push_front(s);

	while (documentPaths.length() > 6)
	{
		documentPaths.pop_back();
	}

	settings.setValue("recentDocuments", documentPaths);
	updateRecentMenu();
}

void MainWindow::openRecent(QAction * a)
{
	readFile(a->text());
}

//question1
void MainWindow::on_actionR_gler_la_police_triggered()
{
    bool ok = false;
    QFont start = m_editorFont;
    QFont font = QFontDialog::getFont(&ok,start,this,tr("Choisir la police"));

    if(!ok){
        return;
    }
    applyEditorFont(font);
    settings.setValue("editorFont",font);
}

//Question1
void MainWindow::applyEditorFont(const QFont &f)
{
    m_editorFont = f;

    for(int i=0;i<ui->tabWidget->count();++i){

        QTextEdit * editor = dynamic_cast<QTextEdit *>(ui->tabWidget->widget(i));
        if(editor != NULL){
            editor -> setFont(f);
            editor -> document() -> setDefaultFont(f);
        }
    }
}

//question2
void MainWindow::updateCursorPos(QTextEdit *editor)
{
    if(!editor||!m_cursorLabel){
        return;
    }

    QTextCursor c = editor -> textCursor();
    int line = c.blockNumber() +1;
    int col = c.positionInBlock();

    m_cursorLabel->setText(tr("Ligne %1, Col %2").arg(line).arg(col));
}
//question2
void MainWindow::connectEditorSignals(QTextEdit *editor)
{
    connect(editor,&QTextEdit::cursorPositionChanged,this,[this,editor]{
        updateCursorPos(editor);
    });

    updateCursorPos(editor);
}




//question3
void MainWindow::on_actionSe_rendre_a_la_ligne_triggered()
{
    auto* editor = currentTextEdit();
    if(!editor){
        return;
    }

    const int lineCount =  editor -> document() ->blockCount();

    const int currentLine = editor->textCursor().blockNumber() + 1;

    bool ok = false;
    const int line = QInputDialog::getInt(
        this,
        tr("Aller à la ligne"),
        tr("Numéro de la ligne (1-%1) :").arg(lineCount),
        currentLine,
        1,
        lineCount,
        1,
        &ok);
    if (!ok){
        return;
    }

    QTextCursor c = editor ->textCursor();
    int target = line;
    c.movePosition(QTextCursor::Start);
    if(target >1){
        c.movePosition(QTextCursor::Down,QTextCursor::MoveAnchor,target-1);

    }
    editor->setTextCursor(c);

}


//Question4
void MainWindow::on_actionRechercher_triggered()
{
    QTextEdit * editor = currentTextEdit();
    if(!editor){
        return;
    }

    bool ok = false;

    const QString mot = QInputDialog::getText(this,
                                     tr("Rechercher"),
                                     tr("Texte à rechercher"),
                                     QLineEdit::Normal,
                                     m_lastFindText,
                                              &ok);

    if(!ok || mot.isEmpty()){
        return;
    }

    const QStringList modes = {tr("Insensible à la case"),tr("Sensible à la case")};
    const int choix = QInputDialog::getItem(
        this,
        tr("Option"),
        tr("Sensibilité:"),
        modes,
        (m_lastCase == Qt::CaseSensitive?1:0),
        false,
        &ok
                          ).toInt();
    const Qt::CaseSensitivity cs = (choix == 1? Qt::CaseSensitive : Qt::CaseInsensitive);

    //mémoriser le mot et le mode
    m_lastFindText = mot;
    m_lastCase = cs ;

    //le mot ne se trouve pas dans le doc
    if(!findNextInEditor(editor,mot,cs,true)){
        QMessageBox::information(this,tr("Recherche"),tr("Le mot <%1> n'apparait as dans le document").arg(mot));
    }
}
//Question4
bool MainWindow::findNextInEditor(QTextEdit *editor, const QString &mot, Qt::CaseSensitivity cs, bool isWrapIfEnd){
    if(!editor || mot.isEmpty()){
        return false;
    }

    QTextDocument* doc = editor -> document();
    QTextCursor start = editor ->textCursor();

    QTextDocument::FindFlags flags;
    if(cs == Qt::CaseSensitive){
        flags |= QTextDocument::FindCaseSensitively;
    }

    QTextCursor hit = doc -> find(mot,start,flags);

    if(hit.isNull() && isWrapIfEnd){
        QTextCursor fromStart(doc);
        fromStart.movePosition(QTextCursor::Start);
        hit = doc->find(mot,fromStart,flags);
    }

    if(hit.isNull()){
        return false;
    }

    editor -> setTextCursor(hit);
    editor ->ensureCursorVisible();

    return true;


}

//Question4
void MainWindow::on_actionRechercher_suivant_triggered()
{
    auto* editor = currentTextEdit();
    if(!editor){
        return;
    }
    if(m_lastFindText.isEmpty()){
        on_actionRechercher_triggered();
        return;
    }

    if(!findNextInEditor(editor,m_lastFindText,m_lastCase,true)){
        QMessageBox::information(this,tr("Recherche Suivant"),tr("Plus d'occurence du mot <%1>").arg(m_lastFindText));
    }
}

//Question5
void MainWindow::on_actionRemplacer_triggered()
{
    if(!m_replaceDlg){
        m_replaceDlg = new ReplaceDialog(this);
    }

    //Suivant
    connect(m_replaceDlg, &ReplaceDialog::findNextRequested,this,[this]{

        auto* editor = currentTextEdit();
        if(!editor) return;
        const QString mot = m_replaceDlg->findText();
        const auto cs = m_replaceDlg->caseSensitivity();
        if(mot.isEmpty()){
            return;
        }
        m_lastFindText = mot ;
        m_lastCase = cs;

        if(!findNextInEditor(editor,mot,cs,true)){
            QMessageBox::information(this,tr("Recherche"),
                                     tr("%1 introuvable").arg(mot));
        }
    });

    //  Remplacer l'occurence
    connect(m_replaceDlg,&ReplaceDialog::replaceOneRequested,this,[this]{
        auto* editor = currentTextEdit();
        if(!editor) return;
        const QString mot = m_replaceDlg->findText();
        const QString repl = m_replaceDlg ->replaceText();
        const auto cs = m_replaceDlg->caseSensitivity();
        if(mot.isEmpty()){
            return;
        }
        if(!replaceCurrentOrNext(editor,mot,repl,cs)){
            QMessageBox::information(this, tr("Remplacer"),
                                     tr("« %1 » introuvable.").arg(mot));
        }

    });

    //Remplacer tout

    connect(m_replaceDlg,&ReplaceDialog::replaceAllRequested,this,[this]{
        auto* editor = currentTextEdit();
        if(!editor) return;
        const QString mot = m_replaceDlg->findText();
        const QString repl = m_replaceDlg ->replaceText();
        const auto cs = m_replaceDlg->caseSensitivity();
        if(mot.isEmpty()){
            return;
        }

        const int n = replaceAllInEditor(editor,mot,repl,cs);
        QMessageBox::information(this, tr("Remplacer tout"),
                                 tr("%1 occurrence(s) remplacée(s).").arg(n));
        m_replaceDlg->close(); // comme demandé par l’énoncé

    });
    m_replaceDlg->show();
    m_replaceDlg->raise();
    m_replaceDlg->activateWindow();
}

//Question5
bool MainWindow::replaceCurrentOrNext(QTextEdit* editor, const QString& mot,
                                      const QString& repl, Qt::CaseSensitivity cs)
{
    if (!editor || mot.isEmpty()) return false;

    QTextCursor c = editor->textCursor();
    const QString sel = c.selectedText();

    auto equal = [cs](const QString& a, const QString& b){
        return cs == Qt::CaseSensitive ? (a == b) : (a.compare(b, Qt::CaseInsensitive) == 0);
    };

    if (!sel.isEmpty() && equal(sel, mot)) {
        c.insertText(repl);              // remplace la sélection
        editor->setTextCursor(c);
        editor->ensureCursorVisible();
        return true;
    }

    // Sinon, cherche la prochaine occurrence puis remplace
    if (!findNextInEditor(editor, mot, cs, /*wrap*/true))
        return false;

    c = editor->textCursor();                // maintenant on a une sélection
    c.insertText(repl);
    editor->setTextCursor(c);
    editor->ensureCursorVisible();
    return true;
}

int MainWindow::replaceAllInEditor(QTextEdit* editor, const QString& mot,
                                   const QString& repl, Qt::CaseSensitivity cs)
{
    if (!editor || mot.isEmpty()) return 0;

    QTextDocument* doc = editor->document();
    QTextDocument::FindFlags flags;
    if (cs == Qt::CaseSensitive) flags |= QTextDocument::FindCaseSensitively;

    int count = 0;

    QTextCursor pos(doc);
    pos.movePosition(QTextCursor::Start);

    editor->blockSignals(true);
    pos.beginEditBlock(); // opération undo/redo unique

    while (true) {
        QTextCursor hit = doc->find(mot, pos, flags);
        if (hit.isNull()) break;
        hit.insertText(repl);     // remplace
        ++count;
        pos = hit;                // continue après l’insert (fin du texte inséré)
    }

    pos.endEditBlock();
    editor->blockSignals(false);

    editor->ensureCursorVisible();

    return count;
}

