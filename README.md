# CST334-Labs
A collection of selected labs from CST 334 - Operating Systems

---

## Paging Simulation Lab

### Description of Implementation:
* The FIFO memory management simulation uses several C files and headers to emulate paging with the specified algorithm. The node.c/.h files contain only details to implement nodes on a linked list, along with debugging options to track and print a list’s contents. We also describe some essential functions such as node_peek and node_next, which function to return the value of the current node and to retrieve the following node, respectively.

* Queue.c/.h describes the process for initializing, populating, and deleting items from the queue structure. It is dependent on the node object already being defined. The creation of linked list nodes occurs here within the enqueue function, and the maximum size accommodation is directly dependent to the buffer size specified in the argument provided to the program before running.

* The queue.c file also houses the critical traverse function, which not only steps through the entire linked list when called, but also checks whether it already contains a number that matches the next block being read from stdin. If that block is found, it returns a boolean true, signifying to the FIFO algorithm that it should not trigger a page fault.

* Finally, fifo.c combines all existing code into the main function. Here, we do some error checking to determine whether or not the proper number of arguments are being handed to the program, as well as if those arguments contain legal characters.

* Immediately following, a while loop takes all of the text fed through stdin, translates it to an integer, and then populates the queue according to the FIFO algorithm rules. If the line does not contain a number, but instead some illegal character such as a letter or space, we print to stderr notifying the user of bad input before ending the process with a return value of 1. After populating the queue, we increment a variable for page faults by 1, if and only if the queue receives a new value. Afterward, we increment a total blocks variable by 1, regardless of the FIFO queue’s outcome.  When the entire input has been read, a generic printf to stdout notifies the user of how many page faults were found out of a total number of blocks.

### Usage:
	cat file | fifo_test buffer_size
  
### Description of results:
With a buffer size of 50, approximately 95% of reads produced a page fault (9516 out of 10001 blocks)
A buffer size of 100 reduces this by about 5% to 90% of reads producing page faults (9019 out of 10001)
Doubling the buffer size to 200 drops the total page faults to 80% of all reads (8042 out of 10001). This suggests that the FIFO algorithm has a linear rate of improvement in regards to the buffer size.
Finally, a buffer of 500 provides approximately 50% page fault rates. This was expected by this point, especially because the accesses.txt file contains numbers ranging 0-999.

---

## Matrix Multiplication Using Threads
This lab uses multithreading to improve the calculation time necessary for solving the dot product of very large matrices. For each row in the matrix, one thread is created. Mutual exclusion is used to allow critical section resources to only be given to one thread at a time, effectively locking those resources until the current thread is finished with its work. 

The result of this short program is a third matrix produced from the dot product of the first two.

---

## 
