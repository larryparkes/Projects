project("Matrix")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

add_executable(MatrixTests
 main.cpp                         test_getandset.cpp
 Matrix.h                         test_getnsetters.cpp
 Matrix_Test.cpp                  test_hilbert.cpp
 test_addition.cpp                test_identitymatrix.cpp
 test_assign_add.cpp              test_inequality.cpp
 test_assignment.cpp              test_matrixinverse.cpp
 test_assign_multiply.cpp         test_matrixmultiply.cpp
 test_assign_subtract.cpp         test_multiplication.cpp
 test_constructor_destructor.cpp  test_scalarmultiply.cpp
 test_determinant.cpp             test_subtraction.cpp
 test_equality.cpp                test_transpose.cpp
 utils.h)


