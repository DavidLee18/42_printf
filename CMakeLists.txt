cmake_minimum_required(VERSION 3.13)
project(ft_printf)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -foptimize-sibling-calls -O2 -g")
add_subdirectory(libft)
set(SOURCE_FILES
		src/free_fmt_arg.c
		src/ft_printf.c
		src/gc_utox.c
		src/iprintf3.c
		src/iprints_.c
		src/is_conv_spec.c
		src/pprintf.c
		src/uprint_pad.c
		src/vprint_fmt.c
		src/vprint_hex.c
		src/xprintf2.c
)
add_library(ft_printf ${SOURCE_FILES})
target_link_libraries(ft_printf libft)