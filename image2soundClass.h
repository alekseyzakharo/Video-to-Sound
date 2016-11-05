#ifndef IMAGE2SOUNDCLASS
#define IMAGE2SOUNDCLASS

#include "ui_image2sound.h"
#include "image2sound.h"
#include <memory>

namespace Ui {
	using std::shared_ptr;
	using std::string;
	class image2sound;
	class image2soundClass : public Ui_image2soundClass {
	private:
		shared_ptr<image2sound> ptr;
		void(*load_ptr)(string &);
	public:
		image2soundClass(shared_ptr<image2sound> p) :ptr(p) {}
		void set_load(void(*Load)(string &)) { load_ptr = Load; }
		public slots :
			void Load(string filepath)
		{
			load_ptr(filepath);
		}
	};
} // namespace Ui


#endif

