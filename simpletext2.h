#ifndef SIMPLETEXT2_H
#define SIMPLETEXT2_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class SimpleText2; }
QT_END_NAMESPACE

class SimpleText2 : public QWidget
{
    Q_OBJECT

public:
    SimpleText2(QWidget *parent = nullptr);
    ~SimpleText2();

 public slots:
    void saveText();
    void clearText();
    void add();

private:
    Ui::SimpleText2 *ui;
    QLineEdit *campo1Input;
    QLineEdit *campo2Input;
    QPushButton *okButton;
    QPushButton *clearButton;
    QPushButton *addButton;

    QMap<QString, QString> collect;
    QString oldCampo1;
    QString oldCampo2;

};
#endif // SIMPLETEXT2_H
