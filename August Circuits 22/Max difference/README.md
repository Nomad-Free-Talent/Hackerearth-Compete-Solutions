# Max Difference

## Problem

The weight of an array is defined as the difference between the maximum and minimum element of the array. For example, the weight of the array [3, 7, 1, 2] is (7 - 1) = 6, the weight of the array [2] is (2 - 2) = 0, the weight of an empty array is 0.<br>
You are given an array A of length N. You have to divide the elements of A into two subsequences S1, and S2 (one of S1, S2 can be empty) such that:

- Each element of A belongs to one of S1 and S2.
- The sum of weights of the two subsequences is maximum.

Find the maximum possible sum of weights of the two subsequences.

**Input format**

- The first line contains *T* denoting the number of test cases. The description of *T* test cases is as follows:
- For each test case:
  - The first line contains *N* denoting the size of array *A*.
  - The second line contains *N* space-separated integers *A[1], A[2], ....., A[N]* - denoting the elements of *A*.

**Output format**

For each test case, print the maximum possible sum of weights of the two subsequences.

**Constraints**

$ 1 \leq T \leq 10^6 $<br/>
$ 2 \leq N \leq 10^5 $<br/>
$ 1 \leq A_i \leq 10^9 $<br/>
$ Sum\;of\;N\;over\;all\;test\;cases\;does\;not\;exceed\;2\cdot10^5.$

|SAMPLE INPUT|SAMPLE OUTPUT|
|------------|-------------|
|1|2|
|3||
|1 2 3|

## Explanation

**Test case 1:** One possible division is [1, 3], [2] Here the total weight is = (3 - 1) + (2 - 2) = 2.

Time Limit:&emsp;1.0 sec(s) for each input file.<br/>
Memory Limit:&emsp;256MB<br/>
Source Limit:&emsp;1024MB<br/>
Marketing Scheme:&emsp;Score is assigned if any testcase passes.<br/>
Allowed Languages:&emsp;Bash, C, C++, C++14, C++17, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, Java 14, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, Python 3.8, Racket, Ruby, Rust, Scala, Swift-4.1, Swift, TypeScript, Visual Basic
