CPSC 131- Data Structure : Project 2

Matthew C.

CWID-7716

Keshav Daga
zz-kdaga@fullerton.edu

Submission: Upload on Canvas the program file with proper extension. Add your name and CWID in the beginning of the starter template. Or else, upload a link to the github repository and give me access. 
Introduction
In this project you will design and implement linked list and linked list operations for the web browser. You will be provided with a starter template with all the test cases. You need to create linked list from scratch and need to add functions  that are specified in the document. Do not change the main function, I have added test cases in it.
Web Browser for CSUF Students
The CSUF IT department is looking for potential developers who will develop the web browser which performs the same operation as browsers available in the market. They want candidates who are interested in making the web browser using a doubly linked list. The browser will implement particular functions for security and efficient use of CSUF students. Though the browser will have front end and back end. But your task will be in the backend, you have to use C++ programming to implement algorithms.
Create a class Tab which represents the node and has three values: url, name, and memory. 
url (string) - represents url of website
Name (string) - represents name of a site
memory(Generalised type) - represents memory consumed by site
Also, it has two pointers next and prev. Create another class Browser which contains all the necessary functions in order to implement specified functions. You need to declare two more pointers head and tail to represent Browser as a doubly linked list. You can add additional pointers to implement the following functions. 
addNewTab() - This function takes three parameters- url, name and memory and creates a new tab. It will assign values to tab values and add it at the last position of a linked list. Always remember the last tab will be the current tab.

switchToPrevTab() - This function switches the cursor from current tab to previous tab. If there is a previous tab, print the details of the tab like url, name and memory. If there is no previous tab it should print a message that says  “No previous tab”. 


switchToNextTab() - This function switches the cursor from the current tab to the next tab. If the next tab is present then print details of the tab. If there is no previous tab it should print a message that says  “No next tab”. 
	
	
closeCurrentTab()- It deletes the current tab from the browser. When you close the current tab the new current tab will be the next tab. Print the new current tab which is the next tab with a message “Now the current tab  = “ and current tab name.  
Before execution:

After execution:

bookmarkCurrent() - It bookmarks the current tab and saves the pair(name,url) in the vector of pairs if the current tab is still present in Browser. Use std::pair to store pairs in the vector. Vector can be defined as -  std::vector<std::pair<data types of elements>> vector name
The repetition of bookmarks is not allowed, if a repetitive tab is trying to insert inside a vector it should give a message “The bookmark is already added!!”. 
showBookmarkTab() - It will print all the bookmarks as follows: 
		Bookmarks:
name(url)

 moveCurrentToFirst() - If the current tab is still present in the browser, move it to first position.
Before function executed:

After function executed:

total_memory() - It calculates the total memory consumed by the browser in total. It will return the memory consumption. 

deleteTab() - It will delete the tab which is consuming the highest memory out of all the tabs. After deletion it will print the message and tab which is deleted with memory consumption.  
	

Grading Rubric:
Your grade will be comprised of following parts: 
addNewTab() (4 marks)
switchToPrevTab(3 marks)
switchToNextTab() (3 marks)
closeCurrentTab() (4 marks)
bookmarkCurrent() (2 marks)
showBookmarkBar() (3 marks)
moveCurrentToFirst() (5 marks)
total_memory(3 marks)
deleteTab() (8 marks)
Compilation of program (5 marks)
Successful run on all test cases(10 marks)- Partial marks will be given if few of them successfully run. 
What to Do
The starter template is provided. It has a main() function. Do not make any changes in the main function. Make changes in respective classes. Add the same name of a function that I mentioned above. If you make any other changes and code is giving different output. You will lose the marks. Make the submissions on time. No extensions will be provided. Late submissions will be accepted but 3% marks will be deducted. 



