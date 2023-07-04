PYTHON_PATH = $(PYTHONHOME)

isEmpty($$PYTHON_PATH): PYTHON_PATH = C:/Python39

message(using PYTHON_PATH $$PYTHON_PATH)

INCLUDEPATH += $$PYTHON_PATH/include $$PYTHON_PATH/Lib/site-packages/torch/include
LIBS += -L$$PYTHON_PATH/libs -lpython3
