
// #include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget(QWidget* parent) : QOpenGLWidget(parent), program(NULL) {
   setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget() {
   if (program != NULL)
      delete program;
}

void MyGLWidget::initializeGL() {
   // Cal inicialitzar l'ús de les funcions d'OpenGL
   initializeOpenGLFunctions();

   glClearColor(0.5, 0.7, 1.0, 1.0);  // defineix color de fons (d'esborrat)
   carregaShaders();
   creaBufferObj1();
   creaBufferObj2();
}

void MyGLWidget::paintGL() {
   // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
   // useu els paràmetres que considereu (els que hi ha són els de per defecte)
   // glViewport (0, 0, ample, alt);

   glClear(GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer

   // Calculem i enviem la TG del obj1
   modelTransformObj1();
   
   // Activem l'Array a pintar
   glBindVertexArray(VAO1);

   // Pintem l'escena
   glDrawArrays(GL_TRIANGLES, 0, 3);

   // Calculem i enviem la TG del obj2
   modelTransformObj2();

   // Activem l'Array a pintar (Segon Objecte)
   glBindVertexArray(VAO2);

   // Pintem l'escena
   glDrawArrays(GL_TRIANGLES, 0, 6);

   // Desactivem el VAO
   glBindVertexArray(0);
}

void MyGLWidget::resizeGL(int w, int h) {
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
   GLint vp[4];
   glGetIntegerv(GL_VIEWPORT, vp);
   ample = vp[2];
   alt = vp[3];
#else
   ample = w;
   alt = h;
#endif
}

void MyGLWidget::keyPressEvent(QKeyEvent *e) {
   makeCurrent();
   if (e->key() == Qt::Key_P) {
      angle_obj1 += 45.0f;
      angle_obj2 -= 45.0f;
      update();
   }
}

void MyGLWidget::modelTransformObj1() {
   glm::mat4 TG = glm::mat4(1.0);
   TG = glm::rotate(TG, glm::radians(angle_obj1), glm::vec3(0.0, 0.0, 1.0));
   glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
   transLoc = glGetUniformLocation(program->programId(), "TG");
}

void MyGLWidget::modelTransformObj2() {
   glm::mat4 TG = glm::mat4(1.0);
   TG = glm::rotate(TG, glm::radians(angle_obj2), glm::vec3(0.0, 0.0, 1.0));
   glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
   transLoc = glGetUniformLocation(program->programId(), "TG");
}


void MyGLWidget::creaBufferObj1() {
   glm::vec3 Vertices[3];  // Tres vèrtexs amb X, Y i Z
   Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
   Vertices[1] = glm::vec3(-0.5, 0.0, 0.0);
   Vertices[2] = glm::vec3(0.0, -1.0, 0.0);

   // Creació del Vertex Array Object (VAO) que usarem per pintar
   glGenVertexArrays(1, &VAO1);
   glBindVertexArray(VAO1);

   // Creació del buffer amb les dades dels vèrtexs
   GLuint VBO1;
   glGenBuffers(1, &VBO1);
   glBindBuffer(GL_ARRAY_BUFFER, VBO1);
   glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
   // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)
   glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(vertexLoc);

   // Desactivem el VAO
   glBindVertexArray(0);
}

void MyGLWidget::creaBufferObj2() {
   glm::vec3 Vertices[6];  // Tres vèrtexs amb X, Y i Z
   Vertices[0] = glm::vec3(0.0, 1.0, 0.0);
   Vertices[1] = glm::vec3(1.0, 1.0, 0.0);
   Vertices[2] = glm::vec3(1.0, 0.0, 0.0);
   Vertices[3] = glm::vec3(0.0, 0.0, 0.0);
   Vertices[4] = glm::vec3(0.0, 1.0, 0.0);
   Vertices[5] = glm::vec3(1.0, 0.0, 0.0);

   // Creació del Vertex Array Object (VAO) que usarem per pintar
   glGenVertexArrays(1, &VAO2);
   glBindVertexArray(VAO2);

   // Creació del buffer amb les dades dels vèrtexs
   GLuint VBO1;
   glGenBuffers(1, &VBO1);
   glBindBuffer(GL_ARRAY_BUFFER, VBO1);
   glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
   // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)
   glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
   glEnableVertexAttribArray(vertexLoc);

   // Desactivem el VAO
   glBindVertexArray(0);
}

void MyGLWidget::carregaShaders() {
   // Creem els shaders per al fragment shader i el vertex shader
   QOpenGLShader fs(QOpenGLShader::Fragment, this);
   QOpenGLShader vs(QOpenGLShader::Vertex, this);
   // Carreguem el codi dels fitxers i els compilem
   fs.compileSourceFile("shaders/basicShader.frag");
   vs.compileSourceFile("shaders/basicShader.vert");
   // Creem el program
   program = new QOpenGLShaderProgram(this);
   // Li afegim els shaders corresponents
   program->addShader(&fs);
   program->addShader(&vs);
   // Linkem el program
   program->link();
   // Indiquem que aquest és el program que volem usar
   program->bind();

   // Obtenim identificador per a l'atribut “vertex” del vertex shader
   vertexLoc = glGetAttribLocation(program->programId(), "vertex");
}
