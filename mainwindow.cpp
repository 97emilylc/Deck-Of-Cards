#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->userPage->setCurrentIndex(LOGIN);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void ReadTransaction(transaction transList[], QString fileName)
{
    int AR_SIZE = 100;
    int i = 0;
    QFile inFile(fileName);
    if(!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open file for input.";
        return;
    }
     QTextStream in(&inFile);

     while(i < AR_SIZE && !in.atEnd())
    {

        // Reading in the Date
        QString dateString;
        Date    dateOfTrans;
        dateString = in.readLine();
        dateOfTrans.StringToDate(dateString);

        //Reading in the member id
        int memberID;
        memberID = (in.readLine()).toInt();

        //Reading in the item name
        QString itemName;
        itemName = in.readLine();

        //Reading in the price and quantity
        QString inputLine;
        float price;
        int quantity;
        inputLine = in.readLine();
        QStringList priceAndQuan = inputLine.split("\t", QString::SkipEmptyParts);
        price = (priceAndQuan.at(0)).toFloat();
        quantity = (priceAndQuan.at(1)).toInt();


        // Assigning to Struct
        transList[i].transDate = dateOfTrans;
        transList[i].memNum    = memberID;
        transList[i].itemName  = itemName;
        transList[i].price     = price;
        transList[i].quantity  = quantity;

        i++;
    }

    inFile.close();
}
member* ReadMemberInfo(QString fileName)
{
    QFile inFile(fileName);
    if(!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open file for input.";
    }
     QTextStream in(&inFile);

     member *head;
     member *memberPtr;
     memberPtr = head;

     head = new member;
//NOT FINISHED
     while(!in.atEnd())
     {

     };
}

void ReadLoginInfo(loginInfo fileLoginInfo[], QString fileName)
{
    int AR_SIZE = 100;
    QFile inFile(fileName);
    if(!inFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open file for input.";
        return;
    }
     QTextStream in(&inFile);
    for(int i = 0; i < AR_SIZE; i++)
    {
        QString line1 = in.readLine();
        QString line2 = in.readLine();

        fileLoginInfo[i].passWord = line2;
        fileLoginInfo[i].userName = line1;
    }

    inFile.close();
}

void MainWindow::on_LoginBtn_clicked()
{

    QString test = "C:/Users/Emily/Desktop/GitHub/Bulk_Club/Files/day1.txt";

    loginInfo managerInfo[100];
    loginInfo adminInfo[100];

    ReadLoginInfo(managerInfo, ADMIN_FILE);
    ReadLoginInfo(adminInfo, MANAGER_FILE);

    QString username;
    QString password;

    QString managerUserKey;
    QString managerPassKey;

    QString adminUserKey;
    QString adminPassKey;

    username = ui->usernameBox->text();
    password = ui->passwordBox->text();

    int index;
    bool found;
    found = false;
    index = 0;


    /***************
     *  Logging In *
     ***************/
    while(index < 100 && !found)
    {
        managerUserKey = managerInfo[index].userName;
        managerPassKey = managerInfo[index].passWord;
        adminUserKey = adminInfo[index].userName;
        adminPassKey = adminInfo[index].passWord;

        if(username == "" && password == "")
        {
                ui->errorLabel->setText("Please Enter a Username and Password.");
        }
        else if(username == managerUserKey && password == managerPassKey)
        {
            ui->userPage->setCurrentIndex(MANGR);
        }
        else if(username == adminUserKey && password == adminPassKey)
        {
            ui->userPage->setCurrentIndex(ADMIN);;
        }
        else if(username == "" && password == "")
        {
                ui->errorLabel->setText("Please Enter a Username and Password.");
        }
        else
        {
            ui->errorLabel->setText("Invalid username or password.");
            ui->passwordBox->setText("");
        }
        index++;
    }
}


/****************
 *  Logging Out *
 ****************/
void MainWindow::on_LogoutBtn_clicked()
{
    ui->userPage->setCurrentIndex(LOGIN);
    ui->usernameBox->setText("");
    ui->passwordBox->setText("");
    ui->errorLabel->setText("");
}

void MainWindow::on_LogoutBtn2_clicked()
{
    ui->userPage->setCurrentIndex(LOGIN);
    ui->usernameBox->setText("");
    ui->passwordBox->setText("");
    ui->errorLabel->setText("");
}


    /****************
     *  Other Pages *
     ****************/
    void MainWindow::on_AddMember_clicked()
    {
        ui->AdminStackedWidget->setCurrentIndex(2);
    }

    void MainWindow::on_DeleteMember_clicked()
    {
        ui->AdminStackedWidget->setCurrentIndex(1);
    }

    void MainWindow::on_AddItem_clicked()
    {
        ui->AdminStackedWidget->setCurrentIndex(3);
    }

    void MainWindow::on_DeleteItem_clicked()
    {
        ui->AdminStackedWidget->setCurrentIndex(4);
    }
