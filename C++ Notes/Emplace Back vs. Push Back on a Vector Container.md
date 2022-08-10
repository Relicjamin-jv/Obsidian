
Topic: Emplace Back vs. Push Back on a Vector Container
Date: Aug 3, 2022

---

### Questions/Cues
- Item

### Notes

###### Emplace Back
 - Reserves space for a new string
 - placement new() into new space
 - Effectivly makes new space for the vector and then places the new information at that vector.
 - Call when making a new object

###### Push Back
- Creates a temp
- Resizes the container
- Moves the temp into the resize container
- Call when you already have the object

### Summary
Highlight ==what’s important!==
