#include "VideoManager.h"
#include "opencv2/imgproc.hpp"
#include <QPixmap>
#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>

#define PI 3.1415926

VideoManager::VideoManager()
{
	audio_manager_.open();
}

VideoManager::~VideoManager()
{
	stopped_ = true;
	if(play_thread_ != NULL)
		play_thread_->join();
	audio_manager_.close();
}


void VideoManager::load(QString & filepath)
{
	//make sure play() is not running anymore
	stopped_ = true;
	if (play_thread_ != NULL &&play_thread_->joinable())
		play_thread_->join();
	play_thread_.reset();
	current_progess_ = 0;
	filepath_ = filepath;
	QString postfix = filepath.right(filepath.length() - filepath.lastIndexOf('.') - 1);
	if (postfix == "png" || postfix == "jpg" || postfix == "bmp")
		load_image(filepath);
	else if (postfix == "avi")
		load_video(filepath);
	else
		;//TODO:ascii code file
}

void VideoManager::load_image(QString & filepath)
{
	image_list_.clear();
	original_image_list_.clear();
	Mat image= imread(filepath.toStdString());
	process_image(image);
	current_image_ = image_list_.begin();
	original_image_ = original_image_list_.begin();
	current_col_ = 0;
}

void VideoManager::load_video(QString & filepath)
{
	image_list_.clear();
	original_image_list_.clear();
	VideoCapture capture(filepath.toStdString());
	if (!capture.isOpened())
	{
		cout << "Open video error" << endl;
		exit(1);
	}

	//read each frame from capture
	for(int i = 0;;i++)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;
		if (i % 30 == 0)
			process_image(frame);
	}
	original_image_ = original_image_list_.begin();
	current_image_ = image_list_.begin();
	current_col_ = 0;
	
	//release the frame buffer
	capture.release();
}


void VideoManager::process_image(Mat & image)
{
	//resize the image to 64*64
	shared_ptr<Mat> sub_image(new Mat(64, 64, CV_8UC1));
	cv::Size size = { 64, 64 };
	resize(image, *sub_image, size);
	//clone an original image and add to the list
	shared_ptr<Mat> original_image(new Mat(image.clone()));
	cvtColor(*original_image, *original_image, CV_BGR2RGB);
	original_image_list_.push_back(original_image);
	//convert to gray image
	cvtColor(*sub_image, *sub_image, CV_BGR2GRAY);
	//shift every gray byte right 4 bits
	for (int x = 0; x < sub_image->cols; x++)
		for (int y = 0; y < sub_image->rows; y++)
			sub_image->at<uchar>(x, y) = sub_image->at<uchar>(x, y) >> 4;
	image_list_.push_back(sub_image);
}

void VideoManager::play()
{
	while (current_image_ != image_list_.end())
	{
		//set Qlabel image
		QPixmap original_pixmap = QPixmap::fromImage(QImage((unsigned char*)(*original_image_)->data,
			(*original_image_)->cols, (*original_image_)->rows, (*original_image_)->step, QImage::Format_RGB888));
		emit update_original_image(original_pixmap);
		QPixmap current_pixmap = QPixmap::fromImage(QImage((unsigned char*)(*current_image_)->data,
			(*current_image_)->cols, (*current_image_)->rows, (*current_image_)->step, QImage::Format_Grayscale8));
		emit update_processed_image(current_pixmap);

		int Fs = 8000;
		float freq[64];
		freq[31] = 440;
		for (int i = 32; i < 64; i++)
			freq[i] = freq[i - 1] * pow(2, 1 / (float)12);
		for (int i = 30; i >= 0; i--)
			freq[i] = freq[i + 1] * pow(2, -1 / (float)12);
		int N = 500;
		float tt[500];
		for (int i = 0; i < 500; i++)
			tt[i] = (i + 1) / (float)Fs;
		for (; current_col_ < 64; current_col_++)
		{
			if (stopped_)
				return;
			float signal[500];
			memset(signal, 0, 500);
			for (int row = 0; row < 64; row++)
			{
				int m = 64 - row + 1;
				float ss[500];
				for (int i = 0; i < 500; i++)
					ss[i] = sin(2 * PI *freq[m] * tt[i]);
				for (int i = 0; i < 500; i++)
				{
					uchar intensity = (*current_image_)->at<uchar>(row, current_col_);
					signal[i] = ss[i] * intensity;
				}
			}
			for (int i = 0; i < 500; i++)
				signal[i] = signal[i] / 64;
			audio_manager_.play(signal, N, Fs);
			audio_manager_.wait();
			//update progress bar
			current_progess_++;
			float percent = current_progess_ / (float)(image_list_.size() * 64) * 100;
			emit update_progressBar(int(percent));
		}
		current_col_ = 0;
		current_image_++;
		original_image_++;
	}

	//ready for playing second time
	current_image_ = image_list_.begin();
	original_image_ = original_image_list_.begin();
	current_col_ = 0;
}

void VideoManager::switch_status()
{
	if (stopped_)
	{
		stopped_ = false;
		if (play_thread_ != NULL && play_thread_->joinable())
			play_thread_->join();
		play_thread_.reset(new std::thread(&VideoManager::play, this));
	}
	else
		stopped_ = true;
}

