## Problem of word composition

### Steps for execution
1) Clone the repository into your local computer.
2) Open the folder in your visual studio code editor.
3) Run the file WCP.cpp(c++ compiler must be installed in your pc).
4) Input files must be in the same folder as data is extracted from these files only.
5) Output will be printed in the terminal.
6) Change input file name (input_01.txt or input_02.txt) as per your requirements in program in line 145 or change the text of the input file as per your input data.

### Approach
1) Sort all the words given through the standard input in ascending order in terms of their length (using a custom Comparator comp). 
2) Then, remove the longest word from the sorted list of words. 
3) Find the shortest prefix of this word that is a compound word.
4) If such one exists, find out if the remainder of the word is a compound word also. 
5) If so, then this word is the longest compound word, otherwise, repeat these steps.

### Implementation
1) Class "Compute" has been made with all its methods as per the requirements of the program.
2) Then,code has been written to read the data from the file that is sent as input data for further execution
3) Input has been stored in the vector "input".
4) A function "find_Longest_Word" has been made which prints the longest and  second longest compounded word.

### Overview 
1) Trie data structure has been used as it proves to be a efficient data structure to be used. It is a multiway data structure used for storing strings.The complexity of creating a trie is O(W*L), where W is the number of words, and L is an average length of the word, we need to perform L lookups on the average for each of the W words in the set and sorting time complexity is O(WlogW).
2) Firstly, I called "find_Longest_Word" function through the Compute class and initialised the words in a trie and then sort the vector so that we have the longest words at the starting and the smallest words at the end of the vector which will eventually help in finding our answer. In the find_Longest_Word function we made two strings Longest and second longest compounded word to store our answer.
3) Now,iteration of vector is done which stores all the input data so that I can access all the words,and then in loop I called a function "reset_flag" which mark the flag as false of the current word.
4) After that I called a function "is_the_word_formed", which will search whether the given word can be formed by using two or more words from all the given words.
5) If the function "is_the_word_formed" returns true, then that word would be a possible answer.
6) At last I call function "word_intialization" to mark the flag of the given word as true again.
7) Then I print both the strings as answer.








