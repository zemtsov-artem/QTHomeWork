#include "tableresults.h"
#include "ui_tableResults.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QSqlRecord>

TableResults::TableResults(QWidget *parent) : QWidget(parent),ui(new Ui::TableResults)
{
    ui->setupUi(this);

    on_CreateButton_clicked();
    on_ReadButton_clicked();

}

void TableResults::on_DeleteButton_clicked()
{
    //ui->DeleteButton->setText("123");

    //int targetRow = ui->tableWidget->SelectRows;
    //ui->DeleteButton->setText(QString::number(targetRow));
    QList<QTableWidgetItem *> selectedList = ui->tableWidget->selectedItems();
    int targetRow = selectedList.last()->row();
    ui->DeleteButton->setText(QString::number(targetRow));
    deleteRaw(targetRow+1);
     on_ReadButton_clicked();


}

void TableResults::addRow(QString name, QString score)
{
    if (!db.isOpen())
    {//DB reopen
        db.open();
    }

     //Get the latest id
    QSqlQuery *getGuery = new QSqlQuery("SELECT MAX(id) FROM "+nameDB, db);
    int id = 0;
    while (getGuery->next()) {
        id = getGuery->value(0).toInt();
    }
    QSqlQuery *query =
    new QSqlQuery(QString("INSERT INTO "+nameDB+" (id, name, score) VALUES(") +
                QString::number(id+1) + QString(",'") + name + QString("','") +
                score + QString("');"), db);
    db.close();
    delete getGuery;
    delete query;
    on_ReadButton_clicked();
}

void TableResults::deleteRaw(int raw)
{
    if (!db.isOpen())
    {//DB reopen
        db.open();
    }

     //Get the latest id

    //QSqlQuery *query = new QSqlQuery("DELETE FROM "+nameDB+" WHERE id ="+raw, db);
    QSqlQuery *query = new QSqlQuery();
    query->prepare("DELETE FROM "+nameDB+" WHERE id = ?");
    query->addBindValue(raw);
    query->exec();

    db.close();
    delete query;
    on_ReadButton_clicked();
}

TableResults::~TableResults()
{
    delete ui;
}

void TableResults::on_AddButton_clicked()
{
    if (!db.isOpen())
    {//DB reopen
        db.open();
    }

     //Get the latest id
    QSqlQuery *getGuery = new QSqlQuery("SELECT MAX(id) FROM " + nameDB, db);
    int id = 0;
    while (getGuery->next()) {
        id = getGuery->value(0).toInt();
    }

    db.close();
    delete getGuery;
    //delete query;
    on_ReadButton_clicked();
}

void TableResults::on_CreateButton_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F:\\ScoreBook.sqlite");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }
    QSqlQuery *query = new QSqlQuery("CREATE TABLE "+nameDB+" (id INTEGER, name TEXT, score TEXT)", db);
    db.close();
    delete query;

    ui->tableWidget->setColumnCount(2); // Указываем число колонок
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    //ui->tableWidget->setHorizontalHeaderLabels(headers);

    QStringList label;
    label<<"name"<<"score";
    ui->tableWidget->setHorizontalHeaderLabels(label);
}

void TableResults::on_ReadButton_clicked()
{
    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery *query = new QSqlQuery(QString("SELECT * FROM "+ nameDB), db);
    QSqlRecord rec = query->record();
    int id = 0;
    QString name = "";
    QString score= "";
    int count =0;
    ui->tableWidget->setRowCount(0);
    while (query->next())
    {
        id = query->value(rec.indexOf("id")).toInt();
        name = query->value(rec.indexOf("name")).toString();
        score = query->value(rec.indexOf("score")).toString();
        qDebug() << "id " << id  << "text " << name << "score "<<score;
        ui->tableWidget->insertRow(count);
       // ui->tableWidget->setItem(count,0,new QTableWidgetItem(QString(id)));
        ui->tableWidget->setItem(count,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(count,1,new QTableWidgetItem(score));
        count++;

    }
    db.close();
    delete query;

}

void TableResults::on_SearchButton_clicked()
{

    if (!db.isOpen())
    {
        db.open();
    }

    QSqlQuery *query = new QSqlQuery(QString("SELECT * FROM " + nameDB), db);
    QSqlRecord rec = query->record();
    int id = 0;
    QString name = "";
    QString score= "";
    int count=0;
    ui->tableWidget->setRowCount(0);
    while (query->next())
    {
        id = query->value(rec.indexOf("id")).toInt();
        name = query->value(rec.indexOf("name")).toString();
        score = query->value(rec.indexOf("score")).toString();
        if(name.toLower() == ui->SearchNameEdit->text().toLower())
        {
            qDebug() << "id " << id  << "text " << name << "score "<<score;
            ui->tableWidget->insertRow(count);
            ui->tableWidget->setItem(count,0,new QTableWidgetItem(name));
            ui->tableWidget->setItem(count,1,new QTableWidgetItem(score));
            count++;
        }
    }
    db.close();
    delete query;
}
