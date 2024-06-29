#! /bin/bash

if ! command -v curl &> /dev/null
then
    echo "curl is not installed. Installing curl..."
    sudo apt update
    sudo apt install -y curl
    echo "curl has been installed"
else
    echo "curl is already installed."
fi

# Get the tag name from GitHub release
# https://github.com/GimbalConsole/GimbalConsolePubRepo/releases/tag/v1.0.1
# GITHUB_API_URL=https://github.com/GimbalConsole/GimbalConsolePubRepo/tags

release_info=$(curl -s https://api.github.com/repos/GimbalConsole/GimbalConsolePubRepo/releases/latest)
tag_name=$(echo "$release_info" | grep -o '"tag_name": *"[^"]*"' | cut -d '"' -f 4)
download_url="https://github.com/GimbalConsole/GimbalConsolePubRepo/releases/download/$tag_name/GimbalConsole2.deb"
file_name="GimbalConsole_$tag_name.deb"

echo $tag_name
echo $download_url
echo $file_name

curl -L "$download_url" -o "$file_name"
chmod 777 $file_name
sudo dpkg -P GimbalConsole2
sudo dpkg -i $file_name

# echo $tag_name
# curl https://api.github.com/repos/Real-Estate-Search-AI/ava-desktop-public/releases/latest | grep "browser_download_url.*exe"
