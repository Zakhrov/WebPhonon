#include "addactordialog.h"
#include "ui_addactordialog.h"
#include <QMessageBox>
AddActorDialog::AddActorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddActorDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Actor");

}

AddActorDialog::~AddActorDialog()
{
    delete ui;
}

void AddActorDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    actor=ui->lineEdit->text();
    db=QSqlDatabase::database("PlayConn");
    model=new QSqlTableModel(this,db);
    model->setTable("actor");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("name",QVariant(actor));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Actor Added");

        }
        else
        {
            msg.setText(model->lastError().text());

        }

    }
    else
    {
        msg.setText(model->lastError().text());
    }
    msg.exec();


}

void AddActorDialog::on_pushButton_2_clicked()
{
    this->close();
}
