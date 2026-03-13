#include "ITEquipmentManager.h"
#include <algorithm> // لاستخدام std::remove_if
#include <iostream>

// إضافة جهاز جديد إلى القائمة
void ITEquipmentManager::addDevice(std::unique_ptr<Device> device) {
    // التحقق مما إذا كان الجهاز موجودًا بالفعل باستخدام الرقم التسلسلي
    if (findDevice(device->getSerialNumber())) {
        std::cout << "خطأ: جهاز بالرقم التسلسلي " << device->getSerialNumber() << " موجود بالفعل.\n";
        return;
    }
    devices.push_back(std::move(device)); // نقل ملكية الجهاز إلى المتجه
    std::cout << "تمت إضافة الجهاز بنجاح.\n";
}

// تحديث حالة جهاز بناءً على الرقم التسلسلي
bool ITEquipmentManager::updateDeviceStatus(const std::string& serialNumber, const std::string& newStatus) {
    Device* device = findDevice(serialNumber);
    if (device) {
        device->setStatus(newStatus);
        std::cout << "تم تحديث حالة الجهاز " << serialNumber << " إلى " << newStatus << ".\n";
        return true;
    }
    std::cout << "خطأ: الجهاز بالرقم التسلسلي " << serialNumber << " غير موجود.\n";
    return false;
}

// حذف جهاز بناءً على الرقم التسلسلي
bool ITEquipmentManager::deleteDevice(const std::string& serialNumber) {
    auto it = std::remove_if(devices.begin(), devices.end(),
                             [&](const std::unique_ptr<Device>& d) {
                                 return d->getSerialNumber() == serialNumber;
                             });
    if (it != devices.end()) {
        devices.erase(it, devices.end());
        std::cout << "تم حذف الجهاز " << serialNumber << " بنجاح.\n";
        return true;
    }
    std::cout << "خطأ: الجهاز بالرقم التسلسلي " << serialNumber << " غير موجود للحذف.\n";
    return false;
}

// عرض معلومات جميع الأجهزة
void ITEquipmentManager::listAllDevices() const {
    if (devices.empty()) {
        std::cout << "لا توجد أجهزة مسجلة حاليًا.\n";
        return;
    }
    std::cout << "\n========== قائمة جميع الأجهزة ==========\n";
    for (const auto& device : devices) {
        device->displayInfo(); // استخدام تعدد الأشكال (Polymorphism)
    }
    std::cout << "========================================\n";
}

// عرض معلومات جهاز معين بناءً على الرقم التسلسلي
void ITEquipmentManager::displayDeviceInfo(const std::string& serialNumber) const {
    Device* device = findDevice(serialNumber);
    if (device) {
        device->displayInfo(); // استخدام تعدد الأشكال (Polymorphism)
    } else {
        std::cout << "خطأ: الجهاز بالرقم التسلسلي " << serialNumber << " غير موجود.\n";
    }
}

// توليد تقرير صيانة لجهاز معين بناءً على الرقم التسلسلي
void ITEquipmentManager::generateMaintenanceReportForDevice(const std::string& serialNumber) const {
    Device* device = findDevice(serialNumber);
    if (device) {
        device->generateMaintenanceReport(); // استخدام تعدد الأشكال (Polymorphism)
    } else {
        std::cout << "خطأ: الجهاز بالرقم التسلسلي " << serialNumber << " غير موجود لإنشاء تقرير صيانة.\n";
    }
}

// البحث عن جهاز بالرقم التسلسلي
Device* ITEquipmentManager::findDevice(const std::string& serialNumber) const {
    for (const auto& device : devices) {
        if (device->getSerialNumber() == serialNumber) {
            return device.get(); // إرجاع مؤشر خام للجهاز
        }
    }
    return nullptr;
}
