#ifndef COMPUTER_H
#define COMPUTER_H

#include "Device.h"

// فئة الكمبيوتر مشتقة من Device
class Computer : public Device {
private:
    std::string processor; // نوع المعالج
    int ramGB;             // حجم الذاكرة العشوائية (RAM) بالجيجابايت
    std::string storageGB; // حجم التخزين بالجيجابايت (مثال: 512GB SSD)

public:
    // المُنشئ
    Computer(const std::string& serial, const std::string& status,
             const std::string& purchase, const std::string& processor,
             int ram, const std::string& storage);

    // دوال الوصول (Getters)
    std::string getProcessor() const;
    int getRamGB() const;
    std::string getStorageGB() const;

    // دالة لعرض معلومات الكمبيوتر (Polymorphism)
    void displayInfo() const override;

    // دالة لتوليد تقرير صيانة خاص بالكمبيوتر
    void generateMaintenanceReport() const override;
};

#endif // COMPUTER_H
