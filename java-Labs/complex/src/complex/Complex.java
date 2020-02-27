
package complex;


public class Complex {

    float real;
    float imag;

    public Complex() {
    }

    public Complex(float real, float imag) {
        this.real = real;
        this.imag = imag;
    }

    public float getReal() {
        return real;
    }

    public void setReal(float real) {
        this.real = real;
    }

    public float getImag() {
        return imag;
    }

    public void setImag(float imag) {
        this.imag = imag;
    }
    public void printComplex()
    {
        if(imag < 0)
        {
           System.out.println(real +""+ imag +"i" );
        }
        else if(imag > 0)
        {
            System.out.println(real +"+"+ imag +"i" );
        }
        
    }

}
