#!/bin/bash
#SBATCH --job-name=hello
#SBATCH --output=res.txt
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:59:00

./cs211_proj1_2_4 2048 -O0
