#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>

#include <gp_Ax2.hxx>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    occView = new OccView(this);

    pushButtonDrawBox = new QPushButton("Draw box");
    pushButtonDrawCone = new QPushButton("Draw cone");
    pushButtonDrawSphere = new QPushButton("Draw sphere");

    QWidget *w = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    QVBoxLayout *verticalLayout = new QVBoxLayout();

    horizontalLayout->addWidget(pushButtonDrawBox);
    horizontalLayout->addWidget(pushButtonDrawCone);
    horizontalLayout->addWidget(pushButtonDrawSphere);

    verticalLayout->addWidget(occView);
    verticalLayout->addItem(horizontalLayout);

    w->setLayout(verticalLayout);

    setCentralWidget(w);

    connect(pushButtonDrawBox, SIGNAL(clicked(bool)), this, SLOT(on_drawBox()));
    connect(pushButtonDrawCone, SIGNAL(clicked(bool)), this, SLOT(on_drawCone()));
    connect(pushButtonDrawSphere, SIGNAL(clicked(bool)), this, SLOT(on_drawSphere()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawBox()
{
    TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(3.0, 4.0, 5.0).Shape();

    occView->DrawShape(aTopoBox);
}

void MainWindow::on_drawCone()
{
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(0.0, 10.0, 0.0));

    TopoDS_Shape aTopoCone = BRepPrimAPI_MakeCone(anAxis, 3.0, 0.0, 5.0).Shape();

    occView->DrawShape(aTopoCone);
}

void MainWindow::on_drawSphere()
{
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(5.0, 5, 0.0));

    TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 3.0).Shape();

    occView->DrawShape(aTopoSphere);
}
