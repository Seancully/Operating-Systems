// Program creates two matrices using arrays and multiplies them (maths matrices multiply way) and shows the output

#include <stdio.h>
#define ROW_COL 3
int main()
{
    int i, j, k;
    int array1[ROW_COL][ROW_COL];
    int array2[ROW_COL][ROW_COL];
    int array3[ROW_COL][ROW_COL];
    int sum = 0;


    // User input into array1
    printf("\nFor array1: \n");
    for ( i = 0; i < ROW_COL; i++)
    {
        for ( j = 0; j < ROW_COL; j++)
        {
            printf("Enter value for row %d column %d: ", i, j);
            scanf("%d", &array1[i][j]);

        } // end inner for j
        
    } // end outer for i
    
    // User input into array2
    printf("\nFor array2: \n");
    for ( i = 0; i < ROW_COL; i++)
    {
        for ( j = 0; j < ROW_COL; j++)
        {
            printf("Enter value for row %d column %d: ", i, j);
            scanf("%d", &array2[i][j]);

        } // end inner for j
        
    } // end outer for i

    // Multiply the two matrices
    for ( i = 0; i < ROW_COL; i++)
    {
        for ( j = 0; j < ROW_COL; j++)
        {
            for ( k = 0; k < ROW_COL; k++)
            {
                sum = sum + array1[i][k] * array2[k][j];

            } // end inner inner for k
            
            array3[i][j] = sum;
            sum = 0;

        } // end inner for j
        
    } // end outer for i
    
    printf("\n");

    // printing array1
    printf("ARRAY1:\n");
    printf("%d  %d  %d\n", array1[0][0], array1[0][1], array1[0][2]);
    printf("%d  %d  %d\n", array1[1][0], array1[1][1], array1[1][2]);
    printf("%d  %d  %d\n", array1[2][0], array1[2][1], array1[2][2]);

    printf("\n");

    // printing array2
    printf("ARRAY2:\n");
    printf("%d  %d  %d\n", array2[0][0], array2[0][1], array2[0][2]);
    printf("%d  %d  %d\n", array2[1][0], array2[1][1], array2[1][2]);
    printf("%d  %d  %d\n", array2[2][0], array2[2][1], array2[2][2]);

    printf("\n");

    // printing array3 (matrix1 * matrix2)
    printf("ARRAY3 (ARRAY1 * ARRAY2):\n");
    printf("%d  %d  %d\n", array3[0][0], array3[0][1], array3[0][2]);
    printf("%d  %d  %d\n", array3[1][0], array3[1][1], array3[1][2]);
    printf("%d  %d  %d\n", array3[2][0], array3[2][1], array3[2][2]);

    return 0;
} // end main()