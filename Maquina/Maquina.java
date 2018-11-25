import javax.swing.JPanel;
import java.awt.Graphics;
import java.util.ArrayList;
import java.awt.Font;
import java.awt.FontMetrics;


public class Maquina extends JPanel
{
  String cadena;
  String cinta;
  String estado;
  int indice;
  String fin = "";

 public Maquina()
 {
   super();
 }
 
 public void setCadena(String cadena)
 {
   this.cinta = cadena;
 }
 
 public void setCinta(String cinta)
 {
   this.cinta = cinta;
 }
 
 public void setFin(String termino)
 {
   fin = "La cadena es "+termino; 
 }
 
 public void setIndice(String indice)
 {
   this.indice = Integer.parseInt(indice);
 }
 

 public void setEstado(String estado)
 {

  if(estado.equals("0") == true)
  {
    this.estado = "q0";
  }else if( estado.equals("1") == true)
  {
    this.estado = "q1";
  }else if(estado.equals("2") == true)
  {
    this.estado = "q2";
  }else if(estado.equals("3") == true)
  {
    this.estado = "q3";
  }else if(estado.equals("4"))
  {
    this.estado = "q4";
  }else
  {
    this.estado = "S/E";
  } 

 }
 

 @Override
 public void paintComponent(Graphics g)
 {
   super.paintComponent(g);
   int fontSize = 15;
   g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize)); 
   int inx = 20, iny = 50;
   g.drawString("La cadena es: "+cadena,inx,iny);
   FontMetrics metrica = g.getFontMetrics();
   fontSize = 25;
   g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize)); 
   metrica = g.getFontMetrics();
   dibujarCinta(g);
   for(int i=0;i<entrada.length();i++)
   {
     g.drawString(Character.toString(entrada.charAt(i)),(inx+30)*(i+1), (iny+38) );
   }
     String primero = Character.toString(entrada.charAt(0));
     int p1x = inx+30+(metrica.stringWidth(primero))/2;
     /* Dibujar flecha superior */
     g.drawLine(p1x,iny+48,p1x,iny+90); 
     g.drawLine(p1x,iny+48,p1x-10,iny+60);
     g.drawLine(p1x,iny+48,p1x+10,iny+60);
     /* Dibujar caja */
     g.drawRect(p1x-25,iny+100,50,50);
     /* Dibujar estado */
      fontSize = 15;
      g.setFont(new Font("Arial", Font.PLAIN, fontSize)); 
      metrica = g.getFontMetrics();
     int ctx,cty;
     ctx = p1x-25+(50-metrica.stringWidth(estado))/2;
     cty = iny+100+((50-metrica.getHeight())/2)+metrica.getAscent(); 
     g.drawString(estado,ctx,cty);
     /* Dibujar flecha inferior */
     g.drawLine(p1x,iny+160,p1x,iny+208); 
     g.drawLine(p1x,iny+208,p1x-10,iny+190);
     g.drawLine(p1x,iny+208,p1x+10,iny+190);
    
     g.drawString("Pila: ",p1x-50,iny+220);
     /* Dibujar pila */
      fontSize = 20;
      g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize)); 
      metrica = g.getFontMetrics();
     for(int i = pila.length()-1,j=1; i >= 0 ;i--)
     {
      g.drawString(Character.toString(pila.charAt(i)),p1x-8,(iny+220+(j*20)));
      j++;
     }
     fontSize = 15;
     g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize)); 
     g.drawString(fin,p1x+100,iny+125);


   /*
   for(Nodo estado:Q)
   {
     int radio = estado.getRadio();
     int h = estado.getH();
     int k = estado.getK();
     int h_l = h + (radio - metrica.stringWidth(estado.getId()))/2 ;
     int k_l = k + ((radio - metrica.getHeight())/2) + metrica.getAscent() ;
     g.drawOval(h,k,radio,radio);
     if(estado.getAceptacion())
     {
	g.drawOval(h+6,k+6,radio-12,radio-12);
     }
     g.drawString(estado.getId(),h_l,k_l);
	for(String sim:estado.simbolos)
	{
	  int i = estado.simbolos.indexOf(sim);
	  for(Nodo siguiente: estado.transiciones.get(i))
	  {
	    dibujarTransicion(estado,sim,siguiente,g);
	  } 
	}	
   }
   */

 }
 
 public void dibujarCinta(Graphics g)
 {

 }
  


}
