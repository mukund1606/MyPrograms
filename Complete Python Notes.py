"""
#####################################################################################################################################
📘 List of Topics 📘
-- Basic --
- Variables
- Conditions
- Chained Conditionals
- Operators
- Control Flow (If/Else)
- Loops and iterables
- Basic Data Structure
- Functions
- Mutable vs. Immutable
- Common Methods
- File IO

-- Intermediate --
- Comprehension
- Lambda
- Collections Module
- Map and Filter
- *args and **kwargs
- Inheritance
- Advanced Class
- Behaviour
- PIP
- Environments
- Module Creation
Async IO

-- Advanced --
- Decorators
- Genrerators
- Context Managers
- Metaclass
- Concurrency
- Parallelism
- Testing
- Packages
- Cython

-- Expert/Master --
-  How Python is built
-  Where are you using your skills?
-  Apply skills to a profession
#####################################################################################################################################


#################################################Beginners Python#################################################
####Data Types

4 Basic Data Dypes -
int - integers
str - strings
bool - boolean (True and False)
float - Decimal Numbers





a + ib
a + jb
25 65 35 ---- Numbers
45.5 35.44 ------ Decimal Number (Float)
"ABC" -------- String
true and false ----- boolean









####Variables -

name = "ABC"
a = 1
b = 5
c = a + b


####Operators-

##Arithematic
+, -, *, /,
**  -   Power
//  -   Floor Division
%   -   Remainder

##Comparison
<, >, ==, !=, >=, <=


##if-elif-else


####Loops

#for loop
##while loop


####Lists

list = [1, 2, 3, 'apple, 'banana']
#Index starts from 0
#To add - .append(at end)
list.append("ABC")


###Tuple
tup = (1,2,3,"abc", "def")


###String Methods
.strip()    -   Remove Left Right Spaces
len()       -   Returns Length of String
.lower()    -   Converts everything to lowercase
.upper()    -   Everything to uppercase
.split()    -   Split string to list by a parameter passed
.find()     -   Gives 1st Occurance of substring in string
.count()    -   Counts Total Occurance of substring in a string


###Slicing
lst = [1,2,3,4]
txt = "HELLO WORLD!"

print(lst[::2])
print(txt[::5])



###Function
def addTwo(x):
    return x + 2




###Read Text Files

file = open('file.txt', 'r')
a = []
b = file.readlines()
for line in b:
    a.append(line.strip())
print(a)
file.close()


###Writing to a File
file = open("hello.txt", "w")
file.write("Yo\nHello")
file.close()




###Introduction to modular programming

##Using Predefined Modules
import math
print(math.degrees(math.pi))


##Creating Modules
import myModule
print(myModule.myFunc(6))


##Optional Parameters(by using default values)
def func(x="3", text="2"):
    ## Here Text is optional Parameter
    print(x)
    if text=="1":
        print("Text is 1")
    else:
        print("Text is not 1")

func(text="1")
func("ABC")
func("abc", "1")







###Error Handling

text = input("Username:")
try:
    number = int(text)
    print(number)
except:
    print("Invalid Username...")



###Global and Local Variables

a = 5
loop = True
newvar = 9      ##Global Variable

def func(x):
    newvar = 7  ##Local Variable
    if x == 5:
        return newvar

def secondFunction():
    global newvar  ##Using Global Variable and Changing its value
    newvar = 1


func(5)
secondFunction()




#################################################Intermediate Python#################################################
###Classes and Inheritance


##Example-1
class Dog(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age   

    def speak(self):
        print("Hi I am ", self.name,", and I am ", self.age, " years old")

    def talk(self):
        print('Bark!')

class Cat(Dog):
    def __init__(self, name, age, color):
        super().__init__(name, age)
        self.color = color
    
    def talk(self):
        print("Meow!")
    
tim = Cat("tim", 5, "blue")
tim.speak()
tim.talk()



##Example-2
class Vehicle():
    def __init__(self, price, gas, color):
        self.price = price
        self.gas = gas
        self.color = color
        
    def fillUpTank(self):
        self.gas = 100
        
    def emptyTank(self):
        self.gas = 0
        
    def gasLeft(self):
        return self.gas
    
    def beep(self):
        print("Beep Beep")
    
    
class Car(Vehicle):
    def __init__(self, price, gas, color, tires):
        super().__init__(price, gas, color)
        self.tires = tires
        
    def beep(self):
        print("Honk Honk")


##Operator Overloading
class Point():
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
        self.coords = (self.x, self.y)
    
    def move(self, x, y):
        self.x += x
        self.y += y
        
    def __add__(self, p):
        return Point(self.x + p.x, self.y + p.y)

    def __str__(self) -> str:
        return "(" + str(self.x) + ',' + str(self.y) + ")"

    def length(self):
        import math
        return math.sqrt(self.x**2 + self.y**2)
    def __gt__(self, p):
        return self.length() > p.length()
    
    def __ge__(self, p):
        return self.length() >= p.length()

    def __mul__(self,p):
        return(self.x*p.x + self.y*p.y)
    
    

p1 = Point(3,4)
p2 = Point(2,1)
p3 = p1 + p2
p4 = p1<p2

print(p1>p2)



###Private Calss and Public Class
'''
#Private    -   Whose access is not available to everyone
In Python Private classes and methods are generall declared by "_" as initial letter as there is no concept of private and public classes in python
'''
#Public     -   Anyone can access this call unless values are final




###Static and Class Methods
class person(object):
    population = 50
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    @classmethod
    def getPopulation(cls):
        return cls.population

    
    @staticmethod
    def isAdult(age):
        return age >= 18
    
    def display(self):
        print(self.name + " is " + self.age + " years old")

newPerson = person("tim", 18)

##Class Method can be called without creating objects of that class
print(person.getPopulation())

##StaticMethod does not include and class parameters 
##It can be called without object and class
##Acts as a normal function within a class
print(person.isAdult(19))


####Map Function    -   Helps in Mapping Elements of List to a Function
li = [1,2,3,4,5,6,7,8,9,10]

def func(x):
    return x**x

a = list(map(func, li))

b = [func(x) for x in li]

c = [func(x) for x in li if x%2 == 0]

print(a)
print(b)
print(c)


####Filter Function -   Similar to Map Function but returns value only if function is True

def add7(x):
    return x+7

def isOdd(x):
    return x%2 != 0

a = [1,2,3,4,5,6,7,8,9,10]

b = list(filter(isOdd, a))
print(b)

c = list(map(add7, filter(isOdd, a)))
print(c)



####Lambda Function
def func(x):
    return x+5
func2 = lambda x: x+5
func3 = lambda x=5,y=4: x+y
print(func(2))
print(func2(2))
print(func3(y=1))

##Lambda Function with Map Function
a = [1,2,3,4,5,6,7,8,9,10]
newList = list(map(lambda x:x+5,a))
print(newList)

##Lambda Function with Filter Function
a = [1,2,3,4,5,6,7,8,9,10]
newList = list(filter(lambda x:x%2==0,a))
print(newList)




####Collections

from collections import Counter

##Pre Existing Containers(Data Types to Store Values)
#list
#set
#dict
#tuple(immutable)


##Containers added by collection module
#1 counter
#2 deque
#3 namedTuple()
#4 orderedDict
#5 defaultdict

###Counter

# c = Counter("gallad")
# print(c)
# c = Counter(['a','a','b','c','c'])
# print(c)
# c = Counter({'a': 1, 'b': 2})
# print(c)
# c = Counter(cats = 4, dogs = 7, abc = 9)
# print(c['cats'])
# print(c['pet'])     ##No Error if key is not in dict

##Counter Methods
# print(list(c.elements()))
# print(c.most_common(1))
# c = Counter(a=4, b = 2, c = 0, d = 2)   
# d = ['a','b','b','c']
# c.subtract(d)
# c.update(d)
# print(c)

##Counter Operations
# c = Counter(a=4, b = 2, c = 0, d = -2)   
# d = Counter(['a','b','b','c'])
# print(c+d)
# print(c-d)
# print(c & d)
# print(c | d)



##NamedTuple and It's methods
# from collections import namedtuple
# Point = namedtuple("Point", "x y z")
# Point = namedtuple("Point", ['x','y','k'])
# Point = namedtuple("Point", {'x':0,'y':0,'s':0})
# newP = Point(3,4,5)
# print(newP)
# print(newP.x, newP.y)
# print(newP._asdict())
# print(newP._fields)
# print(newP._replace(y=6, s = 1))
# p2 = Point._make(['a','b','c'])
# print(p2)




##Deque and It's Methods
from collections import deque

# d = deque("Hello")
# print(d)
# d.append("4")
# d.appendleft("5")
# print(d)
# d.pop()
# d.popleft()
# print(d)
# d.clear()
# print(d)
# d.extend("456")
# d.extend("Hello")
# print(d)
# d.extend("456")
# d.extendleft("Hello")
# print(d)
# d.rotate(-1)    ## Negative to Left and Positive to Right
# print(d)
# d = deque("Hello", maxlen=5)
# print(d)
# d.append(1)
# print(d)
# d.extend([1,2,3])
# print(d)



#################################################Advanced Python#################################################

"""
