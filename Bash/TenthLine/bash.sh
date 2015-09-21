#!/bin/bash
#sed -n "10p" ./file.txt
cat file.txt | grep -n "" | grep "^10:" |cut -d ":" -f2
