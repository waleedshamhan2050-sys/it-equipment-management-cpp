#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <vector>

// فئة أساسية لتمثيل أي جهاز IT
class Device {
protected:
    std::string serialNumber; // الرقم التسلسلي للجهاز
    std::string type;         // نوع الجهاز (كمبيوتر، طابعة، موجه شبكة)
    std::string status;       // حالة الجهاز (نشط، معطل، تحت الصيانة)
    std::string purchaseDate; // تاريخ الشراء

public:
    // المُنشئ (Constructor)
    Device(const std::string& serial, const std::string& type, 
           const std::string& status, const std::string& purchase);

    // المُدمرات الافتراضية (Virtual Destructor) لضمان التدمير الصحيح للفئات المشتقة
    virtual ~Device() = default;

    // دوال الوصول (Getters)
    std::string getSerialNumber() const;
    std::string getType() const;
    std::string getStatus() const;
    std::string getPurchaseDate() const;

    // دوال التعديل (Setters)
    void setStatus(const std::string& newStatus);

    // دالة افتراضية لعرض معلومات الجهاز (Polymorphism)
    virtual void displayInfo() const;

    // دالة افتراضية لتوليد تقرير صيانة (Polymorphism)
    virtual void generateMaintenanceReport() const;
};

#endif // DEVICE_H
