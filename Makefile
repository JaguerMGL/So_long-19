# ----------------------------------En LEGENDE------------------------------------
GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
BLUE = \033[0;34m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
CLOSE = \033[0m

# -----------------------------------Makefile------------------------------------
NAME 	= so_long
NAME_BONUS 	= so_long_bonus
DEBUG 	= debug.out
# -----------------------------------Sources-------------------------------------
HEADER	 = includes/so_long.h

SRCS	 = main.c \
			error.c \
			init_game.c \
			init_map.c \
			verif_map.c \
			get_img.c \
			display.c \
			hook.c \
			destroy_img.c \

SRCS_bonus	 = bonus_main.c \
			bonus_error.c \
			bonus_init_game.c \
			bonus_init_map.c \
			bonus_verif_map.c \
			bonus_get_img.c \
			bonus_display.c \
			bonus_hook.c \
			bonus_anim.c \
			bonus_destroy_img.c \

			
SRC_bonus	 = ${addprefix sources/, ${SRCS_bonus}}
OBJS_bonus	 = ${SRC_bonus:.c=.o}

			
SRC		  = ${addprefix sources/, ${SRCS}}

OBJS	   = ${SRC:.c=.o}
# -----------------------------------Compilation---------------------------------
CC			= cc
FLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f
FSANITIZE	= -fsanitize=address -g
# ---------------------------------Librairies-----------------------------------
FT_FOLDER 	= libft
FT			= ${FT_FOLDER}/libft.a
MAKE_FT		= make -s -C ${FT_FOLDER}
INCLUDES	= -I ${FT_FOLDER}/includes \
			  -I ./includes
LIBRARIES	= -L./${FT_FOLDER} -lft

# ----------------------------------En LEGENDE------------------------------------
GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
RED = \033[0;31m
RED_BOLD = \033[1;31m
MAGENTA = \033[0;35m
BLUE = \033[0;34m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
CLIGNOT = \033[5m
WHITE_BG = \033[47m
CLOSE = \033[0m


TOTAL_FILES 	:= $(words $(SRCS) $(SRCS_bonus))
CURRENT_FILE 	:= 0

define progress_bar_so_long
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(MAGENTA)Compiling So_long... ⌛⌛⌛[%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "="; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo "$(YELLOW)\n\nSo_long c'est bon ma gueule 👌\n$(CLOSE)"; fi
endef


# -----------------------------------Rules---------------------------------------

all: $(NAME)

$(NAME): ${FT} $(OBJS) ${HEADER}
	@$(CC)  $(OBJS) ${LIBRARIES} $(LDFLAGS) -o $(NAME)

${FT}:
	@${MAKE_FT}

bonus : ${FT} $(OBJS_bonus) ${HEADER}
	@$(CC)  $(OBJS_bonus) ${LIBRARIES} $(LDFLAGS) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(FLAGS) -c $(INCLUDES) -c $< -o $@
	$(call progress_bar_so_long)

debug: ${FT} $(OBJS) ${HEADER}
	$(CC) $(FLAGS) $(LDFLAGS) $(FSANITIZE) $(OBJS) ${LIBRARIES} -o $(DEBUG)

clean:
	@$(RM) $(OBJS) $(OBJS_bonus)
	@${MAKE_FT} clean
	@sleep 0.3
	@echo "\n$(BLUE)🧹🧹🧹 It's clean. 🧹🧹🧹$(CLOSE)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) $(DEBUG) 
	@${MAKE_FT} fclean 
	@sleep 0.6
	@printf "\n$(GREEN_BOLD)🌪🌪🌪 It's super clean. 🌪🌪🌪\n\n$(CLOSE)"

re: fclean all
# -----------------------------------.phony-------------------------------------
.PHONY: all clean fclean re debug bonus