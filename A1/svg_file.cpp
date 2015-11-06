#include "svg_file.h"

bool svg_file_init ( svg_file *f, int height, int width, const char * name)
{
	f->height = height;
	f->width = width;
	f->name = string(name);

	f->file.open(name);
	if (f->file.is_open())
	{
		f->file	<< "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>" << endl;
		f->file	<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 20001102//EN\" \"http://www.w3.org/TR/2000/CR-SVG-20001102/DTD/svg-20001102.dtd\">" << endl;
		f->file	<< "<svg version=\"1.1\"" << endl 
			<< "xmlns=\"http://www.w3.org/2000/svg\"" << endl
			<< "xmlns:xlink=\"http://www.w3.org/1999/xlink\"" << endl
			<< "width=\"" << f->width << "\" height=\"" << f->height << "\" >" << endl;
			
		f->file << "<g transform=\"translate("<< f->width/2 << " " << f->height/2 << ")\">" << endl;
		f->file << "<g transform=\"scale(1 -1)\">" << endl;
		f->file << "<g id=\"turleGraphics\">" << endl;
		return true;
	}
	return false;	
}

void svg_file_line (svg_file *f, int x1, int y1, int x2, int y2)
{
	f->file << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" ";
	f->file << "style=\"stroke:rgb(0,0,0);stroke-width:2\" />" << endl;
}

void svg_file_end  ( svg_file *f)
{
	f->file << "</g>" << endl << "</g>" << endl << "</g>" << endl << "</svg>" << endl;
	f->file.close();
}

