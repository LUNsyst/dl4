# dl4.3
 dl4.3 is a simple program for linear regression.
 
 Short manual:
 Compilation requirements:
	* gcc 7.5.0 or higher
	* clang 12.0.0 or higher

Compilation:
	* with source (for Linux): 
		** g++ dl4.3-source.cpp -o dl4.3
	* or 
		** downald the .tar file, 
		** explore them,
		** enter into explored folder via Linux terminal
		** type: make 
		   in the folder dl4.3 should appear dl4.3 binary file, which You can run   
Run the program dl4.3 for Linux:
    * in terminal type: ./dl4.3
	* or: ./(path to binary file dl4.3)/dl4.3

Construction of the input file: 
	* File should not contain chars of the alphabet, ect. except integers (example: 4) and floating point numbers (example: 0.4).
	* File should contain three columns in the following order: X value, Y value, Uncertainty/Error Y.
	* In case of unknown uncertaints/errors in 3-rd column You should write 1.

Usefull commands:
    * man(2) -- manual,
    * return(2) -- returns to the beginning of the program,
    * author(2) -- display information about author/authors and the used sources,
    * exit(2) --  close the program.

Interpretation of a output:
    *A, B -- linear regression/fitted parameters with their uncertainty,
    *R^2 -- coefficient of determination,
    *Chi^2 -- chi-square,
    *n -- degree of freedom,
    *r -- correlation coefficient,    
    *RSS -- residual sum of squares,
    *TSS -- total sum of squares.

Author: Łukasz Łysakowski. 
The following sources were used during creating the program: 
  * Andrzej Zięba: ANALIZA DANYCH W NAUKACH ŚCISŁYCH I TECHNICE, PWN, Warszawa: 2014, page: 118-124 
  * www.wikipedia.org/wiki/Coefficient_of_determination
 
