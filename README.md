# Partitions Enumeration

Supplementary material of [Lexicographic Enumeration of Set Partitions](https://arxiv.org/abs/2105.07472).

## Abstract

In this report, we summarize the set partition enumeration problems and thoroughly explain the algorithms used to solve them. These algorithms iterate through the partitions in lexicographic order and are easy to understand and implement in modern high-level programming languages, without recursive structures and jump logic. We show that they require linear space in respect to the set cardinality and advance the enumeration in constant amortized time. The methods discussed in this document are not novel. Our goal is to demonstrate the process of enumerating set partitions and highlight the ideas behind it. This work is an aid for learners approaching this enumeration problem and programmers undertaking the task of implementing it.

## List of Implementations

| Algorithm | Description                                                                     | Implementation   |
|:----------|:--------------------------------------------------------------------------------|:-----------------|
| V         | Enumerate all partitions of the set                                             | [v.cpp](v.cpp)   |
| W         | Enumerate all partitions with at most `k` blocks                                | [w.cpp](w.cpp)   |
| X         | Enumerate all partitions with exactly `k` blocks                                | [x.cpp](x.cpp)   |
| Y         | Enumerate all partitions with exactly `k` blocks                                | [y.cpp](y.cpp)   |
| Z         | Enumerate all partitions whose number of blocks are between `k_min` and `k_max` | [z.cpp](z.cpp)   |
| Z*        | The reverse of algorithm Z                                                      | [zr.cpp](zr.cpp) |
| U         | Enumerate all partitions whose number of blocks are in the set `K`              | [u.cpp](u.cpp)   |
| U*        | The reverse of algorithm U                                                      | [ur.cpp](ur.cpp) |
