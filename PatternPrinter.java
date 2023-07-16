import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PatternPrinter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        printPattern(N);
    }

    public static void printPattern(int N) {
        List<String> list = new ArrayList<>();
        int count = 1;
        for (int i = 1; i <= N; i++) {
            String str = "";
            for (int j = 1; j <= i; j++) {
                str += count;
                System.out.print(count++);
                if (j != i) {
                    str += "*";
                    System.out.print("*");
                }
            }
            list.add(str);
            System.out.println();
        }

        for (int i = list.size() - 1; i >= 0; i--) {
            System.out.println(list.get(i));
        }
    }
}