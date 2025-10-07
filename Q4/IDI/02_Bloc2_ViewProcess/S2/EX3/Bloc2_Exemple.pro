TEMPLATE    = app
QT         += opengl 

INCLUDEPATH +=  /usr/include/glm /home/neyk/Documents/UPC_FIB/Q4/IDI/Model

FORMS += MyForm.ui

HEADERS += MyForm.h BL2GLWidget.h MyGLWidget.h

SOURCES += main.cpp MyForm.cpp \
        BL2GLWidget.cpp MyGLWidget.cpp /home/neyk/Documents/UPC_FIB/Q4/IDI/Model/model.cpp
