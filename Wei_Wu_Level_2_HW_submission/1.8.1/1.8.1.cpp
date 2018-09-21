#include <stdio.h>
#include <iostream>
using namespace std;

struct Article
{
	int article_number;
	int quatity;
	char description[21];	//maximum description characters number are 20+'\0'
};

void Print(struct Article *pa)
{
	printf("Article number = %d\n",(*pa).article_number);	//print the article number using structure pointer
	printf("Quantity = %d\n",(*pa).quatity);				//print the article quantity using structure pointer
	printf("Description = %s\n",(*pa).description);			//print the article description using structure pointer
	return;
}

int main()
{
	struct Article article1 = {12 , 23, "Refugee exodus."};			//initiate the strucutre article1
	struct Article* p_article;										//pointer to structure
	p_article = &article1;											//pointer points to structure's initial address
	Print(p_article);												//print the content of the structure
	return 0;
}
