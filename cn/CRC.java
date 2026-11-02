
import java.util.Scanner;

class CRC {

    static String divisor = "10001000000100001";

    static String divide(String data) {

        char[] rem = data.toCharArray();

        for (int i = 0; i <= rem.length - divisor.length(); i++) {

            if (rem[i] == '1') {

                for (int j = 0; j < divisor.length(); j++) {

                    rem[i + j] =
                        (rem[i + j] == divisor.charAt(j)) ? '0' : '1';
                }
            }
        }

        return new String(rem).substring(
            rem.length - 16
        );
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of data bits: ");
        int n = sc.nextInt();

        System.out.print("Enter data bits: ");
        String data = sc.next();

        if (data.length() != n || !data.matches("[01]+")) {
            System.out.println("Invalid data bits!");
            sc.close();
            return;
        }

        String appended = data + "0000000000000000";

        String remainder = divide(appended);

        String codeword = data + remainder;

        System.out.println("CRC remainder: " + remainder);
        System.out.println("Transmitted codeword: " + codeword);

        System.out.print("Enter received codeword: ");
        String received = sc.next();

        if (received.length() != codeword.length()
                || !received.matches("[01]+")) {
            System.out.println("Invalid received codeword!");
        } else {

            String check = divide(received);

            System.out.println("Receiver remainder: " + check);

            if (check.equals("0000000000000000")) {
                System.out.println("No error detected.");
            } else {
                System.out.println("Error detected!");
            }
        }

        System.out.println("Thank You!");
        sc.close();
    }
}
