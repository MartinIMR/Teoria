import javax.swing.JFrame;
import javax.swing.JPanel;


public class Ventana extends JFrame
{
  public Ventana()
  {
    super("Ventana 1");
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setBounds(0,0,500,500);
  }

 public void plasmarDibujo(JPanel panel)
 {
   setContentPane(panel);
   setVisible(true);
 }

}
