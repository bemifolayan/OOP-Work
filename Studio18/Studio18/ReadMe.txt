studio 18 answers here
Bemi Folayan
Regan Williamson

1. It would be easy but tedious to create a new file system implementation that creates different file types than the simple file system
because we already understand the method through simple file system but it requires us to rewrite it for new files and new systems each time.

3. If the class needs to store memeber variables, we would need to create a new concrete file factory class. If a new file type is intorduced,
we would ad an if statement to the creatFile method that would search for its file extention and make a new file. Yes, the same factory can be used
to create files for two system implementations that manage the same types of files. Yes, the same concrete factory can be used to create files for two
system implementations that manage different types of files, as long as the factory has the ability to create all files from both implementations.

5. We tested open on an image file (pee.img), which ran succesfully. We tested write on a text file (poop.txt), which succcesfuly wrote a vector containing "TA" to the file. 
 We tested read on poop.txt, which succesfully printed "TA" to the console.
