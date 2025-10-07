# CPSC351_Assignment1_Q2/Q3


## Names / Emails:
- Josh Navarro: joshpatnav@csu.fullerton.edu
- Monica Soliman: msoliman14@csu.fullerton.edu
- Isaac Morrell: isaacmorrell13@csu.fullerton.edu
- Spencer Blunt: sblunt3@csu.fullerton.edu
- Michelle Pineda: pinedama@csu.fullerton.edu
- Mathew Estrada: mestrada145@csu.fullerton.edu

## Contribution

## Statement
We all understand and are familiar with the functionality in the assignment

## Programming Language
C++

## How to Execute
Use 
g++ serial.cpp -o serial (compile)
./serial(run program) / time ./serial(get times)

## Execution Times

## Questions/Answers
1. In the output of time, what is the difference between real, user, and sys times?

Answer: 
Real time: The total time it will take for the program to run from start to finish.
User time: Is how long the CPU spends running the program’s own code.
Sys time: The time the CPU spends doing work for the program inside the operating system, like handling files or input and output.

2. Which is longer: user time or sys time? Use your knowledge to explain why.

Answer:
User time and system times will relatively be the same, it comes down to the level of privilege the instruction a process has. User mode will deal with all non-privileged instructions and the system will execute all privileged instructions. Ideally processes should be granted the minimum privileges needed for their tasks, meaning we hope to spend more time in user mode. This means our processes will have less of a chance to potentially damage the system. Our time ./serial output and time ./parallel reflect this. Our user time for serial is 0.259s greater than system, with our user time being 0.309s and system being 0.050s, and for parallel our user time is 0.242s greater than system with our user time being 0.299s and our system time at 0.057s.

3. When fetching all of the locations in the file, which fetcher finishes faster? Why do you think
that is?

Answer:

4. Suppose one of the fetcher children crashes. Will this affect other children? Explain. What
is your conclusion regarding the benefits or disadvantages of isolating each fetch task within
a different process?

Answer:
