#include <iostream>
#include <cstdio>
#include <bits/stdc++.h> 
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std; 

// Multiplies str1 and str2, and prints result. 
string iloczyn(string num1, string num2) 
{ 
	int n1 = num1.size(); 
	int n2 = num2.size(); 
	if (n1 == 0 || n2 == 0) 
	return "0"; 

	// will keep the result number in vector 
	// in reverse order 
	vector<int> result(n1 + n2, 0); 

	// Below two indexes are used to find positions 
	// in result. 
	int i_n1 = 0; 
	int i_n2 = 0; 
	
	// Go from right to left in num1 
	for (int i=n1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = num1[i] - '0'; 

		// To shift position to left after every 
		// multiplication of a digit in num2 
		i_n2 = 0; 
		
		// Go from right to left in num2			 
		for (int j=n2-1; j>=0; j--) 
		{ 
			// Take current digit of second number 
			int n2 = num2[j] - '0'; 

			// Multiply with current digit of first number 
			// and add result to previously stored result 
			// at current position. 
			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

			// Carry for next iteration 
			carry = sum/10; 

			// Store result 
			result[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 

		// store carry in next cell 
		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 

		// To shift position to left after every 
		// multiplication of a digit in num1. 
		i_n1++; 
	} 

	// ignore '0's from the right 
	int i = result.size() - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 

	// If all were '0's - means either both or 
	// one of num1 or num2 were '0' 
	if (i == -1) 
	return "0"; 

	// generate the result string 
	string s = ""; 
	
	while (i >= 0) 
		s += patch::to_string(result[i--]); 

	return s; 
} 

string suma(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

string l(string k) {
 //wielomian L(k)=960k^2+1208k+376
 string L[3]={"960","1208","376"};
 string wynik;

	int i=0; wynik = "0";
	while(i<3) {
		wynik = suma(iloczyn(wynik,k) , L[i] );
		i++;
	}
 return wynik;
}

string m(string k) {
 //wielomian M(k)=4096k^4+8192k^3+5696k^2+1552k+120
 string M[5]={"4096","8192","5696","1552","120"};
 string wynik;

	int i=0; wynik = "0";
	while(i<5) {
		wynik = suma(iloczyn(wynik,k) , M[i] );
		i++;
	}
 return wynik;
}

string sixteen(int k) {
  string l;
  if(k==0) return "1";
  else
  {
     l="1";
     for (int i = 0; i < k; i++) { 
	l = iloczyn("16",l);
	//cout << "16^" << i << "=" << l << endl;
	//cout << "----------------------------------------------------------------------" << endl;
     }
     return l;
  } 
}

 int main() { 
	string l0="376", m0="120";
	int k, n;
	string il;
	cout << "Program będzie obliczał wybrane przybliżenia liczby PI w postaci ułamk zwykłego, obliczanej według formuły Bailey (2000) and Borwein and Bayley (2003) \nhttp://mathworld.wolfram.com/BBP-TypeFormula.html \nProgram wypisuje składniki wielomianowe sumy częściowej licznika i mianownika." << endl; 
	cout << "k="; 
	cin >> n;

	cout << "k=0" << endl;
	cout << l0 << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << m0 << " * 1" << endl;
 //puts("\n"); 

	for (k = 1; k <= n; k++) { 
		//puts("\n"); 
		cout << "k=" << k << ": " << endl;
		cout << l(patch::to_string(k)) << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << m(patch::to_string(k)) << " * " << sixteen(k) << endl;
   	} 
 return 0;
 }


