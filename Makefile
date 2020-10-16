# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laurencianmkhwane <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 10:47:16 by laurenci          #+#    #+#              #
#    Updated: 2020/10/16 02:39:05 by laurenci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHKRNAME = checker
PSNAME = push_swap

#Checker files
CHKRPATH = ./ps_checker/obj/
CHKRFILES = ./ps_checker/checker.c ./ps_checker/utils.c ./ps_checker/check.c \
			./ps_checker/do_ops.c ./ps_checker/swap_push_ops.c \
			./ps_checker/rotate_ops.c ./ps_checker/free_stacks.c
CHKROBJS = checker.o utils.o check.o do_ops.o swap_push_ops.o \
		   rotate_ops.o free_stacks.o
CHKROBJ = $(addprefix $(CHKRPATH), $(CHKROBJS))
CHKRHEADER = -I ./ps_checker/inc/

#Push_Swap files
PSPATH = ./pushswap/obj/
PSFILES = ./pushswap/main.c ./pushswap/utils.c ./pushswap/check.c \
		  ./pushswap/swap_push_ops.c \
		  ./pushswap/rotate_ops.c ./pushswap/init_push_swap.c \
		  ./pushswap/push_swap_3.c ./pushswap/push_swap.c \
		  ./pushswap/free_stacks.c
PSOBJS = main.o utils.o check.o swap_push_ops.o swap_push_ops.o \
		 rotate_ops.o init_push_swap.o push_swap_3.o \
		 push_swap.o free_stacks.o
PSOBJ = $(addprefix $(PSPATH), $(PSOBJS))
PSHEADER = -I ./pushswap/inc/

FLAGS = -Wall -Werror -Wextra

LIB = ./libft/libft.a
LIBINC = -I ./libft/
LIBLINK = -L ./libft -lft

#Compiling Checker
$(CHKRNAME): $(CHKROBJ)
	@echo "Checker compiling..."
	@gcc $(FLAGS) -o $@ $^ $(CHKRHEADER) $(LIB)
	@echo "Checker compiled"

#Storing object files in seperate directory
$(CHKRPATH)%.o: ./ps_checker/%.c
	@echo "Creating Checker object files"
	@gcc $(CHKRHEADER) -o $@ -c $<

#Compiling Push_Swap
$(PSNAME): $(PSOBJ)
	@echo "Push_Swap compiling..."
	@gcc $(FLAGS) -o $@ $^ $(PSHEADER) $(LIB)
	@echo "Push_Swap compiled"

#Storing object files in seperate directory
$(PSPATH)%.o: ./pushswap/%.c
	@echo "Creating Push_Swap object files"
	@gcc $(PSHEADER) -o $@ -c $<

all: $(CHKRPATH) $(PSPATH) lib $(CHKRNAME) $(PSNAME)

lib:
	@make -C libft/ re
	@echo "Libft cleaned and compiled"

clean:
	@make -C libft/ fclean
	@rm -f header.h.gch
	@rm -f $(CHKROBJ)
	@echo "Checker cleaned"
	@rm -f $(PSOBJ)
	@echo "Push_Swap cleaned"

fclean:
	@rm -f header.h.gch
	@rm -f $(CHKRNAME) $(PSNAME)
	@echo "Checker and Push_Swap deleted"

re: clean fclean all
