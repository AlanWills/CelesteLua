set(LIBS 
    #Lua
    #DolceLua
    Celeste)

set(TEST_LIBS
    CelesteMocks
    CelesteTestResources
    CelesteTestUtils)

build_library(NAME CelesteLua FOLDER Celeste TYPE STATIC LIBS "${LIBS}" TEST_LIBS "${TEST_LIBS}")