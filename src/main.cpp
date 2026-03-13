#include "ITEquipmentManager.h"
#include <iostream>
#include <limits> // لاستخدام numeric_limits

// دالة مساعدة لمسح الإدخال غير الصالح
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ITEquipmentManager manager;

    // إضافة أجهزة جديدة (توضيح استخدام الفئات المشتقة)
    std::cout << "\n--- إضافة أجهزة جديدة ---\n";
    manager.addDevice(std::make_unique<Computer>("COMP-001", "active", "2023-01-15", "Intel i7", 16, "512GB SSD"));
    manager.addDevice(std::make_unique<Printer>("PRNT-002", "active", "2022-11-01", 30, true));
    manager.addDevice(std::make_unique<Router>("RTR-003", "inactive", "2023-03-20", 4, "Wi-Fi 6"));
    manager.addDevice(std::make_unique<Computer>("COMP-004", "maintenance", "2024-02-10", "AMD Ryzen 5", 8, "1TB HDD"));
    manager.addDevice(std::make_unique<Printer>("PRNT-005", "inactive", "2023-07-22", 20, false));

    // محاولة إضافة جهاز بنفس الرقم التسلسلي (يجب أن تفشل)
    manager.addDevice(std::make_unique<Computer>("COMP-001", "active", "2023-01-15", "Intel i7", 16, "512GB SSD"));

    // عرض جميع الأجهزة
    manager.listAllDevices();

    // تحديث حالة جهاز
    std::cout << "\n--- تحديث حالة جهاز ---\n";
    manager.updateDeviceStatus("RTR-003", "active");
    manager.updateDeviceStatus("NON-EXISTENT", "active"); // محاولة تحديث جهاز غير موجود

    // عرض معلومات جهاز معين
    std::cout << "\n--- عرض معلومات جهاز معين ---\n";
    manager.displayDeviceInfo("COMP-001");
    manager.displayDeviceInfo("PRNT-002");

    // توليد تقارير صيانة (توضيح تعدد الأشكال Polymorphism)
    std::cout << "\n--- توليد تقارير صيانة ---\n";
    manager.generateMaintenanceReportForDevice("COMP-004");
    manager.generateMaintenanceReportForDevice("PRNT-005");
    manager.generateMaintenanceReportForDevice("RTR-003");

    // حذف جهاز
    std::cout << "\n--- حذف جهاز ---\n";
    manager.deleteDevice("PRNT-002");
    manager.deleteDevice("NON-EXISTENT"); // محاولة حذف جهاز غير موجود

    // عرض جميع الأجهزة بعد الحذف
    manager.listAllDevices();

    // مثال على واجهة تفاعلية بسيطة (يمكن توسيعها)
    std::cout << "\n========== نظام إدارة معدات IT (قائمة تفاعلية) ==========\n";
    int choice;
    std::string serial, status;

    do {
        std::cout << "\n1. إضافة جهاز\n";
        std::cout << "2. تحديث حالة جهاز\n";
        std::cout << "3. حذف جهاز\n";
        std::cout << "4. عرض جميع الأجهزة\n";
        std::cout << "5. عرض معلومات جهاز معين\n";
        std::cout << "6. توليد تقرير صيانة لجهاز\n";
        std::cout << "0. خروج\n";
        std::cout << "أدخل اختيارك: ";
        std::cin >> choice;
        clearInputBuffer(); // مسح المخزن المؤقت بعد قراءة الرقم

        switch (choice) {
            case 1: {
                std::cout << "\n--- إضافة جهاز جديد ---\n";
                std::string type, purchaseDate, processor, storage;
                int ram, ppm, ports;
                bool isColor;

                std::cout << "الرقم التسلسلي: ";
                std::getline(std::cin, serial);
                std::cout << "النوع (Computer, Printer, Router): ";
                std::getline(std::cin, type);
                std::cout << "الحالة الأولية (active, inactive, maintenance): ";
                std::getline(std::cin, status);
                std::cout << "تاريخ الشراء (YYYY-MM-DD): ";
                std::getline(std::cin, purchaseDate);

                if (type == "Computer") {
                    std::cout << "المعالج: ";
                    std::getline(std::cin, processor);
                    std::cout << "الذاكرة العشوائية RAM (GB): ";
                    std::cin >> ram;
                    clearInputBuffer();
                    std::cout << "التخزين (مثال: 512GB SSD): ";
                    std::getline(std::cin, storage);
                    manager.addDevice(std::make_unique<Computer>(serial, status, purchaseDate, processor, ram, storage));
                } else if (type == "Printer") {
                    std::cout << "سرعة الطباعة PPM: ";
                    std::cin >> ppm;
                    clearInputBuffer();
                    std::cout << "هل هي ملونة؟ (1 للون، 0 للأبيض والأسود): ";
                    std::cin >> isColor;
                    clearInputBuffer();
                    manager.addDevice(std::make_unique<Printer>(serial, status, purchaseDate, ppm, isColor));
                } else if (type == "Router") {
                    std::cout << "عدد المنافذ: ";
                    std::cin >> ports;
                    clearInputBuffer();
                    std::cout << "معيار الشبكة اللاسلكية (مثال: Wi-Fi 6): ";
                    std::getline(std::cin, wirelessStandard);
                    manager.addDevice(std::make_unique<Router>(serial, status, purchaseDate, ports, wirelessStandard));
                } else {
                    std::cout << "نوع جهاز غير مدعوم.\n";
                }
                break;
            }
            case 2: {
                std::cout << "\n--- تحديث حالة جهاز ---\n";
                std::cout << "أدخل الرقم التسلسلي للجهاز: ";
                std::getline(std::cin, serial);
                std::cout << "أدخل الحالة الجديدة (active, inactive, maintenance): ";
                std::getline(std::cin, status);
                manager.updateDeviceStatus(serial, status);
                break;
            }
            case 3: {
                std::cout << "\n--- حذف جهاز ---\n";
                std::cout << "أدخل الرقم التسلسلي للجهاز المراد حذفه: ";
                std::getline(std::cin, serial);
                manager.deleteDevice(serial);
                break;
            }
            case 4:
                manager.listAllDevices();
                break;
            case 5: {
                std::cout << "\n--- عرض معلومات جهاز معين ---\n";
                std::cout << "أدخل الرقم التسلسلي للجهاز: ";
                std::getline(std::cin, serial);
                manager.displayDeviceInfo(serial);
                break;
            }
            case 6: {
                std::cout << "\n--- توليد تقرير صيانة لجهاز ---\n";
                std::cout << "أدخل الرقم التسلسلي للجهاز: ";
                std::getline(std::cin, serial);
                manager.generateMaintenanceReportForDevice(serial);
                break;
            }
            case 0:
                std::cout << "الخروج من البرنامج. مع السلامة!\n";
                break;
            default:
                std::cout << "اختيار غير صالح. يرجى المحاولة مرة أخرى.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
