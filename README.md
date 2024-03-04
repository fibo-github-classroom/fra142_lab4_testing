# Lab 4: Testing
ให้ดาวน์โหลดและนำไฟล์ทั้งหมดไปใส่ไว้ใน folder lab4_xxx/test ของนักศึกษา จากนั้นให้ลบโฟลเดอร์ build และรัน cmake อีกรอบตามขั้นตอนต่อไปนี้

- Step 1: Create build folder under lab4 folder.
```
mkdir build
```
- Step 2: generate Makefiles using cmake. 
```
cmake -S . -B build
```
ถ้าใครใช้ Windows, ให้ใช้
```
cmake -S . -B build -G "MinGW Makefiles"
```

- Step 3: Compile the code
```
cmake --build build
```
- Step 4: Run testing
```
./build/test/part_1test
./build/test/part_1test
```
