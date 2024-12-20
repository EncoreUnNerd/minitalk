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

GREEN = \033[32m
BLUE = \033[34m
RESET = \033[0m

all: $(NAME_CLIENT) $(NAME_SERVER)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTILS) $(PRINTF_DIR)/libftprintf.a
	@printf "$(BLUE)[💭] client compiling$(RESET)\n"
	@$(CC) $(CFLAGS) -o $@ $^ 
	@printf "$(GREEN)[✅] client compiled$(RESET)\n"

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS) $(PRINTF_DIR)/libftprintf.a
	@printf "$(BLUE)[💭] server compiling$(RESET)\n"
	@$(CC) $(CFLAGS) -o $@ $^
	@printf "$(GREEN)[✅] server compiled$(RESET)\n"

$(PRINTF_DIR)/libftprintf.a:
	@printf "$(BLUE)[💭] libftprintf compiling$(RESET)\n"
	@make -sC $(PRINTF_DIR)
	@printf "$(GREEN)[✅] libftprintf compiled$(RESET)\n"

clean:
	@printf "$(BLUE)[🧹] cleaning$(RESET)\n"
	@make fclean -sC $(PRINTF_DIR)
	@rm -f $(OBJS_SERVER)
	@rm -f $(OBJS_UTILS)
	@rm -f $(OBJS_CLIENT)
	@printf "$(GREEN)[✨] cleaned$(RESET)\n"

fclean: clean
	@rm -f $(NAME_CLIENT)
	@rm -f $(NAME_SERVER)
	@printf "$(GREEN)[✨] fully cleaned$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re