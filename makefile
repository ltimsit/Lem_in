NAME = lem_in

SRCS = $(addprefix $(SRCDIR)/, $(addsuffix .c, \
	   main get_data make_list parsing_tools get_tube free dis_free\
	   find_path refresh_paths path_tools path_tools2 path_tools3 debug\
	   print_tools make_tuboard_and_rooms print_result init_display\
	   display rooms_display display_setup tube_display hook rotation_ant))

OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

SRCDIR = src
LIBFT = libft/libft.a
LIBFTPRINTF = libftprintf.a
LIBMLX = libmlx.a
INC = -I include -I libft

FLAGS = -Wall -Wextra -Werror
CC = gcc $(INC) $(FLAGS) -c
FRAMEWORKS = -framework OpenGL -framework AppKit

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
UNDER = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
NOCOLOR = \033[0m

NB_FILE = $(words $(SRCS))
CPT = 1

all : $(NAME)


$(NAME) : $(LIBFT) $(OBJ)
	@echo "\n$(MAGENTA)COMPILATION  $(YELLOW)LEMIN$(MAGENTA) : $(GREEN)OK !$(NOCOLOR)"
	@sleep 0.2
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"
	@sleep 0.2
	@echo "\033[11A"
	@echo "   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n /  $(REVERSE)$(YELLOW) 🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜        L E M I N       🐜  🐜  🐜  🐜  🐜  🐜  🐜  🐜  $(NOCOLOR)  \\ \n|                                                                             |\n|                                                                             |"
	@echo "|   \\(•)/   $(GREEN)   \\(•)/   $(CYAN)   \\(•)/   $(RED)   \\(•)/   $(MAGENTA)   \\(•)/   $(YELLOW)   \\(•)/   $(BLUE)   \\(•)/   $(NOCOLOR)|"
	@echo "|   -(•)-   $(GREEN)   -(•)-   $(CYAN)   -(•)-   $(RED)   -(•)-   $(MAGENTA)   -(•)-   $(YELLOW)   -(•)-   $(BLUE)   -(•)-   $(NOCOLOR)|"
	@echo "|   /(•)\\   $(GREEN)   /(•)\\   $(CYAN)   /(•)\\   $(RED)   /(•)\\   $(MAGENTA)   /(•)\\   $(YELLOW)   /(•)\\   $(BLUE)   /(•)\\   $(NOCOLOR)|"
	@echo "|                                                                             |\n|    abinois                                                      ltimsit-    |\n \\ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ /"

	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBFTPRINTF) $(LIBMLX) $(FRAMEWORKS)
	@echo "\n                               $(BLINK)👌  $(NOCOLOR)$(GREEN)A L L   G O O D $(NOCOLOR)$(BLINK)👌 $(NOCOLOR)"

-include $(DEP)

$(SRCDIR)/%.o : $(SRCDIR)/%.c makefile
	@echo "\033[K$(BLUE)Compilation of file$(NOCOLOR) [$(CPT) / $(NB_FILE)] : $(GREEN)$<\033[A$(NOCOLOR)"
	$(eval CPT=$(shell echo $$(($(CPT) + 1))))
	@gcc $(FLAGS) $(INC) -MMD -MP -c $< -o $@ 

$(LIBFT) : force
	@make -C libft
force :

clean :
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "$(MAGENTA)SUPPR  $(YELLOW)OBJ $(MAGENTA): $(GREEN) OK !$(NOCOLOR)"
	@rm -f $(DEP)
	@echo "$(MAGENTA)SUPPR  $(YELLOW)DEP $(MAGENTA): $(GREEN) OK !$(NOCOLOR)"
	@echo "$(GREEN)LEMIN CLEAN : 👌 $(NOCOLOR)"

fclean : clean
	@make fclean -C libft
	@echo "$(MAGENTA)SUPPR  $(YELLOW)EXE$(MAGENTA): $(RED)$(NAME)$(NOCOLOR)"
	@rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all force
