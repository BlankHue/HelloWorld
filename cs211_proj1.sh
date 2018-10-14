#!/bin/bash
#SBATCH --job-name=hello
#SBATCH --output=res.txt
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:20:00

foo=bar
:'
./cs211_proj1_2_3 64

./cs211_proj1_2_3 128

./cs211_proj1_2_3 256

./cs211_proj1_2_3 512

./cs211_proj1_2_3 1024
'

./cs211_proj1_2_3 2048

foo=bar
:'
./cs211_proj1_1_3 64

./cs211_proj1_1_3 128

./cs211_proj1_1_3 256

./cs211_proj1_1_3 512

./cs211_proj1_1_3 1024

./cs211_proj1_1_3 2048


./cs211_proj1_1_1 64

./cs211_proj1_1_1 128
 
./cs211_proj1_1_1 256

./cs211_proj1_1_1 512

./cs211_proj1_1_1 1024

./cs211_proj1_1_1 2048


./cs211_proj1_1_2 64

./cs211_proj1_1_2 128

./cs211_proj1_1_2 256

./cs211_proj1_1_2 512

./cs211_proj1_1_2 1024

./cs211_proj1_1_2 2048
'
