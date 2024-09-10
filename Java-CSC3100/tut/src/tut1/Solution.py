class MyClass:
    # initialization
    def __init__(self, n1, v1=0.0, v2=0.0):
        self.num_1 = n1
        self.val_1 = v1
        self.__val_2 = v2 # private attribute
    
    def getVal2(self):
        return self.__val_2
    
    def setVal2(self, new_val):
        self.__val_2 = new_val

a = 0
b = 0.0

def foo():
    pass

def main():
    foo()

    a = int(input())
    b = float(input())

    mc = MyClass(a)

    print(a, b)
    print(mc.getVal2())

if __name__ == '__main__':
    main()