##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

SRC	=	./src/Gates/Gates.cpp							\
		./src/Factory.cpp								\
		./src/AComponent.cpp							\
		./src/Circuit.cpp								\
		./src/main.cpp									\
		./src/Pin.cpp									\
		./src/Chipsets/Chipset4081.cpp					\
		./src/Chipsets/Chipset4071.cpp					\
		./src/Chipsets/Chipset4069.cpp					\
		./src/Chipsets/Chipset4030.cpp					\
		./src/Chipsets/Chipset4011.cpp					\
		./src/Chipsets/Chipset4001.cpp					\
		./src/ElementaryComponents/AndComponent.cpp		\
		./src/ElementaryComponents/OrComponent.cpp		\
		./src/ElementaryComponents/XorComponent.cpp		\
		./src/ElementaryComponents/NotComponent.cpp		\
		./src/SpecialComponents/ClockComponent.cpp		\
		./src/SpecialComponents/FalseComponent.cpp		\
		./src/SpecialComponents/InputComponent.cpp		\
		./src/SpecialComponents/OutputComponent.cpp		\
		./src/SpecialComponents/TrueComponent.cpp		\
		./src/Parser/Parser.cpp							\
		./src/Parser/Link.cpp							\
		./src/Parser/Chipset.cpp						\
		./src/Errors/MainError.cpp						\
		./src/Errors/ParserError.cpp					\
		./src/Errors/InputError.cpp						\
		./src/Errors/FactoryError.cpp					\

OBJ	=	$(SRC:.cpp=.o)

FLAG	=	-Wall -g

NAME	=	nanotekspice

INCLUDE = ./include/

all:	$(NAME)

%.o:	%.cpp
		g++ -I$(INCLUDE) $(FLAG) -c $< -o $@

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
