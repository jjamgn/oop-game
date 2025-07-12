cmake_minimum_required(VERSION 3.10)
project(OOPGame)

set(CMAKE_CXX_STANDARD 17)

# Chỉ định thư mục chứa mã nguồn
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Tạo file thực thi
add_executable(game ${SRC_FILES})

# Chỉ định thư viện SFML
set(SFML_DIR "C:/SFML/SFML-3.0.0/lib/cmake/SFML")  # đổi path nếu khác

# Tìm gói SFML (cần: graphics, window, system)
find_package(SFML 3 REQUIRED COMPONENTS graphics window system)

# Thêm include path nếu cần
target_include_directories(game PRIVATE "src")

# Liên kết thư viện SFML
target_link_libraries(game PRIVATE sfml-graphics sfml-window sfml-system)
