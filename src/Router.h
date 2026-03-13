#ifndef ROUTER_H
#define ROUTER_H

#include "Device.h"

// فئة الموجه (Router) مشتقة من Device
class Router : public Device {
private:
    int numberOfPorts; // عدد المنافذ
    std::string wirelessStandard; // معيار الشبكة اللاسلكية (مثال: Wi-Fi 6)

public:
    // المُنشئ
    Router(const std::string& serial, const std::string& status,
           const std::string& purchase, int ports, const std::string& standard);

    // دوال الوصول (Getters)
    int getNumberOfPorts() const;
    std::string getWirelessStandard() const;

    // دالة لعرض معلومات الموجه (Polymorphism)
    void displayInfo() const override;

    // دالة لتوليد تقرير صيانة خاص بالموجه
    void generateMaintenanceReport() const override;
};

#endif // ROUTER_H
