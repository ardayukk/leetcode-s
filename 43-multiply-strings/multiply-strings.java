import java.math.BigInteger;
class Solution {
    public String multiply(String num1, String num2) {
        BigInteger num1int = new BigInteger(num1);
        BigInteger num2int = new BigInteger(num2);
        String s = "" + num1int.multiply(num2int);
        return s;
    }
}