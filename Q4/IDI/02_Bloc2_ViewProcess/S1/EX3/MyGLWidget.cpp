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
   BL2GLWidget::initializeGL();
   iniCamera(); // inicialitzem la càmera (VM&PM) i enviem els uniforms corresponents al shader.
}

void MyGLWidget::carregaShaders() {
   BL2GLWidget::carregaShaders();
   // Obtenim identificador per a l'uniform de la view matrix
   viewLoc = glGetUniformLocation(program->programId(), "VM");
   // Obtenim identificador per a l'uniform de la project matrix
   projLoc = glGetUniformLocation(program->programId(), "PM");
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
   OBS = glm::vec3(0.0, 0.0, 1.0);
   VRP = glm::vec3(0.0, 0.0, 0.0);
   UP = glm::vec3(1.0, 0.0, 0.0); // UP cap a x positives per a visualitzar la caseta amb la taulada a la esquerra.
   viewTransform(); // Enviem la VM al VS
   FOV = float(M_PI/2.0f);
   ra = 1.0f;
   zNear = 0.4f;
   zFar = 3.0f;
   projectTransform(); // Enviem la PM al VS
}