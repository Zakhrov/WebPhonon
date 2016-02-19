#include "addtvcastdialog.h"
#include "ui_addtvcastdialog.h"

AddTVCastDialog::AddTVCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTVCastDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Actors to TV Shows");
    db=QSqlDatabase::database("PlayConn");
    db.open();
    model1=new QSqlQueryModel(this);
    model1->setQuery("select tv_id, title from tv",db);
    model2=new QSqlQueryModel(this);
    model2->setQuery("select actor_id, actor.name from actor",db);
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(1);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
}

AddTVCastDialog::~AddTVCastDialog()
{
    delete ui;

}

void AddTVCastDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    charecter=ui->lineEdit->text();
    role=ui->lineEdit_2->text();
    actor_id = model2->data(model2->index(ui->comboBox_2->currentIndex(),0)).toInt();
    tv_id = model1->data(model1->index(ui->comboBox->currentIndex(),0)).toInt();
    model=new QSqlTableModel(this,db);
    model->setTable("tv_cast");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("charecter_name",QVariant(charecter));
    record.setValue("role",QVariant(role));
    record.setValue("actor_id",QVariant(actor_id));
    record.setValue("tv_id",QVariant(tv_id));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Tv Cast Added");

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

void AddTVCastDialog::on_pushButton_2_clicked()
{
    this->close();
}
