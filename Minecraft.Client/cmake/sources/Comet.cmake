set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Comet/")

set(COMET_BASE
  "${BASE_DIR}/Comet.h"
  "${BASE_DIR}/Comet.cpp"
  "${BASE_DIR}/Module.h"
  "${BASE_DIR}/Module.cpp"
  "${BASE_DIR}/Speed.h"
  "${BASE_DIR}/Speed.cpp"
)
source_group("COMET_FILES" FILES ${COMET_BASE})

set(COMET_CLIENT
${COMET_BASE}
)