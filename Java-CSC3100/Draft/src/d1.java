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
        double b = 6.745254245;
        char c = 'c';
        Integer d = 0x64;
        String e = "test for string";
        System.out.println(Math.round(b));

        char[] hello = {'h', 'e', '1', '1', '0'};
        String hello2 = new String(hello);
        System.out.println("wdf".concat(hello2));

        int[] list = new int[10];
        list[0] = 1;
        System.out.println(list[4]);
        for (int i: list) {
            System.out.println(i);
        }
    }
}
