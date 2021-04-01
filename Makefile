all:
	make -C ./checker
	mv ./checker/checker .
	make -C ./push_swap
	mv ./push_swap/push_swap

clean:
	make -C ./checker clean
	make -C ./push_swap clean

fclean: clean
	rm -rf checker
	rm -rf push_swap

re: fclean all

phony: all clean fclean re
