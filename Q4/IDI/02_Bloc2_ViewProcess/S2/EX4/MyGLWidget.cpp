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
   patricioModelTransform();
   // Activem el VAO per a pintar a homer
   glBindVertexArray(patricio.VAO);
   // pintem
   glDrawArrays(GL_TRIANGLES, 0, sizeof(GLfloat)*patricio.model.faces().size()*3*3);

   // Carreguem la transformació del terra
   flatModelTransform();
   // Activem el VAO del terra
   glBindVertexArray(VAO_flat);
   // pintem
   glDrawArrays(GL_TRIANGLES, 0, 6);

   glBindVertexArray(0);
}

void MyGLWidget::resizeGL(int w, int h) {
   BL2GLWidget::resizeGL(w, h);
   ra = float(w)/float(h); // ra_window = ra_viewport
   
   if (ra < 1) { // ajustem el nou FOV en cas que hagi augmentat en vertical
      FOV = 2*glm::atan(glm::tan(FOV_ini/2.0f)/ra);
   }
   projectTransform(); // actualitzem la Matriu PM;

}

void MyGLWidget::creaBuffers() {
   // Carrega del model
   patricio.model.load("/home/neyk/Documents/UPC_FIB/Q4/IDI/models/Patricio.obj");
   calcBoxContainter(patricio);

   glGenVertexArrays(1, &patricio.VAO);
   glBindVertexArray(patricio.VAO);

   GLuint VBOs_patricio[2]; // on VBOs_patricio[0] es l'identificador del VBO de vertex i VBOs_patricio[1] el de color.
   // Carreguem vertex del model
   glGenBuffers(2, VBOs_patricio);
   glBindBuffer(GL_ARRAY_BUFFER, VBOs_patricio[0]);
   // sizeof(GLfloat)*homer.faces().size()*3*3
   //                 nombre_de_cares * 3 vertex/cara * 3 components/vertex
   glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patricio.model.faces().size()*3*3, patricio.model.VBO_vertices(), GL_STATIC_DRAW);

   glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(vertexLoc);

   // Carreguem colors de cada vertex
   glBindBuffer(GL_ARRAY_BUFFER, VBOs_patricio[1]);
   // sizeof(GLfloat)*patricio.model.faces().size()*3*3
   //                 nombre_de_cares * 3 vertex/cara * 3 components/vertex
   glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*patricio.model.faces().size()*3*3, patricio.model.VBO_matdiff(), GL_STATIC_DRAW);
   
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
      patricio.angle += 45.0f;
      update();
   }
}

void MyGLWidget::patricioModelTransform() {
   glm::mat4 TG(1.0f);
   TG = glm::translate(TG, glm::vec3(0.0, 4.0/2.0, 0.0));
   // Podriem haver fet la primera traslació com -base_center i ens haguesim estalviat aquesta ultima traslació.
   // Tot i que en aquest cas hagues funcionat (rotacio eix y amb model.y = 0) pel cas general la primera traslacio 
   // ha de ser portar al centre.
   TG = glm::rotate(TG, glm::radians(patricio.angle), glm::vec3(0.0, 1.0, 0.0));
   TG = glm::scale(TG, glm::vec3(4.0/patricio.height)); // escalat uniforme
   TG = glm::translate(TG, -patricio.center); // portem al centre de coordenades
   glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::flatModelTransform() {
   // Podriem fer el model directament de tamany 5x5 centrat en y = 0 pero per practicar farem les transformacions.
   glm::mat4 TG(1.0f);
   // /*2*/ TG = glm::translate(TG, glm::vec3(0.0, 0.0, 0.0)); // Baixem 1 a Y (Estaba a 0 ara esta a -1).
   /*1*/ TG = glm::scale(TG, glm::vec3(5.0, 1.0, 5.0)); // Escalat de 4 en x i z
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
   setSphere(glm::vec3(-2.5, 0.0, -2.5), glm::vec3(2.5, 4.0, 2.5));
   float D = 2*radius;
   OBS = center + D*glm::vec3(0.0, 0.0, 1.0); // OBS = centre + D*v on v es la direccio en la que volem moure-la
   VRP = center;
   UP = glm::vec3(0.0, 1.0, 0.0); // UP cap a x positives per a visualitzar la caseta amb la taulada a la esquerra.
   viewTransform(); // Enviem la VM al VS
   FOV_ini = FOV = 2 * glm::asin(radius/D);
   ra = 1.0f;
   zNear = D - radius;
   zFar = D + radius;
   projectTransform(); // Enviem la PM al VS
}

void MyGLWidget::calcBoxContainter(modelStruct &m) {
   int n = m.model.vertices().size();
   if (n >= 3) {
      m.p_min.x = m.p_max.x = m.model.vertices()[0];
      m.p_min.y = m.p_max.y = m.model.vertices()[1];
      m.p_min.z = m.p_max.z = m.model.vertices()[2];
      for (int i = 3; i < n; i += 3) {
         if (m.model.vertices()[i] < m.p_min.x) m.p_min.x = m.model.vertices()[i];
         else if (m.model.vertices()[i] > m.p_max.x) m.p_max.x = m.model.vertices()[i];

         if (m.model.vertices()[i+1] < m.p_min.y) m.p_min.y = m.model.vertices()[i+1];
         else if (m.model.vertices()[i+1] > m.p_max.y) m.p_max.y = m.model.vertices()[i+1];

         if (m.model.vertices()[i+2] < m.p_min.z) m.p_min.z = m.model.vertices()[i+2];
         else if (m.model.vertices()[i+2] > m.p_max.z) m.p_max.z = m.model.vertices()[i+2];
      }
      // un cop trobats punt minim i maxim
      m.center = (m.p_max + m.p_min)/2.0f;
      m.base_center = glm::vec3(m.center.x, m.p_min.y, m.center.z);
      m.height = m.p_max.y - m.p_min.y;
   }
}

void MyGLWidget::setSphere(glm::vec3 p_min, glm::vec3 p_max) {
   radius = glm::distance(p_max, p_min)/2.0f;
   center = (p_max + p_min)/2.0f;
}