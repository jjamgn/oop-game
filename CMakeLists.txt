cmake_minimum_required(VERSION 3.10)
project(OOPGame)

set(CMAKE_CXX_STANDARD 17)

# Chỉ định thư mục chứa mã nguồn
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Tạo file thực thi
add_executable(game ${SRC_FILES})

# Chỉ định thư viện SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")  # đổi path nếu khác

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_include_directories(game PRIVATE "src")
target_link_libraries(game sfml-graphics sfml-window sfml-system)
