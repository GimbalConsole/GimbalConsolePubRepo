#!/bin/bash

# Update system
echo "Updating system..."
sudo apt update && sudo apt upgrade -y

# Install required packages
echo "Installing required packages..."
sudo apt install -y build-essential dkms git

# Clone the CH340 driver repository
echo "Cloning CH340 driver repository..."
git clone https://github.com/juliagoda/CH340-Driver.git

# Change to the driver directory
cd CH340-Driver

# Compile and install the driver
echo "Compiling and installing the CH340 driver..."
make
sudo make load

# Check if the driver is loaded
echo "Checking if the driver is loaded..."
dmesg | grep ch34x

# Create a symbolic link (optional)
echo "Creating a symbolic link for ease of access..."
sudo ln -s /dev/ttyUSB0 /dev/CH340

# Clean up
echo "Cleaning up..."
cd ..
rm -rf CH340-Driver

echo "CH340 driver installation completed successfully!"

# Reboot prompt
read -p "Reboot is recommended to apply changes. Do you want to reboot now? (y/n): " REBOOT
if [[ "$REBOOT" == "y" || "$REBOOT" == "Y" ]]; then
    sudo reboot
else
    echo "Please reboot your system manually to apply the changes."
fi
