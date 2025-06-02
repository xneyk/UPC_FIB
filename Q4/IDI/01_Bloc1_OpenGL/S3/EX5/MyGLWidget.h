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

      // mousePressEvent - Es cridat cada vegada que es prem un boto del mouse
      virtual void mousePressEvent(QMouseEvent *e);

      // mousePressEvent - Es cridat cada vegada que es deixa anar un boto del mouse
      virtual void mouseReleaseEvent(QMouseEvent *e);

      virtual void mouseMoveEvent(QMouseEvent *e);

      // modelTransform - Crea la TG del model que volem pintar.
      void modelTransform();

   private:
      void creaBuffers();
      void carregaShaders();

      // attribute locations
      GLuint vertexLoc;
      GLuint colorLoc;
      GLuint transLoc;

      // Program
      QOpenGLShaderProgram *program;
      
      float angle = 0.0f; // Valor per a la rotacio de l'objecte.
      float tx = 0.0f, ty = 0.0f; // Valors per a la translacio del objecte.
      float sx = 1.0f, sy = 1.0f; // Valors per a l'escalat NO uniforme

      bool mouseBeingPressed = false;
      int oldMouseX;
      int oldMouseY;

      GLuint VAO1;
      GLint ample, alt;
};
