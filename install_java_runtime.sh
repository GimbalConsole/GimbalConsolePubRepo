#!/bin/bash

# Update package index
sudo apt update

# Install OpenJDK JRE
sudo apt install -y openjdk-11-jre

# Verify the installation
java -version

echo "Java Runtime Environment installation completed."
