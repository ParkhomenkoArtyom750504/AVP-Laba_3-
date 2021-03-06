﻿#include "pdi.hpp"
#include <string>

#include <opencv2/imgcodecs/legacy/constants_c.h>


int main(int argc, char* argv[]) {

	int filter_opt = 8;//negative_rgb

	std::string file_name = "Test.jpg";
	std::string input_name = "D:/" + file_name;
	file_name = file_name.substr(0, file_name.length() - 4);

	int load_type = strcmp("", "pb") ? cv::IMREAD_COLOR : cv::IMREAD_GRAYSCALE;

	Mat img = imread(input_name, load_type);
	Mat img_out;
	Mat mask;

	std::string output_name = "D:/" + file_name;

	switch (filter_opt) {
	case 0:
		img_out = img;
		output_name += "1_1_original ";
		break;
	case 1:
		img_out = rgb2yiq2rgb(img);
		output_name += "1_1 ";
		break;
	case 2:
		img_out = split(img, 0, true);
		output_name += "1_2_R_mono ";
		break;
	case 3:
		img_out = split(img, 1, true);
		output_name += "1_2_G_mono ";
		break;
	case 4:
		img_out = split(img, 2, true);
		output_name += "1_2_B_mono ";
		break;
	case 5:
		img_out = split(img, 0, false);
		output_name += "1_2_R_tri ";
		break;
	case 6:
		img_out = split(img, 1, false);
		output_name += "1_2_G_tri ";
		break;
	case 7:
		img_out = split(img, 2, false);
		output_name += "1_2_B_tri ";
		break;
	case 8:
		img_out = negative_rgb(img);
		output_name += "1_3_rgb ";
		break;
	case 9:
		img_out = negative_y(img);
		output_name += "1_3_y ";
		break;
	case 10:
		img_out = addBrightness(img, 30);
		output_name += "1_4_add30 ";
		break;
	case 11:
		img_out = addBrightness(img, 80);
		output_name += "1_4_add100 ";
		break;
	case 12:
		img_out = addBrightness(img, -100);
		output_name += "1_4_add-100 ";
		break;
	case 13:
		img_out = addBrightness(img, -150);
		output_name += "1_4_add-150 ";
		break;
	case 14:
		img_out = mulBrightness_rgb(img, 0.5f);
		output_name += "1_5_mul_rgb-50 ";
		break;
	case 15:
		img_out = mulBrightness_rgb(img, 1.5f);
		output_name += "1_5_mul_rgb+50 ";
		break;
	case 16:
		img_out = mulBrightness_y(img, 0.5f);
		output_name += "1_5_mul_y-50 ";
		break;
	case 17:
		img_out = mulBrightness_y(img, 1.5f);
		output_name += "1_5_mul_y+50 ";
		break;
	case 18:
		img_out = thresholding(img, 50, 0, false);
		output_name += "1_6_thres_50 ";
		break;
	case 19:
		img_out = thresholding(img, 120, 0, false);
		output_name += "1_6_thres_120 ";
		break;
	case 20:
		img_out = thresholding(img, 200, 0, false);
		output_name += "1_6_thres_200 ";
		break;
	case 21:
		img_out = thresholding(img, 230, 0, false);
		output_name += "1_6_thres_230 ";
		break;
	case 22:
		img_out = thresholding(img, 0, 0, true);
		output_name += "1_6_thres_mean ";
		break;
	case 23:
		img_out = meanFilter(img, 3);
		output_name += "1_7_mean_3 ";
		break;
	case 24:
		img_out = meanFilter(img, 7);
		output_name += "1_7_mean_7 ";
		break;
	case 25:
		img_out = meanFilter(img, 11);
		output_name += "1_7_mean_11 ";
		break;
	case 26:
		img_out = medianFilter(img, 3);
		output_name += "1_7_med_3 ";
		break;
	case 27:
		img_out = medianFilter(img, 7);
		output_name += "1_7_med_7 ";
		break;
	case 28:
		img_out = medianFilter(img, 11);
		output_name += "1_7_med_11 ";
		break;
	case 29:
		img_out = laplacianFilter(img);
		output_name += "1_8_lap ";
		break;
	case 30:
		img_out = sobelFilter(img);
		output_name += "1_8_sob ";
		break;
	case 31:
		mask = (Mat_<float>(3, 3) <<
			0, -1, 0,
			-1, 5, -1,
			0, -1, 0);

		img_out = filter(img, mask);
		output_name += "1_9_a ";
		break;
	case 32:

		mask = (Mat_<float>(3, 3) <<
			0, 0, 0,
			0, 1, 0,
			0, 0, -1);
		img_out = filter(img, mask);
		output_name += "1_9_b ";
		break;
	case 33:
		img_out = noiseSaltPepper(img, 0.05f);
		output_name += "2_0_noise_pepper ";
		break;
	case 34:
		img_out = noiseSaltPepper(img, 0.05f);
		img_out = meanFilter(img_out, 3);
		output_name += "2_0_mean ";
		break;
	case 35:
		img_out = noiseSaltPepper(img, 0.05f);
		img_out = medianFilter(img_out, 3);
		output_name += "2_0_med ";
		break;
	default:
		break;
	}

	output_name += ".jpg";
	imwrite(output_name, img_out);
	return 0;
}