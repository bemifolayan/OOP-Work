Lab 5 Readme
Bemi Folayan
Regan Williamson

FOr each problem in the lab we switched between who was the person reading the document and talking through the problem, and who was the person doing the actual coding.

9. We chose to implement the Touch + cat command. It is invoked from the command prompt with tc <filename>. We tested this by typing tc birdie.txt
into the command prompt, and were immediately prompted to write something to the newly created file. We named our new parsing strategy
AdditionalParsingStrategy.

Tests:
$   ls
	To test this command, we entered into the command prompt: touch regan.txt / touch bemi.img / touch test.txt / ls. ls returned the properly 
	formatted list of existing files.
$   ls -m
	To test this command, we entered into the command prompt: touch regan.txt / touch bemi.img / touch test.txt / ls. ls returned the properly 
	formatted list of existing files and their associated metadata.
$   rm <filename>
	To test this command, we entered: touch regan.txt / touch bemi.img / ls (to check that these were added properly) / rm regan.txt / ls (to 
	check that regan.txt was removed). This returned the expected output.
$   touch <filename> -p
	To test this command, we created a password protected file and tested the existing commands on it.
$   cat <filename> [-a]
	To test this command, we created a text file and wrote to it, and then appended it, each time saving with :wq. Then we created an image file and
	wrote to it and tried to append it, saving each time with :wq. We then wrote and appended to each file, but did not save the changes we made by 
	entering :q. Then we did the same thing for password protected versions of each file type.
$   ds <filename> -d
	To test this command, we created an image file (bemi.img), wrote "X X X X X3" to it with cat, and then called ds bemi.img (whcih displayed 
	the formatted output) and ds bemi.img -d (which displayed the unformatted output). We then did the same thing with a pasword protected 
	version of the file.
$   cp <file_to_copy> <new_name_with_no_extension>
	To test this command, we entered: touch regan.txt / cp regan.txt bemi / ls (to make sure bemi.txt had been created) / cat bemi.txt / test 
	/ :wq /ds regan.txt (to make sure the original file is still empty) / ds bemi.txt (to make sure the copy was updated). We then repeated this
	with bemi.img as the original file, and then with password protected versions of eahc file.
$   rn <existing_file> <new_name_with_no_extension>
	To test this command, we entered: touch bemi.img / cat bemi.img / lol / :wq / rn bemi.img bemi1.img / ls(to make sure bemi1.img was the only 
	file that existed) / ls bemi1.img -m (to make sure that bemi1.img holds the data that bemi.img used to hold). We then repeated this with a
	password protected version of the file.

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