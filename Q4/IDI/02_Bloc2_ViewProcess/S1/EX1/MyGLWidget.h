// MyGLWidget.h
#include "BL2GLWidget.h"

class MyGLWidget : public BL2GLWidget {
   Q_OBJECT

   public:
      MyGLWidget(QWidget *parent = 0) : BL2GLWidget(parent) {}
      ~MyGLWidget();

   protected:
      // Inicialitza OpenGL + crida a projectMatrix();
      virtual void initializeGL();

      // Carrega tots el shaders + afegim el link amb la project matrix
      virtual void carregaShaders();

   private:
      int printOglError(const char file[], int line, const char func[]);

      // calcula i envia la project matrix al VS
      void projectMatrix();

      GLuint projLoc;
};
