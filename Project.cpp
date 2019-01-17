#include<iostream>
#include<iomanip>
using namespace std;

// function declaration goes here
void printMatrix(float matrix[3][3]);
void addMatrices(float matrix1[3][3],float matrix2[3][3]);
void multiplyMatrices(float matrix1[3][3], float matrix2[3][3]);
void matrixInverse(float matrix[3][3]);

int main()
{
	float matrix1[3][3],matrix2[3][3],result[3][3];
	char choice;
	char aORb;
	
    //Taking input and printing first matrix
	cout<<"Enter Elements of First Matrix!\n";
	for(int i=0; i<3; i++)
 	{	
	 for(int j=0; j<3; j++)
	{
	  cout<<"Input : ";
	  cin>>matrix1[i][j];
	}
   }
   cout<<"\nFirst Matrix!";
	printMatrix(matrix1);
   cout<<"\n";
   
   //Taking input and printing second matrix
	cout<<"Enter Elements of Second Element!\n";
	for(int i=0; i<3; i++)
	{
	 for(int j=0; j<3; j++){
	 cout<<"input : ";
	 cin>>matrix2[i][j];
     }
    }
    
    cout<<"\nSecond Matrix!";
	printMatrix(matrix2);
	
    cout<<"\t\t  Enter Your Choice !\n\t\t  A-Add\n\t\t  B-Multiply\n\t\t  C-Inverse\n\t\t  D-Exit\n";
    	
	
do
    {
    	cout<<"\n";
    	cout<<"Choice: ";
		cin>>choice;
		cout<<"\n";

    if(choice== 'a' || choice== 'A')
    {
    	//Adding matrices matrix
		cout<<"\nResult of Addition!";
		addMatrices(matrix1,matrix2);
	}
	else if(choice=='b' ||choice== 'B' )
	{
		//Multiplying Matrices
		cout<<"\nResult of Multiplication!";
		multiplyMatrices(matrix1,matrix2);
	}
	
	else if(choice == 'c'|| choice== 'C')
	{
		cout<< "Matrix A or B \nChoice: ";
	   	cin>>aORb;
	   	if (aORb == 'A' ||aORb == 'a' )
	   	{
	   		matrixInverse(matrix1);
		   }
		else if(aORb == 'B' ||aORb == 'b')
		{
			matrixInverse(matrix2);
		   }
		else{
			cout<<"\nInvalid Choice\n";
		}
	}
	else if(choice == 'd' ||choice== 'D')
	{
		cout<<"\n\n\t\t  END!";
       	break;
	}
	else
	{
		cout<<" \n Invalid Choice! ";
	}
	
}
while(choice!='d' ||choice!='D' );	
}


// for printing 3x3 matrix
void printMatrix(float matrix[3][3])
{   
    cout<<"\n";
	for(int i=0;i<3;i++)
	{
     for(int j=0;j<3;j++)
 	{
  	 cout<<setprecision (2)<<matrix[i][j]<<"  "; //setprecision(1) for showing 2 decimal places
	   	}
	cout<<"\n";
}
}

//for adding matrices + also prints result
void addMatrices(float matrix1[3][3],float matrix2[3][3])
{
	float sum[3][3];
	
	for(int i=0; i<3; i++)
	{
	 for(int j=0; j<3; j++)
	 {
	 	sum[i][j]=matrix1[i][j]+matrix2[i][j];
	 }
    }
    //adding ends here
    
	printMatrix(sum);  //after adding call printMatrix function to print 
}

//for multiplication of matrices + also prints result
void multiplyMatrices(float matrix1[3][3], float matrix2[3][3])
{
	float mult[3][3];
	float product = 0 ;
	
	for(int i = 0; i < 3; ++i)
	{
        for(int j = 0; j < 3; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                product += matrix1[i][k] * matrix2[k][j];
            }
			mult[i][j] = product;
			product = 0;  
        }
    }
	//multiplication ends here
	//now call printMatrix function to print matrix result.
	printMatrix(mult); 
}
//for taking inverse and printing result
void matrixInverse(float matrix[3][3])
{
	float x,y,z,det;
	float t[3][3],ad[3][3],inv[3][3]; 
	
	//***** 1- Find Determinant ******//
	
	x = matrix[0][0]*( matrix[2][2]*matrix[1][1] - (matrix[2][1]*matrix[1][2] ));
    y = matrix[0][1]*( matrix[2][2]*matrix[1][0] - (matrix[2][0]*matrix[1][2] ));
	z = matrix[0][2]*( matrix[2][1]*matrix[1][0] - (matrix[2][0]*matrix[1][1] ));
	det = x - y + z;
    
    //******* 2 -Find Transpose Matrix *******//
    for(int i = 0 ;i<3 ; i++)
    {
    	for(int j = 0; j<3 ; j++)
    	{
    		t[i][j]=matrix[j][i];
		}
	}
	
	//******* 3- Calculating Adjoint of transposed matrix ******//
	ad[0][0] =   t[1][1]*t[2][2] - t[2][1]*t[1][2];
    ad[0][1] = -(t[1][0]*t[2][2] - t[2][0]*t[1][2]);
    ad[0][2] =   t[1][0]*t[2][1] - t[2][0]*t[1][1];
    ad[1][0] = -(t[0][1]*t[2][2] - t[2][1]*t[0][2]);
    ad[1][1] =   t[0][0]*t[2][2] - t[2][0]*t[0][2];
    ad[1][2] = -(t[0][0]*t[2][1] - t[2][0]*t[0][1]);
    ad[2][0] =   t[0][1]*t[1][2] - t[1][1]*t[0][2];
    ad[2][1] = -(t[0][0]*t[1][2] - t[1][0]*t[1][2]);
    ad[2][2] =   t[0][0]*t[1][1] - t[1][0]*t[0][1];
    
    
    //****** 4- Calulating inverse ******//
    for(int i =0 ;i<3 ;i++)
    {
    	for(int j=0; j<3; j++)
    	{
    		inv[i][j] = (ad[i][j])/det;
		}
	}
	
	// ****** 5- Printing Result ******//
	
    printMatrix(inv);

}


