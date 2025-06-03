// MyGLWidget.h
#include "BL2GLWidget.h"
#include "model.h"

class MyGLWidget : public BL2GLWidget {
   Q_OBJECT

   public:
      MyGLWidget(QWidget *parent = 0) : BL2GLWidget(parent) {}
      ~MyGLWidget();

   protected:
      // Inicialitza OpenGL + crida a projectMatrix();
      virtual void initializeGL(); // Canvia per complert

      // paintGL - pinta els objectes en escena.
      virtual void paintGL(); // Canvia per complert

      // Carrega els models y crea tots els buffers.
      virtual void creaBuffers(); // Canvia per complert

      // Carrega tots el shaders + afegim el link amb la project matrix
      virtual void carregaShaders();

      virtual void keyPressEvent(QKeyEvent *e);

   private:
      int printOglError(const char file[], int line, const char func[]);

      // Calcula i envia al VS la TG del objecte Homer
      void homerModelTransform();

      void flatModelTransform();

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

      float homer_angle = 0.0f;

      Model homer;
      GLuint VAO_homer;

      GLuint VAO_flat;

      GLuint viewLoc;
      GLuint projLoc;
};
