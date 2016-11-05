#include "image2sound.h"
#include "QFileDialog"

image2sound::image2sound(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.progressBar->setMaximum(100);
	ui.progressBar->setMinimum(0);
	QObject::connect(&video_manager_, SIGNAL(update_progressBar(int)), ui.progressBar, SLOT(setValue(int)));
	QObject::connect(&video_manager_, SIGNAL(update_original_image(const QPixmap&)), ui.label_original, SLOT(setPixmap(const QPixmap&)));
	QObject::connect(&video_manager_, SIGNAL(update_processed_image(const QPixmap&)), ui.label_processed, SLOT(setPixmap(const QPixmap&)));
	text_ = PLAY;
}

image2sound::~image2sound()
{
	close_window();
}

void image2sound::load()
{
	QString filepath = QFileDialog::getOpenFileName(this,
		tr("Open a multimedia file--video image or ascii file"), "/home/jana", tr("Multimedia Files (*.png *.JPG *.bmp *.avi)"));
	video_manager_.load(filepath);
	ui.button_play->setText("Play");
}

void image2sound::play()
{
	video_manager_.switch_status();
	if (text_ == PLAY)
	{
		text_ = STOP;
		ui.button_play->setText("Stop");
	}
	else
	{
		text_ = PLAY;	
		ui.button_play->setText("Play");
	}
}

void image2sound::close_window()
{
	this->close();
}
