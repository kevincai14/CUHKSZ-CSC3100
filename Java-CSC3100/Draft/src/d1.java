public class d1 {

    static int test_X(int x) {
        if (x > 20) {
            System.out.println("x > 20");
        } else if (x < 20) {
            System.out.println("x < 20");
        }
        return x;
    }

    public static void main(String[] args) {
        System.out.println("test");
        int x = 3;
        if (x == 3) {
            System.out.println("x == 3");
        }
//        while (x != 30) {
//            x++;
//        }
        for (int i = 0; i < 5; i++) {
            x += i;
        }
        x = test_X(x);
        System.out.println(x);

        Puppy newPuppy = new Puppy("Brain");
        boolean a = true;
        double b = (int)6.345254245;
        char c = 'c';
        int d = 0x64;
        String e = "test for string";
        System.out.println(b);
    }
}
