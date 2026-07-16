// 1. Brute force 
// 2. Time and space complexity
// 3. Coding : Use existing methods, save time
            // Only write code when sure about the algorithm
            // Learn from your istakes
            // Always dry run before submitting

//  4. Focus ore on thinking and then spend less time on writing. AND PRACTISE A LOT.

// Time complexity: It tells us about the growth in runtime(not the actual time) of the algorithm wrt to the input. How much does the time change if input increases/decreases
// Spcae complexity: It tells us about the growth in space of the algorithm with respect to it's input.


//Time complexity-
// Since time taken by a machine to execute an operation is directly proportional to the number of operations to be executed,
// we measure time complexity by counting the number of operations and then convert it into big-O notation.

// Space complexity-
// We count it through the numbes of data structures and variables in the program and then convert it into the big-O notation.
// Variables, data structure and recursion of data structure occupies space.

//Big-O notation-
// Syntax: O(expression)
// BEST ONE- If Time= O(1), (aka constant time complexity) then it means that the runtime does not change if you inc. or dec. the number of inputs.
// SECOND BEST- If Time=O(log n), (aka logarithmic time complexity) then it means that
// THIRD BEST- If Time=O(n), (aka linear time complexity) then it means that runtime is directly proportional to "n" (linearly).
// FOURTH BEST -If Time=O(n^2), (aka quadratic time complexity) then it means that runtime is proportional to the square of the number of inputs, n.

//HOW DO YOU KNOW WHICH SOLUTION IS ACCEPTABLE?
// If number of operations(n) is between 10^7 to 10^8 then, the solution is mostoy acceptable, if less than 10^7 then always acceptable.
//but if the number of operations is greater than 10^8 then dont even try, it'll never be acceptable.

//HOW DO YOU GET THE EXPRESSION TO PUT IN BIG -O??
//To get so, add all the numbers of operation, for example if a loop runs n times with printing, iterating and checking conditions each time with 
//declaaring 'i' at statring once,then it's expression would be, (3n+1).
//In big-O notation, always ignore the constants which are getiing multipled or divided to "n". Also omit lower value terms.
// O(constant) example, O(5),O(78) all become O(1).
//