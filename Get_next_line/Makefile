# Nome della libreria statica
NAME = get_next_line.a

# Sorgenti e file oggetto
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# Compilatore e flag di compilazione
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Regola principale: Compila la libreria statica
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regola per compilare i file .o
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file oggetto
clean:
	rm -f $(OBJS)

# Pulizia completa: file oggetto + libreria
fclean: clean
	rm -f $(NAME)

# Ricompilazione totale
re: fclean $(NAME)

# Evitare errori con regole sconosciute
.PHONY: all clean fclean re

