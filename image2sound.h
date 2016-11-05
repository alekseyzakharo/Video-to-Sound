#ifndef IMAGE2SOUND_H
#define IMAGE2SOUND_H

#include <QtWidgets/QMainWindow>
#include "iostream"
#include "ui_image2sound.h"
#include "VideoManager.h"
#include <memory>
#include <thread>

using namespace std;

enum Text {
	PLAY,
	STOP
};

class image2sound : public QMainWindow
{
	Q_OBJECT
public:
	image2sound(QWidget *parent = 0);
	~image2sound();

public slots:
	void load();
	void play();
	void close_window();
private:
	Ui::image2soundClass ui;
	Text text_;
	VideoManager video_manager_;
};

#endif // IMAGE2SOUND_H
