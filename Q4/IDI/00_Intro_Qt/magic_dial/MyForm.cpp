#include "MyForm.h"

MyForm::MyForm(QWidget* parent):QWidget(parent) {
   ui.setupUi(this);
   ui.label->hide(); // Oculta el label al construir el form para que este oculto desde un inicio
                     // Este comportamiento se deberia poder replicar en otras versiones de QtDesigner desmarcando la opcion "Visible".
}