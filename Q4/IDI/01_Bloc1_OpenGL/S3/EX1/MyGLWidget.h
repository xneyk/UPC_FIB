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

      // keyPressEvent - Es cridat cada vegada que es prem una tecla
      virtual void keyPressEvent(QKeyEvent *e);

      // modelTransform - Crea la TG del model que volem pintar.
      void modelTransform();

   private:
      void creaBuffers();
      void carregaShaders();

      // attribute locations
      GLuint vertexLoc;
      GLuint transLoc;

      // Program
      QOpenGLShaderProgram *program;

      float tx = 0.0f, ty = 0.0f; // Valors per a la translacio del objecte.

      GLuint VAO1;
      GLint ample, alt;
};
