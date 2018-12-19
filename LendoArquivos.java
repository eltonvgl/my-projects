
package lendoarquivos;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class LendoArquivos {
    
        public static void main(String[] args) throws IOException {
        String caminho;
        Scanner scan = new Scanner(System.in);
        char continua = 's';
    
       do{
       
        System.out.println("Digite o caminho do arquivo para abri-lo: ");
        System.out.println("Como no modelo: C:\\Users\\XXXX\\Desktop\\XXXX.txt"); 
        caminho = scan.nextLine();
        System.out.println(caminho);
        File file = new File(caminho);
        BufferedReader br = new BufferedReader(new FileReader(file));
        
        String st;
        while ((st = br.readLine())!= null)
            System.out.println(st);
    
        System.out.println("Deseja continuar?<s/n>?");
        continua = scan.next().charAt(0);
       }while(continua =='s'||continua == 'S');    
}
}
