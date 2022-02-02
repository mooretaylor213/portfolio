/*
	Name: Taylor Moore
	Date: 1 February 2021
	Program Type: Course Assignment - Programming Languages
	Program Description: 
		This program reads in monthly rainfall levels for a city, prints the values read from a text file into a table, 
	     	and then prints statistics about the rainfall levels. The text file is provided in the same directory as this
		program. 
*/

package main

import(
	"fmt"
	"bufio"
	"strconv"
	"log"
	"os"
)

// Global Constant Declarations
const TWELVE int=12
const ONE int=1
const ONE_HUNDRED float64=100.0

func main(){
	// Variable Declarations and Initialization
	var min int=0
	var max int
	months:=[]string{"January","February","March","April","May","June","July",
			   "August","September","October","November", "December"}

	// Function Calls
	values,err:=readData()
	
	// Checking for errors, terminate the program if errors are found.
	if err!=nil{
		log.Fatal(err)
	}

	// Function Calls
	max=len(values)-ONE
	printTable(months,values)
	lowest,highest,average:=computations(values)

	// Output
	fmt.Println()
	fmt.Println("The month with the lowest value is: ",months[lowest])
	fmt.Println("The month with the highest value is: ",months[highest])
	fmt.Println("The lowest rainfall value is: ",values[min])
	fmt.Println("The highest rainfall value is: ",values[max-ONE])
	fmt.Print("The average rainfall for month is: ")
	fmt.Printf("%.1f",((average*ONE_HUNDRED)/ONE_HUNDRED))
	fmt.Println()
}

/*
Function Name: readData
Description: Reads data from a text file "rainfall.txt" into an array.
	     Contains appropriate error messages for each action within
	     the function.
Incoming:none
Outgoing: []float64, error
Return: []float64,error
*/

func readData()([]float64,error){
	// Array Declaration
	var lines[]float64

	// Opening Text File
	file,err:=os.Open("rainfall.txt")
	
	// Checking for errors, terminate the program if errors are found.
	if err!=nil{
		return nil,err
	}

	scanner:=bufio.NewScanner(file)

	// Appending file contents.
	for scanner.Scan(){
		line:=scanner.Text()
		rate,err:=strconv.ParseFloat(line,64)
		
		// Checking for errors.
		if err!=nil{
			return lines,err
		}
		
		lines=append(lines,rate)
	}

	count:=len(lines)

	if count<TWELVE || count>TWELVE{
		return lines,err
	}

	// Close file, check for errors.
	err=file.Close()

	if err!=nil{
		return lines,err
	}

	if scanner.Err()!=nil{
		return nil, scanner.Err()
	}

	// Function Return Values
	return lines,nil
}

/*
Function Name: printTable
Description: Prints the table with appropriate headers (month and rainfall).
Incoming:months[]string, values[]float64
Outgoing:none
Return: none
*/

func printTable(months[]string,values[]float64){

	fmt.Println("--------------------------")
	fmt.Println("Table for Monthly Rainfall")
	fmt.Println("--------------------------")
	fmt.Println()
	fmt.Println("Month","              Rainfall")
	fmt.Println("------","             --------")

	for i:=0; i<TWELVE; i++{
		fmt.Printf("%-15s",months[i])
		fmt.Println("      ",values[i])
	}

}

/*
Function Name: computations
Description: Takes the array that has been read in and sorts it using a bubble sort. 
Incoming: values[] - float64
Outgoing: 0, len(values) - int, average - float64
Return: 0, len(values) - int, average - float64
*/

func computations(values[]float64)(int,int,float64){
	var sum float64=0.0
	var temp float64
	var tempArr[]float64
	var min int
	var max int

	for i:=0; i<TWELVE;i++{
		tempArr=append(tempArr,values[i])
	}


	for i:=0;i<(TWELVE-ONE);i++{
	for j:=0; j<(TWELVE-i-ONE);j++{
		 if(values[j]>values[j+ONE]){
			temp=values[j]
			 values[j]=values[j+ONE]
			 values[j+ONE]=temp
		 }
	}
	}

	for i:=0; i<TWELVE;i++{
		sum+=float64(values[i])
	}
	
	average:=sum/float64(len(values))
	
	for i:=0; i <(TWELVE);i++{
		if tempArr[i]==values[0]{
			min=i
		}
		if values[TWELVE-ONE]==tempArr[i]{
			max=i
		}
	}
	
	// Function Returns
	return min,max,average
}
