////////////////////////// TIMER SONECA POR ELTON LUZ////////////////
package timer;
import java.io.IOException;
import static java.lang.Thread.sleep;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Timer {

     public static void main(String[] args) throws IOException {
       Scanner scan = new Scanner(System.in);
       int hora = 0, minutos = 0;
       System.out.println("Bem-vindo ao Timer-Soneca!");
       System.out.println("Digite a hora desejada:");
       hora = scan.nextInt();
       System.out.println("Digite os minutos:");
       minutos = scan.nextInt();
       System.out.println("O computador será desligado em "+hora+" hora(s) e "+minutos+" minuto(s).");
       
       try
        {
            //Thread.sleep(1000);
            TimeUnit.SECONDS.sleep(3600*hora);
            TimeUnit.SECONDS.sleep(60*minutos);
        }
        catch(InterruptedException ex)
        {
            Thread.currentThread().interrupt();
            
        }
       Runtime.getRuntime().exec("shutdown -s");
     }
}