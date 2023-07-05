/* 
Author: Lasha Zibzibadze
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 Task 1

This program reads a txt file, and organizes it.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;




string Next_line(int length, string line, bool true_or_false){

    // Using function to make each line equal to given width in a file.

    int count_complex = 0;
    string result_of_split = "";
    string word_s;
    istringstream iss(line);
    string endline= "\n";
    string blank= " ";
    int i= 0;

    //iss continuously gets line from input text file, and while it recieves lines it keeps modifying the lines to be desired length.


    //if input file has width specified then this logic will work.
    //Remarks: Add boolens to check if input file has new options given for task 2.
    if(true_or_false == true){
        true_or_false == false;

        while(iss >> word_s){
            int word_size= word_s.size();
            int size = word_s.length() + 1;
        
            if(i == 0)
            {          
                result_of_split= result_of_split + word_s;
                count_complex= count_complex + word_size;
                i++;
            }

            else if((size + count_complex) < length)
            {
                result_of_split = result_of_split + (blank + word_s);
                count_complex = count_complex + size;
            }

            else
            {
                result_of_split = result_of_split + (endline + word_s);
                count_complex = word_size;
            }

        }

    }

    return result_of_split;
}

int main() {
    string input;
    string endline= "\n";
    string blank= " ";

    istringstream iss; //Saving it for task 2

    // Ask user for file name and stream the file

    cout<< "Enter the input filename: ";
    cin>> input;
    ifstream infile(input);
    
    //////////// Save given options to variables ///////////////////
    string text;
    getline(infile, text);

    // logic to read width from the first line 
    int i=0;
    int counter_two;
    string read_width;
    string outfile_name_two;

    while(text[i] != ';'){
        read_width+= text[i];
        i++;
        counter_two= i;
    }
    
    // logic to read width from the first line
    while(text[counter_two + 1] != ';'){
        
        outfile_name_two += text[counter_two + 1];
        counter_two ++;
        
    }

    

    stringstream geek(read_width); //Transform string to int
    int width= 0;
    geek >> width;

    ////////////////////////////////////////////////////////////////


    //Needed Booleans
    
    bool give_par;

    if(width != 0){
        give_par = true;
    }




    //Reading text line by line and storing it in the variable until it reaches end of line of the text file

    string line_reader; // String which stores, every line temporarily from text file, and saves it in outcome;
    string outcome = "";
    string section = "";
    int checker= 0;

    while(!infile.eof())
    {
        getline(infile, line_reader);
        int get_size= line_reader.size();

        section= section + (blank + line_reader);
        if((width >= get_size) && give_par == true)
        {
            
            outcome = outcome + (Next_line(width, section, give_par));
            if(line_reader == "" && outcome[outcome.length() - 1] != '\n')
            {
                outcome = outcome + endline;
            }

            outcome = outcome + endline;
            section = "";
            checker = 1;
        }
        else
        {
            checker = 0;
        }

    }

    if(checker == 0 && give_par == true)
    {
        outcome = outcome +(Next_line(width, section, give_par));
    }
    if((outcome[outcome.length() - 1] == '\n') && give_par == true)
    {
        outcome = outcome.substr(0, outcome.size() - 1);
    }

    string output = outcome; // Save result to variable and print it to new text file.

    infile.close(); // Closing file, all operations done.
    
    ofstream outfile(outfile_name_two); // Creating and naming output file from input given parameter.

    outfile<< output; // Write outcome to output file

    outfile.close(); // Close output file

    return 0;
}