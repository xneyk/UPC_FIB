#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QKeyEvent>

#include "glm/gtc/matrix_transform.hpp"
#include "glm/glm.hpp"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
   Q_OBJECT

   public:
      MyGLWidget(QWidget *parent = 0);
      ~MyGLWidget();

   protected:
      // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
      virtual void initializeGL();

      // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
      // Tot el que es dibuixa es dibuixa aqui.
      virtual void paintGL();

      // resize - Es cridat quan canvia la mida del widget
      virtual void resizeGL(int width, int height);

      // keyPressEvent - es crida cada vegada que hi ha un event de tecla premuda al teclat
      virtual void keyPressEvent(QKeyEvent *e);

      // modelTransformObj1 - calcula la TG per a l'obj1 i envia l'uniform al vertexShader
      void modelTransformObj1();

      // modelTransformObj2 - calcula la TG per a l'obj2 i envia l'uniform al vertexShader
      void modelTransformObj2();

   private:
      void creaBufferObj1();
      void creaBufferObj2();
      void carregaShaders();

      // attribute locations
      GLuint vertexLoc;
      GLuint transLoc;

      // Program
      QOpenGLShaderProgram *program;

      float angle_obj1 = 0.0f, angle_obj2 = 0.0f;

      GLuint VAO1;
      GLuint VAO2;
      GLint ample, alt;
};
