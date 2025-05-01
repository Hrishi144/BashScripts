#!/bin/bash
# --- Description Section ---
echo
green='\033[0;32m'
NC='\033[0m'
red='\033[1;91m'
yellow='\033[0;33m'
echo -e "${red}DESCRIPTION:${NC}"
echo -e "${green}--------------------------------------${NC}"
echo -e "${green}File Lister and Counter Script${NC}" ;
sleep 0.5
echo -e "${green}This script lists and counts all files in a given directory.${NC}" ;
sleep 0.5
echo -e "${green}It accepts a directory path as a command-line argument.${NC}" ;
sleep 0.5
echo -e "${green}It prints each file's full path and the total number of files.${NC}" ;
sleep 0.5
echo -e "${green}Author: [Hrishikesh.D]${NC}" ;
 sleep 0.5
echo -e "${green}--------------------------------------${NC}"
sleep 0.7

 if [ -z "$1" ]; then
    echo -e "${yellow}This script uses command line arguments!!${NC}"
    echo -e "${yellow}Please enter a location${NC}"
    echo -e "${yellow}How to use ->./file_name.sh  /DIR/location${NC}"
    echo -e "${red}PLEASE RE-RUN WITH ARGUEMENTS!!${NC}"
    exit 1
 fi

path="$1"

sleep 1

if [ ! -d "$path" ]; then
    echo -e " ${red}ERROR 404 ${NC} ${green}Directory Not Found!!${NC} "
   exit 1
fi

sleep 0.5
echo -e "${red}!!!!!!**All Files in the directory [$path]**!!!!!!${NC}"
for((i=0;i<50;i++)) do
  echo -n "|"
  sleep 0.1
done
echo


find "$path" -type f

NO_File=$(find "$path" -type f | wc -l)
for((i=0;i<50;i++)) do
  echo -n "|"
   sleep 0.1
done
echo
echo "NUMBER OF FILES IN DIRECTORY:-> $path:$NO_File"
