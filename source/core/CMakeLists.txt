FILE (GLOB ${MY_PROJECT_NAME}_SOURCES *.cpp) 
ADD_LIBRARY (${MY_PROJECT_NAME}-lib ${${MY_PROJECT_NAME}_SOURCES}) 
