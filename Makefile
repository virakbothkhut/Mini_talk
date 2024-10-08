
#LIBFT
LIBFT_DIR			= Libft/
LIBFT_NA 			= libft.a
LIBFT 				= $(LIBFT_DIR) $(LIBFT_NA)

#VAR
NAMCLIENT 			= client
NAMESERVER 			= SERVER

CC				 	= gcc 
CFLAGS 				= -Wall -Werror -Wextra
RM 					= rm -f
AR					= ar rcs


# TARGETS
all:$(LIBFT) $(NAMESERVER) $(NAMCLIENT)


#CLEAN AND FCLEAN RULES
clean: 
		$(RM) $(NAMCLIENT) $(NAMESERVER)

fclean: clean

re:fclean all
