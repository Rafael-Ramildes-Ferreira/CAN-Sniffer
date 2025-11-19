# CAN Sniffer

This project was developed for the course *C++ Programming for Embedded Systems* (EEL7323 — 20252) at UFSC. This repository contains the application code.

🔗 **PlatformIO-based launching repository:**  
[![Launch](https://img.shields.io/badge/GitHub-CAN_Sniffer_ESP32_Core-blue?logo=github)](https://github.com/Rafael-Ramildes-Ferreira/ESP-Core-Sniffer.git)

## Development Status
<!-- ![Version 0.5](https://img.shields.io/badge/Version-v0,5,0-blue?logo=gin) -->
![Version 0.5](https://img.shields.io/static/v1?label=Version&message=v0.5&color=blue?logo=gin
)
This version is for the halfway assignment submission. The classes interface are implemented as planned in:

![Block Diagram](.\img\block_diagram.svg)

Code executes both in Linux and in ESP32. Bluetooth is fully implemented and working (only for ESP32).

### To Do
- Implement the application logic (code of the threads)
- SD card module code
- CAN module code
- Implement tests

## Objective

The goal of this project is to develop a CAN Sniffer using the ESP32 microcontroller.  
The system is responsible for reading frames from the CAN bus and storing them in an organized manner for later analysis, facilitating diagnostics and the development of embedded systems that use CAN communication.  
Additionally, the project aims to implement a modular design, allowing the storage or transmission medium to be replaced without requiring major changes to the code.

## Requirements

Beyond the hardware:

- ESP-IDF or Arduino framework  
- NimBLE library  
- SD library (coming soon)

These libraries can be managed with [![PlatformIO](https://img.shields.io/badge/PlatformIO-Ready-orange?logo=platformio)](https://platformio.org/).

## Compilation

The provided Makefile only compiles a Linux application for debugging purposes.  
To build and upload the application to the ESP NodeMCU-32s using PlatformIO, refer to the repository available [here](https://github.com/Rafael-Ramildes-Ferreira/ESP-Core-Sniffer).
