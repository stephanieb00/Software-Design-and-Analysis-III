#Home project 2

Write a class KeywordsInFile. The only required constructor for this class is

KeywordsInFile( filename_with_keywords, filename_with_text)

filename_with_keywords is a name of a plain text file that contains the list of keywords. For the future reference, the number of words in this file is denoted by N.
filename_with_text is a name of a plain text file that contains the text where the keywords must be found. For the future reference, the number of words in this file is denoted by M.
Consider a word to contain only upper- and lower- alphabet symbols. Any non-alphabet symbol is considered a separator.

Your class should be case-sensitive. So, “sun” and “Sun” are two different words.
The processing of the files is done during the object construction. All the data needed for the methods below is stored in the object.

The processing should be done in O(N+M) time. Consider string hashing to be O(1) for this assignment.

The number of keywords can be large. The text can be large. Number of keywords in the text can be very large or very small. Design your class accordingly.

 

Disable the default non-parametrized constructor.

 

The following methods should be implemented:

 

KeywordFound( keyword ) – returns true if the specified keyword was found in the text. Returns false otherwise. The method should run in O(1) time.

 

KeywordInLine( keyword, line_number ) – returns the number of times the specified keyword was seen in  the specified line of the text. The method should run in at most O(log L) time, where L is the number of times the keyword was found in the text.

 

TotalOccurrences( keyword ) – returns the total number of the occurrences of the given keyword in the text. The method should run in at most O(log L) time, where L is the number of times the keyword was found in the text.

 

Overload operator<< that allows you to use object of your class with cout. When in the program I use command cout<operator<< will be a non-class function.

 

Programming style can affect the grade. Class and algorithm design will be graded.

 

Good luck!

