# HTML

-  Define a valid HTML document
```HTML
<!DOCTYPE html>
<html lang="en">
  <head>
  <meta charset="UTF-8">
  <link rel="stylesheet" href="Path to style sheet">
  </head>
  <body>
<img src="img_girl.jpg" alt="Girljacket" width="500" height="600">
<div class="myDiv"> # Can replace with id  
  <h2>This is a heading in a div element</h2>  
  <p>This is some text in a div element.</p>  
  <a href="https://www.w3schools.com">Visit W3Schools.com!</a>
</div>
  </body>
</html>
```

- Use the following basic HTML elements: img div p ul ol li a
	- img: For putting an image 
	- div: Creating an division to be later used to style by css or manipulated by js
	- p: A paragraph
	- ul: Bullet point list, has li tags in it
	- li: used to help create an UL
	- ol: Used as an ordered list, also use li to help with this
	- a: used for linking 

- Construct an HTML table using the standard table elements: table thead tr th tbody td caption
	![[Pasted image 20220907081633.png]]
- Thead, and tbody are used to section out the different parts of the table
-  Use id and class attributes to make your document easier to style
	- Difference between class and id is that class can be used more than once for any one element and id can only be used once for any element.

-  Link an external CSS stylesheet i.e. a separate CSS file
	<link rel="stylesheet" href="Path to style sheet">
# CSS

v  Set the background color of an HTML element

v  Set the font-family and other text properties like font-weight and font-size of an HTML element

v  Set the size of an element using either relative or absolute length units  
[https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Values_and_units#lengths](https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/Values_and_units#lengths)

v  Use the box-model (padding, border, and margin) to create spacing around an HTML element

v  Use text-align and margin to horizontally center inline and block type elements respectively. Note: use of flexbox is also permitted, though it is newer and fewer examples are available
	- inline: Just shows as it being in the line, cannot set height and width values
	- 