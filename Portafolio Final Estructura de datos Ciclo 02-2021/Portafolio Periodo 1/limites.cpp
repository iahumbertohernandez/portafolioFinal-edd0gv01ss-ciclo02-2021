#include <iostream>
#include <limits>

using namespace std;

int main(){
	
	int imin = numeric_limits<int>::min();
	int imax = numeric_limits<int>::max();
	
     cout << " imin = " << imin << endl;
     cout << " imax = " << imax << "\n";
     cout << " tamanio de int  : " << sizeof(int)<< endl;
     
    float fmin = std::numeric_limits<float>::min();
	float fmax = std::numeric_limits<float>::max();
	
     cout << " fmin = " << fmin << endl;
     cout << " fmax = " << fmax << "\n";
     cout << " tamanio de float  : " << sizeof(float)<< endl;
     
    char cmin = numeric_limits<char>::min();
	char cmax = numeric_limits<char>::max();
	
     cout << " cmin = " << cmin << endl;
     cout << " cmax = " << cmax << "\n";
     cout << " tamanio de char  : " << sizeof(char)<< endl;
     
     // Tipos de datos para la tarea de Investigacion //
     
    double dmin = numeric_limits<double>::min();
	double dmax = numeric_limits<double>::max();
	
     cout << " dmin = " << dmin << endl;
     cout << " dmax = " << dmax << "\n";
     cout << " tamanio de double  : " << sizeof(double)<< endl;
     
    long int limin = numeric_limits<long int>::min();
	long int limax = numeric_limits<long int>::max();
	
     cout << " limin = " << limin << endl;
     cout << " limax = " << limax << "\n";
     cout << " tamanio de long int  : " << sizeof(long int)<< endl;
       

       
	return 0;
}
