#include "ui_Form.h"

class MyForm:public QWidget {
   Q_OBJECT
   public:
      MyForm(QWidget* parent = 0);
   
   private:
      Ui::Form ui; // MyForm si el el .ui es diu també MyForm.ui ; EL NOM HA DE COINCIDIR AMB EL DE QTDESIGNER
};