Lab 5 Readme
Bemi Folayan
Regan Williamson

FOr each problem in the lab we switched between who was the person reading the document and talking through the problem, and who was the person doing the actual coding.

Errors/bugs:
- PasswordProxy: cannot instantiate an abstract class
	We had forgotten that PasswordProxy inherited from AbstractClass when we were trying to implement the prototype pattern, so we had forgotten 
	to add the clone() method to PasswordProxy
- MacroCommand methods weren't working on an AbstractCommand pointer that was dynamically allocated as a MacroCommand object
	Needed to declare a MacroCommand object, call the methods on that object, then allocate an AbstractCommand pointer to point to that object 
	before adding the command
- dangling pointers
	When we were trying to access a file using the openFile() method in certain Command executes, it sometimes returned a nullptr which could not
	be used. We solved this by making sure to always call closeFile() after openFile() was called within an execute().
- unresolved external symbol
	We were trying to add the extra methods needed in MacroCommand to the AbstractCommand interface, but that was messing up every other derived
	class of AbstractComand. We ended up not adding these methods to the interface, and only called these methods on MacroCommand objects in main,
	not an AbstractCommand pointer dynamically allocated to a MacroCommand.
- overloaded function error
	We were being told that the program was assuming that the parse() method in RenameParsingStrategy was assumed to have an integer as its 
	return variable, even though we had explicitly said it was a vector<string>. We had just forgotten to put a semicolon at the end of the class
	header lol.