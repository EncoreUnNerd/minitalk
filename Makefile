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
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS) $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) -o $@ $^ 

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS) $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) -o $@ $^ 

$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

clean:
	make fclean -C $(PRINTF_DIR)
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_UTILS)
	rm -f $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re