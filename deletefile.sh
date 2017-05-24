#!/bin/bash
echo "delete $1"
for filename in `find $1 -name "*.svn"`
do  
    echo "delete " $filename
    rm -rf $filename
done
