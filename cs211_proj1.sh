#!/bin/bash
#SBATCH --job-name=hello
#SBATCH --output=res.txt
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:10:00

./cs211_proj1 64

./cs211_proj1 128
 
./cs211_proj1 256

./cs211_proj1 512

./cs211_proj1 1024

./cs211_proj1 2048

