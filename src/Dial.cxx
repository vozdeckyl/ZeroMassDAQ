#include <ctime>
#include <cmath>
#include <string>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include <pangomm/layout.h>
#include <pangomm/fontdescription.h>


#include "Dial.hpp"

Dial::Dial()
    : m_radius(0.42), m_line_width(0.05)
{
    set_size_request(360,200);
    Glib::signal_timeout().connect( sigc::mem_fun(*this, &Dial::on_timeout), 100);
}

Dial::~Dial()
{
}


bool Dial::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
  // the center of the window
  //cr->scale(width, height);

  // 300; 150

  
  //cr->save();
  cr->set_source_rgba(1.0, 1.0, 1.0, 1.0);
  cr->paint();
  cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
  cr->set_line_width(5);
  cr->translate(180, 190);
  
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  
  for(double marks = 0.0; marks <= 100.0; marks += 10.0)
  {
      cr->move_to(130 * cos(M_PI * marks * 0.01),   -130 * sin(M_PI * marks * 0.01) );
      cr->line_to(140 * cos(M_PI * marks * 0.01),   -140 * sin(M_PI * marks * 0.01) );

      
      auto layout = create_pango_layout(std::to_string(static_cast<int>(5*(100.0-marks))));
      layout->set_font_description(font);
      int label_width, label_height;
      layout->get_pixel_size(label_width, label_height);

      int horizontal_shift;
      if(marks * 0.01 < 0.5)
      {
	  horizontal_shift = 0;
      }
      else if(marks * 0.01 == 0.5)
      {
	  horizontal_shift = -label_width/2;
      }
      else
      {
	  horizontal_shift = -label_width;
      }
      
      cr->move_to(horizontal_shift + 150  * cos(M_PI * marks * 0.01), -10 - 150* sin(M_PI * marks * 0.01));
      
      layout->show_in_cairo_context(cr);
      
  }
  cr->stroke();

  
  auto layout = create_pango_layout("COUNTS PER SECOND");
  layout->set_font_description(font);
  int text_width;
  int text_height;
  layout->get_pixel_size(text_width, text_height);
  cr->move_to(-text_width/2, -50);
  layout->show_in_cairo_context(cr);
  
  

  cr->set_source_rgba(1.0, 0, 0, 1.0);
  cr->set_line_width(8);


  cr->move_to(0.0,0.0);
  cr->line_to(-130 * cos(M_PI * m_reading * 0.01/5),  -130 * sin(M_PI * m_reading * 0.01/5) );
  cr->stroke();


  cr->set_source_rgba(0.0, 0.0, 0.0, 1.0);
  cr->arc(0.0, 0.0, 10, 0.0, 2 * M_PI);
  cr->fill();


  
  return true;

}


bool Dial::on_timeout()
{
    // force our program to redraw the entire dial
    auto win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}

void Dial::setReading(double value)
{
    m_reading = value;
}
