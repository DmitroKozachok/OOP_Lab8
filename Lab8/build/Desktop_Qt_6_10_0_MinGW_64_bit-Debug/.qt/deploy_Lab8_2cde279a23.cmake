include("C:/Users/Dmitro/Documents/Lab8/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Lab8-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/Users/Dmitro/Documents/Lab8/build/Desktop_Qt_6_10_0_MinGW_64_bit-Debug/Lab8.exe"
    GENERATE_QT_CONF
)
