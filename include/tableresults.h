#ifndef TABLERESULTS_H
#define TABLERESULTS_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class TableResults;
}

class TableResults : public QWidget
{
    Q_OBJECT
    QSqlDatabase db;
    const QString nameDB = "phonebook";

public:

    explicit TableResults(QWidget *parent = 0);
    ~TableResults();

    void addRow(QString name, QString score);

    void deleteRaw(int raw);
private slots:
    void on_AddButton_clicked();

    void on_CreateButton_clicked();

    void on_ReadButton_clicked();

    void on_SearchButton_clicked();

    void on_DeleteButton_clicked();


private:
    Ui::TableResults *ui;
};

#endif // TABLERESULTS_H


