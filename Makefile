NAME			=	cub3D

LIBFT_DIR		=	./libft
MINILIB_DIR		=	./minilibx_opengl_20191021

LIBFT_LIB		=	./libft/libft.a
MINILIB_LIB		=	./minilibx_opengl_20191021/libmlx.a

SRCS			=	cub3d.c\
					bresenhem.c\
					map.c\
					move.c\
					draw_wall.c\
					draw_floor.c\
					draw_ceiling.c\
					draw_sprite.c\
					raycasting.c\
					utils_part_a.c\
					utils_part_b.c\
					utils_part_c.c\
					utils_part_d.c\
					utils_part_e.c\
					rotate.c\
					screenshot.c\
					file_parser.c\
					parse.c\
					map_validator.c\
					sort_sprite.c\
					init.c\
					get_next_line/get_next_line.c\
					get_next_line/get_next_line_utils.c\

# OBJS			=	$(SRCS:.c=.o)
# 위의 명령어로 돌리면 cub_17 에 get_next_line.o 가 생성되고 OBJS 명령어는 그 파일을 gnl 폴더에서 찾는다.
OBJS			=	cub3d.o\
					bresenhem.o\
					map.o\
					move.o\
					draw_wall.o\
					draw_floor.o\
					draw_ceiling.o\
					draw_sprite.o\
					raycasting.o\
					utils_part_a.o\
					utils_part_b.o\
					utils_part_c.o\
					utils_part_d.o\
					utils_part_e.o\
					rotate.o\
					screenshot.o\
					file_parser.o\
					parse.o\
					map_validator.o\
					sort_sprite.o\
					init.o\
					get_next_line/get_next_line.o\
					get_next_line/get_next_line_utils.o\


CC				=	gcc

CFLAG			=	-Wall -Werror -Wextra

RM				=	rm -f

all 			:	$(NAME)

bonus			:	$(NAME)

clean			:
					$(RM) $(OBJS) *.gch *.swp a.out
					cd $(LIBFT_DIR); make clean
					cd $(MINILIB_DIR); make clean

fclean			:	clean
					$(RM) $(NAME)
					$(RM) $(LIBFT_LIB)
					$(RM) screenshot.bmp

re				:	fclean all

# L은 라이브러리 경로를 파일을 찾는 옵션, I는 같이 링크할 라이브러리를 찾는 옵션
$(NAME)			:	$(OBJS) $(LIBFT_LIB) $(MINILIB_LIB)
					$(CC) $(CFLAG) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft -L $(MINILIB_DIR) -lmlx -I $(MINILIB_DIR) -framework OpenGL -framework Appkit

$(LIBFT_LIB)	:
					cd $(LIBFT_DIR); $(MAKE) bonus

$(MINILIB_LIB)	:
					cd $(MINILIB_DIR); $(MAKE)

.PHONY			:	all clean fclean re bonus
