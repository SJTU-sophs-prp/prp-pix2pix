conda activate painting
python ./py/test.py --dataroot ./datasets/mask15_2_10w/ --name wuyong_contrast_lsgan_linear_150 --model pix2pix --direction BtoA --preprocess resize_and_crop --num_test 3000 --results_dir ./results/mask15_2_10w/ 