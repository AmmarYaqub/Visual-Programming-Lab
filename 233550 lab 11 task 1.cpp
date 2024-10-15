#include<iostream>
using namespace std;

class Matrix{
	private:
		int matrix[4][4];
		public:
			
			void setmatrix(int r, int c, int value){
				matrix[r][c]=value;
			}
			int getmatrix(int r, int c){
				return matrix[r][c];
			}
			
			Matrix operator+(const Matrix& other){
				Matrix result;
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
						result.matrix[i][j]=matrix[i][j]+other.matrix[i][j];
					}
				}
			}
			Matrix operator-(const Matrix& other){
				Matrix result;
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
						result.matrix[i][j]=matrix[i][j]-other.matrix[i][j];
					}
				}
			}
			Matrix operator*(const Matrix& other){
				Matrix result;
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
						result.matrix[i][j]=0;
						for(int k=0; k<4; ++k)
						result.matrix[i][j]=matrix[i][k]*other.matrix[k][i];
					}
				}
			}
			bool operator==(const Matrix& other){
				Matrix result;
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
						if(matrix[i][j] != other.matrix[i][j]){
						return false;
						}
					}
				}
				return true;
			}
			void speak(){
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
			cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
			};
int main(){
				Matrix m1,m2;
				cout<<"Enter the First Matrix: "<<endl;
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
						int value;
						cin>>value;
						m1.setmatrix(i,j,value);
					}
				}
				cout<<"Enter the Second Matrix: "<<endl;
				for(int i=0; i<4; ++i){
					for(int j=0; j<4; ++j){
						int value;
						cin>>value;
						m2.setmatrix(i,j,value);
					}
				}				
														
				Matrix addition= m1+m2;
				cout<<"The Sum are: "<<endl;
				addition.speak(); 
				
				Matrix substraction= m1-m2;
				cout<<"The substraction are: "<<endl;
				substraction.speak();
				
				Matrix multiply= m1*m2;
				cout<<"The multiplication are: "<<endl;
				multiply.speak();
							
				bool equal = (m1==m2);
				cout<<"The equal are: "<<(equal ? "EQUAL" : "NOT EQUAL")<<endl;
								
}
