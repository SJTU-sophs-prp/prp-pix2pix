import os
import sys

mask_path = '~/code/G2/results/ssj_100+160+250_ssj/ssj_overlap_100_lsgan/test_latest/A/'

list = sorted(os.listdir(mask_path))

print(list)
iterator = 0
for file in list:
    os.rename(mask_path +list[iterator], mask_path + str(iterator) + '.jpg')
    iterator = iterator + 1
