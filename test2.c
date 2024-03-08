#include <stdio.h>

void changeValue(int** ptr) {
    **ptr = 20; // เปลี่ยนค่าของตัวแปรที่ ptr ชี้ไปยังเป็น 20
}

int main() {
    int x = 10;
    int* ptr = &x; // ประกาศ pointer ชี้ไปยัง x
    printf("Before: %d\n", x); // แสดงค่า x ก่อนเรียกฟังก์ชัน
    changeValue(&ptr); // ส่ง pointer ของ pointer ไปยังฟังก์ชัน
    printf("After: %d\n", x); // แสดงค่า x หลังจากเรียกฟังก์ชัน
    return 0;
}