# CMakeLists.txt : CMake project for MatrixSolver, include source and define
# project specific logic here.

# Add source to this project's executable.
add_executable(MatrixSolver  "MatrixSolver.h" "MatrixSolverTests.cpp" "Main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MatrixSolver PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
