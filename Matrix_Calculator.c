#include <stdio.h>

int n, m, n2, m2;

void scanMatrix(int arr[n][m]);
void scalarMultiplication(int factor, int arr[n][m]);
void addMatrices(int matrix1[n][m], int matrix2[n][m], int result[n][m]);
void subtractMatrices(int matrix1[n][m], int matrix2[n][m], int result[n][m]);
void multiplyMatrices(int matrix1[n][m], int matrix2[n2][m2], int result[n][m2]);

int main()
{
    int operation;
    printf("Vidushi\nC Final Project\nMatrix Calculator\n");
    printf("Choose Your Operation:\n1. Addition\t2. Subtraction\n3. Scalar Multiplication\t4. Multiplication\n");
    scanf("%d", &operation);
    if(operation = 3){
    printf("Enter the dimensions of the matrix (rows x columns): ");
  scanf("%d%d", &n, &m);
  }else {
    printf("Enter the dimensions of the first matrix (rows x columns): ");
    scanf("%d%d", &n, &m);
    printf("Enter the dimensions of the second matrix (rows x columns): ");
    scanf("%d%d", &n2, &m2);
          }
    int matrix1[n][m], matrix2[n2][m2];
    
    int result[20][20]; 
    switch (operation)
    {
    case 1:
        if (n != n2 || m != m2)
        {
            printf("Matrix Dimensions must be the same for addition\n...Exiting");
            break;
        }
        printf("Enter the elements of the first matrix:\n");
        scanMatrix(matrix1); 
        printf("Enter the elements of the second matrix:\n");
        scanMatrix(matrix2); 

        addMatrices(matrix1, matrix2, result);

        
        printf("Matrix after addition:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;

    case 2:
        if (n != n2 || m != m2)
        {
            printf("Matrix Dimensions must be the same for subtraction\n...Exiting");
            break;
        }

        printf("Enter the elements of the first matrix:\n");
        scanMatrix(matrix1); 

        printf("Enter the elements of the second matrix:\n");
        scanMatrix(matrix2); 

        subtractMatrices(matrix1, matrix2, result);

        printf("Matrix after subtraction:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;

    case 3:
        printf("Enter the elements of the matrix:\n");
        scanMatrix(matrix1); 

        int multiple;
        printf("Enter the scalar value to multiply: ");
        scanf("%d", &multiple);

        scalarMultiplication(multiple, matrix1);

        printf("Matrix after scalar multiplication:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", matrix1[i][j]);
            }
            printf("\n");
        }
        break;

    case 4:
        if (m != n2)
        {
            printf("Error! Column of first matrix must be equal to row of second matrix.\n...Exiting");
            break;
        }

        printf("Enter the elements of the first matrix:\n");
        scanMatrix(matrix1); 

        printf("Enter the elements of the second matrix:\n");
        scanMatrix(matrix2); 

        multiplyMatrices(matrix1, matrix2, result);

        printf("Matrix after multiplication:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m2; j++) 
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;

    default:
        printf("Invalid operation.\n");
        break;
    }

    return 0;
}

void scanMatrix(int arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("At (%d, %d): ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

void scalarMultiplication(int factor, int arr[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] *= factor;
        }
    }
}

void addMatrices(int matrix1[n][m], int matrix2[n][m], int result[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[n][m], int matrix2[n][m], int result[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[n][m], int matrix2[n2][m2], int result[n][m2])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m2; j++) 
        {
            for (int k = 0; k < m; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
