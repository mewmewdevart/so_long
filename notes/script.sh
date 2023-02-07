#!/bin/sh

if [ -d "./libs/mlx" ]
then
        echo "Essa biblioteca existe"
        rm -rf ./libs/mlx
else
        echo "Error"
fi
