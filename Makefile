all:
	make -C ./checker_srcs
	mv ./checker_srcs/checker .
	make -C ./push_swap_srcs
	mv ./push_swap_srcs/push_swap .

clean:
	make -C ./checker_srcs clean
	make -C ./push_swap_srcs clean

fclean: clean
	rm -rf checker
	rm -rf push_swap

re: fclean all

phony: all clean fclean re
