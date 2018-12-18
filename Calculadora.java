import java.util.Scanner;

class  calculadora
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    //Scanneer scan = new Scanner(System.int);
    int num = 0, num1= 0, sum = 0, sub=0,sub1=0,sub2=0;
    int div=0,div1=0,div2=0,mul=0,mul1=0,mul2=0, opcao=0;
    char continua = 's';
    //opcoes
    do{
    System.out.println("Escolha uma opcao: ");
    System.out.println("1 - soma");
    System.out.println("2 - subtracao");
    System.out.println("3 - divisao");
    System.out.println("4 - multiplicacao");
    opcao = scan.nextInt();

   
   //soma
    switch(opcao)
    {
      case 1: System.out.println("Insira um numero: ");
      num = scan.nextInt();
      System.out.println("Insira um numero: ");
      num1 = scan.nextInt();
      sum = num + num1;
      System.out.println("O resultado da soma e: "+ sum);
      System.out.println("Deseja continuar? <s/n>");
      continua = scan.next().charAt(0);
      break;
      //subtracao
      case 2: System.out.println("Insira um numero");
      sub= scan.nextInt();
      System.out.println("Insira um numero");
      sub1 = scan.nextInt();
      sub2 = sub-sub1;
      System.out.println("O resultado da subtracao e "+ sub2);
      System.out.println("Deseja continuar? <s/n>");
      continua = scan.next().charAt(0);
      break;
      //divisao
      case 3: System.out.println("Insira um numero");
      div = scan.nextInt();
      System.out.println("Insira um numero");
      div1= scan.nextInt();
      div2 = div/div1;
      System.out.println("O resultado da divisao e "+ div2);
      System.out.println("Deseja continuar? <s/n>");
      continua = scan.next().charAt(0);
      break;
      //multiplicacao
      case 4:System.out.println("Insira um numero");
      mul= scan.nextInt();
      System.out.println("Insira um numero");
      mul1= scan.nextInt();
      mul2=mul*mul1;
      System.out.println("O resultad e "+ mul2);
      System.out.println("Deseja continuar? <s/n>");
      continua = scan.next().charAt(0);
      break;
      default: System.out.println("Escolha uma opcao valida");
      break;
      }
    }while(continua == 's'|| continua == 'S');
    System.out.println("Obrigado por utilizar a calculadora!");
          
  }
}