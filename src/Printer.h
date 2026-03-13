#ifndef PRINTER_H
#define PRINTER_H

#include "Device.h"

// فئة الطابعة مشتقة من Device
class Printer : public Device {
private:
    int pagesPerMinute; // سرعة الطباعة (صفحة في الدقيقة)
    bool isColor;       // هل هي طابعة ملونة؟

public:
    // المُنشئ
    Printer(const std::string& serial, const std::string& status,
            const std::string& purchase, int ppm, bool color);

    // دوال الوصول (Getters)
    int getPagesPerMinute() const;
    bool getIsColor() const;

    // دالة لعرض معلومات الطابعة (Polymorphism)
    void displayInfo() const override;

    // دالة لتوليد تقرير صيانة خاص بالطابعة
    void generateMaintenanceReport() const override;
};

#endif // PRINTER_H
