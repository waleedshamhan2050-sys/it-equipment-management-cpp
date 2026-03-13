#ifndef IT_EQUIPMENT_MANAGER_H
#define IT_EQUIPMENT_MANAGER_H

#include "Device.h"
#include "Computer.h"
#include "Printer.h"
#include "Router.h"
#include <vector>
#include <memory> // لاستخدام smart pointers

// فئة لإدارة جميع أجهزة IT
class ITEquipmentManager {
private:
    // استخدام std::unique_ptr لإدارة الذاكرة تلقائيًا وتجنب تسرب الذاكرة
    std::vector<std::unique_ptr<Device>> devices;

public:
    // المُنشئ (Constructor)
    ITEquipmentManager() = default;

    // المُدمر (Destructor)
    ~ITEquipmentManager() = default;

    // إضافة جهاز جديد
    void addDevice(std::unique_ptr<Device> device);

    // تحديث حالة جهاز بناءً على الرقم التسلسلي
    bool updateDeviceStatus(const std::string& serialNumber, const std::string& newStatus);

    // حذف جهاز بناءً على الرقم التسلسلي
    bool deleteDevice(const std::string& serialNumber);

    // عرض معلومات جميع الأجهزة
    void listAllDevices() const;

    // عرض معلومات جهاز معين بناءً على الرقم التسلسلي
    void displayDeviceInfo(const std::string& serialNumber) const;

    // توليد تقرير صيانة لجهاز معين بناءً على الرقم التسلسلي
    void generateMaintenanceReportForDevice(const std::string& serialNumber) const;

    // البحث عن جهاز بالرقم التسلسلي
    Device* findDevice(const std::string& serialNumber) const;
};

#endif // IT_EQUIPMENT_MANAGER_H
