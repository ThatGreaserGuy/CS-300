# CS-300
A repository of scripting done for my CS 300: Analysis and Design class.

-----------------------------------------------------------------------------------------------------------------------

PROJECT 1:
  - Purpose & Goals:
    - Provide pseudocode for course list requirements similar to Project 2 with the
      added detail of ADT variety focusing on vectors, hash tables, and binary search
      trees.
    - Analyze runtime complexity for the three data structures and display.
    - Compare these runtime complexities as well as pros and cons of each data structure.
    - Reflect upon these comparisons and provide an educated recommendation of the
      best data structure to utilize for the given scenario.
  
  - Only file included is the .docx file for the pseudocode, analyses, and comparisons.
  - This is to promote a comprehension followed by critical thinking in implementation.
  - The runtime complexities included do not accurately represent the final product(s)
    as pieces of the project can be interchanged depending on criteria -- one such
    example being prerequisite validation that was not implemented.

-----------------------------------------------------------------------------------------------------------------------

PROJECT 2:
  - Purpose & Goals:
    - Load course information from a CSV file into a course list ADT (vector).
    - Print entire course list in alphanumeric order.
    - Search for and print information regarding a specified course.

  - ADT of choice is the vector, chosen over hash table and binary search tree.
  - No .hpp or other .cpp files required -- all done within one.
  - Utilizes <THREAD> and <CHRONO> as well as Byte Order Mark (BOM) skipping.
    - These were not requirements of the project and were extra for aesthetically
      spacing out console actions/outputs and removing special characters from strings,
      respectively.

-----------------------------------------------------------------------------------------------------------------------

END OF TERM REFLECTION:
  1) What was the problem you were solving in the projects for this course?
    - This term focused on supplying a kind of software to load courses into a data structure,
      sort these courses, and display informaiton pertaining to them whether it be the entire
      list of courses or one particular course.
  
  2) How did you approach the problem?  Consider why data structures are important to understand.
    - I approached the problem from a conceptual standpoint -- WHAT is desired and HOW can this
      be brought to reality?  Data structures are important to understand because they immediately
      and profoundly aid at this foundational level; your level of understanding of ADTs can make
      this conceptualizing vastly more difficult or incredibly easier as storing information into
      an ADT is a core concept of most softwares that exist.    // One might dare say, "all".
  
  3) How did you overcome any roadblocks you encountered while going through the activities or project?
    - There were many roadblocks experienced ranging from simple syntax misunderstandings to full-blown conceptual nightmares.
      The hardest concept to grasp was reading and parsing a CVS file.  For some reason, I could not understand it until this
      final project, essentially.  Utilizing a common "temporarily store and use" functionality got the concept to fully
      sink in.
  
    - Overcoming this and many other roadblocks really just took a lot of punching and punching and punching until
      they crumbled.    // Why overcome when you can destroy and pass through easily?
    - This strategy, though frustrating and, at times, time-consuming, is my go-to because it works very well for my brain
      and how it functions.  Really, the hardest part is finding time to make this strategy work.
  
  4) How has your work on this project expanded your approach to designing software and developing programs?
    - This project has given me a better respect for more behind-the-scenes functionalities that do not "immediately"
      pertain to the project's goals (example: CVS parsing, though fundamental to this project, was not an immediate
      requirement to the concept of creating a course list).  My approach has expanded in the sense of possessing
      multiple perspectives at which to attack the goal.
  
  5) How has your work on this project evolved the way you write programs that are maintable, readable, and adaptable?
    - This project has affirmed my personal desire to "overuse" white space instead of under-using it.  I may not need
      to press enter between a function's opening and its first line, but I do so for clarity especially when the
      function is a hefty one.  I also enjoy tabbing comments over and having them follow the same invisible vertical line
      down the length of the script.  It may make it slightly more difficult to see exactly what line it is pertaining
      to, but overall it is a uniform look that compliments the scripting wonderfully.
  
    - On the concept of making programs adaptable, I see now why "private" and "public" are simultaneously utilized to pass
      functions to each other.  In other words, I noticed a public function, say, "AddCourse" simply calls a private function
      "AddNode".  At first, I did not understand the superfluous nature of having a function simply call another function
      when the first function could suffice if scripted properly.  However, upon reviewing and analyzing "why" this may be
      done, I have a newfound respect and desire to follow the same mindset.  It adds to an overall safe and modular scripting
      experience which may just as well benefit projects in the future.

-----------------------------------------------------------------------------------------------------------------------
