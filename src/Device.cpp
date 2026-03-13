#include "Device.h"
#include <iostream>

// المُنشئ (Constructor)
Device::Device(const std::string& serial, const std::string& type,
               const std::string& status, const std::string& purchase)
    : serialNumber(serial), type(type), status(status), purchaseDate(purchase) {}

// دوال الوصول (Getters)
std::string Device::getSerialNumber() const {
    return serialNumber;
}

std::string Device::getType() const {
    return type;
}

std::string Device::getStatus() const {
    return status;
}

std::string Device::getPurchaseDate() const {
    return purchaseDate;
}

// دوال التعديل (Setters)
void Device::setStatus(const std::string& newStatus) {
    status = newStatus;
}

// دالة لعرض معلومات الجهاز
void Device::displayInfo() const {
    std::cout << "----------------------------------------\n";
    std::cout << "معلومات الجهاز:\n";
    std::cout << "  الرقم التسلسلي: " << serialNumber << "\n";
    std::cout << "  النوع: " << type << "\n";
    std::cout << "  الحالة: " << status << "\n";
    std::cout << "  تاريخ الشراء: " << purchaseDate << "\n";
}

// دالة لتوليد تقرير صيانة (افتراضية للفئة الأساسية)
void Device::generateMaintenanceReport() const {
    std::cout << "----------------------------------------\n";
    std::cout << "تقرير صيانة للجهاز (الرقم التسلسلي: " << serialNumber << ")\n";
    std::cout << "  لا يوجد تقرير صيانة محدد لهذا النوع من الأجهزة.\n";
}
