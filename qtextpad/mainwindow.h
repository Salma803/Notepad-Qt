#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "replacedialog.h"
#include <QMainWindow>
#include <QTextEdit>
#include <QStringList>
#include <QSettings>
#include <QFont>
#include <QLabel>
namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
	explicit MainWindow(QWidget * parent = 0);
	~MainWindow();
	void manageRecentDocument(const QString & s);

	private slots:
	void on_actionNouveau_triggered();
	void on_actionCouper_triggered();
	void on_actionCopier_triggered();
	void on_actionColler_triggered();
	void on_actionS_lectionner_tout_triggered();
	void on_actionD_faire_triggered();
	void on_actionRefaire_triggered();
	void on_actionEnregistrer_sous_triggered();
	void on_actionEnregistrer_triggered();
	void on_actionOuvrir_triggered();
	void on_actionFermer_triggered();
	void on_tabWidget_tabCloseRequested(int index);
	void openRecent(QAction * a);

    void on_actionR_gler_la_police_triggered();

    void on_actionSe_rendre_a_la_ligne_triggered();

    void on_actionRechercher_triggered();

    void on_actionRechercher_suivant_triggered();

    void on_actionRemplacer_triggered();

    void on_actionAfficher_les_num_ros_de_lignes_triggered();

protected:
	void closeEvent(QCloseEvent *);

	private:
	QStringList documentPaths;
	QSettings settings;
	Ui::MainWindow * ui;
	int nvCount;

    //question1
    QFont m_editorFont;
    void applyEditorFont(const QFont& f);

    //question2
    QLabel * m_cursorLabel = nullptr;
    void updateCursorPos(QTextEdit* editor);
    void connectEditorSignals(QTextEdit * editor);

    //question4

    QString m_lastFindText;
    Qt::CaseSensitivity m_lastCase = Qt::CaseInsensitive;
    bool findNextInEditor(QTextEdit * editor,
                          const QString& mot,
                          Qt::CaseSensitivity cs,
                          bool isWrapIfEnd=true);

    //question5
    ReplaceDialog* m_replaceDlg = nullptr;
    bool replaceCurrentOrNext(QTextEdit* ed, const QString& mot,
                              const QString& repl, Qt::CaseSensitivity cs);
    int  replaceAllInEditor(QTextEdit* ed, const QString& mot,
                           const QString& repl, Qt::CaseSensitivity cs);



	QTextEdit * currentTextEdit();
	void saveFile(const QString & fileName);
	void readFile(const QString & fileName);
	void updateRecentMenu();
};

#endif // MAINWINDOW_H
