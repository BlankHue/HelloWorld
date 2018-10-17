#!/bin/bash
#SBATCH --job-name=hello
#SBATCH --output=res.txt
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:59:00

./cs211_proj1_2_4 2046

foo=bar
: '
./cs211_proj1_2_3 64

./cs211_proj1_2_31 128

./cs211_proj1_2_31 256

./cs211_proj1_2_31 512

./cs211_proj1_2_31 1024

./cs211_proj1_2_31 2048

./cs211_proj1_1_31 64

./cs211_proj1_1_31 128

./cs211_proj1_1_31 256

./cs211_proj1_1_31 512

./cs211_proj1_1_31 1024

./cs211_proj1_1_31 2048

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
