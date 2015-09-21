#!/bin/bash
for f in file.txt
do
    tr -d '\r' < $f >> big-UNIX-file.txt
done
