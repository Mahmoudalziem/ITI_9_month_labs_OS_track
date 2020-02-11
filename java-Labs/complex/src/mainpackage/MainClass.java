
package mainpackage;
import  complex.Complex;

public class MainClass {
    
        public static void main(String[] args) 
        {
            Complex c1 = new Complex(3,-5);
            Complex c2 = new Complex(4 , 3);
            Complex c3 = new Complex();
            
            c3 = additionNum(c1, c2);
            System.out.println("add c1 + c2 = ");
            c3.printComplex();
            
            c3 =subtractionNum(c1, c2);
            System.out.println("add c1 - c2 = ");
            c3.printComplex();
            
        
        }
        public static Complex additionNum(Complex c1,Complex c2)
        {
            Complex p = new Complex();
            float x,y;
            
            x = c1.getReal() + c2.getReal();
            p.setReal(x);
            
            y = c1.getImag()+ c2.getImag();
            p.setImag(y);
            return p;
        }
        
        public static Complex subtractionNum(Complex c1,Complex c2)
        {
            Complex p = new Complex();
            float x,y;
            
            x = c1.getReal() - c2.getReal();
            p.setReal(x);
            
            y = c1.getImag()- c2.getImag();
            p.setImag(y);
            return p;
        }
        
}
        
    
    

