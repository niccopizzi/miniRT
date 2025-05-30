CFLAGS = -Wall -Wextra -Werror -Warray-bounds --fast-math  -msse2 -march=native -mavx2 -O2 -I./include
NAME = miniRT

LIBFT_DIR = ./lib/minift
LIB = -L./lib/minilibx-linux -lmlx_Linux -L./lib/minift -lminift -lX11 -lXext -lm  

MY_SOURCES = ./src/main.c 			\
				./src/math/matrix/matrix_SIMD_op1.c 		\
				./src/math/matrix/matrix_SIMD_op2.c			\
				./src/math/matrix/matrix_SIMD_op3.c			\
				./src/math/matrix/matrix_SIMD_op4.c			\
				./src/math/matrix/matrix_SIMD_op5.c			\
				./src/math/quaternions/quaternions_op1.c	\
				./src/math/vector/vector_SIMD_op1.c			\
				./src/math/vector/vector_SIMD_op2.c			\
				./src/math/vector/vector_SIMD_op3.c			\
				./src/math/vector/vector_SIMD_op4.c			\
				./src/mlx_utils/mlx_hooks.c				 	\
				./src/mlx_utils/reload.c				 	\
				./src/mlx_utils/mlx_utils_1.c				\
				./src/mlx_utils/mlx_utils_2.c				\
				./src/world/objects/hit_functions_utils.c	\
				./src/world/objects/hit_functions.c			\
				./src/world/objects/normal_functions.c		\
				./src/world/objects/object_utils.c			\
				./src/world/material.c						\
				./src/world/camera.c						\
				./src/world/world_setup.c					\
				./src/parsing/parsing_file_1.c			 	\
				./src/parsing/parsing_file_2.c			 	\
				./src/parsing/parsing_utils_1.c			 	\
				./src/parsing/parsing_utils_2.c			 	\
				./src/ray/ray.c								\
				./src/rendering/random.c					\
				./src/rendering/scene_render.c				\
				./src/rendering/trace.c						\
				./src/rendering/shading.c					\
				./src/testing/print_utils.c

all: $(NAME)

$(NAME): $(MY_SOURCES)
	@make -C $(LIBFT_DIR)
	@cc $(CFLAGS) $(MY_SOURCES) $(LIB) -o $(NAME) 
	@echo "... Amazing! I managed to compile $(NAME)"

%.o :%.c
	@cc $(CFLAGS) -c $< -o $@ 
	@echo "$< compiled."
	
clean:
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@$(RM) $(MY_OBJECTS)
	@echo "Objects files removed."

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) fclean
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re: fclean all
