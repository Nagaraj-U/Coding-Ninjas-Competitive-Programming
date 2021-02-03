#include <iostream>
using namespace std;


int main()
{
     char ch = 'A';
     int p = 2.5;
     float f = 102.53;
     long l =1234;
     double d = 134.567;
     long long num = 1234567;
     long double no = 123456.2345;
     
     char *cp = &ch;
     int *pi = &p;
     float *pf = &f;
     long *lp = &l;
     double *dp = &d;
     long long *llp = &num;
     long double *ldp = &no;
     
     
     cout << "data type sizes : "<< endl;
     cout << "char " << sizeof(ch) << endl;
     cout <<"int " <<  sizeof(p) << endl;
     cout <<"float "<< sizeof(f) << endl;
     cout <<"long " <<  sizeof(l) << endl;
     cout <<"double "<< sizeof(d) << endl;
     cout << "long long " << sizeof(num) << endl;
     cout << "long double " << sizeof(no) << endl;
     cout << endl <<endl ;
     cout << "pointer sizes : "<<endl;
     cout << "char " << sizeof(cp) << endl;
     cout <<"int " <<  sizeof(pi) << endl;
     cout <<"float "<< sizeof(pf) << endl;
     cout <<"long " <<  sizeof(lp) << endl;
     cout <<"double "<< sizeof(dp) << endl;
     cout << "long long " << sizeof(llp) << endl;
     cout << "long double " << sizeof(ldp) << endl;
     
     

     return 0;
}


/*

data type sizes :                                                                                                                             
char 1                                                                                                                                        
int 4                                                                                                                                         
float 4                                                                                                                                       
long 8                                                                                                                                        
double 8                                                                                                                                      
long long 8                                                                                                                                   
long double 16                                                                                                                                
                                                                                                                                              
                                                                                                                                              
pointer sizes :                                                                                                                               
char 8                                                                                                                                        
int 8                                                                                                                                         
float 8                                                                                                                                       
long 8                                                                                                                                        
double 8                                                                                                                                      
long long 8                                                                                                                                   
long double 8 


 NOTE : pointers sizes remains constant irrespective of various types of pointers(ie int,char etc )
*/
