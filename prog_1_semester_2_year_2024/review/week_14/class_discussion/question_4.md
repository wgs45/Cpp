1. Please create a Template class Car and design a function show,
   This function accepts a std::list of Car object pointers as a parameter and displays the pos attribute of each Car object.
   First, define a Template class Car, which should contain a data member pos to store the location of the vehicle.
   The data type of pos may be int, float, double, etc.

Next, in the main function, create three Car object indicators and set their pos values to 1.2, 2.3 and 3.5 (assuming pos
is of double type). Store these three Car object pointers in a std::list and pass the list to the show function. In the show function, use a loop to traverse the list and display the pos of each vehicle.

2. Modify the above question, change std::list to std::map, each element in the map is {ID, Car indicator},
   In addition to the show function in the previous question displaying the pos of each Car,
   Also design a find function, input a coordinate value, output which Car has the coordinate, and return its ID value. If it cannot be found, it returns -1.
