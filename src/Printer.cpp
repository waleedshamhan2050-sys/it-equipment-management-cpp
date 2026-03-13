#include "Printer.h"
#include <iostream>

// المُنشئ (Constructor)
Printer::Printer(const std::string& serial, const std::string& status,
                 const std::string& purchase, int ppm, bool color)
    : Device(serial, "Printer", status, purchase), // استدعاء مُنشئ الفئة الأساسية
      pagesPerMinute(ppm), isColor(color) {}

// دوال الوصول (Getters)
int Printer::getPagesPerMinute() const {
    return pagesPerMinute;
}

bool Printer::getIsColor() const {
    return isColor;
}

// دالة لعرض معلومات الطابعة (Polymorphism)
void Printer::displayInfo() const {
    Device::displayInfo(); // استدعاء دالة الفئة الأساسية لعرض المعلومات العامة
    std::cout << "  سرعة الطباعة: " << pagesPerMinute << " صفحة/دقيقة\n";
    std::cout << "  ملونة: " << (isColor ? "نعم" : "لا") << "\n";
    std::cout << "----------------------------------------\n";
}

// دالة لتوليد تقرير صيانة خاص بالطابعة
void Printer::generateMaintenanceReport() const {
    std::cout << "----------------------------------------\n";
    std::cout << "تقرير صيانة للطابعة (الرقم التسلسلي: " << serialNumber << ")\n";
    std::cout << "  فحص خراطيش الحبر/التونر، تنظيف رأس الطباعة، تحديث برامج التشغيل.\n";
    if (status == "inactive") {
        std::cout << "  ملاحظة: الطابعة معطلة، قد تحتاج إلى استبدال أجزاء داخلية.\n";
    }
    std::cout << "----------------------------------------\n";
}
