#include <stdio.h>
#include <string.h>

void swap(float v[], int i, int j){
  float temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

float less_than(float i, float j){
	if(i < j){
		return 1;
	}
	return 0;
}

float greater_than(float i, float j){
	if (i > j){
		return 1;
	}
	return 0;
}

void bubble_sort_generic(float v[], float (*comp)(float, float)) {
	int i;
	int j;
	int cmp;
	int len;

	for(i=0; i<3000; i++){
		if(v[i]==0){
			len = i;
			break;
		}
		
	}

	for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
  		   	 cmp =(*comp)(v[i], v[j]); 
	    	 if(cmp>0){
				swap(v, i, j);
	    	 }
	    }
	}

	return;
}

void main(){
	float numbers[3000];
	int i, n;

	for(i=0; i<3000; i++){
		scanf("%f", &numbers[i]);
		if(numbers[i]==0){
			break;
		}
	}


	printf("The original values are:\n");
	for(i=0; i<3000; i++){
		n = i + 1;
		if(numbers[n]==0){
			printf("%G\n", numbers[i]);
			break;
		}
		printf("%G ", numbers[i]);
	}

	bubble_sort_generic(numbers, &greater_than);

		printf("The sorted values are:\n");
	for(i=0; i<3000; i++){
		n = i + 1;
		if(numbers[n]==0){
			printf("%G\n", numbers[i]);
			break;
		}
		printf("%G ", numbers[i]);
	}

	bubble_sort_generic(numbers, &less_than);

	printf("The sorted values are:\n");
	for(i=0; i<3000; i++){
		n = i + 1;
		if(numbers[n]==0){
			printf("%G\n", numbers[i]);
			break;
		}
		printf("%G ", numbers[i]);
	}
}
