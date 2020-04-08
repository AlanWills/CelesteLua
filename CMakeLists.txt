set(LIBS 
    Lua
    DolceLua
    Celeste)

build_library(NAME CelesteLua FOLDER Celeste/Lua TYPE STATIC LIBS "${LIBS}")