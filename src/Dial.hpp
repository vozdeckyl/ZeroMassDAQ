#ifndef DIAL_H
#define DIAL_H

#include <gtkmm/drawingarea.h>

class Dial : public Gtk::DrawingArea
{
public:
    Dial();
    virtual ~Dial();
    void setReading(double value);
    
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    bool on_timeout();

    double m_radius;
    double m_line_width;

private:
    double m_reading;
};

#endif
