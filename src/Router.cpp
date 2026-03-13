#include "Router.h"
#include <iostream>

// المُنشئ (Constructor)
Router::Router(const std::string& serial, const std::string& status,
               const std::string& purchase, int ports, const std::string& standard)
    : Device(serial, "Router", status, purchase), // استدعاء مُنشئ الفئة الأساسية
      numberOfPorts(ports), wirelessStandard(standard) {}

// دوال الوصول (Getters)
int Router::getNumberOfPorts() const {
    return numberOfPorts;
}

std::string Router::getWirelessStandard() const {
    return wirelessStandard;
}

// دالة لعرض معلومات الموجه (Polymorphism)
void Router::displayInfo() const {
    Device::displayInfo(); // استدعاء دالة الفئة الأساسية لعرض المعلومات العامة
    std::cout << "  عدد المنافذ: " << numberOfPorts << "\n";
    std::cout << "  معيار الشبكة اللاسلكية: " << wirelessStandard << "\n";
    std::cout << "----------------------------------------\n";
}

// دالة لتوليد تقرير صيانة خاص بالموجه
void Router::generateMaintenanceReport() const {
    std::cout << "----------------------------------------\n";
    std::cout << "تقرير صيانة للموجه (الرقم التسلسلي: " << serialNumber << ")\n";
    std::cout << "  فحص الاتصال، تحديث البرامج الثابتة (Firmware)، إعادة تشغيل الجهاز.\n";
    if (status == "inactive") {
        std::cout << "  ملاحظة: الموجه معطل، قد يكون هناك مشكلة في مصدر الطاقة أو المكونات الداخلية.\n";
    }
    std::cout << "----------------------------------------\n";
}
