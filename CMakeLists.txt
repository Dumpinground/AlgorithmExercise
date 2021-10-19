cmake_minimum_required(VERSION 3.19)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        AlgorithmExercise
        main.cpp
        myLib/list/ArrayList.h
        myLib/list/LinkedList.h
        myLib/stack/stack.h
        test/test.cpp
        test/3.1.4-Stack.cpp
        myLib/list/LinkedList.cpp
        myLib/stack/stack.cpp
        myLib/queue/Queue.h
        myLib/queue/Queue.cpp
        test/3.2.5-Queue.cpp
        test/3.3.6.cpp
        myLib/TypeElement.h
        myLib/TypeElement.cpp
        test/4.cpp
        myLib/tree/binaryTree.h
        test/5.2.3-BinaryTree.cpp
        myLib/tree/binaryTree.cpp
        myLib/tree/ThreadTree.h
        myLib/tree/ThreadTree.cpp
        myLib/tree/TreeElement.h
        myLib/tree/TreeElement.cpp
        myLib/tree/Tree.h
        myLib/tree/Tree.cpp
        test/5.4.5-TreeForest.cpp
        myLib/tree/binarySearchTree.h
        myLib/tree/binarySearchTree.cpp
        test/5.5.4-TreeApplication.cpp
        myLib/graph/Graph.h
        myLib/graph/Graph.cpp
        test/6-Graph.cpp
)

include(GoogleTest)
target_link_libraries(AlgorithmExercise gtest_main)

gtest_discover_tests(AlgorithmExercise)