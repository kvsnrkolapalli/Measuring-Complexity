# Measuring-Complexity-in-C

One way of characterizing data is to measure and compare its relative complexity. This requires a definition of complexity and a method of comparison.
Consider linguistic complexity. We could define the complexity of written text as the ratio of the number of unique words to the total number of words in a sample. Think of a book for young readers (“See Spot. See Spot run.”). The intuition is that repeated words and a small vocabulary make for simpler comprehension.
This complexity metric is very easy to compute. The text sample “Now is the time for all good men to come to the aid of their country.” is a sentence consisting of 16 words, of which 14 are unique. Hence its complexity is 0.875 as defined.
Different types of documents naturally have different complexities. Speeches and sermons are often less complex, both because of their oral delivery mode and their desire to establish a pleasing or memorable rhythm in the ear of the listener. Novels are often of low total complexity simply because they are lengthy (i.e. resulting in a large denominator)
Interestingly, it’s not uncommon for complexity to change in a given document. For example, the introductory chapter of a textbook might use less discipline-specific words and hence be less complex than later chapters. Measuring local complexity requires the use of a sliding window, which is used to compute the changing complexity at varying points in a sample. Using the text sample from above:

In this case the size of the sliding window is defined as 5 words. At the location given in the first example, all five words are unique, resulting in a complexity of 1. The window is then slid forward one word. The complexity is now 0.8, as there are only four unique words within the window.
