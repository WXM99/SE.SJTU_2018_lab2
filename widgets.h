#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <FL/Fl.H>
#include <FL/Fl_Single_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <stdlib.h>
#include <FL/Fl_Multiline_Input.H>
#include "evalue.h"

Fl_Box *text;
Fl_Input *input;
Fl_Input *input_func;
Fl_Multiline_Input *show_history;
Fl_Double_Window* grapher;
Fl_Double_Window* window;


//static vector<Fomula> history_table = pass;
//Fl_Double_Window *window2;
//static string answer;
//string pass_ans;
//Fl_Double_Window *window;


/*void update_input_text(Fl_Widget* o, const char *input) {
  if (input) {
    o->copy_label(input);
    o->redraw();
  }
}

void rename_me(Fl_Widget*o) {
  const char *input = fl_input("Input:");//o->label());
  string s = my_eval(input);
  const char *c_s=s.c_str(); 
  update_input_text(o, c_s);
}

void rename_me_pwd(Fl_Widget*o) {
  const char *input = fl_input("Input PWD:", o->label());
  update_input_text(o, input);
}

void show_history_cb(Fl_Widget*o) {

}

void input_cb(Fl_Widget *o,void *) {
    //present.exp = input->value();
  //string s = my_eval(input->value());
  //const char *c_s=s.c_str();
  //text->copy_label(c_s);
}*/

void equi_cb(Fl_Widget *o, void *){
  string pass_ans,exp_pass,trash;
  exp_pass = input->value();
  pass_ans = my_eval(exp_pass);
  const char* ans_char = nullptr;
  ans_char = pass_ans.c_str();
  text->copy_label(ans_char);
  string lines;
  for(int i = 0;i<history.size();i++){
      stringstream trans;
      trans<<history[i].ans;
      string num,ans;
      trans>>ans;
      trans<<i+1;
      trans>>num;
      lines +=  ans + '\n'; 
  };
  const char* his_char = lines.c_str();
  show_history->value(his_char);
};

void clean_cb(Fl_Widget*o, void *){
    const char zero = '0';
    const char nothing = ' '; 
    const char* clean = &zero;
    const char* clear = &nothing; 
    input->value(clean);
    text->copy_label(clear);
    present.clean();
    expStr.str("");
};

void back_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "") mid = "";
    else mid.pop_back();
    const char*ans_add = mid.c_str();
    input->value(ans_add);
};


void lastAns_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "ANS";
    else mid += "ANS";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}

void plus_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "+";
    else mid += "+";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}

void minus_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "-";
    else mid += "-";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}

void multi_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "*";
    else mid += "*";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}

void devide_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "/";
    else mid += "/";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}

void module_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "%";
    else mid += "%";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}

void one_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "1";
    else mid += "1";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void zero_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "0";
    else mid += "0";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void two_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "2";
    else mid += "2";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void three_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "3";
    else mid += "3";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void four_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "4";
    else mid += "4";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void five_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "5";
    else mid += "5";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void six_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "6";
    else mid += "6";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void seven_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "7";
    else mid += "7";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void eight_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "8";
    else mid += "8";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void nine_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "9";
    else mid += "9";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void point_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = ".";
    else mid += ".";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void bracket0_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "(";
    else mid += "(";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void bracket1_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = ")";
    else mid += ")";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}
void step_cb(Fl_Widget*o, void *){
    string mid = input->value();
    if(mid == "0") mid = "!";
    else mid += "!";
    const char*ans_add = mid.c_str();
    input->value(ans_add);
}


void showhis_cb(Fl_Widget *o, void *){
  string lines;
  for(int i = 0;i<history.size();i++){
      stringstream trans;
      trans<<history[i].ans;
      string num,ans;
      trans>>ans;
      trans<<i+1;
      trans>>num;
      lines +=  to_string(i+1) + ">>  " + history[i].exp + "=" + ans + '\n'; 
  };
  const char* his_char = lines.c_str();
  show_history->value(his_char);
}
void showans_cb(Fl_Widget *o, void *){
  string lines;
  for(int i = 0;i<history.size();i++){
      stringstream trans;
      trans<<history[i].ans;
      string num,ans;
      trans>>ans;
      trans<<i+1;
      trans>>num;
      lines +=  ans + '\n'; 
  };
  const char* his_char = lines.c_str();
  show_history->value(his_char);
}
/*------------------------------*/
int ox = 295;
int oy = 290;
string fomula = "x";


void show_grapher(Fl_Widget*o) {
    int invalid_counter = 0;
    grapher->show();
    fomula = input_func->value();
    for(double i = 10-ox; i < 580-ox ;i += 1){//
    double x = (i);
    double y;
    try{y = -50*my_func(fomula, 0.02*i);}
    catch(...){
    invalid_counter ++;
      }
    }
    o->parent()->redraw();
    if(invalid_counter>10){fl_message("invalid function!");invalid_counter = 0;}
}

void show_cal(Fl_Widget*o){
    window->show();
};

void axis(){
  
  if(ox>=10&&ox<=580){
  fl_begin_line();	
  fl_vertex(ox+0,90); 
  fl_vertex(ox+0,490);
  fl_end_line();
  }
  if(oy>=90 && oy<=490){
  fl_begin_line();	
  fl_vertex(10,oy+0); 
  fl_vertex(580,oy+0);
  fl_end_line();
  }
  fl_color(45);
  for(int i = 50 ; i<max(ox-10,580-ox); i+= 50){
     fl_begin_line();	
     fl_vertex(ox+i,90); 
     fl_vertex(ox+i,490);
     fl_end_line();
     fl_begin_line();	
     fl_vertex(ox-i,90); 
     fl_vertex(ox-i,490);
     fl_end_line();
  }
    for(int i = 50 ; i<max(oy-90,490-oy); i+= 50){
     fl_begin_line();	
     fl_vertex(10,oy+i); 
     fl_vertex(580,oy+i);
     fl_end_line();
     fl_begin_line();	
     fl_vertex(10,oy-i); 
     fl_vertex(580,oy-i);
     fl_end_line();
  }
}


void left_cb(Fl_Widget* o){
    ox = ox - 10;
    o->parent()->redraw();
}
void right_cb(Fl_Widget* o){
    ox = ox + 10;
    o->parent()->redraw();
}
void up_cb(Fl_Widget* o){
    oy = oy - 10;
    o->parent()->redraw();
}
void down_cb(Fl_Widget* o){
    oy = oy + 10;
    o->parent()->redraw();
}
void op_cb(Fl_Widget* o){
    ox = 295;
    oy = 290;
    o->parent()->redraw();
}


void the_line(){
    
  fl_push_matrix();
  fl_line_style(FL_SOLID);
  fl_translate(ox, oy);//position
  for(double i = 10-ox; i < 580-ox ;i += 1){//
    double x = (i);
    double y;
    try{y = -50*my_func(fomula, 0.02*i);
    if(x+ox<=11 || x+ox >=579 || oy+y<=91 || oy+y >= 489){}
    else{
        fl_begin_line();
		fl_vertex(i,-50*my_func(fomula, 0.02*i));
		fl_vertex((i+1),-50*my_func(fomula, 0.02*(i+1)));
         fl_end_line();
        }
    }
    catch(...){
    fl_begin_line();
	fl_vertex(0,0);
	fl_vertex(0,0);
    fl_end_line();
    }
  }
  fl_pop_matrix();
}

void func_draw(int w,int h) {//draw on the canvas
  fl_color(FL_WHITE); fl_rectf(10,90,w-20,h-100);
	//a white rectangle blocks what has been drawn
  //fl_color(173); //find what color in "Enumerations.H"
  //star(demention);//the koch line
  fl_color(FL_BLACK);axis();
  fl_color(173);the_line();
  fl_color(49); fl_rectf(0,0,590,90);fl_rectf(0,0,10,500);
  fl_rectf(580,0,10,500);fl_rectf(0,490,590,10);
};

class Canvas : public Fl_Window {
  void draw() {
    func_draw(w(),h());
    draw_child(*child(0)); 
    draw_child(*child(1));
    draw_child(*child(2));
    draw_child(*child(3));
	draw_child(*child(4)); 
    draw_child(*child(5)); 
    draw_child(*child(6)); 
    draw_child(*child(7));
    draw_child(*child(8));
  };
  //func_draw(w(),h());}
public:
  Canvas(int x, int y,int w,int h,const char *l)
    : Fl_Window(x,y,w,h,l) {resizable(this);}
};
