// MyGLWidget.h
#include "BL2GLWidget.h"
#include "model.h"

struct modelStruct {
   Model model;
   GLuint VAO;
   glm::vec3 p_min;
   glm::vec3 p_max;
   glm::vec3 center;
   glm::vec3 base_center;
   float height;
   float angle = 0.0f;
};

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

      // resizeGL - afegim control del aspect ratio
      virtual void resizeGL(int w, int h);

      // Carrega els models y crea tots els buffers.
      virtual void creaBuffers(); // Canvia per complert

      // Carrega tots el shaders + afegim el link amb la project matrix
      virtual void carregaShaders();

      virtual void keyPressEvent(QKeyEvent *e);

   private:
      int printOglError(const char file[], int line, const char func[]);

      // Calcula i envia al VS la TG del objecte Patricio
      void patricioModelTransform();

      void flatModelTransform();

      // Calcula i envia la view matrix al VS
      void viewTransform();

      // Calcula i envia la project matrix al VS
      void projectTransform();

      // Inicialitza la Càmera
      void iniCamera();


      // Calcula la capça contenedora del model i actualitza m.p_min, m.p_max center, base_center i height
      void calcBoxContainter(modelStruct &m);

      // Defineix l'esfera contenedora de la escena (centre i radi)
      void setSphere(glm::vec3 p_min, glm::vec3 p_max);

      // Atributs de la escena
      glm::vec3 center;
      float radius;
      
      // Atributs de la Càmera
      glm::vec3 OBS, VRP, UP;
      bool isPrespective = false;
      // Atributs de la Òptica de la Càmera
      float FOV, FOV_ini, ra, zNear, zFar;
      float l, r, b, t;
      modelStruct patricio;

      GLuint VAO_flat;

      GLuint viewLoc;
      GLuint projLoc;
};
