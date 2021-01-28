#include <stdio.h>
#include <string.h>

int main(){
	
	char g[100] = {};
	int a = 1;

	scanf("%s",&g);

	if(strlen(g) == 10){
		puts("PROXIMO!\n");

			printf(">>> ");
			scanf("%s",&g);
			puts("");

		while(strlen(g) == a){
			printf(">>> ");
			scanf("%s",&g);
		if(a > 100) {
			puts("PARABENS! VOCE CONSEGUIU <FLAG>");
		return 0;
}
		a++;
puts("");
	}
}
	else 
	{
		printf("TENTE NOVAMENTE!");
		return 1;
	}
return 0;
}
