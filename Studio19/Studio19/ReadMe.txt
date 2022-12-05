studio 19 answers here
Bemi Folayan
Regan Williamson

2c. We created a text file that was empty and stored its contents in a local vector. We then edited that vector to contain 'TA' and wrote 
it to the text file.

3. When the accept method is called on a file object, a visitor is passed as a parameter and the accept method calls the visitor's visit
method on the file object.

4. The visitor pattern uses delegation by having a visitor object forward a visit file call to a text file or image file object.

5. We will need to modify MetadataDisplay, AbstractFileVisitor, BasicDisplayVisitor, AbstractFile, the negative consequence of the visitor pattern
is that anytime we add a new concrete file type, we will have to edit the headers and source files of every visitor. Its a bad idea to use
this pattern when we have a lot of unique file types and a lot of visitors.