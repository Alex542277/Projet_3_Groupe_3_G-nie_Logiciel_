#ifndef IPCALCULATOR_H
#define IPCALCULATOR_H

#include <QString>
#include <QStringList>
#include <vector>

class IPCalculator
{
public:
    IPCalculator(const QString& ip, int mask);
    std::vector<QString> calculateSubnets();

private:
    QString ipAddress;
    int subnetMask;

    bool isValidIp(const QString& ip);
    quint32 ipToUInt(const QString& ip);
    QString uintToIp(quint32 ip);
};

#endif // IPCALCULATOR_H

