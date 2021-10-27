SRCS		= client.c server.c

OBJ_DIR		= obj/

OBJS		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

OBJS_D		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME		= minitalk

LIBFT		= ./libft/libft.a

SERVER		= server

CLIENT		= client

HEADER		= minitalk.h

CC			= gcc

FLAGS		= -Wall -Werror -Wextra -O2 -MMD

${OBJ_DIR}%.o : %.c
			${CC} ${FLAGS} -c $< -o $@

all:		${OBJ_DIR} ${NAME} ${SERVER} ${CLIENT}

${OBJ_DIR}:
			mkdir -p ${OBJ_DIR}

${NAME}:	${OBJS} ${HEADER} ${LIBFT}
			${MAKE} -C ./libft

${SERVER}:	obj/server.o ${HEADER}
			${CC} ${FLAGS} -o server -lft -L./libft

${CLIENT}:	obj/client.o ${HEADER}
			${CC} ${FLAGS} -o client -lft -L./libft

${BONUS}:
			@make OBJS='${OBJS} ${OBJS_B}' all

clean:
			rm -rf ${OBJ_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

