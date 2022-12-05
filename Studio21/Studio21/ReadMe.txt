Studio 21 ReadMe.txt 
Bemi Folayan
Regan Williamson

2. It is important to declare a virtual destructor in the base class because any use of this class will hold a pointer to the interface,
not the concrete classes that derive it, in which case the interface destructor will be called. Otherwise, we open up the potential for memory leaks.
3. Dependency injection makes the command prompt flexible and reusable because, by making its member variables pointers to abstract classes/interfaces,
it doesn't need to know the concrete classes that derive from those interfaces, but is still able to interact with them. As a result, the command prompt
does not need to be edited each time a new file type is created derived by AbstractFile. The command prompt can be easily
configured to use different file system implementations instead of the simple file system and its associated factory object.