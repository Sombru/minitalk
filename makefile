# Programs name
SERV = server
CLI = client
# Compiler
CC    = cc
FLAGS = -Wall -Wextra -Werror -I libft/ 

LIBFT = libft/libft.a

# Sources
SRC_SERVER = server.c
SRC_CLIENT = client.c

# Objects
OBJ_PATH = obj/
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(addprefix $(OBJ_PATH), $(OBJ_SERVER))
OBJS_CLIENT = $(addprefix $(OBJ_PATH), $(OBJ_CLIENT))

# Targets
all: $(OBJ_PATH) $(LIBFT) $(SERV) $(CLI)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(SERV): $(OBJS_SERVER)
	$(CC) $(FLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERV)

$(CLI): $(OBJS_CLIENT)
	$(CC) $(FLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLI)
 
# Build libft
$(LIBFT):
	make -C libft --no-print-directory

clean:
	rm -rf $(OBJ_PATH)
	make clean -C libft --no-print-directory

fclean: clean
	rm -f $(SERV) $(CLI) 
	make fclean -C libft --no-print-directory

re: fclean all

.PHONY: all clean fclean re