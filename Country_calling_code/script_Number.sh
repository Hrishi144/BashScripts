#!/bin/bash

while IFS= read -r number
do
    if [[ $number =~ ^(\+91|91)\ ?[0-9]{10}$ ]]; then
        echo -e "\e[31mIndia:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+1|1)\ ?[0-9]{10}$ ]]; then
        echo -e "\e[31mUSA/Canada:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+44|44)\ ?[0-9]{10}$ ]]; then
        echo -e "\e[31mUK:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+49|49)\ ?[0-9]{9,11}$ ]]; then
        echo -e "\e[31mGermany:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+61|61)\ ?[0-9]{9}$ ]]; then
        echo -e "\e[31mAustralia:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+81|81)\ ?[0-9]{9,10}$ ]]; then
        echo -e "\e[31mJapan:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+33|33)\ ?[0-9]{9}$ ]]; then
        echo -e "\e[31mFrance:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+55|55)\ ?[0-9]{11}$ ]]; then
        echo -e "\e[31mBrazil:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+7|7)\ ?[0-9]{10}$ ]]; then
        echo -e "\e[31mRussia:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+27|27)\ ?[0-9]{9}$ ]]; then
        echo -e "\e[31mSouth Africa:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+34|34)\ ?[0-9]{9}$ ]]; then
        echo -e "\e[31mSpain:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+39|39)\ ?[0-9]{10}$ ]]; then
        echo -e "\e[31mItaly:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^(\+86|86)\ ?[0-9]{11}$ ]]; then
        echo -e "\e[31mChina:\e[0m \e[34m$number\e[0m"
    elif [[ $number =~ ^[0-9]{10,12}$ ]]; then
        echo -e "\e[31mUnknown region:\e[0m \e[34m$number\e[0m"
    else
        echo -e "\e[31mInvalid number:\e[0m \e[34m$number\e[0m"
    fi
done < number.txt
