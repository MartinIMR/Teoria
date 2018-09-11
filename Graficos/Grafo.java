import java.awt.Graphics;
import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class Grafo extends JFrame{
 
 public Grafo(){
 super("Grafo");
 setSize(400,165);
 setVisible(true);
 }

 public void paint(Graphics g)
 {
  super.paint(g);
  g.setColor(Color.BLACK);
  g.drawLine(5,30,350,30);
 }

 public static void main(String []args)
 {
  Grafo grafo = new Grafo();
  grafo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 }

}
