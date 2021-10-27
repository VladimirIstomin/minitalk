SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_B		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

OBJ_DIR		= obj/

OBJS		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

OBJS_D		= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

OBJS_B		= $(addprefix ${OBJ_DIR}, ${SRCS_B:.c=.o})

OBJS_B_D	= $(addprefix ${OBJ_DIR}, ${SRCS_B:.c=.d})

NAME		= libft.a

HEADER		= libft.h

BONUS		= bonus

CC			= gcc

FLAGS		= -Wall -Werror -Wextra -O2 -MMD

${OBJ_DIR}%.o : %.c
			${CC} ${FLAGS} -c $< -o $@

all:		${OBJ_DIR} ${NAME}

${OBJ_DIR}:
			mkdir -p ${OBJ_DIR}

${NAME}:	${OBJS} ${HEADER} ${NAME}
			ar rcs ${NAME} $?

${BONUS}:
			@make OBJS='${OBJS} ${OBJS_B}' all

clean:
			rm -rf ${OBJ_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include	${OBJS_D} ${OBJS_B_D}
