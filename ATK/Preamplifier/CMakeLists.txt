
if(EIGEN_FOUND)

FILE(GLOB_RECURSE
  ATK_PREAMPLIFIER_SRC
  *.cpp
)

FILE(GLOB_RECURSE
  ATK_PREAMPLIFIER_HEADERS
  *.h*
)

SET(ATK_PREAMPLIFIER_DEFINITIONS)
SET(ATK_PREAMPLIFIER_INCLUDE)
SET(ATK_PREAMPLIFIER_LIBRARIES ATKCore)

IF(EIGEN_FOUND)
  LIST(APPEND ATK_PREAMPLIFIER_INCLUDE ${EIGEN_INCLUDE_DIRS})
ENDIF(EIGEN_FOUND)

SET(ATK_PREAMPLIFIER_NAME ATKPreamplifier)
SET(ATK_PREAMPLIFIER_FOLDER Preamplifier)

ATK_add_library(ATK_PREAMPLIFIER)

endif(EIGEN_FOUND)
