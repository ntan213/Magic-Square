// C++ Program to print Magic square 
// of Doubly even order 
#include<stdio.h> 
#include<string.h>
// Function for calculating Magic square 

void generateSquare(int n)
{
    int magicSquare[n][n];
 
    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));
 
    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;
 
    // One by one put all values in magic square
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) // 3rd condition
        {
            j = n - 2;
            i = 0;
        }
        else {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;
 
            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j]) // 2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++; // set number
 
        j++;
        i--; // 1st condition
    }
 
    // Print magic square
    printf("The Magic Square for n=%d:\nSum of "
           "each row or column %d:\n\n",
           n, n * (n * n + 1) / 2);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

void doublyEven( int n ) 
{ 
	int arr[n][n], i, j; 

	// filling matrix with its count value 
	// starting from 1; 
	for ( i = 0; i < n; i++) 
		for ( j = 0; j < n; j++) 
			arr[i][j] = (n*i) + j + 1; 
	
	// change value of Array elements 
	// at fix location as per rule 
	// (n*n+1)-arr[i][j] 
	// Top Left corner of Matrix 
	// (order (n/4)*(n/4)) 
	for ( i = 0; i < n/4; i++) 
		for ( j = 0; j < n/4; j++) 
			arr[i][j] = (n*n + 1) - arr[i][j]; 
	
	// Top Right corner of Matrix 
	// (order (n/4)*(n/4)) 
	for ( i = 0; i < n/4; i++) 
		for ( j = 3 * (n/4); j < n; j++) 
			arr[i][j] = (n*n + 1) - arr[i][j]; 
	
	// Bottom Left corner of Matrix 
	// (order (n/4)*(n/4)) 
	for ( i = 3 * n/4; i < n; i++) 
		for ( j = 0; j < n/4; j++) 
			arr[i][j] = (n*n+1) - arr[i][j]; 
	
	// Bottom Right corner of Matrix 
	// (order (n/4)*(n/4)) 
	for ( i = 3 * n/4; i < n; i++) 
		for ( j = 3 * n/4; j < n; j++) 
			arr[i][j] = (n*n + 1) - arr[i][j]; 
	
	// Centre of Matrix (order (n/2)*(n/2)) 
	for ( i = n/4; i < 3 * n/4; i++) 
		for ( j = n/4; j < 3 * n/4; j++) 
			arr[i][j] = (n*n + 1) - arr[i][j]; 

	  printf("The Magic Square for n=%d:\nSum of "
           "each row or column %d:\n\n",
           n, n * (n * n + 1) / 2);
	// Printing the magic-square 
	for (i = 0; i < n; i++) 
	{ 
		for ( j = 0; j < n; j++) 
			//cout << arr[i][j] << " "; 
		{	printf ("%d ",arr[i][j]);
			}	
//		cout << "\n"; 
		printf("\n");
	} 
} 

// driver program 
int main() 
{ 
	int n;
	printf("Enter n: ");
	scanf("%d",&n); 
	if (n%2==0){
			doublyEven(n); //Function call 
	}
	else
{
	generateSquare(n);
}
	return 0; 
} 

