#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void manual()
{
printf(" Construction of the input file: \n    * File should not contain chars of the alphabet, ect. except integers (example: 4) and floating point numbers (example: 0.4). \n    * File should contain three columns in the following order: X value, Y value, Uncertainty/Error Y. \n    * In case of unknown uncertainties/errors in 3-rd column You should write 1.\n Usefull commands: \n    * man(2) -- manual, \n    * return(2) -- returns to the beginning of the program, \n    * author(2) -- display information about author/authors and the used sources, \n    * exit(2) --  close the program. \n Interpretation of a output: \n    *A, B -- linear regression/fitted parameters with their uncertainty, \n    *R^2 -- coefficient of determination, \n    *Chi^2 -- chi-square, \n    *n -- degree of freedom, \n    *r -- correlation coefficient, \n    *RSS -- residual sum of squares, \n    *TSS -- total sum of squares. \n");
}

string funkcja_sprawdzajaca(string sprawdzacz)
{
		string pr;
		if(sprawdzacz == "exit(2)")
			{
				printf("\n Program dl4.3 was closed successfully. \n");
				exit(0);
			}
	    else if(sprawdzacz == "author(2)") {printf("Author: Łukasz Łysakowski. \n The following sources were used during creating the program: \n * Andrzej Zięba: ANALIZA DANYCH W NAUKACH ŚCISŁYCH I TECHNICE, PWN, Warszawa: 2014, page: 118-124 \n * www.wikipedia.org/wiki/Coefficient_of_determination \n");}
        else if(sprawdzacz == "man(2)"){manual();}
		else if(sprawdzacz == "return(2)") { return "L98L";}
		else
		{
			pr = sprawdzacz;
		}

		 return pr;
}

string funkcja_sprawdzajaca2(string a, string b)
{
	string pr;
	string wpisz;
	bool znaczni = true;
	while(znaczni){
		cin >> wpisz;
		if(wpisz == "exit(2)")
			{
				printf("\n Program dl4.3 was closed successfully. \n");
				exit(0);
				znaczni = false;
			}
		else if(wpisz == a || wpisz == b) {pr = wpisz; znaczni = false;}
		else if(wpisz == "return(2)") { return "L98L";}
	    else if(wpisz == "author(2)") { printf("Author: Łukasz Łysakowski. \n The following sources were used during creating the program: \n * Andrzej Zięba: ANALIZA DANYCH W NAUKACH ŚCISŁYCH I TECHNICE, PWN, Warszawa: 2014, page: 118-124 \n * www.wikipedia.org/wiki/Coefficient_of_determination \n");}
        else if(wpisz == "man(2)"){manual();}
        else {znaczni = true;}
	}
		return pr;
		
}

struct lindop
	{
		double wspA, wspB, niepwspA, niepwspB, par_r, Chi2, rss, ss, dR, nsA, nsB; 
	};
typedef struct lindop Struct;

Struct dl4engin(vector<double> X, vector<double> Y, vector<double> U)
{
	Struct l;

	double A=0, B=0, C=0, D=0, E=0, F=0,Dprim=0, xsuma=0, ysuma=0, licznik=0;
        for(int j=0; j<X.size(); j++)
        {
            xsuma=xsuma+X[j];
            ysuma=ysuma+Y[j];
            A=A+(1/(U[j]*U[j]));
            D=D+(1/(U[j]*U[j]))*X[j];
            E=E+(1/(U[j]*U[j]))*Y[j];
            Dprim=Dprim+(1/(U[j]*U[j]))*X[j]*X[j];
         }
        double xw, yw, xw2, sredniax, sredniay;
        double xsx=0, ysy=0, xsx2=0, ysy2=0, x=0, x2=0;
        sredniax=xsuma/X.size();
        sredniay=ysuma/Y.size();
        xw=(1/A)*D;
        yw=(1/A)*E;
    	for(int k=0; k<X.size(); k++)
    	{
            xsx=xsx+(X[k]-sredniax);
            ysy=ysy+(Y[k]-sredniay);
            xsx2=xsx2+(X[k]-sredniax)*(X[k]-sredniax);
            ysy2=ysy2+(Y[k]-sredniay)*(Y[k]-sredniay);
	    licznik=licznik+((X[k]-sredniax)*(Y[k]-sredniay));
            B=B+((X[k]-xw)*(Y[k]-yw))/(U[k]*U[k]);
    	    C=C+((X[k]-xw)*(X[k]-xw))/(U[k]*U[k]);
            F=F+(X[k]*X[k])*A;
            x2=x2+X[k]*X[k];
            x=x+X[k];

    	}
    	xw2=(1/A)*F;

        double ua, ua2, ub;
        double a, b, r, R;
        ua2=1/C;
        ua=sqrt(ua2);
    	  ub=sqrt(ua*ua*1/A*Dprim);
    	  a=ua*ua*B;
    	  b=yw-a*xw;
        r=(licznik)/(sqrt(xsx2)*sqrt(ysy2));
        double RSS=0, SS=0, chi2=0;
        int ilosc;
        ilosc = X.size();
        for(int i=0;i<X.size();i++)
            {
                chi2=chi2+pow((Y[i]-a*X[i]-b)/U[i] , 2);
                RSS=RSS+pow((Y[i]-(a*X[i]+b)),2);
                SS=SS+pow((Y[i]-pow(ilosc,-1) * ysuma),2);
            }
        R=1-(RSS/SS);
        double d, s, usA, usB;
        d=ilosc*x2-(x*x);
        s=sqrt(RSS/(ilosc-2));
        usA=s*sqrt(ilosc/d);
        usB=s*sqrt(x2/d);

    l.wspA = a;
	l.wspB = b;
	l.niepwspA = ua;
	l.niepwspB = ub;
	l.par_r = r;
	l.Chi2 = chi2;
	l.rss = RSS;
	l.ss = SS;
	l.dR = R;
    l.nsA = usA;
    l.nsB = usB;
	return l;
}
int main()
{
    cout << "\n Program: dl4.3. Written by: Lukasz Lysakowski \n"<< endl;
    cout << "---------------------------------------------------------------------"<<endl;
	for(;;)
    	{
	  zlam1:
      cout<< "Run program [1], exit [2]" <<endl;
      string wybor;
      wybor = funkcja_sprawdzajaca2("1", "2");
	  if(wybor == "L98L"){goto zlam1;}
      if(wybor == "1")
        {
		 vector<double> dx, dy, du;
    	  double dana_du, dana_dx, dana_dy;
        ifstream plik;
        string nazwa, nazwa2;
        bool sprawdz=true;
        while(sprawdz)
		{
         	cout << "Input file: ";
         	cin >> nazwa;
		 	nazwa = funkcja_sprawdzajaca(nazwa);
			if(nazwa == "L98L"){goto zlam1;}
		 	plik.open(nazwa.c_str(),ios::in);
         	if(plik.fail())
         	{
             	cout << "File not found. Please give name of the input file again." << endl;
             	sprawdz=true;
         	}
         	else {sprawdz=false;}
        }
        cout << "Value x: "<< "Value y: "<<"Value u_y: "<<endl;
         while(plik >> dana_dx >> dana_dy >> dana_du)
        {
    		dx.push_back(dana_dx);
    		dy.push_back(dana_dy);
    		du.push_back(dana_du);
            cout<< dana_dx <<"   "<< dana_dy<<"    " <<dana_du<<endl;
        }
        plik.close();
        
		  	 double a, b, ua, ub, r, chi2, RSS, SS, R, usa, usb;
		  	 Struct wynik;
			 wynik = dl4engin(dx, dy, du);
        	 a= wynik.wspA;
			 b= wynik.wspB;
			 ua= wynik.niepwspA;
			 ub= wynik.niepwspB;
			 r= wynik.par_r;
			 chi2 = wynik.Chi2;
			 RSS = wynik.rss;
			 SS =  wynik.ss;
			 R = wynik.dR;
             usa =  wynik.nsA;
             usb = wynik.nsB;
        cout << "---------------------------------------------------------------------"<<endl;
	cout << "Results of linear regression (f(x)=Ax+B) to measurement points: " <<endl;
	cout << "A= " << a<<" +- "<<ua<<endl;
        cout << "B= " << b<<" +- "<<ub<<endl;
        cout << "f(x)= ("<< a<<" +- "<<ua<< ") x  + ("<< b<<" +- "<<ub<<")"<<endl;
	cout << "R^2= " << R << endl;
        cout << "Chi^2= " << chi2 << endl;
        cout << "n= " << dx.size()-2 <<endl;
        cout << "r= "<< r<<endl;
        cout << "RSS= "<<RSS<<endl;
        cout << "TSS= "<<SS<<endl;
        cout << "In case of unknown (u_y=1) or scalable uncertainties:" << endl;
        cout << "A= " << a<<" +- "<<usa<<endl;
        cout << "B= " << b<<" +- "<<usb<<endl;
        cout << "Save to  file [4], or continue without saving [5]." << endl;
        ofstream plikwyjsciowy;
        string nazwapw;
        wybor = funkcja_sprawdzajaca2("4", "5");
	if(wybor == "L98L"){goto zlam1;}
        if(wybor == "4")
        {
            cout << "Output file: ";
            cin >> nazwapw;
	    nazwapw = funkcja_sprawdzajaca(nazwapw);
	    if(nazwapw == "L98L"){goto zlam1;}
            plikwyjsciowy.open(nazwapw.c_str(),ios::out);
            plikwyjsciowy <<"Results of linear regression (f(x)=Ax+B) to measurement points form the file: " << nazwa <<"." <<endl;
            plikwyjsciowy <<"A= " << a<<" +- "<<ua<<endl;
            plikwyjsciowy <<"B= " << b<<" +- "<<ub<<endl;
            plikwyjsciowy <<"f(x)= ("<< a<<" +- "<<ua<< ") x  + ("<< b<<" +- "<<ub<<")"<<endl;
	        plikwyjsciowy << "R^2= " << R << endl;
            plikwyjsciowy << "Chi^2= " << chi2 << endl;
            plikwyjsciowy << "n= " << dx.size()-2 <<endl;
            plikwyjsciowy << "r= "<< r<<endl;
            plikwyjsciowy << "RSS= "<<RSS<<endl;
            plikwyjsciowy << "TSS= "<<SS<<endl;
            plikwyjsciowy << "In case of unknown (u_y=1) or scalable uncertainties:" << endl;
            plikwyjsciowy << "A= " << a<<" +- "<<usa<<endl;
            plikwyjsciowy << "B= " << b<<" +- "<<usb<<endl;
            plikwyjsciowy.close();
        }
        else if(wybor == "5"){continue;}
      }
      else if(wybor == "2"){printf("\n Program dl4.3 was closed successfully. \n"); exit(0);}
      getchar();
}
    return 0;
}
