package tut1;// import all classes in java.util package
import java.util.*; 


// Please name the program file the same as 
// the public class name inside.
// e.g., "public class Main" should be defined
//      in "Main.java"
public class Solution {
    static int a;
    static double b;

    // define functions in the following form
    public static void foo() { }

    public static void main(String[] args) {
        
        /* your main fuction here */
        foo();
        Scanner input = new Scanner(System.in);

        // sample inputs
        a = input.nextInt();
        b = input.nextDouble();

        MyClass mc = new MyClass(a);
        
        System.out.println(a + " " + b);
        System.out.println(mc.getVal2());
        input.close();
    }
}

// If you need self-defined classes,
// please define it below.
// NOTE: the class should not be declared as 'public'
class MyClass {
    
    // Define public attributes
    public int num_1;
    public double val_1;

    // Define private attributes
    private double val_2;

    // initialization
    // note that java does not allow default parameters
    // you can overload your functions if needed
    public MyClass(int n1, double v1, double v2) {
        num_1 = n1;
        // you can also write as below, which
        // is equivalent
        this.val_1 = v1;
        this.val_2 = v2;
    }
    // example of overloading
    public MyClass(int n1) {
        num_1 = n1;
        val_1 = 0.0;
        val_2 = 0.0;
    }

    // method defination
    public double getVal2() {
        return val_2;
    }
    public void setVal2(double new_val) {
        val_2 = new_val;
    }
}