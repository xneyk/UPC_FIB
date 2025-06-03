// MyGLWidget.cpp
#include "MyGLWidget.h"

#include <stdio.h>

#include <iostream>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__, __FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) {
   GLenum glErr;
   int retCode = 0;

   glErr = glGetError();
   const char* error = 0;
   switch (glErr) {
      case 0x0500:
         error = "GL_INVALID_ENUM";
         break;
      case 0x501:
         error = "GL_INVALID_VALUE";
         break;
      case 0x502:
         error = "GL_INVALID_OPERATION";
         break;
      case 0x503:
         error = "GL_STACK_OVERFLOW";
         break;
      case 0x504:
         error = "GL_STACK_UNDERFLOW";
         break;
      case 0x505:
         error = "GL_OUT_OF_MEMORY";
         break;
      default:
         error = "unknown error!";
   }
   if (glErr != GL_NO_ERROR) {
      printf("glError in file %s @ line %d: %s function: %s\n",
             file, line, error, func);
      retCode = 1;
   }
   return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::initializeGL() {
   // Cal inicialitzar l'ús de les funcions d'OpenGL
   initializeOpenGLFunctions();

   glEnable(GL_DEPTH_TEST); // Activem el Z-Buffer   
   glClearColor(0.5, 0.7, 1.0, 1.0);  // defineix color de fons (d'esborrat)
   carregaShaders();
   creaBuffers();

   iniCamera(); // inicialitzem la càmera (VM&PM) i enviem els uniforms corresponents al shader.
}

void MyGLWidget::paintGL() {
   // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
   // useu els paràmetres que considereu (els que hi ha són els de per defecte)
   //  glViewport (0, 0, ample, alt);

   // Esborrem el frame-buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Carreguem la transformació de model
   homerModelTransform();
   // Activem el VAO per a pintar a homer
   glBindVertexArray(VAO_homer);
   // pintem
   glDrawArrays(GL_TRIANGLES, 0, sizeof(GLfloat)*homer.faces().size()*3*3);

   // Carreguem la transformació del terra
   flatModelTransform();
   // Activem el VAO del terra
   glBindVertexArray(VAO_flat);
   // pintem
   glDrawArrays(GL_TRIANGLES, 0, 6);

   glBindVertexArray(0);
}

void MyGLWidget::creaBuffers() {
   // Carrega del model
   homer.load("/home/neyk/Documents/UPC_FIB/Q4/IDI/models/HomerProves.obj");
   
   glGenVertexArrays(1, &VAO_homer);
   glBindVertexArray(VAO_homer);

   GLuint VBOs_homer[2]; // on VBOs_homer[0] es l'identificador del VBO de vertex i VBOs_homer[1] el de color.
   // Carreguem vertex del model
   glGenBuffers(2, VBOs_homer);
   glBindBuffer(GL_ARRAY_BUFFER, VBOs_homer[0]);
   // sizeof(GLfloat)*homer.faces().size()*3*3
   //                 nombre_de_cares * 3 vertex/cara * 3 components/vertex
   glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*homer.faces().size()*3*3, homer.VBO_vertices(), GL_STATIC_DRAW);

   glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(vertexLoc);

   // Carreguem colors de cada vertex
   glBindBuffer(GL_ARRAY_BUFFER, VBOs_homer[1]);
   // sizeof(GLfloat)*homer.faces().size()*3*3
   //                 nombre_de_cares * 3 vertex/cara * 3 components/vertex
   glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*homer.faces().size()*3*3, homer.VBO_matdiff(), GL_STATIC_DRAW);

   glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(colorLoc);

   // FLAT //

   glm::vec3 flat_vertex[6];
   flat_vertex[0] = glm::vec3(-1.0, 0.0, -1.0);
   flat_vertex[1] = glm::vec3(-1.0, 0.0, 1.0);
   flat_vertex[2] = glm::vec3(1.0, 0.0, -1.0);
   flat_vertex[3] = glm::vec3(-1.0, 0.0, 1.0);
   flat_vertex[4] = glm::vec3(1.0, 0.0, 1.0);
   flat_vertex[5] = glm::vec3(1.0, 0.0, -1.0);

   glGenVertexArrays(1, &VAO_flat);
   glBindVertexArray(VAO_flat);

   GLuint VBO_flat[2];
   glGenBuffers(2, VBO_flat);
   glBindBuffer(GL_ARRAY_BUFFER, VBO_flat[0]);
   glBufferData(GL_ARRAY_BUFFER, sizeof(flat_vertex), flat_vertex, GL_STATIC_DRAW);

   glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(vertexLoc);

   glm::vec3 flat_color[6];
   flat_color[0] = glm::vec3(0.5, 0.0, 1.0);
   flat_color[1] = glm::vec3(0.5, 0.0, 1.0);
   flat_color[2] = glm::vec3(0.5, 0.0, 1.0);
   flat_color[3] = glm::vec3(0.5, 0.0, 1.0);
   flat_color[4] = glm::vec3(0.5, 0.0, 1.0);
   flat_color[5] = glm::vec3(0.5, 0.0, 1.0);

   glBindBuffer(GL_ARRAY_BUFFER, VBO_flat[1]);
   glBufferData(GL_ARRAY_BUFFER, sizeof(flat_color), flat_color, GL_STATIC_DRAW);

   glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(colorLoc);

   glBindVertexArray(0); // Desvinculem el VAO
}

void MyGLWidget::carregaShaders() {
   BL2GLWidget::carregaShaders();
   // Obtenim identificador per a l'uniform de la view matrix
   viewLoc = glGetUniformLocation(program->programId(), "VM");
   // Obtenim identificador per a l'uniform de la project matrix
   projLoc = glGetUniformLocation(program->programId(), "PM");
}

void MyGLWidget::keyPressEvent(QKeyEvent *e) {
   makeCurrent();
   if (e->key() == Qt::Key_R) {
      homer_angle += 45.0f;
      update();
   }
}

void MyGLWidget::homerModelTransform() {
   glm::mat4 TG(1.0f);
   TG = glm::rotate(TG, glm::radians(homer_angle), glm::vec3(0.0, 1.0, 0.0));
   glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::flatModelTransform() {
   // Podriem fer el model directament de tamany 4x4 centrat en y = -1 pero per practicar farem les transformacions.
   glm::mat4 TG(1.0f);
   /*2*/ TG = glm::translate(TG, glm::vec3(0.0, -1.0, 0.0)); // Baixem 1 a Y (Estaba a 0 ara esta a -1).
   /*1*/ TG = glm::scale(TG, glm::vec3(4.0, 1.0, 4.0)); // Escalat de 4 en x i z
   glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform() {
   glm::mat4 VM = glm::lookAt(OBS, VRP, UP);
   glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &VM[0][0]);
}

void MyGLWidget::projectTransform() {
   glm::mat4 PM = glm::perspective(FOV, ra, zNear, zFar);
   glUniformMatrix4fv(projLoc, 1, GL_FALSE, &PM[0][0]); // enviem la project matrix
}

void MyGLWidget::iniCamera() {
   // punts min i max calculats a mà
   setSphere(glm::vec3(-4.0, -1.0, -4.0), glm::vec3(4.0, 1.0, 4.0));
   float D = 2*radius;
   OBS = center + D*glm::vec3(0.0, 0.0, 1.0); // OBS = centre + D*v on v es la direccio en la que volem moure-la
   VRP = center;
   UP = glm::vec3(0.0, 1.0, 0.0); // UP cap a x positives per a visualitzar la caseta amb la taulada a la esquerra.
   viewTransform(); // Enviem la VM al VS
   FOV = 2 * glm::asin(radius/D);
   ra = 1.0f;
   zNear = D - radius;
   zFar = D + radius;
   projectTransform(); // Enviem la PM al VS
}

void MyGLWidget::setSphere(glm::vec3 p_min, glm::vec3 p_max) {
   radius = glm::distance(p_max, p_min)/2.0f;
   center = (p_max + p_min)/2.0f;
}