package akif;
import java.util.Scanner;

public class Meters_to_Pulses_Calc {
    public static void main(String[] args) {
       
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the distance in meters: ");
        double distance = scanner.nextDouble();

        double result = (distance / 0.4) * 540;

        System.out.println(distance + " meters is approximately: " + result + " pulses");

        scanner.close();
    }
}

