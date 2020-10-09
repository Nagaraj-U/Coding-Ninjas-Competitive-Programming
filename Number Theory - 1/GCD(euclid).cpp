/*
GCD
Send Feedback
Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
x and y (separated by space)
Output format :
GCD of x and y
Sample Input 1:
20 
5
Sample Output 1:
5
Sample Input 2:
96 
14
Sample Output 2:
2
*/
// void swap(int &a,int &b){
//     int temp = a;
//     a = b;
//     b = temp;
//     return;
// }



//time complexity of algorithm is O(log2(max(a,b)))
int gcd(int a,int b)
{
	
    // if(b>a){
    //     swap(a,b);
    // }
    
    //no need to handle b>a case algorithm handle itself (dry run to confirm)
    if(b == 0){
        return a;
    }
    
    return gcd(b,a%b);
}

