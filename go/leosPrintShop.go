/*
	Name: Taylor Moore
	Program Type: Course Assignment - Programming Languages
	Date: 18 January 2021
	Program Description:
		This program was written to see how much a cutomer owes for copies given the
		prices at Leo's Print Shoppe. The customer must input their name and how 
		many copies they need. Then, the program provides the customer's name and total 
		cost. Prices are dependent on the total number of copies ordered.
*/

package main

import(
	"fmt"
	"bufio"
	"log"
	"os"
	"strconv"
	"strings"
)


func main(){


	// Variable Declaration
	var copyCost float64=0.0
	
	// Beginning loop
	for{
		//User Input for Name 
		fmt.Print("Enter customer name: ")
		reader:=bufio.NewReader(os.Stdin)
		name,err:=reader.ReadString('\n')
		
		// Checking for errors, terminates the program if any are found. 
		if err!=nil{
			log.Fatal(err)
		}

		// User Input for Copies Needed
		fmt.Print("Enter number of copies: ")
		reader2:=bufio.NewReader(os.Stdin)
		input,err:=reader2.ReadString('\n')
		
		// Checking for errors, terminates the program if any are found. 
		if err!=nil{
			log.Fatal(err)
		}
	
		input = strings.TrimSpace(input)
		copies,err:=strconv.ParseFloat(input,64)

		// Checking for errors, terminates the program if any are found.
		if err != nil{
			log.Fatal(err)
		}

		// Price Calculations
		if (copies<=200){
			copyCost = 0.10 * copies
		}else{
			copies = copies - 200
			copyCost =(0.05 * copies) + 20.0
		}

		// Output
		fmt.Print("Customer Name: ", name)
		fmt.Print("Total Cost: $")
		fmt.Printf("%.2f",copyCost)
		fmt.Println()
		fmt.Println()
	
		// Asking if the user wants to input another customer. 
		fmt.Print("Another customer (Y/N)? ")
		reader3:=bufio.NewReader(os.Stdin)
		againResponse,err:=reader3.ReadString('\n')
		againResponse = strings.TrimSpace(againResponse)
		fmt.Println()

		if againResponse=="N"{
			break
		}else{
			continue
	
		}

	// End loop	
	}
}
