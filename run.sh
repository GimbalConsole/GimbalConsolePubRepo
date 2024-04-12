#! /bin/bash

# Get the tag name from GitHub release
# https://github.com/GimbalConsole/GimbalConsolePubRepo/releases/tag/v1.0.1
release_info=$(curl -s https://github.com/GimbalConsole/GimbalConsolePubRepo/releases/latest)

tag_name=$(echo "$release_info" | grep -o '"tag_name": *"[^"]*"' | cut -d '"' -f 4)
download_url="https://github.com/GimbalConsole/GimbalConsolePubRepo/releases/download/$tag_name/GimbalConsole"
file_name="GimbalConsole_$tag_name"

echo $tag_name
echo $download_url
curl -L "$download_url" -o "$file_name"
chmod 777 $file_name

# echo $tag_name
# curl https://api.github.com/repos/Real-Estate-Search-AI/ava-desktop-public/releases/latest | grep "browser_download_url.*exe"