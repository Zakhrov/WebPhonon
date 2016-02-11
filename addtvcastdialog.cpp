#include "addtvcastdialog.h"
#include "ui_addtvcastdialog.h"

AddTVCastDialog::AddTVCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTVCastDialog)
{
    ui->setupUi(this);
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
    db.open();
    query=new QSqlQuery(db);
    if(db.driverName()=="QSQLITE")
        query->prepare("INSERT INTO `tv_cast` (`tv_id`, `actor_id`, `charecter_name`, `role`) VALUES (:tv_id, :actor_id, :charecter_name, :role);");
    else
    query->prepare("INSERT INTO `webphonon`.`tv_cast` (`tv_id`, `actor_id`, `charecter_name`, `role`) VALUES (:tv_id, :actor_id, :charecter_name, :role);");
    query->bindValue(":tv_id",tv_id);
    query->bindValue(":actor_id",actor_id);
    query->bindValue(":charecter_name",charecter);
    query->bindValue(":role",role);
    if(query->exec())
    {
        msg.setText("TV Charecter and Role Added");
    }
    else
    {
        msg.setText("Error"+query->lastError().text());
    }
    msg.exec();
    //db.close();
    //this->close();


}

void AddTVCastDialog::on_pushButton_2_clicked()
{
    this->close();
}
