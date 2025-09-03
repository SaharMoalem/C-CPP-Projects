IoT Based Drive
A Linux-based user-space program that provides a virtual drive, accessible via the native directory GUI. Although data appears to be stored locally, it is actually distributed across multiple IoT devices (referred to as minions) on the same local network.

🚀 Motivation
This project is designed to leverage unused storage space on common household IoT devices — such as smart air conditioner controllers, smart plugs, Raspberry Pi devices, and more.

Data Accessible only within the Local Area Network (LAN)
Implement RAID 01, therefore the system ensures thata data is:
Secure
Backed up
📚 Introduction
IoT-Based Drive is a user-space application for Linux systems. It allows users to mount a virtual drive using the standard mount shell command.

Data is transmitted via TCP from the kernel space to the user space using the Linux Network Block Device (NBD) module.

🛠 This project was developed as the final assignment in the Infinity Labs R&D Software Development Program.

✅ Prerequisites
Linux OS
Root access (for loading kernel modules and mounting NBD)

Setup & Usage
