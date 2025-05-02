#!/bin/bash

# --- Description Section ---
green='\033[0;32m'
NC='\033[0m'
yellow='\033[0;33m'
red='\033[0;31m'
UWhite='\033[4;37m'
blue='\033[0;34m'
echo -e "${green}------------------------------------------${NC}"
echo -e "${red}       File Renamer Bash Script           ${NC}";
echo -e "      ${blue}-------------------------${NC}"
sleep 0.5
echo -e "${green}This script renames all files in a        ${NC}"; 
sleep 0.5
echo -e "${green}specified directory using a custom        ${NC}";
sleep 0.5
echo -e "${green}naming pattern and a chosen extension.    ${NC}"; 
sleep 0.5
echo -e "${green}It requires 3 arguments:                  ${NC}"; 
sleep 0.5
echo -e "${green}1) Directory path                         ${NC}"; 
sleep 0.5
echo -e "${green}2) New base name                          ${NC}"; 
sleep 0.5
echo -e "${green}3) Desired file extension                 ${NC}"; 
sleep 0.5
echo -e "${green}Author: [Hrishikesh.D]                  ${NC}";
sleep 0.5
echo -e "${green}------------------------------------------${NC}";
sleep 0.7


if [ $# -lt 2 ]; then
  echo -e "${yellow}How to use: $0  <path_to_the_file> <new_name> <extension>${NC}"
  exit 1
fi

DIR_path="$1"
new_name="$2"
exten="$3"


if [ ! -d "$DIR_path" ]; then
   echo -e "${red}ERROR! :'$DIR_path' not found${NC}"
   exit 1
fi

cd "$DIR_path" || exit 1

count=1

for  file in *; do
 if [ -f "$file" ]; then
   
   ext="${file##*.}"

   newname="${new_name}_${count}.${exten}"

    echo "File Renaming From [$file]->[$newname]"
    sleep 0.5
    mv -- "$file" "$newname"
    ((count++))
 fi

done
echo -e  "${yellow}RENAMING COMPLETE !!${NC}"
echo -e  "${yellow}Files Renamed :$((count-1))${NC}"



