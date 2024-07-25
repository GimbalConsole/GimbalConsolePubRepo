#!/bin/bash

# Check if running as root
if [ "$EUID" -ne 0 ]; then
  echo "Please run as root or use sudo"
  exit
fi

echo "Removing brltty service..."
systemctl stop brltty
systemctl disable brltty
apt remove -y brltty

# Update system
echo "Updating system..."
apt update && apt upgrade -y

# Install required packages
echo "Installing required packages..."
apt install -y build-essential dkms git

# Clone the CH341SER driver repository
echo "Cloning CH341SER driver repository..."
git clone https://github.com/juliagoda/CH341SER.git

# Change to the driver directory
cd CH341SER

# Compile and install the driver
echo "Compiling and installing the CH340 driver..."
make

# Disable BTF generation if necessary
if ! grep -q CONFIG_DEBUG_INFO_BTF /boot/config-$(uname -r); then
  echo "Disabling BTF generation..."
  echo "CONFIG_DEBUG_INFO_BTF=n" >> /boot/config-$(uname -r)
fi

sudo make load

# Check if the driver is loaded
echo "Checking if the driver is loaded..."
sudo dmesg | grep ch34x

# Create a symbolic link (optional)
echo "Creating a symbolic link for ease of access..."
if [ -e /dev/ttyUSB0 ]; then
  sudo ln -s /dev/ttyUSB0 /dev/CH340
else
  echo "/dev/ttyUSB0 not found, skipping symlink creation."
fi

# Clean up
echo "Cleaning up..."
cd ..
rm -rf CH341SER

echo "CH340 driver installation completed successfully!"

# Reboot prompt
read -p "Reboot is recommended to apply changes. Do you want to reboot now? (y/n): " REBOOT
if [[ "$REBOOT" == "y" || "$REBOOT" == "Y" ]]; then
    sudo reboot
else
    echo "Please reboot your system manually to apply the changes."
fi
