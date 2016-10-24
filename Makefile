##
## Makefile for pamela in /home/legald_t/pamela
## 
## Made by Dieu
## Login   <legald_t@epitech.eu>
## 
## Started on  Wed Oct 12 19:41:49 2016 Dieu
## Last update Fri Oct 21 12:25:22 2016 Dieu
##

NAME = pam_pamela.so

FILE = base_pam.cpp

OBJ = $(FILE:.cpp=.o)

LDFLAGS += -fPIC -fno-stack-protector

CXXFLAGS += -fPIC -fno-stack-protector

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	g++ -shared -Wl,-soname,$(NAME) -o $(NAME) $(OBJ)
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME) && $(RM) a.out
re : fclean all

test :
	g++ test_main.cpp -lpam -lpam_misc

.PHONY : all clean fclean re
