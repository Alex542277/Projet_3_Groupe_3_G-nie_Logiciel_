#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ip_calculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connexion du bouton au slot
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    // Récupération des entrées utilisateur
    QString ip = ui->ipInput->text();
    int mask = ui->maskInput->value();

    // Vérification des entrées
    if (ip.isEmpty()) {
        ui->resultList->addItem("⚠ Veuillez entrer une adresse IP!");
        return;
    }
    // Calcul des sous-réseaux
    IPCalculator calc(ip, mask);
    auto subnets = calc.calculateSubnets();

    // Affichage des résultats
    ui->resultList->clear();
    for (const QString &subnet: subnets) {
        ui->resultList->addItem(subnet);
    }
}
