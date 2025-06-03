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

      // Calcula i envia la view matrix al VS
      void viewTransform();

      // Calcula i envia la project matrix al VS
      void projectTransform();

      // Inicialitza la Càmera
      void iniCamera();

      // Atributs de la Càmera
      glm::vec3 OBS, VRP, UP;
      // Atributs de la Òptica de la Càmera
      float FOV, ra, zNear, zFar;

      GLuint viewLoc;
      GLuint projLoc;
};
