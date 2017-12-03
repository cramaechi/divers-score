# Diver's Score
A program that prints out a diver's score given suitable input.

### Synopsis
There are seven judges who can award a score between 0 and 10, where each score may be a floating point number.

The highest and lowest scores are thrown out and the remaining scores are added together.

The sum is then multiplied by the degree of difficulty for that dive. The degree of difficulty ranges from 1.2 to 3.8 points.

The total sum is then multiplied by 0.6 to determine the diver's score.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/divers-score.git
   ```
    or [download as ZIP](https://github.com/cramaechi/divers-score/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd divers-score
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./divers_score
```

Sample Output:
```
Enter degree of difficulty: 3.1                                                                                       
Enter in 7 scores: 6.7 8.0 6.0 5.9 7.0 7.5 6.7                                                                        
The divers score is 63.1                                                                                              
                                                                                                                      
Enter degree of difficulty: 3.8                                                                                       
Enter in 7 scores: 9.6 9.0 8.9 9.2 9.0 8.8 8.9                                                                        
The divers score is 102.6 
```
