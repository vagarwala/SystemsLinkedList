#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

void print_list(struct node *lst){
	while((*lst).next != NULL){
		printf("%i, ", (*lst).data);
		lst = (*lst).next;
	}
	printf("%i \n", (*lst).data);
}


struct node * insert_front(struct node *lst, int front_data){
	struct node *front = (struct node *)malloc(sizeof(struct node));
	(*front).data = front_data;
	(*front).next = lst;
	return front;
}

struct node * free_list(struct node *lst){
	if (lst->next){
		free_list(lst->next);
	}
	free(lst);
	return lst;
}

int main(){
	struct node *linked_list = insert_front(0, 1);
	print_list(linked_list);

	int i;
	for(i = 2; i < 10; i++){
		linked_list = insert_front(linked_list, i);
	}
	print_list(linked_list);

	free_list(linked_list);
	return 0;
}