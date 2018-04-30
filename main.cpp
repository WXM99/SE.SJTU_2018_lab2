#include <stdio.h>
#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <stdlib.h>
#include <FL/Fl_Multiline_Input.H>
#include "widgets.h"


int main(int argc, char **argv) {


  //widgets in grapher below---------------------------
  grapher = new Fl_Double_Window(590,500,"grapher"); //window for grapher
  Canvas image(0,0,590,500,"wxm"); //widgets and image  

  Fl_Button sub_cal(20, 10, 160, 35,  "Calculator"); sub_cal.callback(show_cal);
  //call up calculator window
  sub_cal.labelfont(1);
  sub_cal.labelsize(20);
  sub_cal.labelcolor(0);

  Fl_Return_Button sub_gra(20, 50, 160, 35,"Grapher"); sub_gra.callback(show_grapher);
  //bound with keboard Return
  sub_gra.labelfont(1);
  sub_gra.labelsize(20);
  sub_gra.labelcolor(FL_WHITE);
  sub_gra.color(228);

  input_func = new Fl_Input(230,10,340,35,""); 
  input_func->static_value("x");

  int xx= 190, y0 = 50, w0 = 76, h5= 35;//location for image
  Fl_Box* fx;
  fx = new Fl_Box(xx,10,35,35,"f(x)=");//prompt
  fx->labelfont(1);
  fx->labelsize(20);

  Fl_Button move_l(xx,y0,w0,h5,"▶︎"); move_l.callback(left_cb);//image movement
  Fl_Button move_r(xx+w0,y0,w0,h5,"◀︎");move_r.callback(right_cb);
  Fl_Button move_u(xx+2*w0,y0,w0,h5,"▲");move_u.callback(down_cb);
  Fl_Button move_d(xx+3*w0,y0,w0,h5,"▼");move_d.callback(up_cb);
  Fl_Button move_o(xx+4*w0,y0,w0,h5,"⦿") ;move_o.callback(op_cb);

  //widgets in calculator below------------------------------
  window = new Fl_Double_Window (590, 500,"calculator"); 

  Fl_Return_Button cal(20, 10, 160, 35, "Calculator"); cal.callback(equi_cb);
  //bound with keboard Return
  cal.labelfont(1);
  cal.labelsize(20);
  cal.labelcolor(FL_WHITE);
  cal.color(228);
  Fl_Button gra(20, 50, 160, 35, "Grapher"); gra.callback(show_grapher);
  //call up grapher window
  gra.labelfont(1);
  gra.labelsize(20);
  gra.labelcolor(0);


  input = new Fl_Input(70,100,450,30," ");
  input->static_value("0");
  input->when(FL_WHEN_CHANGED);
  input->labelsize(10);
  input->labelcolor(FL_BLUE);
  
  text = new Fl_Box(FL_FRAME_BOX,70,130,500,50,"Welcome!");//output 
  text->labelcolor(FL_WHITE);
  text->labelsize(32);
  text->color(35);
  text->labelfont(1);
  text->align(FL_ALIGN_CENTER);

  show_history = new Fl_Multiline_Input(250,10,320,75); 
  show_history->selection_color(173);
  show_history->align(FL_ALIGN_RIGHT);

  Fl_Button show_his(190,10,60,35,"history");show_his.callback(showhis_cb);
  Fl_Button show_ans(190,50,60,35,"ans");show_ans.callback(showans_cb);

  Fl_Button equi(20,130,50,49,"=");equi.callback(equi_cb);
  equi.labelcolor(FL_WHITE);
  equi.labelfont(0);
  equi.labelsize(44);
  equi.color(173);
  
  Fl_Button clean(20,100,50,30,"AC");clean.callback(clean_cb);
  clean.labelcolor(FL_WHITE);
  clean.labelfont(1);
  clean.labelsize(20);
  clean.color(228);

  Fl_Button back(520,100,50,30,"C");back.callback(back_cb);
  back.labelcolor(FL_WHITE);
  back.labelfont(1);
  back.labelsize(20);
  back.color(228);

  const int x = 20,y = 200; //button location
  const int w = 110,h = 70; //button size
  Fl_Button lastAns(x+4*w,y+3*h,w,h,"ANS");lastAns.callback(lastAns_cb);lastAns.labelsize(42);   
  Fl_Button plus(x+3*w,y,w,h,"+");plus.callback(plus_cb);plus.labelsize(42);  
  Fl_Button minus(x+3*w,y+h,w,h,"—");minus.callback(minus_cb);minus.labelsize(42); 
  Fl_Button multi(x+3*w,y+2*h,w,h,"*");multi.callback(multi_cb);multi.labelsize(42); 
  Fl_Button devide(x+3*w,y+3*h,w,h,"/");devide.callback(devide_cb);devide.labelsize(42); 
  Fl_Button module(x+4*w,y,w,h,"%");module.callback(module_cb); module.labelsize(42);  
  
  Fl_Button zero(x+w,y+3*h,w,h,"0");zero.callback(zero_cb,(void*)0);zero.labelsize(42);
  Fl_Button one(x+2*w,y+2*h,w,h,"1");one.callback(one_cb,(void*)1);one.labelsize(42);
  Fl_Button two(x+w,y+2*h,w,h,"2");two.callback(two_cb,(void*)2);two.labelsize(42);
  Fl_Button three(x,y+2*h,w,h,"3");three.callback(three_cb,(void*)3);three.labelsize(42);
  Fl_Button four(x+2*w,y+h,w,h,"4");four.callback(four_cb,(void*)4);four.labelsize(42);
  Fl_Button five(x+w,y+h,w,h,"5");five.callback(five_cb,(void*)5);five.labelsize(42);
  Fl_Button six(x,y+h,w,h,"6");six.callback(six_cb,(void*)6);six.labelsize(42);
  Fl_Button seven(x+2*w,y,w,h,"7");seven.callback(seven_cb,(void*)7);seven.labelsize(42);
  Fl_Button eight(x+w,y,w,h,"8");eight.callback(eight_cb,(void*)8);eight.labelsize(42);
  Fl_Button nine(x,y,w,h,"9");nine.callback(nine_cb,(void*)9);nine.labelsize(42);
  
  Fl_Button point(x+4*w,y+h,w,h,".");point.callback(point_cb,(void*)10);point.labelsize(42);
  Fl_Button step(x+4*w,y+2*h,w,h,"!");step.callback(step_cb,(void*)11);step.labelsize(42);
  Fl_Button bracket0(x,y+3*h,w,h,"(");bracket0.callback(bracket0_cb,(void*)12);bracket0.labelsize(42);
  Fl_Button bracket1(x+2*w,y+3*h,w,h,")");bracket1.callback(bracket1_cb,(void*)13);bracket1.labelsize(42);

  window->end();
  window->resizable(&cal);
  window->show(argc, argv);

  return Fl::run();
}
