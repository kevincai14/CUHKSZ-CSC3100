/**
 * Rational 类表示有理数，并包含一些用于有理数运算的方法。
 */
public class Rational {
    private int num; // 分子
    private int den; // 分母

    /** 创建一个值为 0 的有理数 */
    public Rational() {
        this(0);
    }

    /**
     * 使用整数 n 创建一个有理数，其值为 n/1
     * @param n 初始值
     */
    public Rational(int n) {
        this(n, 1);
    }

    /**
     * 创建一个值为 x/y 的有理数
     * @param x 分子
     * @param y 分母
     */
    public Rational(int x, int y) {
        int g = gcd(Math.abs(x), Math.abs(y)); // 计算 x 和 y 的最大公约数
        num = x / g;  // 简化分子
        den = Math.abs(y) / g;  // 简化分母
        if (y < 0) {
            num = -num;  // 保持分母为正数
        }
    }

    /**
     * 将此有理数与另一个有理数相乘
     * @param r 用于相乘的有理数
     * @return 相乘后的新有理数
     */
    public Rational multiply(Rational r) {
        return new Rational(this.num * r.num, this.den * r.den);
    }

    /**
     * 将此有理数除以另一个非零的有理数
     * @param r 用作除数的非零有理数
     * @return 相除后的新有理数
     */
    public Rational divide(Rational r) {
        return new Rational(this.num * r.den, this.den * r.num);
    }

    /**
     * 将此有理数与另一个有理数相加
     * @param r 要相加的有理数
     * @return 相加后的新有理数
     */
    public Rational add(Rational r) {
        return new Rational(this.num * r.den + r.num * this.den, this.den * r.den);
    }

    /**
     * 将此有理数减去另一个有理数
     * @param r 要减去的有理数
     * @return 相减后的新有理数
     */
    public Rational subtract(Rational r) {
        return new Rational(this.num * r.den - r.num * this.den, this.den * r.den);
    }

    /**
     * 计算 x 和 y 的最大公约数（使用欧几里得算法）
     * @param x 第一个整数
     * @param y 第二个整数
     * @return x 和 y 的最大公约数
     */
    private int gcd(int x, int y) {
        int r = x % y;
        while (r != 0) {
            x = y;
            y = r;
            r = x % y;
        }
        return y;
    }

    /**
     * 生成此有理数的字符串表示形式
     * @return 此有理数的字符串表示
     */
    @Override
    public String toString() {
        if (den == 1) {
            return String.valueOf(num);
        } else {
            return num + "/" + den;
        }
    }
}

