import java.lang.StringBuilder;
import java.util.Scanner;
import java.io.FileReader;

public class Principal
{

 public static void main(String []args)
 {
	Ventana marco = new Ventana();
        Maquina maquina = new Maquina();
	try{
	Scanner entrada = new Scanner(new FileReader("datos.txt"));
	StringBuilder sb = new StringBuilder();
	String cadena = entrada.next();
	grafo.setCadena(cadena);
	//marco.plasmarDibujo(grafo);
	String termino = "";
	try{

	while(entrada.hasNext())
	{
	  String estado = entrada.next();
	  if(estado.equals("aceptada"))
	  {
	  termino = estado; 
	  break;
	  }else if(estado.equals("no"))
	  {
	  termino = estado +" "+ entrada.next();
	  break;
          }
	  String cinta = entrada.next();
	  String indice = entrada.next();
	  maquina.setEstado(estado);
	  maquina.setCinta(cinta);
	  maquina.setIndice(indice);

	  System.out.println("El estado es:"+estado);
	  System.out.println("La cadena es:"+cadena_actual);
	  System.out.println("La pila tiene:"+pila);
	  Thread.sleep(7000);
	  marco.plasmarDibujo(maquina);
	}
	  grafo.setFin(termino);
	  marco.plasmarDibujo(grafo);
	}catch(Exception e)
	{
	  System.out.println("No se pudo retrasar");	
	}
	entrada.close();
	}catch(Exception e)
	{
	System.out.println("Excepcion encontrada");
	}

	
 }

  
  
 
}
