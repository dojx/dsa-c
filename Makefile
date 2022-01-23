CC=gcc

llmake: main.c linked_list.c queue_list.c
	$(CC) -o main main.c linked_list.c queue_list.c -I.

# qlmake: queue_list.o
# 	$(CC) -o queuelist queue_list.o