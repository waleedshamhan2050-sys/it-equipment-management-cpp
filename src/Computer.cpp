#include "Computer.h"
#include <iostream>

// المُنشئ (Constructor)
Computer::Computer(const std::string& serial, const std::string& status,
                   const std::string& purchase, const std::string& processor,
                   int ram, const std::string& storage)
    : Device(serial, "Computer", status, purchase), // استدعاء مُنشئ الفئة الأساسية
      processor(processor), ramGB(ram), storageGB(storage) {}

// دوال الوصول (Getters)
std::string Computer::getProcessor() const {
    return processor;
}

int Computer::getRamGB() const {
    return ramGB;
}

std::string Computer::getStorageGB() const {
    return storageGB;
}

// دالة لعرض معلومات الكمبيوتر (Polymorphism)
void Computer::displayInfo() const {
    Device::displayInfo(); // استدعاء دالة الفئة الأساسية لعرض المعلومات العامة
    std::cout << "  المعالج: " << processor << "\n";
    std::cout << "  الذاكرة العشوائية (RAM): " << ramGB << "GB\n";
    std::cout << "  التخزين: " << storageGB << "\n";
    std::cout << "----------------------------------------\n";
}

// دالة لتوليد تقرير صيانة خاص بالكمبيوتر
void Computer::generateMaintenanceReport() const {
    std::cout << "----------------------------------------\n";
    std::cout << "تقرير صيانة للكمبيوتر (الرقم التسلسلي: " << serialNumber << ")\n";
    std::cout << "  فحص الأداء العام، تحديث البرامج، تنظيف المكونات الداخلية.\n";
    std::cout << "  المعالج: " << processor << ", RAM: " << ramGB << "GB.\n";
    if (status == "inactive") {
        std::cout << "  ملاحظة: الجهاز معطل، يتطلب فحصًا شاملاً للمكونات الرئيسية.\n";
    }
    std::cout << "----------------------------------------\n";
}
