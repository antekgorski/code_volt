#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;


void    insert_after(t_node *current_node, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if(new_node == NULL)
        exit(1);
    new_node->data = value;
    new_node->next = current_node->next;
    current_node->next = new_node;

}

void	add_element_to_begin(t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->data = value;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *head;
		*head = new_node;
	}
}

void insert_sort(t_node **head, int value)
{
    if(*head == NULL || (*head)->data >= value)
    {
        add_element_to_begin(head, value);
        return ;
    }
    t_node *current = *head;
    while(current->next != NULL)
    {
        if(current->next->data >= value)
        {
            insert_after(current, value);
            return ;
        }
        current = current->next;
    }
    insert_after(current, value);
}

void	add_element_to_end(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->data = value;
	current = *head;
	if (current == NULL)
	{
		*head = new_node;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	dealocate(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}

void remove_node(t_node **head, int value)
{
    if(*head == NULL)
        return ;
    if ((*head)->data == value)
    {
        t_node *to_remove;
        to_remove = *head;
        *head = (*head)->next;
        free(to_remove);
        return ;    
    }
    t_node *current = *head;
    while(current->next != NULL)
    {
      if(current->next->data == value)
      {
        t_node *to_remove = current->next;
        current->next = current->next->next;
        free(to_remove);
      }
      current = current->next;
    }
}
void    reverse_list(t_node **head)
{
    t_node *prev = NULL;
    t_node *current = *head;
    while(current != NULL)
    {
        t_node *next;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
     *head = prev;
}

int is_loop(t_node *head)
{
    t_node *slow = head;
    t_node *fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return (1);
    }
    return (0);
}

int	main(void)
{
	t_node *node1 = NULL;
	// t_node *node1 = malloc(sizeof(t_node));
	// if(node1 == NULL)
	//     exit(1);
	// node1->data = 1;
	// node1->next = NULL;

	// node1.next = malloc(sizeof(t_node));
	// node1.next->data = 2;
	// node1.next->next = NULL;

	// add_element_to_end(&node1, 2);
	// add_element_to_end(&node1, 3);
	// add_element_to_end(&node1, 4);
	// add_element_to_end(&node1, 5);

    // add_element_to_begin(&node1, 0);
    // add_element_to_begin(&node1, -1);
    // add_element_to_begin(&node1, -2);

    // insert_after(node1->next, 100);

    //insert_sort(&node1, 8);
    insert_sort(&node1, 1);
    insert_sort(&node1, 1);
    insert_sort(&node1, 3);
    insert_sort(&node1, 6);
    insert_sort(&node1, 7);

    node1->next->next->next->next->next = node1->next;

    if(is_loop(node1) == 1)
    {  
        printf("loop linklist detected\n");
        return (1);
    }

    //insert_sort(&node1, 6);
    // insert_sort(&node1, 7);
    //insert_sort(&node1, 9);

    //remove_node(&node1, 1);
    reverse_list(&node1);

	t_node *current;
	current = node1;

	while (current != NULL)
	{
		printf("node data: %d\n", current->data);
		current = current->next;
	}

	dealocate(&node1);
	return (0);
}