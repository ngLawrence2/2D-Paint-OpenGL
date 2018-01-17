#include <math.h>
#include <stdio.h>
#include <string.h>

#ifdef __APPLE__
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
  #include <GLUT/glut.h>
#elif __linux__
  #include <GL/glut.h>
#endif


#define LEFT_MOUSE_BUTTON 1
#define MIDDLE_MOUSE_BUTTON 2
#define RIGHT_MOUSE_BUTTON 3
int last_mouse_button_pressed =  0;
int points = 0; 
int d =0 ;
char draw[10];
int numlineinit= 0 ;
int numrec=0;
int numrec1=0;
int numel1=0;
int numel=0;
int numb=0;
const float DEG2RAD = 3.14159/180.0;

float r, g ,b;

struct pointXY {
	int x ;
	int y;
};

struct pointXY lineA; 
struct pointXY lineB;
struct pointXY lineC;
struct pointXY lineD;
struct l {
	struct pointXY a;
	struct pointXY b;
	float red,green,blue;
};

struct r {
 struct pointXY a;
  struct pointXY b;
  float red, green , blue;
};

struct e {
struct pointXY a;
struct pointXY b;
	float rad;
	 float red, green , blue;
	
};

struct b {
	struct pointXY a;
struct pointXY b;
	struct pointXY c;
struct pointXY d;
	 float red, green , blue;
	
};

struct l line1;
struct r rec1;
struct e ell1;
struct b b1;

struct l maxList[10];
struct r recList[10];
struct r ureclist[10];
struct e elList[10];
struct e uelList[10];
struct b bList[10];

void menu (int value)
{
  switch (value) 
  {
    case 1:
      printf ("ellipse -> fill ->  red\n");
		     strcpy(draw,"ell");
		  points = 0 ;
		  r= 1.0;
		  g= 0.0;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
    case 2:
      printf ("ellipse -> fill -> green\n");
		   strcpy(draw,"ell");
		  points = 0 ;
		  r= 0.0;
		  g= 1.0;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
    case 3:
      printf ("ellipse -> fill -> blue\n");
		  strcpy(draw,"ell");
		  points = 0 ;
		  r= 0.0;
		  g= 0.0;
		  b = 1.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		    case 4:
      printf ("ellipse -> fill -> yellow\n");
		      	    points = 0;
     
		   strcpy(draw,"ell");
		  
		  r= 1.0;
		  g= 1.0;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		    case 5:
      printf ("ellipse -> fill -> white\n");
		  strcpy(draw,"ell");points = 0 ;
		  
		  r= 1.0;
		  g= 1.0;
		  b = 1.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		    case 6:
      printf ("ellipse -> fill -> purple\n");
		  	    strcpy(draw,"ell");points = 0 ;
		  r= 0.5;
		  g= 0.0;
		  b = 1.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		    case 7:
      printf ("ellipse -> fill -> orange\n");
		    strcpy(draw,"ell");points = 0 ;
		     r= 1.0;
		  g= 0.5;
		  b = 0.0;
		     (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		    case 8:
      printf ("ellipse -> fill -> pink\n");
		      strcpy(draw,"ell");points = 0 ;
		  r= 1.0;
		  g= 0.0;
		  b = .7;
		    (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 9:
      printf ("ellipse -> outline -> red \n");
		     strcpy(draw,"ell1");
		  points = 0 ;
		  r= 1.0;
		  g= 0.0;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		      case 10:
      printf ("ellipse -> outline -> green \n");
		  	     strcpy(draw,"ell1");
		  points = 0 ;
		  r= .0;
		  g= 1.0;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		      case 11:
      printf ("ellipse -> outline -> blue \n");
		  	     strcpy(draw,"ell1");
		  points = 0 ;
		  r= 0.0;
		  g= 0.0;
		  b = 1.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		      case 12:
      printf ("ellipse -> outline -> yellow\n");
		  
		   strcpy(draw,"ell1");
		  
		  r= 1.0;
		  g= 1.0;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		      case 13:
      printf ("ellipse -> outline -> white\n");
		  	     strcpy(draw,"ell1");
		  points = 0 ;
		  r= 1.0;
		  g= 1.0;
		  b = 1.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;    
	  case 14:
      printf ("ellipse -> outline -> purple\n");
		  	     strcpy(draw,"ell1");
		  points = 0 ;
		  r= .5;
		  g= 0.0;
		  b = 1.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;    
	  case 15:
      printf ("ellipse -> outline -> orange\n");
		  	     strcpy(draw,"ell1");
		  points = 0 ;
		  r= 1.0;
		  g= 0.5;
		  b = 0.0;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		      case 16:
      printf ("ellipse -> outline -> pink\n");
		  	     strcpy(draw,"ell1");
		  points = 0 ;
		  r= 1.0;
		  g= 0.0;
		  b = 0.7;
		   (&ell1)->red = r;
		  (&ell1)->green = g;
		  (&ell1)->blue = b;
    break;
		      case 17:
      printf ("rec -> fill -> red\n");
		points = 0 ;
		  strcpy(draw,"rec1");
		  r = 1.0;
		  g= 0.0;
		  b= 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 18:
      printf ("rec -> fill -> green\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		  r= 0.0;
		  g= 1.0;
		  b = 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 19:
      printf ("rec -> fill -> blue\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		  r = 0.0;
		  g= 0.0;
		  b= 1.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 20:
      printf ("rec -> fill -> yellow\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		   r= 1.0;
		  g= 1.0;
		  b = 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 21:
      printf ("rec -> fill -> white\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		  r= 1.0;
		  g= 1.0;
		  b = 1.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 22:
      printf ("rec -> fill -> purple\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		  
		  r= 0.5;
		  g= 0.0;
		  b = 1.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 23:
      printf ("rec -> fill -> orange\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		    r= 1.0;
		  g= 0.5;
		  b = 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 24:
      printf ("rec -> fill -> pink\n");
		  points = 0 ;
		  strcpy(draw,"rec1");
		  r= 1.0;
		  g= 0.0;
		  b = .7;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 25:
      printf ("rec -> outline -> red\n");
		  points = 0 ;
		  strcpy(draw,"rec");
		  r = 1.0;
		  g= 0.0;
		  b= 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 26:
      printf ("rec -> outline -> green\n");
		    points = 0 ;
		  strcpy(draw,"rec");
		  r= 0.0;
		  g= 1.0;
		  b = 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 27:
      printf ("rec -> outline -> blue\n");
		   points = 0 ;
		  strcpy(draw,"rec");
		  r = 0.0;
		  g= 0.0;
		  b= 1.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 28:
      printf ("rec -> outline -> yellow\n");
		   points = 0 ;
		  strcpy(draw,"rec");
		   r= 1.0;
		  g= 1.0;
		  b = 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 29:
      printf ("rec -> outline ->  white\n");
		    points = 0 ;
		  strcpy(draw,"rec");
		  r= 1.0;
		  g= 1.0;
		  b = 1.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 30:
      printf ("rec -> outline -> purple\n");
		   points = 0 ;
		  strcpy(draw,"rec");
		  
		  r= 0.5;
		  g= 0.0;
		  b = 1.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 31:
      printf ("rec -> outline -> orange\n");
		    points = 0 ;
		  strcpy(draw,"rec");
		    r= 1.0;
		  g= 0.5;
		  b = 0.0;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 32:
      printf ("rec -> outline -> pink\n");
		    points = 0 ;
		  strcpy(draw,"rec");
		  r= 1.0;
		  g= 0.0;
		  b = .7;
		  (&rec1)->red = r;
		  (&rec1)->green = g;
		  (&rec1)->blue = b;
    break;
		      case 33:
      printf ("line -> red \n");
		points = 0 ;
		  strcpy(draw,"line");
		  r = 1.0;
		  g= 0.0;
		  b= 0.0;
		  (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
		
    break;
		      case 34:
		    points = 0;
      printf ("line -> green \n");
		   strcpy(draw,"line");
		  
		  r= 0.0;
		  g= 1.0;
		  b = 0.0;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
		
    break;
		      case 35:
      printf ("line -> blue \n");
		  	    points = 0;
     
		   strcpy(draw,"line");
		  
		  r= 0.0;
		  g= 0.0;
		  b = 1.0;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
		
    break;
		      case 36:
      printf ("line -> yellow \n");
		    	    points = 0;
     
		   strcpy(draw,"line");
		  
		  r= 1.0;
		  g= 1.0;
		  b = 0.0;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
    break;
		      case 37:
      printf ("line -> white \n");
		    	    points = 0;
     
		   strcpy(draw,"line");
		  
		  r= 1.0;
		  g= 1.0;
		  b = 1.0;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
    break;
		      case 38:
      printf ("line -> purple\n");
		    	    points = 0;
     
		   strcpy(draw,"line");
		  
		  r= 0.5;
		  g= 0.0;
		  b = 1.0;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
		  
    break;
		      case 39:
      printf ("line -> orange\n");
		    	    points = 0;
     
		   strcpy(draw,"line");
		  
		  r= 1.0;
		  g= 0.5;
		  b = 0.0;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
    break;
		      case 40:
      printf ("line -> pink \n");
		    	    points = 0;
     
		   strcpy(draw,"line");
		  
		  r= 1.0;
		  g= 0.0;
		  b = .7;
		   (&line1)->red = r;
		  (&line1)->green = g;
		  (&line1)->blue = b;
    break;
		      case 41:
      printf ("bezier_curve -> red\n");
            	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 1.0;
		  g= 0.0;
		  b = 0.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
		      case 42:
      printf ("bezier_curve -> green \n");
            	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 0.0;
		  g= 1.0;
		  b = 0.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
		      case 43:
      printf ("bezier_curve -> blue \n");
            	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 0.0;
		  g= 0.0;
		  b = 1.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
		      case 44:
      printf ("bezier_curve -> yellow \n");
          points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 1.0;
		  g= 1.0;
		  b = 0.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
      
    break;
		      case 45:
      printf ("bezier_curve -> white \n");
          	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 1.0;
		  g= 1.0;
		  b = 1.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
		      case 46:
      printf ("bezier_curve -> purple \n");
            	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= .5;
		  g= 0.0;
		  b = 1.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
		      case 47:
      printf ("bezier_curve -> orange \n");
            	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 1.0;
		  g= .5;
		  b = 0.0;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
		      case 48:
      printf ("bezier_curve -> pink \n");
            	    points = 0;
     
		   strcpy(draw,"b");
		  
		  r= 1.0;
		  g= .0;
		  b = .7;
		   (&b1)->red = r;
		  (&b1)->green = g;
		  (&b1)->blue = b;
    break;
    default: 
    break;
  }
  glutPostRedisplay();
}

void drawLine(struct l la) {
	glColor3f(la.red, la.green, la.blue);
	glBegin(GL_LINE_STRIP);
	glVertex2f(la.a.x, la.a.y);
	glVertex2f(la.b.x,la.b.y);
	glEnd();
}

void drawunfilledrec(struct r la) {
    glColor3f(la.red, la.green, la.blue);
	
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(la.a.x,la.a.y);
	glVertex2f(la.b.x,la.a.y);
	glVertex2f(la.b.x,la.b.y);
	glVertex2f(la.a.x,la.b.y);
	glEnd();
  
}



void drawFilledRec(struct r la) {
    glColor3f(la.red, la.green, la.blue);
	glRectf(la.a.x,la.a.y,la.b.x,la.b.y);
  
}

void drawc(struct e la) {
	int circle_center_x =  la.a.x, circle_center_y =  la.a.y;
	
	float theta, circle_iterations =  24.0;
	glColor3f(la.red, la.green, la.blue);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);
	for(theta=0; theta < 2 * M_PI; theta +=M_PI/circle_iterations) {
		glVertex3f(circle_center_x+ cos(theta) * (la.rad) ,
				   circle_center_y + sin(theta) * (la.rad/2), 0.0f);	
	
	}
	glEnd();
}

void drawuc(struct e la) {
	int circle_center_x =  la.a.x, circle_center_y =  la.a.y;
	
	float theta, circle_iterations =  24.0;
	glColor3f(la.red, la.green, la.blue);
	
	glBegin(GL_LINE_LOOP);
	for(theta=0; theta < 2 * M_PI; theta +=M_PI/circle_iterations) {
		glVertex3f(circle_center_x+ cos(theta) * (la.rad)  ,
				   circle_center_y + sin(theta) * (la.rad/2), 0.0f);	
	
	}
	glEnd();
}





void drawbez(struct b b2) {
  
GLfloat ctrlpoints[4][3] = {
        { b2.a.x, b2.a.y, 0.0}, { b2.b.x, b2.b.y, 0.0}, 
        {b2.c.x, b2.c.y, 0.0}, {b2.d.x, b2.d.y, 0.0}};
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
   glEnable(GL_MAP1_VERTEX_3);
  int i;

 
   glColor3f(b2.red, b2.green, b2.blue);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
  
}



void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);


  
//draw bez curve
  drawbez(bList[0]);
  drawbez(bList[1]);
  drawbez(bList[2]);
  drawbez(bList[3]);
  drawbez(bList[4]);
  drawbez(bList[5]);
   drawbez(bList[6]);
   drawbez(bList[7]);
   drawbez(bList[8]);
   drawbez(bList[9]);
  
  

	
	//draw filled ellipse
	drawc(elList[0]);
	drawc(elList[1]);
	drawc(elList[2]);
	drawc(elList[3]);
	drawc(elList[4]);
	drawc(elList[5]);
	drawc(elList[6]);
	drawc(elList[7]);
	drawc(elList[8]);
	drawc(elList[9]);
	
  //draw unfilled ellipse
	drawuc(uelList[0]);
	drawuc(uelList[1]);
	drawuc(uelList[2]);
	drawuc(uelList[3]);
	drawuc(uelList[4]);
	drawuc(uelList[5]);
	drawuc(uelList[6]);
	drawuc(uelList[7]);
	drawuc(uelList[8]);
	drawuc(uelList[9]);
	
	//draws lines
	drawLine(maxList[0]) ;
	drawLine(maxList[1]) ;
	drawLine(maxList[2]) ;
	drawLine(maxList[3]) ;
	drawLine(maxList[4]) ;
	drawLine(maxList[5]) ;
	drawLine(maxList[6]) ;
	drawLine(maxList[7]) ;
	drawLine(maxList[8]) ;
	drawLine(maxList[9]) ;
  
  //draw filled rec
	
	drawFilledRec(recList[0]);
		drawFilledRec(recList[1]);
		drawFilledRec(recList[2]);
		drawFilledRec(recList[3]);
		drawFilledRec(recList[4]);
		drawFilledRec(recList[5]);
		drawFilledRec(recList[6]);
		drawFilledRec(recList[7]);
		drawFilledRec(recList[8]);
		drawFilledRec(recList[9]);
  
  //draw unfilled rec
	
	drawunfilledrec(ureclist[0]);
	drawunfilledrec(ureclist[1]);
	drawunfilledrec(ureclist[2]);
	drawunfilledrec(ureclist[3]);
	drawunfilledrec(ureclist[4]);
	drawunfilledrec(ureclist[5]);
	drawunfilledrec(ureclist[6]);
	drawunfilledrec(ureclist[7]);
	drawunfilledrec(ureclist[8]);
	drawunfilledrec(ureclist[9]);
	
	
	
	
	
  glutPostRedisplay();
	
/*  don't wait!  
 *  start processing buffered OpenGL routines 
 */
    glFlush ();
}





void mouse(int mouse_btn, int state, int x , int y) {
			char line[10];
	char rec[10];
	char ell[10];
	char bez[10];

	strcpy(line,"line");//if user selected line option
	if(strcmp(line,draw)==0) {
		if ((mouse_btn ==   GLUT_RIGHT_BUTTON) &&   (state == GLUT_DOWN)){
			if(points <2) {
				
				if(points ==0 )  {
					 (&lineA)->x = x;
					(&lineA)->y = y;
			//		printf("%d\t%d\n", x , y);
				}
				if(points ==1 ) {
						(&lineB)->x = x;
					(&lineB)->y = y;
				//	printf("%d\t%d\n", x , y);
					(&line1)->a=lineA;
				(&line1)->b = lineB;
				maxList[numlineinit] = line1;
			//	printf("%d\n", maxList[numlineinit].a.x);
				numlineinit++;
					strcpy(draw,"");
				}
				points++;
			}else {
				
				
				//printf("%d\n", numlineinit);
			strcpy(draw,"");
			}
		}
	}
  
  strcpy(rec,"rec1");
  //if user selected rec option
  if(strcmp(rec,draw)==0) {
    if((mouse_btn==GLUT_RIGHT_BUTTON) && (state==GLUT_DOWN)) {
      if(points <2) {
				if(points ==0 )  {
					 (&lineA)->x = x;
					(&lineA)->y = y;
					printf("%d\t%d\n", x , y);
				}
				if(points ==1 ) {
						(&lineB)->x = x;
					(&lineB)->y = y;
					printf("%d\t%d\n", x , y);
					(&rec1)->a=lineA;
				(&rec1)->b = lineB;
					
				recList[numrec] = rec1;
			//	printf("%d\n", maxList[numlineinit].a.x);
				numrec++;
					strcpy(draw,"");
				}
				points++;
			}else {
				
				
				//printf("%d\n", numlineinit);
			strcpy(draw,"");
			}
    }
  }
	
	 strcpy(rec,"rec");
  //if user selected rec option
  if(strcmp(rec,draw)==0) {
    if((mouse_btn==GLUT_RIGHT_BUTTON) && (state==GLUT_DOWN)) {
      if(points <2) {
				if(points ==0 )  {
					 (&lineA)->x = x;
					(&lineA)->y = y;
				//	printf("%d\t%d\n", x , y);
				}
				if(points ==1 ) {
						(&lineB)->x = x;
					(&lineB)->y = y;
					//printf("%d\t%d\n", x , y);
					(&rec1)->a=lineA;
				(&rec1)->b = lineB;
					
				ureclist[numrec1] = rec1;
			//	printf("%d\n", maxList[numlineinit].a.x);
				numrec1++;
					strcpy(draw,"");
				}
				points++;
			}else {
				
				
				//printf("%d\n", numlineinit);
			strcpy(draw,"");
			}
    }
  }
	
	strcpy(ell, "ell") ;
	//if user selected ellipse option
  if(strcmp(ell,draw)==0) {
    if((mouse_btn==GLUT_RIGHT_BUTTON) && (state==GLUT_DOWN)) {
      if(points <2) {
				if(points ==0 )  {
					 (&lineA)->x = x;
					(&lineA)->y = y;
					printf("%d\t%d\n", x , y);
				}
				if(points ==1 ) {
						(&lineB)->x = x;
					(&lineB)->y = y;
					printf("%d\t%d\n", x , y);
					(&ell1)->a=lineA;
				(&ell1)->b = lineB;
					
					float radius = sqrt((pow((lineB.x-lineA.x), 2))+(pow((lineB.y-lineA.y), 2)));
					(&ell1)->rad=radius;
					
					
				elList[numel1] = ell1;
			
				numel1++;
					strcpy(draw,"");
					
					
					
				}
				points++;
			}else {
				//printf("%d\n", numlineinit);
			strcpy(draw,"");
			}
    }
  }
	
		strcpy(ell, "ell1") ;
	//if user selected ellipse option
  if(strcmp(ell,draw)==0) {
    if((mouse_btn==GLUT_RIGHT_BUTTON) && (state==GLUT_DOWN)) {
      if(points <2) {
				if(points ==0 )  {
					 (&lineA)->x = x;
					(&lineA)->y = y;
					printf("%d\t%d\n", x , y);
				}
				if(points ==1 ) {
						(&lineB)->x = x;
					(&lineB)->y = y;
					printf("%d\t%d\n", x , y);
					(&ell1)->a=lineA;
				(&ell1)->b = lineB;
					
					float radius = sqrt((pow((lineB.x-lineA.x), 2))+(pow((lineB.y-lineA.y), 2)));
					(&ell1)->rad=radius;
					
					
				uelList[numel] = ell1;
			
				numel++;
					strcpy(draw,"");
					
					
					
				}
				points++;
			}else {
				//printf("%d\n", numlineinit);
			strcpy(draw,"");
			}
    }
  }
  
  
  
  
  	strcpy(bez, "b") ;
	//if user selected ellipse option
  if(strcmp(bez,draw)==0) {
    if((mouse_btn==GLUT_RIGHT_BUTTON) && (state==GLUT_DOWN)) {
      if(points <4) {
				if(points ==0 )  {
					 (&lineA)->x = x;
					(&lineA)->y = y;
					printf("%d\t%d\n", x , y);
         
				}
				if(points ==1 ) {
						(&lineB)->x = x;
					(&lineB)->y = y;
									
				}
        
        if(points == 2 ) {
          	 (&lineC)->x = x;
					(&lineC)->y = y;
					printf("%d\t%d\n", x , y);
        }
        
        if(points ==3 ) {
          	 (&lineD)->x = x;
					(&lineD)->y = y;
					printf("%d\t%d\n", x , y);
          
          (&b1)->a = lineA;
           (&b1)->b = lineB;
           (&b1)->c = lineC;
           (&b1)->d = lineD;
          
          bList[numb] = b1;
          numb++;
          		strcpy(draw,"");
          
        }
				points++;
         printf("%d\n", points);
			}else {
				//printf("%d\n", numlineinit);
			strcpy(draw,"");
			}
    }
  }
  
  
 
	
	
	glutPostRedisplay();
}



void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
	glViewport(0,0,1000,1000);
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 //   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	//glViewport (0, 0, (GLsizei) 1000, (GLsizei) 1000); 
  gluOrtho2D (0.0, (GLdouble) 1000,  (GLdouble) 1000 ,0.0);
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000,1000);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
	 int submenu1,submenu2,submenuFillEllipse, submenuOutlineEllipse,submenuFillRec,submenuOutlineRec, submenuLineColor,
	submenuCurveColor;
	
         
 submenuFillEllipse = glutCreateMenu(menu);
         glutAddMenuEntry("red", 1);
         glutAddMenuEntry("green", 2);
         glutAddMenuEntry("blue", 3);
		glutAddMenuEntry("yellow", 4);
		glutAddMenuEntry("white",5);
		glutAddMenuEntry("purple", 6);
		glutAddMenuEntry("orange", 7);
		glutAddMenuEntry("pink", 8);
	
	 submenuOutlineEllipse = glutCreateMenu(menu);
         glutAddMenuEntry("red", 9);
         glutAddMenuEntry("green", 10);
         glutAddMenuEntry("blue", 11);
		glutAddMenuEntry("yellow", 12);
		glutAddMenuEntry("white",13);
		glutAddMenuEntry("purple", 14);
		glutAddMenuEntry("orange", 15);
		glutAddMenuEntry("pink", 16);
	
	submenuFillRec= glutCreateMenu(menu);
         glutAddMenuEntry("red", 17);
         glutAddMenuEntry("green", 18);
         glutAddMenuEntry("blue", 19);
		glutAddMenuEntry("yellow", 20);
		glutAddMenuEntry("white",21);
		glutAddMenuEntry("purple", 22);
		glutAddMenuEntry("orange", 23);
		glutAddMenuEntry("pink", 24);
	
	submenuOutlineRec= glutCreateMenu(menu);
         glutAddMenuEntry("red", 25);
         glutAddMenuEntry("green", 26);
         glutAddMenuEntry("blue", 27);
		glutAddMenuEntry("yellow", 28);
		glutAddMenuEntry("white",29);
		glutAddMenuEntry("purple", 30);
		glutAddMenuEntry("orange", 31);
		glutAddMenuEntry("pink", 32);
	
	submenuLineColor= glutCreateMenu(menu);
         glutAddMenuEntry("red", 33);
         glutAddMenuEntry("green", 34);
         glutAddMenuEntry("blue", 35);
		glutAddMenuEntry("yellow", 36);
		glutAddMenuEntry("white",37);
		glutAddMenuEntry("purple", 38);
		glutAddMenuEntry("orange", 39);
		glutAddMenuEntry("pink", 40);
	
	submenuCurveColor = glutCreateMenu(menu);
         glutAddMenuEntry("red", 41);
         glutAddMenuEntry("green", 42);
         glutAddMenuEntry("blue", 43);
		glutAddMenuEntry("yellow", 44);
		glutAddMenuEntry("white",45);
		glutAddMenuEntry("purple", 46);
		glutAddMenuEntry("orange", 47);
		glutAddMenuEntry("pink", 48);
	
	
	
		
	 submenu1 = glutCreateMenu(menu);
         glutAddSubMenu("fill", submenuFillRec );
         glutAddSubMenu("outline", submenuOutlineRec);
	
	 submenu2 = glutCreateMenu(menu);
         glutAddSubMenu("fill", submenuFillEllipse );
         glutAddSubMenu("outline", submenuOutlineEllipse);
	
         glutCreateMenu(menu);
         glutAddSubMenu("rectangle", submenu1);
	 glutAddSubMenu("ellipse", submenu2);
         glutAddSubMenu("line", submenuLineColor);
         glutAddSubMenu("bezier curve",submenuCurveColor);
        
	
	

  glutAttachMenu (GLUT_LEFT_BUTTON);
    init ();
	glutMouseFunc(mouse);
  glutDisplayFunc(display); 
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}