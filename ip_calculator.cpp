#include "ip_calculator.h"

IPCalculator::IPCalculator(const QString& ip, int mask)
    : ipAddress(ip), subnetMask(mask) {}

bool IPCalculator::isValidIp(const QString& ip) {
    QStringList parts = ip.split(".");
    if (parts.size()!= 4) return false;
    for (const QString& part: parts) {
        bool ok = false;
        int byte = part.toInt(&ok);
        if (!ok || byte < 0 || byte> 255) return false;
    }
    return true;
}

quint32 IPCalculator::ipToUInt(const QString& ip) {
    QStringList parts = ip.split(".");
    quint32 result = 0;
    for (const QString& part: parts)
        result = (result << 8) + part.toUInt();
    return result;
}

QString IPCalculator::uintToIp(quint32 ip) {
    return QString("%1.%2.%3.%4")
    .arg((ip>> 24) & 0xFF)
        .arg((ip>> 16) & 0xFF)
        .arg((ip>> 8) & 0xFF)
        .arg(ip & 0xFF);
}
std::vector<QString> IPCalculator::calculateSubnets() {
    std::vector<QString> results;

    if (!isValidIp(ipAddress) || subnetMask < 0 || subnetMask> 32) {
        results.push_back("⚠️ Adresse IP ou masque invalide.");
        return results;
    }

    quint32 base = ipToUInt(ipAddress);
    int hostBits = 32 - subnetMask;
    int maxSubnets = std::min(32, 1 << std::min(hostBits, 8)); // Limite le nombre affiché

    for (int i = 0; i < maxSubnets; ++i) {
        quint32 subnet = (base & (~((1u << hostBits) - 1))) + (i << (hostBits> 8? hostBits - 8: 0));
        results.push_back(uintToIp(subnet));
    }

    return results;
}

