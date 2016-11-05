#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include <QString>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <memory>
#include <list>
#include <thread>
#include <atomic>
#include "AudioManager.h"
#include <Qwidget>

using namespace cv;
using namespace std;

enum Type {
	Video,
	Image,
	Ascii
};

class VideoManager : public QObject{
	Q_OBJECT
private:
	list<shared_ptr<Mat>> image_list_;
	list<shared_ptr<Mat>> original_image_list_;
	list<shared_ptr<Mat>>::iterator original_image_ = original_image_list_.begin();
	list<shared_ptr<Mat>>::iterator current_image_ = image_list_.begin();
	int current_col_ = 0;
	int current_progess_ = 0;
	shared_ptr<std::thread> play_thread_;
	QString filepath_;
	atomic<bool> stopped_ = true;
	AudioManager audio_manager_;
public:
	VideoManager();
	~VideoManager();
	void load(QString &filepath);
	void load_image(QString &filepath);
	void load_video(QString &filepath);
	void process_image(Mat & image);
	void play();
	void switch_status();
signals:
	void update_progressBar(int);
	void update_original_image(const QPixmap &);
	void update_processed_image(const QPixmap &);
};




#endif