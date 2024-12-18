NAME_CLIENT = client
NAME_SERVER = server

PRINTF_DIR = ft_printf

SRC_CLIENT = client.c
SRC_SERVER = server.c
UTILS = utils.c

OBJS_CLIENT = src_client/$(SRC_CLIENT:.c=.o)
OBJS_SERVER = src_server/$(SRC_SERVER:.c=.o)
OBJS_UTILS = utils/$(UTILS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS) $(PRINTF_DIR)/libftprintf.a
	@$(CC) $(CFLAGS) -o $@ $^ 
	@printf "client compiled ✅\n"

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS) $(PRINTF_DIR)/libftprintf.a
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "server compiled ✅\n"

$(PRINTF_DIR)/libftprintf.a:
	@make -sC $(PRINTF_DIR)
	@printf "libftprintf compiled ✅\n"

clean:
	@make fclean -sC $(PRINTF_DIR)
	@rm -f $(OBJS_SERVER)
	@rm -f $(OBJS_UTILS)
	@rm -f $(OBJS_CLIENT)
	@printf "cleaned 🧹\n"

fclean: clean
	@rm -f $(NAME_CLIENT)
	@rm -f $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re