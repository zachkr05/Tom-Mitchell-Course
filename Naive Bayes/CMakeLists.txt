
CMAKE_MINIMUM_REQUIRED(VERSION 4.0.3)
project(NaiveGuassianBayesClassifier LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(
  ${PROJECT_NAME} 
  src/main.cpp
  src/csv.cpp
  src/gaussian.cpp)


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
