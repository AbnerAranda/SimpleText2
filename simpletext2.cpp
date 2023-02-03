#include "simpletext2.h"
#include "./ui_simpletext2.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

SimpleText2::SimpleText2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimpleText2)
{
    QLabel *campo1Label = new QLabel(tr("Campo 1:"));
    campo1Input = new QLineEdit;
    QLabel *campo2Label = new QLabel(tr("Campo 2:"));
    campo2Input = new QLineEdit;

    okButton = new QPushButton(tr("Ok"));
    okButton->show();
    clearButton = new QPushButton(tr("Clear"));
    clearButton->show();
    addButton = new QPushButton(tr("Add"));
    addButton->show();

    connect(okButton, &QPushButton::clicked, this, &SimpleText2::saveText);
    connect(clearButton, &QPushButton::clicked, this, &SimpleText2::clearText);
    connect(addButton, &QPushButton::clicked, this, &SimpleText2::add);

    QHBoxLayout *campo1Layout = new QHBoxLayout;
    campo1Layout->addWidget(campo1Label);
    campo1Layout->addWidget(campo1Input);

    QHBoxLayout *campo2Layout = new QHBoxLayout;
    campo2Layout->addWidget(campo2Label);
    campo2Layout->addWidget(campo2Input);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(clearButton);
    buttonsLayout->addWidget(addButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(campo1Layout);
    mainLayout->addLayout(campo2Layout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);
    setWindowTitle("Simple Text 2");

    ui->setupUi(this);
}

void SimpleText2::saveText(){
    QString printPreviousText;
    for(auto[value1, value2] : collect.asKeyValueRange()){
        printPreviousText = printPreviousText + "Campo 1: " + value1 + "\n" + "Campo 2: " + value2 + "\n" + "\n";
    }
    QString campo1Print = campo1Input->displayText();
    QString campo2Print = campo2Input->displayText();
    QString printLastText = "Campo 1: " + campo1Print + "\n" + "Campo 2: " + campo2Print + "\n";
    QString printText = printPreviousText + printLastText;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Text"), "",tr("Text (*.txt);;All Files (*)"));
    clearText();

    if(fileName.isEmpty())
            return;
        else{
                QFile file(fileName);
                if (!file.open(QIODevice::WriteOnly)) {
                    QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                    return;
                }
                QTextStream out(&file);
                out << printText;
            }
}

void SimpleText2::clearText(){
    campo1Input->clear();
    campo2Input->clear();
}

void SimpleText2::add(){
    oldCampo1 = campo1Input->text();
    oldCampo2 = campo2Input->text();
    collect.insert(oldCampo1,oldCampo2);
    clearText();
}

SimpleText2::~SimpleText2()
{
    delete ui;
}

